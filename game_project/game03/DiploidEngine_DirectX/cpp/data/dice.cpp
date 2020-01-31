#include "data/dice.h"

Dice::Dice()
{
	dice_number = 6;
	dice_roll = true;

	dice_roll_active = false;

	roll_time = GetRand(20) + 40;
}

void Dice::Load()
{
	dice_1.image.Load("texter/dice/dice_1.png");
	dice_2.image.Load("texter/dice/dice_2.png");
	dice_3.image.Load("texter/dice/dice_3.png");
	dice_4.image.Load("texter/dice/dice_4.png");
	dice_5.image.Load("texter/dice/dice_5.png");
	dice_6.image.Load("texter/dice/dice_6.png");

}

void Dice::Init(VECTOR pos, float scale)
{
	dice_1.image.Init(pos, scale);
	dice_2.image.Init(pos, scale);
	dice_3.image.Init(pos, scale);
	dice_4.image.Init(pos, scale);
	dice_5.image.Init(pos, scale);
	dice_6.image.Init(pos, scale);

}

void Dice::Push(DiploidEngineImpact& impact, VECTOR pos, float scale)
{
	box.Init(pos, VScale(VGet(24, 24, 0), scale));
	box.number = impact.GetAllArraySize();
	box.name_tag = "1D6";
	impact.PushBox(box);

}

void Dice::Update()
{	
	input.Update();


	//スペースボタンを押したら
	if (input.GetPressKey(KEY_INPUT_F10) == true)
	{
		roll_time = GetRand(20) + 40;
		dice_roll = true;//さいころを振るフラグを立てる。
		dice_roll_active = true;//さいころを振っているというフラグを立てる。
	}


	//振るフラグと振っているフラグが立っていたら
	if ((dice_roll == true) && (dice_roll_active == true))
	{
		if (roll_time >= 0)//振っている時間が０じゃなかったら
		{
			dice_number = GetRand(5) + 1;//さいころの目を決める。
			--roll_time;//時間を減らす。
		}

		if (roll_time <= 0)//振っている時間が０だったら
		{
			dice_roll = false;
			dice_roll_active = false;
		}
	}
}

void Dice::Draw(bool draw)
{
	if (draw == true)
	{
		
	}

	switch (dice_number)
	{
	case 1:
		dice_1.image.Draw();
		break;

	case 2:
		dice_2.image.Draw();
		break;

	case 3:
		dice_3.image.Draw();
		break;

	case 4:
		dice_4.image.Draw();
		break;

	case 5:
		dice_5.image.Draw();
		break;

	case 6:
		dice_6.image.Draw();
		break;

	default:
		break;
	}
}

void Dice::Roll()
{
	roll_time = GetRand(20) + 40;
	dice_roll = true;//さいころを振るフラグを立てる。
	dice_roll_active = true;//さいころを振っているというフラグを立てる。
}