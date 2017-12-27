//include
#include "DxLib.h"
#include "System.h"

System::System()
{
	size.x = 1280;
	size.y = 720;
	size.bit = 32;

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
	SetUseDXArchiveFlag(TRUE);//�A�[�J�C�u�ǂݍ��݉\�ɕύX
	SetDXArchiveExtension("kou");//�g���q�ύX
	SetDXArchiveKeyString("999");//�A�[�J�C�u�p�X���[�h���w��
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 1.0f, 0.0f));
	SetMouseDispFlag(TRUE);
	SetUseASyncLoadFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetBackgroundColor(r, g, b);
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
}*/