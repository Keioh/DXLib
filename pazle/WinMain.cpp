//include
#include "DxLib.h"
#include "Main_Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main_Game* MG = new Main_Game();

	//ライブラリ初期化
	MG->main_system.Dx_Init(TRUE, 255, 255, 255, "Pazle Project ver0.00");
	
	//ゲームループ
	MG->Main_Game_Loop();

	//DXLIB終了
	MG->main_system.Dx_End();

	//メモリ解放
	delete MG;

	return 0;
}