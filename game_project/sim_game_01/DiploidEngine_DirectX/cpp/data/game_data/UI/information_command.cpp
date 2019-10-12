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

	character_level_positin = VAdd(position, VGet(300, 75, 0));
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
	//HP、MP、SPの最大値の計算
	HealthPointCalculation();
	MagicPointCalculation();
	StaminaPointCalculation();

	//各ステータスのレベル計算
	VitalityCalculation();
	StaminaCalculation();
	StrengthCalculation();
	AgilityCalculation();
	SpiritCalculation();
	WillpowerCalculation();
	FortuneCalculation();
	MadnessCalculation();

	//プレイヤーLVの計算
	CharacterLevelCalculation();
}

void InformationCommand::Draw(bool ui_flag, int command_type, bool draw)
{
	if (ui_flag == true)
	{
		if (command_type == INFORMATION_COMMAND)
		{
			back_image.image.Draw(draw);

			//各ステータス
			DrawFormatString(vitality_position.x, vitality_position.y, GetColor(0, 0, 0), "%d", GetVitality());
			DrawFormatString(stamina_position.x, stamina_position.y, GetColor(0, 0, 0), "%d", GetStamina());
			DrawFormatString(strength_position.x, strength_position.y, GetColor(0, 0, 0), "%d", GetStrength());
			DrawFormatString(agility_position.x, agility_position.y, GetColor(0, 0, 0), "%d", GetAgility());
			DrawFormatString(spirit_position.x, spirit_position.y, GetColor(0, 0, 0), "%d", GetSpirit());
			DrawFormatString(willpower_position.x, willpower_position.y, GetColor(0, 0, 0), "%d", GetWillpower());
			DrawFormatString(fortune_position.x, fortune_position.y, GetColor(0, 0, 0), "%d", GetFortune());
			DrawFormatString(madness_position.x, madness_position.y, GetColor(0, 0, 0), "%d", GetMadness());

			//各ステータスのレベル
			DrawFormatString(vitality_position.x + 122, vitality_position.y, GetColor(0, 0, 0), "%d", GetVitalityLv());
			DrawFormatString(vitality_position.x + 122 + 75, vitality_position.y, GetColor(0, 0, 0), "%d", GetVitalityEXP());

			DrawFormatString(stamina_position.x + 122, stamina_position.y, GetColor(0, 0, 0), "%d", GetStaminaLv());
			DrawFormatString(stamina_position.x + 122 + 75, stamina_position.y, GetColor(0, 0, 0), "%d", GetStaminaEXP());

			DrawFormatString(strength_position.x + 122, strength_position.y + 5, GetColor(0, 0, 0), "%d", GetStrengthLv());
			DrawFormatString(strength_position.x + 122 + 75, strength_position.y + 5, GetColor(0, 0, 0), "%d", GetStrengthEXP());

			DrawFormatString(agility_position.x + 122, agility_position.y + 2, GetColor(0, 0, 0), "%d", GetAgilityLv());
			DrawFormatString(agility_position.x + 122 + 75, agility_position.y + 2, GetColor(0, 0, 0), "%d", GetAgilityEXP());

			DrawFormatString(spirit_position.x + 122, spirit_position.y + 5, GetColor(0, 0, 0), "%d", GetSpiritLv());
			DrawFormatString(spirit_position.x + 122 + 75, spirit_position.y + 5, GetColor(0, 0, 0), "%d", GetSpiritEXP());

			DrawFormatString(willpower_position.x + 122, willpower_position.y + 3, GetColor(0, 0, 0), "%d", GetWillpowerLv());
			DrawFormatString(willpower_position.x + 122 + 75, willpower_position.y + 3, GetColor(0, 0, 0), "%d", GetWillpowerEXP());

			DrawFormatString(fortune_position.x + 122, fortune_position.y + 8, GetColor(0, 0, 0), "%d", GetFortuneLv());
			DrawFormatString(fortune_position.x + 122 + 75, fortune_position.y + 8, GetColor(0, 0, 0), "%d", GetFortuneEXP());

			DrawFormatString(madness_position.x + 122, madness_position.y + 5, GetColor(0, 0, 0), "%d", GetMadnessLv());
			DrawFormatString(madness_position.x + 122 + 75, madness_position.y + 5, GetColor(0, 0, 0), "%d", GetMadnessEXP());

			
			//キャラクターLV
			DrawFormatString(character_level_positin.x, character_level_positin.y, GetColor(0, 0, 0), "%d", GetCharacterLevel());

		}
	}
}


void InformationCommand::CharacterLevelCalculation()
{
	character_level = vitality_level + stamina_level + strength_level + agility_level + spirit_level + willpower_level + fortune_level + madness_level + 1;
}

int InformationCommand::GetCharacterLevel()
{
	return character_level;
}


int InformationCommand::GetMaxHealthPoint()
{
	return hp_max;
}

int InformationCommand::GetHealthPoint()
{
	return hp;
}

int InformationCommand::HealthPointCalculation()
{
	hp_max = GetMaxVitality() + ((GetMaxStamina() + GetMaxStrength()) / 2);//vitalityにstaminaとstrengthの平均値を足す

	return hp_max;
}

