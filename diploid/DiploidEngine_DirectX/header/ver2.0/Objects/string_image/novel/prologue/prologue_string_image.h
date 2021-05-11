#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "system\DiploidEngineSetting.h"

class PrologueStringImage
{
private:
	//Option�̉摜
	VECTOR position = VGet(0, 0, 0);
	DiploidImageV2 prologue_images;
	DiploidImageV2 zyo_images;
	DiploidImageV2 black_back_images;


	DiploidImageV2 string_images[13];

	bool fead_flag = false;//true�ɂȂ�ƃt�F�[�h�A�E�g�J�n
	int fead_count;
	int next_fead_time = 100;//�t�F�[�h�A�E�g���J�n����܂ł̎���

	int string_alpha[13];//�e�摜�̃A���t�@�l

	int anime_pos_init = -25;

	int alpha_speed = 5;//���ߑ��x
	int animation_speed = 1;//�A�j���[�V�����̑���

	bool finish = false;

public:
	void Load();
	void Init(DiploidEngineSetting& setting, VECTOR pos);
	void Updata();
	void Draw(bool draw = true, bool debug = false);

	void NextAnimation();//���̃A�j���[�V�������Đ����܂��B

	void Reset();//�A�j���[�V���������Z�b�g���܂��B

	bool GetFinish();//�Đ������t���O�𓾂܂�(treu�Ŋ���)
};