#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//window�֘A
	window_x = 1280;
	window_y = 720;
	window_bit = 32;
	refresh_rate = 60;
	window_mode = TRUE;
	window_name = "DiploidEngine ver0.00";
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
	SetGraphMode(window_x, window_y, window_bit, refresh_rate);//�𑜓x�ύX
	ChangeWindowMode(window_mode);//�E�B���h�E���[�h�ύX
	SetDrawScreen(DX_SCREEN_BACK);//����ʏ������I��
	SetMainWindowText(window_name);//�A�v���P�[�V�����̖��O��ύX
}

void DiploidEngineSetting::SetEnd()
{

}

void DiploidEngineSetting::End()
{
	DxLib_End();
}