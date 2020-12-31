#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//window�֘A
	window_x = 1280;
	window_y = 720;
	window_bit = 32;
	refresh_rate = 60;
	window_mode = TRUE;
	window_name = "���ɛƂ�l ver0.0.10 [DiploidEngine Ver0.06]";//Diploid Engine ver0.06
}

void DiploidEngineSetting::Init()
{
	DiploidEngineSetting::SetBegin();//DXLIB���������O�ɐݒ肷�鏈���B

	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	DiploidEngineSetting::SetEnd();//DXLIB����������ɐݒ肷�鏈���B
}

void DiploidEngineSetting::SetBegin()
{
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);
	//SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//�����R�[�h�ύX	
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//�t�H���g�̕`��̎d��
	SetFontThickness(1);//�t�H���g�̑�����ݒ�
	ChangeFont("���C���I");//�t�H���g�̎�ނ̐ݒ�
	SetFontSize(15);//�t�H���g�̑傫����ݒ�
	SetBackgroundColor(50, 50, 50);
	SetOutApplicationLogValidFlag(FALSE);//���O�o�͊֘A
	SetGraphMode(window_x, window_y, window_bit, refresh_rate);//�𑜓x�ύX
	ChangeWindowMode(window_mode);//�E�B���h�E���[�h�ύX
	SetMainWindowText(window_name);//�A�v���P�[�V�����̖��O��ύX

	SetUseASyncLoadFlag(TRUE);//�񓯊��ǂݍ���
	SetUseDXArchiveFlag(TRUE);//DX�A�[�J�C�u�ǂݍ���
	SetAlwaysRunFlag(TRUE);//�E�B���h�E��A�N�e�B�u�ŏ��������s

	SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);//��ʕ�Ԃ̕ύX
	SetDrawMode(DX_DRAWMODE_NEAREST);//�摜�g�厞�̕�ԕύX
	SetFullSceneAntiAliasingMode(4, 2);//AA�ݒ�

	SetEnableXAudioFlag(TRUE);//XAudio�t���O

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

}

void DiploidEngineSetting::SetEnd()
{
	SetDrawScreen(DX_SCREEN_BACK);//����ʏ������I��
	SetCameraNearFar(0.1f, 10000.0f);

}

void DiploidEngineSetting::End()
{
	DxLib_End();
}