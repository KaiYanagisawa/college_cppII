#include <iostream>

//i�sj��̈ʒu���W�̒�`
struct Pos
{
  int i, j;
  bool operator==(const Pos p) const { return i == p.i && j == p.j; };
  bool operator!=(const Pos p) const { return i != p.i || j != p.j; };
};

//�q�ɔԂ̃Q�[���t�B�[���h�̒�`
class Field
{
private:
  //�Q�[���t�B�[���h�̏����ݒ�
  const int row{3};     //�s���i�c�̒����j
  const int column{3};  //�񐔁i���̒����j
  const Pos wall{1, 1}; //�ǁi��Q���j�̈ʒu
  const Pos goal{0, 0}; //�S�[���̈ʒu
  Pos player{2, 2};     //�v���C���[�̏����ʒu
  Pos box{0, 1};        //���̏����ʒu

public:
  //�t�B�[���h��[����ɕ\��
  void print()
  {
    for (int i = -1; i <= row; i++)
    {
      for (int j = -1; j <= column; j++)
      {
        //�t�B�[���h�̎��͂ɕǂ�\��
        if (i < 0 || i >= row || j < 0 || j >= column)
        {
          std::cout << 'X';
        }
        //�v���C���[�A�ǁA�S�[���A����\��
        //�v���C���[�̏ꏊ�ł�'@'��\��
        //�ǂ̏ꏊ�ł�'X'��\��
        //�S�[���Ɣ����d�Ȃ��Ă���ꍇ��'O'��\��
        //�S�[���݂̂̏ꍇ��'+'��\��
        //���݂̂̏ꍇ��'$'��\��
        //����ȊO�͋�' '��\��
        else
        {
          if (i == player.i && j == player.j)
            std::cout << "@";
          else if (i == wall.i && j == wall.j)
            std::cout << "X";
          else if (goal == box && goal.i == i && goal.j == j)
            std::cout << "O";
          else if (i == goal.i && j == goal.j)
            std::cout << "+";
          else if (i == box.i && j == box.j)
            std::cout << "$";
          else
            std::cout << " ";
        }
      }
      std::cout << '\n';
    }
  }

  //�S�[���Ɣ����d�Ȃ��Ă���ꍇ�̓Q�[���N���A�Ɣ���
  bool
  completed()
  {
    if (goal == box)
      return true;
    else
      return false;
  }

  //u(up), d(down), r(right), l(left)�̕�������󂯂ăv���C���[�����̕����Ɉړ�
  //move�֐��̈����Ƃ��āAPos�^�������ړ������ɕύX���郉���_����^����
  //�Ⴆ�� d=='u'�̏ꍇ�́APos�^�ϐ�p�������Ƃ��āAp.i��1���炵�āAp��Ԃ������_����^����
  void movec(char d)
  {
    if (d == 'u')
      move([](Pos p)
           {
             p.i--;
             return p;
           });
    else if (d == 'd')
      move([](Pos p)
           {
             p.i++;
             return p;
           });
    else if (d == 'r')
      move([](Pos p)
           {
             p.j++;
             return p;
           });
    else if (d == 'l')
      move([](Pos p)
           {
             p.j--;
             return p;
           });
  }

  //Pos�^�ϐ����ړ�����֐�next���󂯎��t�B�[���h�̏�ԍX�V���s��
  template <typename T>
  void move(T next)
  {
    //Pos�^����p���ړ��\�Ȉʒu�����肷��֐��������_���Œ�`
    //p��0�`(row-1), 0�`(column-1)�̍��W�Ɏ��܂��Ă��邩�Awall�Əd�Ȃ��Ă��Ȃ����𔻒�
    auto can_move = [=](Pos &p)
    {
      return (p.i >= 0 && p.i <= row - 1 && p.j >= 0 && p.j <= column - 1 && wall != p);
    };
    Pos pnext = next(player); //�v���C���[�̎��̈ʒu�̌v�Z
    if (can_move(pnext))
    { //�v���C���[���ړ��\�ȏꍇ�̂ݍX�V
      //�v���C���[�����ɏd�Ȃ�Ȃ��ꍇ�͂��̂܂܈ړ�
      if (pnext != box)
      {
        player = pnext;
        next(player);
      }
      //�v���C���[�����ɏd�Ȃ�ꍇ�͔��̈ړ����肪�K�v
      else
      {
        Pos bnext = next(box); //���̎��̈ʒu���v�Z
                               //�����ړ��\�ȏꍇ�̓v���C���[�Ɣ����ړ�
        if (can_move(bnext))
        {
          player = pnext;
          next(player);
          box = bnext;
          next(box);
        }
      }
    }
  };
};

int main()
{
  Field f; //�t�B�[���h�̏�����
  char c;
  f.print(); //�����t�B�[���h�̕\��
  while (std::cin >> c)
  {
    // 'q' �̏ꍇ�͏I���i���^�C�A�j
    if (c == 'q')
    {
      std::cout << "quit" << '\n';
      exit(1);
    }
    // 'u', 'd', 'r', 'l' �̏ꍇ�͂��̈ړ������ɏ]���čX�V���A�Q�[���N���A�̏ꍇ�͏I��
    if (c == 'u' || c == 'd' || c == 'r' || c == 'l')
    {
      f.movec(c);
      f.print();
      if (f.completed())
      {
        std::cout << "The work is completed!!\n";
        break;
      }
    }
    //��L�ȊO�̓��͂̏ꍇ�͐��������͌���\��
    else
      std::cout << "u(up), d(down), r(right), l(left), q(quit)" << '\n';
  }
}