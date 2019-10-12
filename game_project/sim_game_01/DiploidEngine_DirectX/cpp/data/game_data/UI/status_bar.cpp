#include "data/game_data/UI/status_bar.h"

void StatusBar::Load()
{
	status_bar.image.Load("texter/game/status_bar/status_bar.png");

}

void StatusBar::Init(VECTOR position)
{
	status_bar.image.Init(VGet(position.x + (640 / 2), position.y + (128 / 2), 0));

	health_position = VGet(position.x + 200 , position.y + 16, 0);
	mana_position = VGet(position.x + 200, position.y + 44, 0);
	stamina_position = VGet(position.x + 200, position.y + 72, 0);

}

void StatusBar::Push(DiploidEngineImpact& impact)
{

}

void StatusBar::Updata(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	status_bar.image.Updata();
}

void StatusBar::Draw(bool draw)
{
	status_bar.image.Draw();
}


void StatusBar::StatusUpdate(InformationCommand& info_command)
{
	info_command.StatusUpdate();
}

void StatusBar::StatusDraw(InformationCommand& info_command)
{
	DrawFormatString(health_position.x, health_position.y, GetColor(255, 255, 255), "%d / %d", info_command.GetHealthPoint(), info_command.GetMaxHealthPoint());
	DrawFormatString(mana_position.x, mana_position.y, GetColor(255, 255, 255), "%d / %d", info_command.GetMagicPoint(), info_command.GetMaxMagicPoint());
	DrawFormatString(stamina_position.x, stamina_position.y, GetColor(255, 255, 255), "%d / %d", info_command.GetStaminaPoint(), info_command.GetMaxStaminaPoint());

}



int StatusBar::SubHP(int val, InformationCommand& info_command)
{
	hp_buffer = info_command.GetHealthPoint() - val;

	info_command.SetHealthPoint(hp_buffer);

	return hp_buffer;
}

int StatusBar::AddHP(int val, InformationCommand& info_command)
{
	hp_buffer = info_command.GetHealthPoint() + val;

	info_command.SetHealthPoint(hp_buffer);

	return hp_buffer;
}


int StatusBar::SubMP(int val, InformationCommand& info_command)
{
	mp_buffer = info_command.GetMagicPoint() - val;

	info_command.SetMagicPoint(mp_buffer);

	return mp_buffer;
}

int StatusBar::AddMP(int val, InformationCommand& info_command)
{
	mp_buffer = info_command.GetMagicPoint() + val;

	info_command.SetMagicPoint(mp_buffer);

	return mp_buffer;

}


int StatusBar::SubSP(int val, InformationCommand& info_command)
{
	sp_buffer = info_command.GetStaminaPoint() - val;

	info_command.SetStaminaPoint(sp_buffer);

	return sp_buffer;
}

int StatusBar::AddSP(int val, InformationCommand& info_command)
{
	sp_buffer = info_command.GetStaminaPoint() + val;

	info_command.SetStaminaPoint(sp_buffer);

	return sp_buffer;
}