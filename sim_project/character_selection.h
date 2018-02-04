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
	int character_number;//�I�񂾃L�����N�^�[�̔ԍ�(0����l��(��)�A3��4�l��(�E))0�͑I�����Ă��Ȃ���ԁB

	void init();
	void Load();
	void Draw(int window_x, int window_y, Filer config, bool wire);
};