void InformationCommand::SetHealthPoint(int val)
{
	hp = val;
}


int InformationCommand::GetMaxMagicPoint()
{
	return mp_max;
}

int InformationCommand::GetMagicPoint()
{
	return mp;
}

int InformationCommand::MagicPointCalculation()
{
	mp_max = GetMaxSpirit() + ((GetMaxStamina() + GetMaxWillpower()) / 2);//spiritにstaminaとwillpowerの平均値を足す

	return mp_max;
}

void InformationCommand::SetMagicPoint(int val)
{
	mp = val;
}


int InformationCommand::GetMaxStaminaPoint()
{
	return sp_max;
}

int InformationCommand::GetStaminaPoint()
{
	return sp;
}

int InformationCommand::StaminaPointCalculation()
{
	sp_max = GetMaxStamina() + ((GetMaxVitality() + GetMaxAgility()) / 2);//staminaにvitalityとagilityの平均値を足す

	return sp_max;

}

void InformationCommand::SetStaminaPoint(int val)
{
	sp = val;
}


int InformationCommand::VitalityCalculation()
{
	if (vitality_exp > vitality_need_exp)
	{
		vitality_level += 1;

		vitality_exp = 0;

		vitality_need_exp = (vitality_level + 1) * (vitality_exp * exp_scale);//必要経験値を算出

		return vitality_need_exp;
	}

	return vitality_need_exp;
}

int InformationCommand::GetMaxVitality()
{
	return vitality_max;
}

int InformationCommand::GetVitality()
{
	return vitality;
}

int InformationCommand::GetVitalityLv()
{
	return vitality_level;
}

int InformationCommand::GetVitalityEXP()
{
	return vitality_exp;
}

int InformationCommand::GetVitalityNeedEXP()
{
	return vitality_need_exp;
}

void InformationCommand::SetMaxVitality(int val)
{
	vitality_max = val;
}

void InformationCommand::SetVitality(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		vitality = 0;
	}

	//vitality_maxより大きかったら
	if (val >= vitality_max)
	{
		vitality = vitality_max;
	}

	vitality = val;
}

void InformationCommand::SetVitalityEXP(int val)
{
	vitality_exp = val;
}


int InformationCommand::StaminaCalculation()
{
	if (stamina_exp > stamina_need_exp)
	{
		stamina_level += 1;

		stamina_exp = 0;

		stamina_need_exp = (stamina_level + 1) * (stamina_exp * exp_scale);//必要経験値を算出

		return stamina_need_exp;
	}

	return stamina_need_exp;
}

int InformationCommand::GetMaxStamina()
{
	return stamina_max;
}

int InformationCommand::GetStamina()
{
	return stamina;
}

int InformationCommand::GetStaminaLv()
{
	return stamina_level;
}

int InformationCommand::GetStaminaEXP()
{
	return stamina_exp;
}

int InformationCommand::GetStaminaNeedEXP()
{
	return stamina_need_exp;
}

void InformationCommand::SetMaxStamina(int val)
{
	stamina_max = val;
}

void InformationCommand::SetStamina(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		stamina = 0;
	}

	//vitality_maxより大きかったら
	if (val >= stamina_max)
	{
		stamina = stamina_max;
	}

	stamina = val;
}

void InformationCommand::SetStaminaEXP(int val)
{
	stamina_exp = val;
}


int InformationCommand::StrengthCalculation()
{
	if (strength_exp > strength_need_exp)
	{
		strength_level += 1;

		strength_exp = 0;

		strength_need_exp = (strength_level + 1) * (strength_exp * exp_scale);//必要経験値を算出

		return strength_need_exp;
	}

	return strength_need_exp;
}

int InformationCommand::GetMaxStrength()
{
	return strength_max;
}

int InformationCommand::GetStrength()
{
	return strength;
}

int InformationCommand::GetStrengthLv()
{
	return strength_level;

}

int InformationCommand::GetStrengthEXP()
{
	return strength_exp;
}

int InformationCommand::GetStrengthNeedEXP()
{
	return strength_need_exp;
}

void InformationCommand::SetMaxStrength(int val)
{
	strength_max = val;
}

void InformationCommand::SetStrength(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		strength = 0;
	}

	//vitality_maxより大きかったら
	if (val >= strength_max)
	{
		strength = strength_max;
	}

	strength = val;
}

void InformationCommand::SetStrengthEXP(int val)
{
	strength_exp = val;
}


int InformationCommand::AgilityCalculation()
{
	if (agility_exp > agility_need_exp)
	{
		agility_level += 1;

		agility_exp = 0;

		agility_need_exp = (agility_level + 1) * (agility_exp * exp_scale);//必要経験値を算出

		return agility_need_exp;
	}

	return agility_need_exp;
}

int InformationCommand::GetMaxAgility()
{
	return agility_max;
}

int InformationCommand::GetAgility()
{
	return agility;
}

int InformationCommand::GetAgilityLv()
{
	return agility_level;
}

int InformationCommand::GetAgilityEXP()
{
	return agility_exp;
}

