#pragma once
#include <list>
#include "math.h"
#include "DxLib.h"

#include "diploidInput/DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "diploidInput/DiploidEngineInput.h"

#include "data/res_data/anime/animation.h"

#include "data/res_data/player/player_attack.h"
#include "data/res_data/player/player_defense.h"

class Player
{
private:
	//Player�̃X�e�[�^�X
	float hit_point = 3.0f;//�̗�
	float defense_point = 3.0f;//�h��\��(�J�E���^�[)
	float attack_speed = 3.0f;//�U�����x
	float defense_speed = 3.0f;//�h�䑬�x
	float attack_range = 45.0f;//�U������
	float attack_size = 30.0f;//�U���̑傫��
	float defense_size = 70.0f;//�h��̑傫��
	float enemy_destory_volume = 0.0f;

	//Player�{��
	DiploidCircleV2 player;
	VECTOR player_pos;
	float player_size = 35.0f;//�v���C���[�̓����蔻��̑傫��

	//Player�̍U��
	std::list<PlayerAttack> attack_list;
	PlayerAttack attack;
	VECTOR attack_pos;//���ۂ̍U���ʒu
	float attack_rote;//�}�E�X��Player�Ԃ̊p�x
	bool is_attack = false;//�U�������ǂ���

	//Player�̖h��
	PlayerDefense defense;
	std::list<PlayerDefense> defense_list;
	bool is_defense = false;//�h�䒆���ǂ���

	//�U���A�j���[�V����
	DiploidImageV2 attack_image;
	Animation attack_anime;

	//�h��A�j���[�V����
	DiploidImageV2 defense_image;
	Animation defense_anime;

	//����
	DiploidEngineInput input_left;
	DiploidEngineInput input_right;

public:
	void LoadGraphics();

	void Init(VECTOR pos);
	void Updata();
	void Draw(bool debug = false, bool draw = true);

	void SetPlayerSize(float new_size);
	void isEnemyDestoryHelthRecovery(float destory_enemy_volume);//�G���|���ꂽ�Ƃ���1�������

	float GetPlayerSize();
	float GetPlayerDefensePoint();
	float GetEnemyDestoryVolume();

	DiploidCircleV2* PlayerCirclePtr();

	std::list<PlayerAttack>* GetAttackListPtr();//<list>attack_list�ւ�pointer���擾���܂��B
	std::list<PlayerDefense>* GetDefenseListPtr();//<list>defense_list�ւ�pointer���擾���܂��B

	std::list<PlayerAttack>::iterator GetAttackListIterator();//<list>attack_list�̃C�e���[�^���擾���܂��B
	std::list<PlayerDefense>::iterator GetDefenseListIterator();//<list>defense_list�̃C�e���[�^���擾���܂��B

};