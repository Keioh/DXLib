#ifndef _SYSTEM
#define _SYSTEM

//include
#include "DxLib.h"
#include "System.h"

#endif

//DXLIB初期化
void Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIBより前に初期化する関数
	ChangeWindowMode(w_mode);
	SetGraphMode(Window::window_w, Window::window_h, Window::window_b);
	SetMainWindowText(name);
	SetWindowSizeChangeEnableFlag(true);

	//DXLIBの初期化
	DxLib_Init();

	//DXLIBの後に初期化する関数	
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

//瞬間のクリック
bool Mouse_Cilck(int MouseInput, int flag)
{
	int Button, x, y;

	// クリック情報を取得する
	if (GetMouseInputLog(&Button, &x, &y, TRUE) == 0)
	{
		if ((GetMouseInput() & Button & MouseInput) != flag)
		{
			return true;
		}
	}
	return false;
}

//マウスの継続クリック
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
	
//カーソル画像ロード
int Cursor_Graph[1];
void Cursor_Load()
{
	Cursor_Graph[0] = LoadGraph("res/graph/cursor/cursor.png");
}

//カーソル画像描写
void Cursor_Draw(int& mouse_x, int& mouse_y)
{
		DrawGraph(mouse_x, mouse_y, Cursor_Graph[0], TRUE);
}