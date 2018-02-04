#include "character_selection.h"

void CharacterSelection::init()
{
	for (int n = 0; n > 4; n++)
	{
		character[n].Init();
		collider_size[n] = { 0.0f,0.0f };
		collider_pos[n] = { 0.0f,0.0f };
	}

	character[0].color = GetColor(255, 255, 0);
	character[1].color = GetColor(0, 255, 0);
	character[2].color = GetColor(255, 0, 0);
	character[3].color = GetColor(0, 0, 255);

	character_number = 0;
}

void CharacterSelection::Load()
{
	for (int n = 0; n > 4; n++)
	{
		character[n].Load("");
	}
}

void CharacterSelection::CursorHit()
{

}

void CharacterSelection::CharacterName(int window_x, int window_y, Filer config)
{
	DrawFormatString(0, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_0);
	DrawFormatString(window_x / 4, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_1);
	DrawFormatString((window_x / 4) * 2, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_2);
	DrawFormatString((window_x / 4) * 3, 50, GetColor(0, 0, 0), "%s", config.character_name.charcter_name_3);
}

void CharacterSelection::CharacterDescription(int window_x, int window_y, Filer config)
{
	DrawFormatString(0, 50 + 100, GetColor(0, 0, 0), "%s", config.character_description.charcter_0);
	DrawFormatString(window_x / 4, 50 + 100, GetColor(0, 0, 0), "%s", config.character_description.charcter_1);
	DrawFormatString((window_x / 4) * 2, 50 + 100, GetColor(0, 0, 0), "%s", config.character_description.charcter_2);
	DrawFormatString((window_x / 4) * 3, 50 + 100, GetColor(0, 0, 0), "%s", config.character_description.charcter_3);

}

void CharacterSelection::Draw(int window_x, int window_y, Filer config, bool wire)
{
	CharacterSelection::CursorHit();

	if (character[0].BoxUI_Button_BOX(0, 0, window_x / 4, window_y, 1, wire) == true)
	{
		character_number = 1;
	}

	if (character[1].BoxUI_Button_BOX(window_x / 4, 0, window_x / 4, window_y, 1, wire) == true)
	{
		character_number = 2;
	}

	if (character[2].BoxUI_Button_BOX((window_x / 4) * 2, 0, window_x / 4, window_y, 1, wire) == true)
	{
		character_number = 3;
	}

	if (character[3].BoxUI_Button_BOX((window_x / 4) * 3, 0, window_x / 4, window_y, 1, wire) == true)
	{
		character_number = 4;
	}

	CharacterSelection::CharacterName(window_x, window_y, config);
	CharacterSelection::CharacterDescription(window_x, window_y, config);

	DrawFormatString(0, 0, GetColor(0, 0, 0), "character number = %d", character_number);
}