#include "character_selection.h"

void CharacterSelection::init()
{
	for (int n = 0; n > 4; n++)
	{
		character[n].Init();
	}

	character[0].color = GetColor(255, 255, 0);
	character[1].color = GetColor(0, 255, 0);
	character[2].color = GetColor(255, 0, 0);
	character[3].color = GetColor(0, 0, 255);

}

void CharacterSelection::Load()
{
	for (int n = 0; n > 4; n++)
	{
		character[n].Load("");
	}
}

void CharacterSelection::Draw(int window_x, int window_y, Filer config, bool wire)
{
	character[0].BoxUI_Button_BOX(0, 0, window_x / 4, window_y, 1, wire);
	character[1].BoxUI_Button_BOX(window_x / 4, 0, window_x / 4, window_y, 1, wire);
	character[2].BoxUI_Button_BOX((window_x / 4) * 2, 0, window_x / 4, window_y, 1, wire);
	character[3].BoxUI_Button_BOX((window_x / 4) * 3, 0, window_x / 4, window_y, 1, wire);

	DrawFormatString(0, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_0);
	DrawFormatString(window_x / 4, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_1);
	DrawFormatString((window_x / 4) * 2, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_2);
	DrawFormatString((window_x / 4) * 3, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_3);

}