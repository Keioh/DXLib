#pragma once
#include "button_ui.h"

class FactionInformation
{
private:
	ButtonUI faction_circle;

public:

	void Init();
	void Load();
	void Draw(int pos_x, int pos_y, bool wire);

	void CollisionOff();//�q�b�g�{�b�N�X���I�t�ɂ���B

};