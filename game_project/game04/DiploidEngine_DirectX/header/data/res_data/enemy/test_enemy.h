#pragma once
#include <list>
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "data/res_data/enemy/enemy_data.h"
#include "data/res_data/enemy/move_pattern.h"
#include "data/res_data/enemy/enemy_attack.h"
#include "diploidPhysics/diploidPhysics.h"
#include "data/res_data/anime/animation.h"
#include "data/res_data/anime/animation.h"

class _TestEnemy
{
private:
	DiploidImageV2 counter_icon_image;

	DiploidCircleV2 circle;

	//�A�j��	
	int anime_frame_volume = 4;//�A�j���[�V�����Ɏg���摜�̖���
	int anime_time = 0;//�R�}����̑ҋ@����
	int play_time = 4;//�A�j���[�V�����Đ����x
	int anime_count = 0;//���݂̃R�}	
	DiploidImageV2 move_image[5];//�A�j���p�摜�̓ǂݍ���


	std::list<EnemyAttack> attack_list;
	EnemyAttack attack;

	EnemyData data;
	EnemyData data_buffer;

	MovePattern move_pattern;
	MoveData move_data;

	float counter_time_buffer;
	bool counter_flag = false;

	bool destory_flag = false;


public:
	void SetEnemyData(EnemyData new_data);
	void LoadGraphics();
	void LoadHandles(int handle);
	void Init();
	void PushBackMoveDate(MoveData date);//Init()�̌�ɌĂяo������
	void Updata();
	void Draw(bool draw = true);

	void isSetDestoryFlag(bool new_flag);
	void SetMoveSpeed(float new_speed);
	bool GetCounterFlag();

	EnemyData* GetDataPtr();
	DiploidCircleV2* GetCirclePtr();
	std::list<EnemyAttack>* GetAttackListPtr();

};