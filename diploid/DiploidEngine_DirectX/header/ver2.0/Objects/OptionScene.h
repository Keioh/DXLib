#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"
#include "ver2.0/Objects/button/WindowSize.h"

#include "ver2.0/Objects/string_image/option/option_string_image.h"
#include "ver2.0/Objects/string_image/option/display_string_image.h"

#include "ver2.0/Graphics/DiploidTriangle.h"


class OptionScene
{
private:

	std::vector<DiploidTriangle> triangle_vector;
	TRIANGLE triangle_data;
	DiploidTriangle triangle;
	unsigned int color;
	VECTOR pos;
	float anime, add;

	DiploidBoxV2 box;//�t�F�[�h�pBOX

	Back back_button;//�߂�{�^��
	Save save_button;//�ۑ��{�^��

	WindowSize window_resize_button_960_540;//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	WindowSize window_resize_button_1280_720;//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	WindowSize window_resize_button_1600_900;//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	WindowSize window_resize_button_1920_1080;//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)


	//Option�̉摜
	OptionStringImage option_string_image;
	DisplayStringImage display_string_image;

	VECTOR position = VGet(0,0,0);

	//�E�B���h�E�T�C�Y�ύX�{�^���Q�̈ʒu
	int window_resize_button_position_x = 100;
	int window_resize_button_position_y = 100;


	//���ߏ����̕ϐ�
	int alpha = 255;
	int alpha_speed = 8;//���ߑ��x

	int box_draw_flag = 0;//0�Ńt�F�[�h�A�E�g�A1�Ńt�F�[�h�A�E�g�����A2�Ńt�F�[�h�C���A3�Ńt�F�[�h�C������

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input, DiploidEngineSetting& setting);
	void Draw(bool draw = true, bool debug = false);

	bool GetReturnFlag();//�߂�{�^���������ꂽ��true���Ԃ�B
};