#pragma once
#include "DxLib.h"

class EnemyData
{
private:

public:
	VECTOR pos;//�ʒu
	float size;//�傫��
	float move_speed;//�ړ����x
	float attack_speed;//�U�����x
	int hit_point;//�̗�
	float attack_size;//�U���͈̔�
	float attack_renge;//�U���̋���
	float counter_time;//�J�E���^�[��t�\�Ȏ���
	float knock_back_scale;//�m�b�N�o�b�N�{��
	int enemy_type;//�G�̎��(�摜���ς��)
	int direction;//�����Ă������(0�ŉE�A1�ō�)
	bool is_ground;//�n�ʂɒ����Ă��邩
	float scale;
};