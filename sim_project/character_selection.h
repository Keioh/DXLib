#pragma once
#include "Object_Base.h"
#include "FileInput.h"

#include "button_ui.h"

class CharacterSelection : public ObjectBase
{
private:
	ButtonUI character[4];

	Vector2F collider_size[4];
	Vector2F collider_pos[4];

	void CursorHit();

	void CharacterName(int window_x, int window_y, Filer config);
	void CharacterDescription(int window_x, int window_y, Filer config);

public:
	int character_number;//選んだキャラクターの番号(0が一人目(左)、3が4人目(右))0は選択していない状態。

	void init();
	void Load();
	void Draw(int window_x, int window_y, Filer config, bool wire);
};