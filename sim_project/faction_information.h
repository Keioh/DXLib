#pragma once
#include "button_ui.h"
#include "Input.h"
#include "FileInput.h"

class FactionInformation
{
private:
	Input Key;

	int infomation_tab_active_flag = -1;

	void DrawFactionStrings(Filer config);

public:
	ButtonUI faction_box;
	ButtonUI infomation_tab_close;

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, Filer config, bool wire);

	void FactionInfomationTabOff();//�^�u���I�t�ɂ���B
	void CollisionOff();//�q�b�g�{�b�N�X���I�t�ɂ���B
	void CollisionOn();//�q�b�g�{�b�N�X���I���ɂ���B

};