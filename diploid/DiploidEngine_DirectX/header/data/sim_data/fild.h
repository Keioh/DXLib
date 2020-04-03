#pragma once
#include "DxLib.h"

#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Main/Collision.h"
#include "diploidInput/DiploidEngineInput.h"

class Fild
{
private:

	int mouse_x, mouse_y;//�}�E�X�ʒu
	bool is_hit_mouse;//box�Ɠ������Ă��邩�̃t���O
	bool is_click_mouse;//box�Ɠ������Ă���Ƃ��ɃN���b�N���Ă��邩�̃t���O

	float on_hit_color_scale = 0.9f;//box�ƃ}�E�X���������Ă��Ȃ��Ƃ��̐F�̈Â�(1.0f��100%)

	int isBuilding = 0;//���_�����邩�Ȃ����̃t���O(0�łȂ��A1�Ŏ����_�A2�œG���_�A3�ŗF�D���_)
	int isTerrain = 0;//�n�`�̎��(0�ő����A1�ōr�n)
	int isFild = 0;//�x�z�̈�̎��(0�Ŗ������A1�Ŏ��́A2�œG�́A3�ŗF�D��)

	DiploidBoxV2 box;
	DiploidImageV2 grass_terrain, rock_terrain;
	DiploidImageV2 my_building;
	DiploidCollision collision;

public:
	void Load();
	void Init(VECTOR pos, float scale = 1.0f);
	void Updata(DiploidEngineInput* input);
	void Draw(bool draw = true);

	void SetBuildingType(int new_building_type);//�V�������_�̃^�C�v��ݒ肵�܂��B(0�łȂ��A1�Ŏ����_�A2�œG���_�A3�ŗF�D���_)
	void SetTerrainType(int new_terring_type);//�V�����n�`�̃^�C�v��ݒ肵�܂��B(0�ő����A1�ōr�n)

	int GetBuildingType();//���݂̋��_�̃^�C�v���擾���܂��B
	int GetTerrainType();//���݂̒n�`�̃^�C�v���擾���܂��B

	int GetSizeX();
	int GetSizeY();

};