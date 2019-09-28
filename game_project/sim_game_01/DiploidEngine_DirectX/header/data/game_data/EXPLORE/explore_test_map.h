/*---------------------------------------------------------*/
/*--------------�T���e�X�g�}�b�v�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "diploid3D/diploidPanel.h"

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
	float movement_speed = 5.0f;//�v���[���[�̈ړ����x


public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};