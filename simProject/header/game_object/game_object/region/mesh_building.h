#pragma once
#include "button_ui.h"
#include "building.h"
#include "game_window.h"
#include "struct_set.h"

class MeshBuilding
{
private:
	InGameWindow window;
	int window_flag = -1;//�E�B���h�E��\�����邩���Ȃ����̃t���O

public:
	ButtonUI market_place_button;
	Building building0, building1, building2;//0=�X�n�I�u�W�F�N�g�A1=���Տ��I�u�W�F�N�g�A2=�������I�u�W�F�N�g

	int affiliation_faction = 0;//�������Ă���t�@�N�V����(0�Ŗ�����)
	int building_type = 0;//�����̎��(0=�X�n�A1=���Տ��A2=������)

	void Init();
	void Load();
	void Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos);
	void Updata();
	void Draw(MODE mode, bool wire = false);
	void DrawUI(int window_x, int window_y, MODE mode, bool wire = false);
	void ColliderOff();
	void ColliderOn();
};