//include
#include "DxLib.h"
#include "System.h"

System::System()
{
	window_size.x = 1280;
	window_size.y = 720;
	window_size.z = 32;

}

//DXLIB初期化
void System::Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIBより前に初期化する関数
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(w_mode);
	SetGraphMode(window_size.x, window_size.y, window_size.z);
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

//円のあたり判定
bool System::Circle_Hit(int x, int y, float r, int x2, int y2, float r2)
{
	return true;
}

//瞬間のクリック
/*bool System::Mouse_Cilck(int MouseInput, int flag)
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

//カーソル画像ロード
int Cursor_Graph[1];
void System::Cursor_Load()
{
	Cursor_Graph[0] = LoadGraph("res/graph/cursor/cursor.png");
}

//カーソル画像描写
void System::Cursor_Draw(int& mouse_x, int& mouse_y)
{
		DrawGraph(mouse_x, mouse_y, Cursor_Graph[0], TRUE);
}