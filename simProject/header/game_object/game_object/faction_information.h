#pragma once
#include "Collision.h"
#include "button_ui.h"
#include "Input.h"
#include "FileInput.h"
#include "game_window.h"

class FactionInformation
{
private:
	Input Key;

	int infomation_tab_active_flag = -1;

	void DrawFactionStrings(int pos_x, int pos_y, Filer config);

public:
	Collision branch_point_collision;//�x���_�̐���
	Collision laboratory_collision;//�������̐���
	Collision money_collision;//�����̐���
	Collision research_collision;//�������̐���
	Collision study_collision;//�׋����̐���
	Collision characteristic_collision;//�����̐���
	Collision block_collision;//�����~�̐���

	ButtonUI faction_box;

	InGameWindow faction_tab;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);
	void Instructions(int pos_x, int pos_y, Filer config, bool wire);

	void FactionInfomationTabOff();//�^�u���I�t�ɂ���B
	void CollisionOff();//�q�b�g�{�b�N�X���I�t�ɂ���B
	void CollisionOn();//�q�b�g�{�b�N�X���I���ɂ���B

};