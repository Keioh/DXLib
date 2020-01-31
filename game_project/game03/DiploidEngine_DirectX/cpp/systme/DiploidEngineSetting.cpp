#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//window�֘A
	window_x = 1280;
	window_y = 720;
	window_bit = 32;
	refresh_rate = 60;
	window_mode = TRUE;
	window_name = "DiploidEngine ver0.05";//Diploid Engine ver0.05
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
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//�����R�[�h�ύX
	SetBackgroundColor(50, 50, 50);
	SetOutApplicationLogValidFlag(FALSE);//���O�o�͊֘A
	SetGraphMode(window_x, window_y, window_bit, refresh_rate);//�𑜓x�ύX
	ChangeWindowMode(window_mode);//�E�B���h�E���[�h�ύX
	SetMainWindowText(window_name);//�A�v���P�[�V�����̖��O��ύX

	SetUseASyncLoadFlag(TRUE);//�񓯊��ǂݍ���
	SetUseDXArchiveFlag(TRUE);//DX�A�[�J�C�u�ǂݍ���
	SetAlwaysRunFlag(TRUE);//�E�B���h�E��A�N�e�B�u�ŏ��������s

	SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);//�摜��Ԃ̕ύX

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