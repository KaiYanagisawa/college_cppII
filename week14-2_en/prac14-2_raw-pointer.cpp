// 先頭と最後尾両方のポインタを持つキューの実装例
#include <iostream>
#include <memory>

using std::cout;

// 値と次のノードを指すポインタの2つを持つ構造体
// リスト構造でキューを作るために使用する
struct Node
{
	int value;
	std::shared_ptr<Node> nextp;
	Node(int a, Node *p) : value{a}, nextp{p} {}
	~Node() { cout << "dtor: " << value << "\n"; } // メモリ解放のタイミングを確認
};

// データを最後尾から入れて先頭から取り出すキュー
class ListQueue
{
private:
	Node *front, *rear; // キューの中の，先頭と最後尾のノードを指すポインタ
public:
	ListQueue() : front{nullptr}, rear{nullptr} {}
	~ListQueue()
	{ // キューの中にあるデータを全て解放
		while (front != nullptr)
			dequeue();
	}
	void enqueue(int a)
	{ // キューの最後尾にデータを追加
		if (front == nullptr)
		{
			// rear = front = new Node(a, nullptr);
			rear = front = std::make_shared<Node>(a, nullptr);
		}
		else
		{
			rear = rear->nextp = new Node(a, nullptr);
		}
	}
	int dequeue()
	{ // 先頭からデータを取り出す
		if (front == nullptr)
		{ // キューが既に空
			cout << "dequeue error, this dequeue returns -1.\n";
			return -1;
		}
		else if (front == rear)
		{ // キューにデータが1つだけ（この操作でキューが空になる）
			const int val{front->value};
			delete front;
			front = nullptr;
			rear = nullptr;
			return val;
		}
		else
		{
			const Node *ptr{front};
			const int val{front->value};
			front = front->nextp;
			delete ptr;
			return val;
		}
	}
};

int main()
{
	ListQueue que;
	const int lim{10};
	for (int i{0}; i < lim; ++i)
		que.enqueue(i);
	for (int i{0}; i < lim; ++i)
		que.dequeue();
	que.enqueue(2);
	que.enqueue(6);
	que.enqueue(8);
	que.enqueue(4);
	cout << que.dequeue() << " " << que.dequeue() << " "
		 << que.dequeue() << " " << que.dequeue() << "\n";
	return 0;
}
