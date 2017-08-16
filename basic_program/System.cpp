//include
#include "DxLib.h"
#include "System.h"

System::System()
{
	window_size.x = 1280;
	window_size.y = 720;
	window_size.z = 32;

}

//DXLIB������
void System::Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIB���O�ɏ���������֐�
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(w_mode);
	SetGraphMode(window_size.x, window_size.y, window_size.z);
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

//�~�̂����蔻��
bool System::Circle_Hit(int x, int y, float r, int x2, int y2, float r2)
{
	return true;
}

//�u�Ԃ̃N���b�N
/*bool System::Mouse_Cilck(int MouseInput, int flag)
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
bool System::Mouse_Input_Click(int mouseinput)
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
*/

//�J�[�\���摜���[�h
int Cursor_Graph[1];
void System::Cursor_Load()
{
	Cursor_Graph[0] = LoadGraph("res/graph/cursor/cursor.png");
}

//�J�[�\���摜�`��
void System::Cursor_Draw(int& mouse_x, int& mouse_y)
{
		DrawGraph(mouse_x, mouse_y, Cursor_Graph[0], TRUE);
}