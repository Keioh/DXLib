#pragma once
#include "DxLib.h"
#include "diploidInput\DiploidEngineInput.h"
#include "system\DiploidEngineSetting.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidAnimation.h"
#include "system/DiploidEngineMath.h"
#include "system/define.h"
#include "ver2.0/Objects/DiploidSliderObject.h"
#include "ver2.0/Objects/DiploidSlider.h"
#include "diploidScreen\DiploidEngineScreen.h"

#include "ver2.0/Objects/button/Back.h"
#include "ver2.0/Objects/button/Save.h"
#include "ver2.0/Objects/button/Reset.h"
#include "ver2.0/Objects/button/Title.h"
#include "ver2.0/Objects/button/WindowSize.h"

#include "ver2.0/Objects/string_image/option/option_string_image.h"
#include "ver2.0/Objects/string_image/option/display_string_image.h"
#include "ver2.0/Objects/string_image/option/game_play_string_image.h"

#include "ver2.0/Graphics/DiploidTriangle.h"
#include "ver2.0/Objects/ContinuousTriangle.h"

#include "ver2.0/Graphics/DiploidStrings.h"

#include "ver2.0/Objects/ui/text_speed_auto_setting_ui.h"

#include "data/system_data/system_data.h"


class OptionScene
{
private:

	DiploidEngineMath math;//���w�֐�
	DiploidEngineFile file;

	ContinuousTriangle continuous_triangle;//�A�������O�p�`

	DiploidBoxV2 box;//�t�F�[�h�pBOX

	Back back_button;//�߂�{�^��
	Save save_button;//�ۑ��{�^��
	Reset reset_button;//���Z�b�g�{�^��
	Title title_button;//�^�C�g���{�^��

	WindowSize window_resize_button_960_540;//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	WindowSize window_resize_button_1280_720;//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	WindowSize window_resize_button_1600_900;//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	WindowSize window_resize_button_1920_1080;//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)

	TextSpeedAutoSettingUI text_speed_auto_setting_ui;

	//Option�̉摜
	OptionStringImage option_string_image;
	DisplayStringImage display_string_image;
	GamePlayStringImage game_play_string_image;

	//�E�B���h�E�T�C�Y�ύX�{�^���Q�̈ʒu
	int window_resize_button_position_x = 100;
	int window_resize_button_position_y = 100;

	//�����\�����x�A�I�[�g���x�ύX�{�^���Q�̈ʒu
	int string_speed_button_position_x = 300;
	int string_speed_button_position_y = 100;

	//�ݒ肵���f�[�^���ꎞ�ۑ�����p
	SystemData system_data;

	//�l�̕ۑ��p
	float draw_speed = 80.0f;//�ݒ肵�����݂̕����`�摬�x
	float auto_speed = 50.0f;//�ݒ肵�����݂̃I�[�g���x
	float background_alpha = 100.0f;//�ݒ肵�����݂̕����w�i�̓��ߓx

	//���ߏ����̕ϐ�
	int alpha = 255;
	int alpha_speed = 500;//���ߑ��x

	int box_draw_flag = 0;//0�Ńt�F�[�h�A�E�g�A1�Ńt�F�[�h�A�E�g�����A2�Ńt�F�[�h�C���A3�Ńt�F�[�h�C������

	bool in_game_flag_buffer;

public:

	void Load();
	void Init(DiploidEngineSetting& setting);
	void Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag);
	void Draw(DiploidEngineScreen& screen, bool draw = true, bool debug = false);

	int GetReturnFlag();//�߂�{�^���������ꂽ��true���Ԃ�B

	SystemData GetSystemData();//�ꎞ�ۑ�����Ă��錻�݂̐ݒ���Ăяo���B
};