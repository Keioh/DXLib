#include "data/game_data/UI/information_command.h"

void InformationCommand::Load()
{
	back_image.image.Load("texter/game/command_button/information/information_back.png");
}

void InformationCommand::Init(VECTOR position)
{
	back_image.image.Init(VAdd(position, VGet(image_size_x / 2, image_size_y/ 2,0)));

	vitality_position = VAdd(position, VGet(150, 135, 0));
	stamina_position = VAdd(position, VGet(150, 135 + (50), 0));
	strength_position = VAdd(position, VGet(150, 135 + (50 * 2), 0));
	agility_position = VAdd(position, VGet(150, 135 + (50 * 3), 0));
	spirit_position = VAdd(position, VGet(150, 135 + (50 * 4), 0));
	willpower_position = VAdd(position, VGet(150, 135 + (50 * 5), 0));
	fortune_position = VAdd(position, VGet(150, 135 + (50 * 6), 0));
	madness_position = VAdd(position, VGet(150, 135 + (50 * 7), 0));

}

void InformationCommand::Update(bool ui_flag, int command_type, DiploidEngineImpact& impact)
{
	if (ui_flag == true)
	{
		if (command_type == INFORMATION_COMMAND)
		{
			back_image.image.Updata();
		}
	}
}

void InformationCommand::StatusUpdate()
{
	HealthPointCalculation();
}

void InformationCommand::Draw(bool ui_flag, int command_type, bool draw)
{
	if (ui_flag == true)
	{
		if (command_type == INFORMATION_COMMAND)
		{
			back_image.image.Draw(draw);

			DrawFormatString(vitality_position.x, vitality_position.y, GetColor(0, 0, 0), "%d", GetVitality());
			DrawFormatString(stamina_position.x, stamina_position.y, GetColor(0, 0, 0), "%d", GetStamina());
			DrawFormatString(strength_position.x, strength_position.y, GetColor(0, 0, 0), "%d", GetStrength());
			DrawFormatString(agility_position.x, agility_position.y, GetColor(0, 0, 0), "%d", GetAgility());
			DrawFormatString(spirit_position.x, spirit_position.y, GetColor(0, 0, 0), "%d", GetSpirit());
			DrawFormatString(willpower_position.x, willpower_position.y, GetColor(0, 0, 0), "%d", GetWillpower());
			DrawFormatString(fortune_position.x, fortune_position.y, GetColor(0, 0, 0), "%d", GetFortune());
			DrawFormatString(madness_position.x, madness_position.y, GetColor(0, 0, 0), "%d", GetMadness());
		}
	}
}


int InformationCommand::GetMaxHealthPoint()
{
	return health_max;
}

int InformationCommand::GetHealthPoint()
{
	return health;
}

int InformationCommand::HealthPointCalculation()
{
	health_max = GetMaxVitality() + ((GetMaxStamina() + GetMaxStrength()) / 2);//vitalityÇ…staminaÇ∆strengthÇÃïΩãœílÇë´Ç∑

	return health_max;
}

void InformationCommand::SetHealthPoint(int val)
{
	health = val;
}


int InformationCommand::GetMaxVitality()
{
	return vitality_max;
}

int InformationCommand::GetVitality()
{
	return vitality;
}

void InformationCommand::SetMaxVitality(int val)
{
	vitality_max = val;
}

void InformationCommand::SetVitality(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		vitality = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= vitality_max)
	{
		vitality = vitality_max;
	}

	vitality = val;
}


int InformationCommand::GetMaxStamina()
{
	return stamina_max;
}

int InformationCommand::GetStamina()
{
	return stamina;
}

void InformationCommand::SetMaxStamina(int val)
{
	stamina_max = val;
}

void InformationCommand::SetStamina(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		stamina = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= stamina_max)
	{
		stamina = stamina_max;
	}

	stamina = val;
}


int InformationCommand::GetMaxStrength()
{
	return strength_max;
}

int InformationCommand::GetStrength()
{
	return strength;
}

void InformationCommand::SetMaxStrength(int val)
{
	strength_max = val;
}

void InformationCommand::SetStrength(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		strength = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= strength_max)
	{
		strength = strength_max;
	}

	strength = val;
}


int InformationCommand::GetMaxAgility()
{
	return agility_max;
}

int InformationCommand::GetAgility()
{
	return agility;
}

void InformationCommand::SetMaxAgility(int val)
{
	agility_max = val;
}

void InformationCommand::SetAgility(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		agility = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= agility_max)
	{
		agility = agility_max;
	}

	agility = val;
}


int InformationCommand::GetMaxSpirit()
{
	return spirit_max;
}

int InformationCommand::GetSpirit()
{
	return spirit;
}

void InformationCommand::SetMaxSpirit(int val)
{
	spirit_max = val;
}

void InformationCommand::SetSpirit(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		spirit = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= spirit_max)
	{
		spirit = spirit_max;
	}

	spirit = val;
}


int InformationCommand::GetMaxWillpower()
{
	return willpower_max;
}

int InformationCommand::GetWillpower()
{
	return willpower;
}

void InformationCommand::SetMaxWillpower(int val)
{
	willpower_max = val;
}

void InformationCommand::SetWillpower(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		willpower = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= willpower_max)
	{
		willpower = willpower_max;
	}

	willpower = val;
}


int InformationCommand::GetMaxFortune()
{
	return fortune_max;
}

int InformationCommand::GetFortune()
{
	return fortune;
}

void InformationCommand::SetMaxFortune(int val)
{
	fortune_max = val;
}

void InformationCommand::SetFortune(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		fortune = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= fortune_max)
	{
		fortune = fortune_max;
	}

	fortune = val;

}


int InformationCommand::GetMaxMadness()
{
	return madness_max;
}

int InformationCommand::GetMadness()
{
	return madness;
}

void InformationCommand::SetMaxMadness(int val)
{
	madness_max = val;
}

void InformationCommand::SetMadness(int val)
{
	//0ÇÊÇËè¨Ç≥Ç©Ç¡ÇΩÇÁ
	if (val <= 0)
	{
		madness = 0;
	}

	//vitality_maxÇÊÇËëÂÇ´Ç©Ç¡ÇΩÇÁ
	if (val >= madness_max)
	{
		madness = madness_max;
	}

	madness = val;

}