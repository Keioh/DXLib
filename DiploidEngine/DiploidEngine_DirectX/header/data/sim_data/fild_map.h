#pragma once
#include "DxLib.h"
#include "data/sim_data/fild.h"

class FildMap
{
private:
	float scale = 0.05f;//�}�b�v�`�b�v�̏����̑傫��

	float mouse_scrole;//�}�E�X�X�N���[���ʂ̕ۑ�
	int mouse_x, mouse_y;

	float camera_x, camera_y, camera_speed = 30.0f;//�J�����̈ʒu�ƈړ��X�s�[�h
	VECTOR map_shift;//���������ɂǂꂭ�炢�}�b�v�����炵�ĕ\�����邩

	int click_flag = -1;

	//�摜
	DiploidImageV2 	grass_terrain, rock_terrain, mountain_terrain, my_building;

	Fild fild[MAP_SIZE_Y][MAP_SIZE_X];//�}�b�v�̑傫��������fild�`�b�v���m��

	void CameraInput(DiploidEngineInput* input);//�J�����̐ݒ�(�J�����̈ړ����x�Ƃ�)

public:
	void LoadHandl();
	void LoadGraphics();
	void Load();

	void Init(VECTOR position = { 0.0f,0.0f,0.0f }, float map_size_scale = 0.05f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);

	void SetCollisionActiveFlag(bool flag);//�w�肵���ꏊ�̃}�b�v�̓����蔻��A�N�e�B�u�t���O��ݒ肵�܂��B

	int GetClick();//���݃}�b�v�̂ǂꂩ���N���b�N����Ă��邩�B

	Fild GetClickedFildInfomation();//�N���b�N����Ă���ꏊ�̃f�[�^���擾�B
	Fild GetHitFildInfomation();//�q�b�g���Ă���ꏊ�̃f�[�^���擾�B

};