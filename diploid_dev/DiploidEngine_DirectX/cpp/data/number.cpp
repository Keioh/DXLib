#include "data/number.h"

Number::Number()
{

}

void Number::Load()
{
	number_1.image.Load("texter/number/1.png");
	number_2.image.Load("texter/number/2.png");
	number_3.image.Load("texter/number/3.png");
	number_4.image.Load("texter/number/4.png");
	number_5.image.Load("texter/number/5.png");
	number_6.image.Load("texter/number/6.png");
	number_7.image.Load("texter/number/7.png");
	number_8.image.Load("texter/number/8.png");
	number_9.image.Load("texter/number/9.png");
	number_0.image.Load("texter/number/0.png");

}

void Number::Init(VECTOR pos, float scale)
{
	number_1.image.Init(pos, scale);
	number_2.image.Init(pos, scale);
	number_3.image.Init(pos, scale);
	number_4.image.Init(pos, scale);
	number_5.image.Init(pos, scale);
	number_6.image.Init(pos, scale);
	number_7.image.Init(pos, scale);
	number_8.image.Init(pos, scale);
	number_9.image.Init(pos, scale);
	number_0.image.Init(pos, scale);

}

void Number::Update()
{

}

void Number::Draw(int number, bool draw)
{
	switch (number)
	{
	case 0:
		number_0.image.Draw(draw);
		break;

	case 1:
		number_1.image.Draw(draw);
		break;

	case 2:
		number_2.image.Draw(draw);
		break;

	case 3:
		number_3.image.Draw(draw);
		break;

	case 4:
		number_4.image.Draw(draw);
		break;

	case 5:
		number_5.image.Draw(draw);
		break;

	case 6:
		number_6.image.Draw(draw);
		break;

	case 7:
		number_7.image.Draw(draw);
		break;

	case 8:
		number_8.image.Draw(draw);
		break;

	case 9:
		number_9.image.Draw(draw);
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
	number_1.Init(VAdd(pos, VGet(0 + (24 * 2), -72, 0)), scale);
	number_2.Init(VAdd(pos, VGet(-24 + (24 * 2), -72, 0)), scale);
	number_3.Init(VAdd(pos, VGet(-48 + (24 * 2), -72, 0)), scale);
	number_4.Init(VAdd(pos, VGet(-72 + (24 * 2), -72, 0)), scale);

}

void Number1000::Update()
{

}

void Number1000::Draw(int number, bool draw)
{
	if (number >= 0)
	{
		number_1.Draw(number % 10);//”š‚ğ•\¦(‚P‚ÌˆÊ)

		if (number >= 10)
		{
			number_2.Draw((number / 10) % 10);//”š‚ğ•\¦(‚P‚O‚ÌˆÊ)

			if (number >= 100)
			{
				number_3.Draw((number / 100) % 10);//”š‚ğ•\¦(‚P‚O‚O‚ÌˆÊ)

				if (number >= 1000)
				{
					number_4.Draw((number / 1000) % 10);//”š‚ğ•\¦(‚P‚O‚O‚O‚ÌˆÊ)
				}
			}
		}
	}
}