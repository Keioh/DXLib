#include "Input.h"

Input::Input()
{

}

//�u�Ԃ̃N���b�N
bool Input::MouseCilck(int MouseInput)//�኱������������������
{
	//int Button, x, y;

	// �N���b�N�����擾����
	if (GetMouseInputLog(&button_buffer, &x_buffer, &y_buffer, TRUE) == 0)
	{
		if ((GetMouseInput() & button_buffer & MouseInput) != 0)
		{
			return true;
		}
	}
	return false;
}

//�}�E�X�̌p���N���b�N
bool Input::MouseInputClick(int mouseinput)
{
	if ((GetMouseInput() & mouseinput) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}