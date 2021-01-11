#pragma once
#include "DxLib.h"
//#include "diploidApp\DiploidEngineApp.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidAnimation.h"

#include "data/text_data/ja.h"

class GameScene
{
private:
	ja_text jp;//�e�L�X�g�f�[�^

	DiploidBoxV2 box;//�t�F�[�h�pBOX

	DiploidAnimation anime;//anime

	DiploidImageV2 image_00;//�w�i�摜(��)

	int click = 0;//���݂̃e�L�X�g�ʒu

	//���ߏ����̕ϐ�
	int alpha = 255;
	int alpha_speed = 4;//���ߑ��x

	int box_draw_flag = 0;//0�Ńt�F�[�h�A�E�g�A1�Ńt�F�[�h�A�E�g�����A2�Ńt�F�[�h�C���A3�Ńt�F�[�h�C������

public:
	void Load();

	void Init(DiploidEngineSetting& setting);

	void Updata(DiploidEngineInput& input);

	void Draw();

};