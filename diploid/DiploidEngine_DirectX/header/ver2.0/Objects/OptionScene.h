#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"

class OptionScene
{
private:

	DiploidBoxV2 box;//�t�F�[�h�pBOX

	Back back_button;//�߂�{�^��
	Save save_button;//�ۑ��{�^��


	//���ߏ����̕ϐ�
	int alpha = 255;
	int alpha_speed = 8;//���ߑ��x

	int box_draw_flag = 0;//0�Ńt�F�[�h�A�E�g�A1�Ńt�F�[�h�A�E�g�����A2�Ńt�F�[�h�C���A3�Ńt�F�[�h�C������

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);

	bool GetReturnFlag();//�߂�{�^���������ꂽ��true���Ԃ�B
};