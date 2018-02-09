#include "faction_information.h"

void FactionInformation::Init()
{
	faction_circle.Init();
}

void FactionInformation::Load()
{
	faction_circle.Load("pack/GameObject/faction/blue_faction.png");
}

void FactionInformation::Draw(int pos_x, int pos_y, bool wire)
{
	SetDrawBright(255, 255, 255);//���̏��������Ȃ��Ɖ摜�\�����o�O��܂��B(��ʋP�x���ő�ɐݒ�)

	faction_circle.CircleUI_Button(pos_x, pos_y, 115, 1, wire);
}

void FactionInformation::CollisionOff()
{
	faction_circle.circle_collision.active = false;
}