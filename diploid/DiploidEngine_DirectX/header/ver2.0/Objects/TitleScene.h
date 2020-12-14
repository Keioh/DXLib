#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"


class TitleScene
{
private:
	DiploidEngineInput input;//���͊֘A
	DiploidEngineSetting setting;//WindowSize�擾�p

	DiploidScreenGraphics scr_gra;//���U�C�N�����p

	DiploidBoxV2 box;//�t�F�[�h�C���A�A�E�g�pBOX

	DiploidImageV2 test_back;//�e�X�g�w�i


	//�e��{�^���̕�����
	DiploidStrings start_string;
	DiploidStrings exit_string;

	//�e��{�^���̉摜
	DiploidImageV2 button_back_image;

	//�e��{�^��
	DiploidSelectedUIV2 start_button;
	DiploidSelectedUIV2 exit_button;

	//���ߒl�Ƃ��̃X�s�[�h
	int alpha = 255, alpha_speed = 5;

	//���U�C�N�l�Ƃ��̃X�s�[�h�ƃ��U�C�N�ő�l
	float mosaic = 0.0f, mosaic_speed = 0.01f, mosaic_max = 0.4f;

public:

	void Load();

	void Init();

	void Updata();

	void Draw();

	bool GetFinalScene();

};