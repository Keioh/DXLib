/*---------------------------------------------------------*/
/*--------------�T���e�X�g�}�b�v�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidSystem/diploidSystem.h"

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
	void _MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input);
	void _MapDraw(bool draw = true);

	//�v���[���[�֘A	
	PlayerDirection player_direction;//�v���[���[�\��
	float player_size;//�v���[���[�̑傫��(map_chip_size��0.2�{)

	float movement_speed = 3.0f;//�v���[���[�̈ړ����x
	float movement_run_scale = 1.8f;//����ۂ̈ړ��{��
	float rinjury_lv1_scale = 0.8f;//����𕉂����ۂ�LV1�{��
	float rinjury_lv2_scale = 0.6f;//����𕉂����ۂ�LV2�{��
	float rinjury_lv3_scale = 0.5f;//����𕉂����ۂ�LV3�{��
	float rinjury_lv4_scale = 0.3f;//����𕉂����ۂ�LV4�{��
	float rinjury_lv5_scale = 0.1f;//����𕉂����ۂ�LV5�{��

	int movement_type = PLAYER_WALK;//�v���[���[�̈ړ����

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};