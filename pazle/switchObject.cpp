#include "switchObject.h"

void SwitchObject::init()
{
	object_switch_flag = 0;
	switch_object.Init();
}

void SwitchObject::Load()
{
	switch_object.Load("pack/GameObject/on.png", "pack/GameObject/off.png");
}

void SwitchObject::Draw(int pos_x, int pos_y, bool wire)
{
	object_switch_flag = switch_object.CircleUI_Button_Switch(pos_x, pos_y, 25, 1, wire);
}
