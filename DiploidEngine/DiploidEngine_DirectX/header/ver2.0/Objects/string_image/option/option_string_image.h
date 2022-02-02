#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class OptionStringImage
{
private:
	//Option�̉摜
	VECTOR position = VGet(0, 0, 0);
	DiploidImageV2 option_string_images[7];

	int position_animation_x[7];//�A�j���[�V���������邘���W
	int option_string_alpha[7];//�e�摜�̃A���t�@�l

	int anime_pos_init = -25;

	int alpha_speed = 5;//���ߑ��x
	int animation_speed = 1;//�A�j���[�V�����̑���

public:
	void Load();
	void Init(VECTOR pos);
	void Updata();
	void Draw(bool draw = true, bool debug = false);

	void Reset();//�A�j���[�V���������Z�b�g���܂��B
};