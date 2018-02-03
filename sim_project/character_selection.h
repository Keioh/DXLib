#pragma once
#include "Object_Base.h"
#include "FileInput.h"

#include "button_ui.h"

class CharacterSelection : public ObjectBase
{
private:
	ButtonUI character[4];

public:

	void init();
	void Load();
	void Draw(int window_x, int window_y, Filer config, bool wire);
};