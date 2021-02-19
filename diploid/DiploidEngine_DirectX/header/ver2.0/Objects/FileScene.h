#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"

#include "ver2.0/Objects/button/Back.h"

class FileScene
{
private:
	DiploidEngineInput input;//���͊֘A
	DiploidEngineSetting setting;//WindowSize�擾�p

	DiploidScreenGraphics scr_gra;//���U�C�N�����p

	DiploidBoxV2 box;//�t�F�[�h�C���A�A�E�g�pBOX

	DiploidImageV2 test_back;//�e�X�g�w�i


	Back back_button;


	//���ߒl�Ƃ��̃X�s�[�h
	int alpha = 255, alpha_speed = 10;
	int box_draw_flag = 0;

	//���U�C�N�l�Ƃ��̃X�s�[�h�ƃ��U�C�N�ő�l
	float mosaic = 0.0f, mosaic_speed = 0.01f, mosaic_max = 0.4f;

	int secen_select = GAME_TITLE;//�ǂ̃{�^�������������̂�
	int button_click = 0;//�e�{�^���̂ǂꂩ����������1���Ԃ�B

public:

	void Load();

	void Init();

	void Updata();

	void Draw();

	int GetReturnButton();//�Ō�ɉ������{�^�����ǂꂩ���擾����B(�l��define.h���Q��)
	void SetSecne(int scene_type);//define�t�@�C���ɋL�ڂ���Ă���}�N���ɂ��������ăV�[����ύX���܂��B(GAME_TITLE�Ń^�C�g�����)
};