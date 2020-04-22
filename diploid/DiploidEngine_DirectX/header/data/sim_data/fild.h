#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"
#include "data/sim_data/sim_define.h"

class Fild
{
private:

	int window_size_x = 1280, window_size_y = 720;
	int mouse_x, mouse_y;//�}�E�X�ʒu
	bool is_hit_mouse;//box�Ɠ������Ă��邩�̃t���O
	int is_click_mouse = -1;//box�Ɠ������Ă���Ƃ��ɃN���b�N���Ă��邩�̃t���O

	bool collision_active_flag = true;//�����蔻����s�����ǂ����̃t���O(treu�ōs��)

	float on_hit_color_scale = 0.8f;//box�ƃ}�E�X���������Ă��Ȃ��Ƃ��̐F�̈Â�(1.0f��100%)

	int box_size_x, box_size_y;//�����蔻��p��BOX�̑傫��(��)
	int bright_red, bright_green, bright_blue;//�摜�̋P�x�̐��l


	int isBuilding = 0;//���_�����邩�Ȃ����̃t���O(0�łȂ��A1�Ŏ����_�A2�œG���_�A3�ŗF�D���_)
	int isTerrain = 0;//�n�`�̎��(0�ő����A1�ōr�n�A2�ŎR�x)
	int isFild = 0;//�x�z�̈�̎��(0�Ŗ������A1�Ŏ��́A2�œG�́A3�ŗF�D��)

	DiploidBoxV2 box;
	DiploidImageV2 grass_terrain, rock_terrain, mountain_terrain;
	DiploidImageV2 my_building;
	DiploidCollision collision;

public:
	void LoadGrassTerrain(int grass_terrain_handl);//�����摜�n���h���ǂݍ���
	void LoadRockTerrain(int rock_terrain_handl);//�r�n�摜�n���h���ǂݍ���
	void LoadMountainTerrain(int mountain_terrain_handl);//�R�x�摜�n���h���ǂݍ���
	void LoadMyBuilding(int my_building_handl);//�����_�摜�n���h���ǂݍ���


	void Load(int grass_terrain_handl, int rock_terrain_handl, int mountain_terrain_handl, int my_building_handl);//��̉摜����ǂݍ���
	void Load();//�I�u�W�F�N�g�ʂɉ摜��ǂݍ���
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true, bool debug = false);


	void SetMainCameraFlag(bool flag);//���C���J������ݒ肵�܂��B
	void SetWindowSize(int x, int y);//�`�悷���ʂ̑傫����ݒ肵�܂��B(��ʊO�̃I�u�W�F�N�g�͕`�悳��܂���)
	void SetClick(int flag);

	void SetBuildingType(int new_building_type);//�V�������_�̃^�C�v��ݒ肵�܂��B(0�łȂ��A1�Ŏ����_�A2�œG���_�A3�ŗF�D���_)
	void SetTerrainType(int new_terring_type);//�V�����n�`�̃^�C�v��ݒ肵�܂��B(0�ő����A1�ōr�n)
	void SetFildType(int new_fild_type);//�V�����x�z�̈�̃^�C�v��ݒ肵�܂��B(0�Ŗ������A1�Ŏ��́A2�œG�́A3�ŗF�D��)

	void SetCollisionActiveFlag(bool new_flag);//�}�E�X�Ƃ̓����蔻������邩�̃t���O��ύX���܂��B(true�œ����蔻����s��)

	int GetBuildingType();//���݂̋��_�̃^�C�v���擾���܂��B
	int GetTerrainType();//���݂̒n�`�̃^�C�v���擾���܂��B
	int GetFildType();//���݂̎x�z�̈�̃^�C�v���擾���܂��B

	VECTOR GetPosition();//�����蔻��Ŏg���Ă���BOX�̍���̍��W���擾���܂��B

	int GetClick();//���̒n�`���N���b�N�������ǂ����̃t���O���擾���܂��B(true�ŃN���b�N����)
	bool GetHit();
	bool GetCollisionActiveFlag();//���݂̓����蔻�肪�L�����ǂ����̃t���O���擾���܂��B(true�œ����蔻�肪�L��)

	int GetSizeX();//�����蔻��Ɏg���Ă���BOX��X�����̑傫�����擾���܂��B(�o�O)
	int GetSizeY();//�����蔻��Ɏg���Ă���BOX��Y�����̑傫�����擾���܂��B(�o�O)

	bool GetMainCameraFlag();
};