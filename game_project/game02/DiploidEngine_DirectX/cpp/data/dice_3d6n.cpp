#include "data/dice_3d6n.h"

Dice3D6n::Dice3D6n()
{

}

void Dice3D6n::Load()
{
	dice_1.Load();
	dice_2.Load();
	dice_3.Load();

	number_1.Load();
	number_2.Load();
	number_3.Load();
	number_4.Load();

	custom_number.Load();

	result.image.Load("texter/button/custom_number/back_4.png");
}

void Dice3D6n::Init(DiploidEngineImpact& impact, VECTOR pos)
{
	dice_1.Init(pos, 3.f);
	dice_2.Init(VAdd(pos,VGet(110,0,0)), 3.f);
	dice_3.Init(VAdd(pos,VGet(220,0,0)), 3.f);

	number_1.Init(VAdd(pos, VGet(530, 2, 0)), 2.f);
	number_2.Init(VAdd(pos, VGet(530 -24, 2, 0)), 2.f);
	number_3.Init(VAdd(pos, VGet(530 - 48, 2, 0)), 2.f);
	number_4.Init(VAdd(pos, VGet(530 - 72, 2, 0)), 2.f);


	custom_number.Init(VAdd(pos, VGet(330, 50, 0)), 2.f);

	custom_number.Push(impact, VAdd(pos, VGet(330, 50, 0)), 2.f);

	result.image.Init(VAdd(pos, VGet(500, 2, 0)), 2.f);

}

void Dice3D6n::Update(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	dice_1.Update();
	dice_2.Update();
	dice_3.Update();

	custom_number.Update(impact, input);


	number = dice_1.dice_number + dice_2.dice_number + dice_3.dice_number + custom_number.custom_number;
}

void Dice3D6n::Draw(DiploidEngineImpact& impact, bool draw)
{
	dice_1.Draw();
	dice_2.Draw();
	dice_3.Draw();

	custom_number.Draw(impact, draw);

	result.image.Draw(draw);

	if (number >= 0)
	{
		number_1.Draw(number % 10, draw);

		if (number >= 10)
		{
			number_2.Draw((number / 10) % 10, draw);

			if (number >= 100)
			{
				number_3.Draw((number / 100) % 10, draw);

				if (number >= 1000)
				{
					number_4.Draw((number / 1000) % 10, draw);
				}
			}
		}
	}
}

bool Dice3D6n::DiceActiveFlags()
{
	if ((dice_1.dice_roll_active == true) && (dice_2.dice_roll_active == true) && (dice_3.dice_roll_active == true))
	{
		return true;
	}

	return false;
}