#include "study.h"

void Study::Init()
{
	study_button.Init();
}

void Study::Load()
{
	study_button.Load("pack/GameObject/GameUI/study/study_button.png");
}

void Study::Draw(int pos_x, int pos_y, bool wire)
{
	study_button.BoxUI_Button(pos_x, pos_y, 1, wire);
}