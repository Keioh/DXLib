#include "data/number.h"

Number::Number()
{

}

void Number::Load()
{
	number_1.Load("number/1.png");
	number_2.Load("number/2.png");
	number_3.Load("number/3.png");
	number_4.Load("number/4.png");
	number_5.Load("number/5.png");
	number_6.Load("number/6.png");
	number_7.Load("number/7.png");
	number_8.Load("number/8.png");
	number_9.Load("number/9.png");
	number_0.Load("number/0.png");

}

void Number::Init(VECTOR pos, float scale)
{
	number_1.Init(pos, false);
	number_1.SetScale(scale, scale);

	number_2.Init(pos, false);
	number_2.SetScale(scale, scale);

	number_3.Init(pos, false);
	number_3.SetScale(scale, scale);

	number_4.Init(pos, false);
	number_4.SetScale(scale, scale);

	number_5.Init(pos, false);
	number_5.SetScale(scale, scale);

	number_6.Init(pos, false);
	number_6.SetScale(scale, scale);

	number_7.Init(pos, false);
	number_7.SetScale(scale, scale);

	number_8.Init(pos, false);
	number_8.SetScale(scale, scale);

	number_9.Init(pos, false);
	number_9.SetScale(scale, scale);

	number_0.Init(pos, false);
	number_0.SetScale(scale, scale);


}

void Number::Update(int number)
{
	case_number = number;
}

void Number::Draw(bool draw)
{
	switch (case_number)
	{
	case 0:
		number_0.Draw(draw);
		break;

	case 1:
		number_1.Draw(draw);
		break;

	case 2:
		number_2.Draw(draw);
		break;

	case 3:
		number_3.Draw(draw);
		break;

	case 4:
		number_4.Draw(draw);
		break;

	case 5:
		number_5.Draw(draw);
		break;

	case 6:
		number_6.Draw(draw);
		break;

	case 7:
		number_7.Draw(draw);
		break;

	case 8:
		number_8.Draw(draw);
		break;

	case 9:
		number_9.Draw(draw);
		break;

	default:
		break;
	}
}


Number1000::Number1000()
{

}

void Number1000::Load()
{
	number_1.Load();
	number_2.Load();
	number_3.Load();
	number_4.Load();
}

void Number1000::Init(VECTOR pos, float scale)
{
	number_1.Init(pos, scale);
	number_2.Init(VGet(pos.x - (24 * scale), pos.y, pos.z), scale);
	number_3.Init(VGet(pos.x - ((24 * 2) * scale), pos.y, pos.z), scale);
	number_4.Init(VGet(pos.x - ((24 * 3) * scale), pos.y, pos.z), scale);
}

void Number1000::Update(int number)
{
	case_number = number;
	number_1.Update(case_number % 10);
	number_2.Update((case_number / 10) % 10);
	number_3.Update((case_number / 100) % 10);
	number_4.Update((case_number / 1000) % 10);
}

void Number1000::Draw(bool draw)
{
	if (case_number >= 0)
	{
		number_1.Draw(draw);//”š‚ğ•\¦(‚P‚ÌˆÊ)

		if (case_number >= 10)
		{
			number_2.Draw(draw);//”š‚ğ•\¦(‚P‚O‚ÌˆÊ)

			if (case_number >= 100)
			{
				number_3.Draw(draw);//”š‚ğ•\¦(‚P‚O‚O‚ÌˆÊ)

				if (case_number >= 1000)
				{
					number_4.Draw(draw);//”š‚ğ•\¦(‚P‚O‚O‚O‚ÌˆÊ)
				}
			}
		}
	}

	//DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", case_number);
}