//include
#include "DxLib.h"
#include "System.h"
#include "Main_Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main_Game* MG = new Main_Game();

	//ライブラリ初期化
	Dx_Init(TRUE, 255, 255, 255, "TRPG ASSIST TOOL ver1.99" );

	//ゲームループ
	MG->Main_Game_Loop();

	//メモリ解放
	delete MG;

	//DXLIB終了
	DxLib_End();

	return 0;
}