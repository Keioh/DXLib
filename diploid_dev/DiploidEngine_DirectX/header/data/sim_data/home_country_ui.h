#pragma once
#include "DxLib.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "data/sim_data/military_ui.h"


class CommandUI
{
private:

	int mouse_x, mouse_y;//�}�E�X�ʒu
	bool is_hit_mouse;//box�Ɠ������Ă��邩�̃t���O
	bool is_click_mouse;//box�Ɠ������Ă���Ƃ��ɃN���b�N���Ă��邩�̃t���O

	bool collision_active_flag = true;//�����蔻����s�����ǂ����̃t���O(treu�ōs��)

	float on_hit_color_scale = 0.8f;//box�ƃ}�E�X���������Ă��Ȃ��Ƃ��̐F�̈Â�(1.0f��100%)

	int bright_red = 255, bright_green = 255, bright_blue = 255;//�摜�̋P�x�̐��l


	MilitaryUI military_ui;

	DiploidImageV2 military_graphics;//�R���R�}���h�̉摜
	DiploidImageV2 production_graphics;//���Y�R�}���h�̉摜
	DiploidImageV2 construction_graphics;//���݃R�}���h�̉摜
	DiploidImageV2 politics_graphics;//�����R�}���h�̉摜


	DiploidSelectedUIV2 military;//�R���R�}���h
	DiploidSelectedUIV2 production;//���Y�R�}���h
	DiploidSelectedUIV2 construction;//���݃R�}���h
	DiploidSelectedUIV2 politics;//�����R�}���h

public:
	void Load();
	void Init(VECTOR pos, float scale = 0.2f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetCollisionActiveFlag(bool flag);
	void ResetFlag();

	bool GetCollisionActiveFlag();

	bool GetHit();
};