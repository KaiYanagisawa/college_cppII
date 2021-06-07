#include <iostream>
#include "./vec.hpp"
int main()
{
  //-------(1) int + double �̏ꍇ-------
  std::cout << "(1)\n";

  Vec<int> vec1{"vec1", 1, 3, 5};
  Vec<double> vec2{"vec2", 2.2, 4.4, 6.6};

  //�܂��̓x�N�g����\������D
  vec1.print();
  vec2.print();

  //�x�N�g���̑傫����\������.
  std::cout << vec1.get_n() << "'s length is " << vec1.length() << "\n";
  std::cout << vec2.get_n() << "'s length is " << vec2.length() << "\n";

  //�x�N�g���̓��ς��v�Z���ĕ\������D
  std::cout << "inner product of vec1 & vec2 is " << inner_product(vec1, vec2) << "\n";
  //��̃x�N�g���̒������r���āC�ǂ��炪�傫������\������D
  comp_print(vec1, vec2);
  //�x�N�g���̑����Z�����āC�ł����x�N�g����\������D
  (vec1 + vec2).print();

  //-------(2) double + int �̏ꍇ-------
  std::cout << "(2)\n";

  Vec<double> vec3{"vec3", 10.1, 11.1, 12.1};
  Vec<int> vec4{"vec4", 5, 4, 3};
  vec3.print();
  vec4.print();
  comp_print(vec3, vec4);
  (vec3 + vec4).print();

  //-------(3)��̃x�N�g���̑傫���������ꍇ-------
  std::cout << "(3)\n";

  Vec<int> vec5{"vec5", 10, 20, 30};
  Vec<double> vec6{"vec6", 10.0, 20.0, 30.0};
  vec5.print();
  vec6.print();
  comp_print(vec5, vec6);
  (vec5 + vec6).print();
}
