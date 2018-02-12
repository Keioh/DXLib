//include
#include "DxLib.h"
#include "System.h"

System::System()
{
	size.x = 1280;
	size.y = 720;
	size.bit = 32;
	fullscreen = -1;
}

//DXLIB������
void System::Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIB���O�ɏ���������֐�
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(w_mode);
	SetGraphMode(size.x, size.y, size.bit);
	SetMainWindowText(name);
	SetWindowSizeChangeEnableFlag(true);

	//DXLIB�̏�����
	DxLib_Init();

	//DXLIB�̌�ɏ���������֐�	
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetUseDXArchiveFlag(TRUE);//�A�[�J�C�u�ǂݍ��݉\�ɕύX
	SetDXArchiveExtension("kou");//�g���q�ύX
	SetDXArchiveKeyString("999");//�A�[�J�C�u�p�X���[�h���w��
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//�t�H���g�^�C�v�̕ύX
	SetFontThickness(6);//�t�H���g�̑�����ύX
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 1.0f, 0.0f));
	SetMouseDispFlag(TRUE);
	SetUseASyncLoadFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetBackgroundColor(r, g, b);
}

//DXLIB�I������
void System::Dx_End()
{
	DxLib_End();
}