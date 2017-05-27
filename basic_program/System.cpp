#ifndef _SYSTEM
#define _SYSTEM

//include
#include "DxLib.h"
#include "System.h"

#endif

//DXLIB������
void Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIB���O�ɏ���������֐�
	ChangeWindowMode(w_mode);
	SetGraphMode(Window::window_w, Window::window_h, Window::window_b);
	SetMainWindowText(name);
	SetWindowSizeChangeEnableFlag(true);

	//DXLIB�̏�����
	DxLib_Init();

	//DXLIB�̌�ɏ���������֐�	
	SetCameraPositionAndAngle(VGet(-45.0f, -1800.0f, -800.0f), (DX_PI / 180 * -80.0f), (DX_PI / 180 * 0.0f), (DX_PI / 180 * 0.0f));
	SetMouseDispFlag(TRUE);
	SetUseASyncLoadFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetBackgroundColor(r, g, b);
}

bool Circle_Hit(int x, int y, float r, int x2, int y2, float r2)
{
	return true;
}

//�u�Ԃ̃N���b�N
bool Mouse_Cilck(int MouseInput, int flag)
{
	int Button, x, y;

	// �N���b�N�����擾����
	if (GetMouseInputLog(&Button, &x, &y, TRUE) == 0)
	{
		if ((GetMouseInput() & Button & MouseInput) != flag)
		{
			return true;
		}
	}
	return false;
}

//�}�E�X�̌p���N���b�N
bool Mouse_Input_Click(int mouseinput)
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
	
//�J�[�\���摜���[�h
int Cursor_Graph[1];
void Cursor_Load()
{
	Cursor_Graph[0] = LoadGraph("res/graph/cursor/cursor.png");
}

//�J�[�\���摜�`��
void Cursor_Draw(int& mouse_x, int& mouse_y)
{
		DrawGraph(mouse_x, mouse_y, Cursor_Graph[0], TRUE);
}