int InformationCommand::GetAgilityNeedEXP()
{
	return agility_need_exp;
}

void InformationCommand::SetMaxAgility(int val)
{
	agility_max = val;
}

void InformationCommand::SetAgility(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		agility = 0;
	}

	//vitality_maxより大きかったら
	if (val >= agility_max)
	{
		agility = agility_max;
	}

	agility = val;
}

void InformationCommand::SetAgilityEXP(int val)
{
	agility_exp = val;
}


int InformationCommand::SpiritCalculation()
{
	if (spirit_exp > spirit_need_exp)
	{
		spirit_level += 1;

		spirit_exp = 0;

		spirit_need_exp = (spirit_level + 1) * (spirit_exp * exp_scale);//必要経験値を算出

		return spirit_need_exp;
	}

	return spirit_need_exp;
}

int InformationCommand::GetMaxSpirit()
{
	return spirit_max;
}

int InformationCommand::GetSpirit()
{
	return spirit;
}

int InformationCommand::GetSpiritLv()
{
	return spirit_level;
}

int InformationCommand::GetSpiritEXP()
{
	return spirit_exp;
}

int InformationCommand::GetSpiritNeedEXP()
{
	return spirit_need_exp;
}

void InformationCommand::SetMaxSpirit(int val)
{
	spirit_max = val;
}

void InformationCommand::SetSpirit(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		spirit = 0;
	}

	//vitality_maxより大きかったら
	if (val >= spirit_max)
	{
		spirit = spirit_max;
	}

	spirit = val;
}

void InformationCommand::SetSpiritEXP(int val)
{
	spirit_exp = val;
}


int InformationCommand::WillpowerCalculation()
{
	if (willpower_exp > willpower_need_exp)
	{
		willpower_level += 1;

		willpower_exp = 0;

		willpower_need_exp = (willpower_level + 1) * (willpower_exp * exp_scale);//必要経験値を算出

		return willpower_need_exp;
	}

	return willpower_need_exp;
}

int InformationCommand::GetMaxWillpower()
{
	return willpower_max;
}

int InformationCommand::GetWillpower()
{
	return willpower;
}

int InformationCommand::GetWillpowerLv()
{
	return willpower_level;
}

int InformationCommand::GetWillpowerEXP()
{
	return willpower_exp;
}

int InformationCommand::GetWillpowerNeedEXP()
{
	return willpower_need_exp;
}

void InformationCommand::SetMaxWillpower(int val)
{
	willpower_max = val;
}

void InformationCommand::SetWillpower(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		willpower = 0;
	}

	//vitality_maxより大きかったら
	if (val >= willpower_max)
	{
		willpower = willpower_max;
	}

	willpower = val;
}

void InformationCommand::SetWillpowerEXP(int val)
{
	willpower_need_exp = val;
}


int InformationCommand::FortuneCalculation()
{
	if (fortune_exp > fortune_need_exp)
	{
		fortune_level += 1;

		fortune_exp = 0;

		fortune_need_exp = (fortune_level + 1) * (fortune_exp * exp_scale);//必要経験値を算出

		return fortune_need_exp;
	}

	return fortune_need_exp;
}

int InformationCommand::GetMaxFortune()
{
	return fortune_max;
}

int InformationCommand::GetFortune()
{
	return fortune;
}

int InformationCommand::GetFortuneLv()
{
	return fortune_level;
}

int InformationCommand::GetFortuneEXP()
{
	return fortune_exp;
}

int InformationCommand::GetFortuneNeedEXP()
{
	return fortune_need_exp;
}

void InformationCommand::SetMaxFortune(int val)
{
	fortune_max = val;
}

void InformationCommand::SetFortune(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		fortune = 0;
	}

	//vitality_maxより大きかったら
	if (val >= fortune_max)
	{
		fortune = fortune_max;
	}

	fortune = val;

}

void InformationCommand::SetFortuneEXP(int val)
{
	fortune_exp = val;
}


int InformationCommand::MadnessCalculation()
{
	if (madness_exp > madness_need_exp)
	{
		madness_level += 1;

		madness_exp = 0;

		madness_need_exp = (madness_level + 1) * (madness_exp * exp_scale);//必要経験値を算出

		return madness_need_exp;
	}

	return madness_need_exp;
}

int InformationCommand::GetMaxMadness()
{
	return madness_max;
}

int InformationCommand::GetMadness()
{
	return madness;
}

int InformationCommand::GetMadnessLv()
{
	return madness_level;
}

int InformationCommand::GetMadnessEXP()
{
	return madness_exp;
}

int InformationCommand::GetMadnessNeedEXP()
{
	return madness_need_exp;

}

void InformationCommand::SetMaxMadness(int val)
{
	madness_max = val;
}

void InformationCommand::SetMadness(int val)
{
	//0より小さかったら
	if (val <= 0)
	{
		madness = 0;
	}

	//vitality_maxより大きかったら
	if (val >= madness_max)
	{
		madness = madness_max;
	}

	madness = val;

}

void InformationCommand::SetMadnessEXP(int val)
{
	madness_exp = val;
}