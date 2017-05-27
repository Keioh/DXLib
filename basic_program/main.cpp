//include
#include "DxLib.h"
#include "System.h"
#include "Main_Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main_Game* MG = new Main_Game();

	//���C�u����������
	Dx_Init(TRUE, 255, 255, 255, "TRPG ASSIST TOOL ver1.99" );

	//�Q�[�����[�v
	MG->Main_Game_Loop();

	//���������
	delete MG;

	//DXLIB�I��
	DxLib_End();

	return 0;
}