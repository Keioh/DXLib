#include "Input.h"


void Input::init()
{
	click = false;
	//button_buffer = -1;
	//x_buffer = -1;
	//y_buffer = -1;
	//button_input_log_buffer = -1;
}

//�u�Ԃ̃N���b�N
bool Input::MouseCilck(int MouseInput)//�኱������������������
{
	//int Button, x, y;

	// �N���b�N�����擾����
	if (GetMouseInputLog2(&button_buffer, &x_buffer, &y_buffer, &button_input_log_buffer, TRUE) == 0)
	{
		if ((GetMouseInput() & button_buffer & MouseInput) != 0)
		{
			return click = true;
		}
	}
	return click = false;
}

//�}�E�X�̌p���N���b�N
bool Input::MouseClickContinuation(int mouseinput)
{
	if ((GetMouseInput() & mouseinput) != 0)
	{
		return  click = true;
	}
	else
	{
		return click = false;
	}
}