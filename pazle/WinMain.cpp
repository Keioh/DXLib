//include
#include "DxLib.h"
#include "Main_Game.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Main_Game* MG = new Main_Game();

	//���C�u����������
	MG->main_system.Dx_Init(TRUE, 255, 255, 255, "Pazle Project ver0.00");
	
	//�Q�[�����[�v
	MG->Main_Game_Loop();

	//DXLIB�I��
	MG->main_system.Dx_End();

	//���������
	delete MG;

	return 0;
}