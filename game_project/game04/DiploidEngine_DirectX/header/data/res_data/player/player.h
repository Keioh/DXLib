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
	float attack_speed = 8.0f;//�U�����x
	float defense_speed = 3.0f;//�h�䑬�x
	float attack_range = 45.0f;//�U������
	float attack_size = 30.0f;//�U���̑傫��
	float defense_size = 70.0f;//�h��̑傫��
	int enemy_destory_volume = 0.0f;//�G���j��
	float hp_recovery_probability = 0.0f;//�G�����j�����ۂ�HP���񕜂���m���B
	float cp_recovery_probability = 0.0f;//�ݒ肵���G���j���ɒB��������CP���񕜂���B


	//Player�{��
	DiploidCircleV2 player;
	VECTOR player_pos;
	float player_size = 35.0f;//�v���C���[�̓����蔻��̑傫��
	float hp_probability_buffer = 0.0f;//�m����ۑ�
	float cp_probability_buffer = 0.0f;//�m����ۑ�
	bool enemy_destory_flag_bffer;//enemy_manager����̃f�X�g���C�t���O�̕ۑ��p

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

	void HpRecoveryProbabilityUpdate();
	void CpRecoveryProbabilityUpdate();

	void SetPlayerSize(float new_size);
	void isEnemyDestoryVolume(float destory_enemy_volume);//�G���|���ꂽ�Ƃ���1�������
	void isGetEnemyDestroyFlag(bool destory_enemy_flag);

	float GetPlayerSize();
	float GetPlayerDefensePoint();
	float GetEnemyDestoryVolume();
	float GetHpRecoveryProbability();
	float GetCpRecoveryProbability();

	void SetAttackSpeed(float new_vol);
	void AddAttackSpeed(float add_vol);//AS�ɑ���
	void AddHpRecoveryProbability(float add_vol);//HP�񕜊m���ɑ���
	void AddCpRecoveryProbability(float add_vol);//CP�񕜊m���ɑ���

	DiploidCircleV2* PlayerCirclePtr();

	std::list<PlayerAttack>* GetAttackListPtr();//<list>attack_list�ւ�pointer���擾���܂��B
	std::list<PlayerDefense>* GetDefenseListPtr();//<list>defense_list�ւ�pointer���擾���܂��B

	std::list<PlayerAttack>::iterator GetAttackListIterator();//<list>attack_list�̃C�e���[�^���擾���܂��B
	std::list<PlayerDefense>::iterator GetDefenseListIterator();//<list>defense_list�̃C�e���[�^���擾���܂��B

};