/*---------------------------------------------------------*/
/*--------------�v���[���[�̉摜������������---------------*/
/*------------PL�̈ړ������̓e�X�g�}�b�v�ɋL��-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"

class PlayerDirection
{
private:

	//�v���[���[�֘A
	DiploidObject player_up;//�v���[���[�̏�̓����蔻��
	DiploidObject player_down;//�v���[���[�̉��̓����蔻��
	DiploidObject player_left;//�v���[���[�̍��̓����蔻��
	DiploidObject player_right;//�v���[���[�̉E�̓����蔻��

	DiploidObject player_up_image;//�v���[���[�̏�̉摜
	DiploidObject player_down_image;//�v���[���[�̉��̉摜
	DiploidObject player_left_image;//�v���[���[�̍��̉摜
	DiploidObject player_right_image;//�v���[���[�̉E�̉摜

	DiploidObject player_left_up_image;//�v���[���[�̍���̉摜
	DiploidObject player_right_up_image;//�v���[���[�̉E��̉摜
	DiploidObject player_left_down_image;//�v���[���[�̍����̉摜
	DiploidObject player_right_down_image;//�v���[���[�̉E���̉摜

	int player_direction = PLAYER_DOWN;//�v���[���[�̌���
	float player_scale;//�v���[���[�̑傫���ۑ��p(player_size�̕ۑ��p)
	float player_size;//�v���[���[�̑傫��(map_chip_size��0.2�{)
	float movement_speed = 5.0f;//�v���[���[�̈ړ����x


public:

	void Load();
	void Init(float player_scale);
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

	int GetDirection();//���݌����Ă�������𓾂܂��B
};