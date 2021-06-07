#include<iostream>
class Ref{
    int &x, y;
    public:
    //コンストラクタ
        Ref(int x, int y){
            
        }
        void set(int a,int b){x=a;y=b;}
        void print() const{
            std::cout<<x<<" "<<y<<"\n";
        }
};
int main(){
    int n{10};
    Ref s{n,0}, t{n,2};
    s.set(3,1);
    s.print();
    t.print();
}