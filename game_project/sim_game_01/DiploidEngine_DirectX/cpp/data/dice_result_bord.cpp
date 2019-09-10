#include "data/dice_result_bord.h"

DiceResultBord::DiceResultBord()
{

}


void DiceResultBord::Load()
{
	number_1.Load();
	number_2.Load();
	number_3.Load();

	edge.image.Load("texter/button/button/edge.png");
	back.image.Load("texter/button/button/back.png");

}

void DiceResultBord::Init(VECTOR pos, float scale)
{
	number_1.Init(VAdd(pos, VGet((0 * scale) + (12 * scale), 0, 0)), scale);
	number_2.Init(VAdd(pos, VGet((-12 * scale) + (12 * scale), 0, 0)), scale);
	number_3.Init(VAdd(pos, VGet((-24 * scale) + (12 * scale), 0, 0)), scale);

	edge.image.Init(VAdd(pos, VGet(0, 0, 0)), scale);
	back.image.Init(VAdd(pos, VGet(0, 0, 0)), scale);

}

void DiceResultBord::Update()
{
	number_1.Update();
	number_2.Update();
	number_3.Update();

	edge.image.Updata();
	back.image.Updata();

}

void DiceResultBord::Draw(int result_number, bool draw)
{
	back.image.Draw(draw);
	edge.image.Draw(draw);

	if (result_number >= 0)
	{
		number_1.Draw(result_number % 10);//”š‚ğ•\¦

		if (result_number >= 10)
		{
			number_2.Draw((result_number / 10) % 10);//”š‚ğ•\¦

			if (result_number >= 100)
			{
				number_3.Draw((result_number / 100) % 10);//”š‚ğ•\¦
			}
		}
	}
}