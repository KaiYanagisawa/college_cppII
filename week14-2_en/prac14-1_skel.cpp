#include <iostream>
using std::cout;

void sqrt(int *x, int *y); // ������K���Ɏw��

int main()
{
	int x{10};
	cout << "&x   : " << &x << "\n"; // x���Q�Ɓi�A�h���X���������Ɓj

	int *xPtr;							// �|�C���^�̐錾�i*�͊֐ߎQ�Ɖ��Z�q�j
	xPtr = &x;							// x�̃A�h���X����
	cout << "*xPtr: " << *xPtr << "\n"; // x���ԐړI�ɏo��
	cout << " xPtr: " << xPtr << "\n";	// x�̃A�h���X���o��

	int y{5};
	int *yPtr = &y;						// �|�C���^��錾���Cy�̃A�h���X����
	cout << "*yPtr: " << *yPtr << "\n"; // y���ԐړI�ɏo��
	cout << " yPtr: " << yPtr << "\n";	// y�̃A�h���X���o��

	sqrt(xPtr, yPtr);					// sqrt�֐��̌Ăяo��
	cout << "*yPtr: " << *yPtr << "\n"; // y���ԐړI�ɏo��

	cout << "x = " << x << ", y = " << y << "\n";
}

void sqrt(int *x, int *y)
{				  // ������K���Ɏw��
	*y = *x * *x; // �����v�Z
}
// �Ԃ�l���Ȃ��C�܂�C�R�s�[���쐬����K�v���Ȃ�
// ��K�͂ȃf�[�^�Ŋ֐��Ăяo�����Ă��C�f�[�^�̃R�s�[�����Ȃ����߁C�������̈��������Ȃ