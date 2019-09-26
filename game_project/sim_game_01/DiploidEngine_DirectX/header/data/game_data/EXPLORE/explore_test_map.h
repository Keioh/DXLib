/*---------------------------------------------------------*/
/*--------------�T���p�[�g�̂��ׂĂ�������-------------*/
/*---------------------------------------------------------*/

#pragma once
#include "diploidObject/DiploidEngineObject.h"
#include "diploidImpact/DiploidEngineImpact.h"
#include "diploidInput/DiploidEngineInput.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "diploid3D/diploidPanel.h"

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

	//�v���[���[�֘A
	DiploidObject player_up;//�v���[���[�̏�
	DiploidObject player_down;//�v���[���[�̉�
	DiploidObject player_left;//�v���[���[�̍�
	DiploidObject player_right;//�v���[���[�̉E
	float player_size;
	float movement_speed = 5.0f;

public:
	Explore_TestMap() {};
	~Explore_TestMap() {};

	void Load();
	void Init(VECTOR position = { 0.0f,0.0f,0.0f });
	void Push(DiploidEngineImpact& impact);
	void Updata(DiploidEngineImpact& impact, DiploidEngineInput& input);
	void Draw(bool draw = true);

};