/*---------------------------------------------------------*/
/*--------------�T���e�X�g�}�b�v�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidSystem/diploidSystem.h"
#include "diploidUI/diploidUI.h"

#include "data/game_data/UI/command_ui.h"
#include "data/game_data/UI/status_bar.h"
#include "data/game_data/UI/clock.h"

#include "data/game_data/CHARACTER/player_direction.h"


class Explore_TestMap
{
private:
	//�}�b�v�֘A
	DiploidObject test_map;//�}�b�v�쐻�p
	DiploidObject test_map_texter;//�}�b�v�e�N�X�`���p
	VECTOR map_position;//�}�b�v�̈ʒu
	VECTOR map_center_position_sub;//�}�b�v�̃Y����
	VECTOR map_size;//�}�b�v�̑傫��
	float map_chip_size;//�}�b�v�`�b�v�̑傫��
	float map_image_x, map_image_y;//�}�b�v�摜�̑傫��
	int map_number;//name_tag�̔ԍ�

	void _MapLoad();
	void _MapInit(VECTOR position);
	void _MapPush(DiploidEngineImpact* impact);
	void _MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input, CommandUI* command_ui, StatusBar* status_bar, Clock* clock);
	void _MapDraw(bool draw = true);

	//�v���[���[�֘A	
	DiploidObject player_visibility;//���E�摜
	PlayerDirection player_direction;//�v���[���[�\��
	float player_size;//�v���[���[�̑傫��(map_chip_size��0.2�{)

	float movement_speed = 3.0f;//�v���[���[�̈ړ����x
	float movement_run_scale = 1.8f;//����ۂ̈ړ��{��

	int movement_type = PLAYER_WAIT;//�v���[���[�̈ړ����


	//�G�֘A
	DiploidObject enemy_test;//�G�̓����蔻��

	VECTOR enemy_position;
	bool enemy_dead = false;
	bool enemy_hit = false;

	//�퓬���
	DiploidSystem system;//�����V���b�g�ǂݍ��ݗp

	DiploidObject combat_back_texter;//�퓬��ʂ̔w�i
	DiploidObject mouse_point;//�퓬��ʗp�̃}�E�X�|�C���g

	DiploidUI battle_command;//�퓬�R�}���h

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};


	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input, CommandUI& command_ui, StatusBar& status_bar, Clock& clock);
	void Draw(bool draw = true);

	bool GetEnemyHitFlag();

};