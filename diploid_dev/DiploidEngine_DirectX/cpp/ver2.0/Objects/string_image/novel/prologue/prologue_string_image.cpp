#include "ver2.0/Objects/string_image/novel/prologue/prologue_string_image.h"

void PrologueStringImage::Load()
{
	zyo_images.Load("texter/novel/prologue/zyo.png");
	prologue_images.Load("texter/novel/prologue/prologue.png");
	black_back_images.Load("texter/basic/16_9_black.png");

	string_images[0].Load("texter/novel/prologue/1.png");
	string_images[1].Load("texter/novel/prologue/9.png");
	string_images[2].Load("texter/novel/prologue/_r1.png");
	string_images[3].Load("texter/novel/prologue/_l1.png");
	string_images[4].Load("texter/novel/prologue/7.png");
	string_images[5].Load("texter/novel/prologue/d.png");
	string_images[6].Load("texter/novel/prologue/a.png");
	string_images[7].Load("texter/novel/prologue/y.png");
	string_images[8].Load("texter/novel/prologue/_r0.png");
	string_images[9].Load("texter/novel/prologue/_l0.png");
}

void PrologueStringImage::Init(DiploidEngineSetting& setting, VECTOR pos)
{
	position = pos;

	for (int count = 0; count != 10; count++)
	{
		string_alpha[count] = 0;
		string_images[count].Init(position);
		string_images[count].SetScale(setting.GetSystemData().window_x / string_images[count].GetSize().x, setting.GetSystemData().window_y / string_images[count].GetSize().y);
	}

	zyo_images.Init(position);
	zyo_images.SetScale(setting.GetSystemData().window_x / zyo_images.GetSize().x, setting.GetSystemData().window_y / zyo_images.GetSize().y);

	prologue_images.Init(position);
	prologue_images.SetScale(setting.GetSystemData().window_x / prologue_images.GetSize().x, setting.GetSystemData().window_y / prologue_images.GetSize().y);

	black_back_images.Init(position);
	black_back_images.SetScale(setting.GetSystemData().window_x / black_back_images.GetSize().x, setting.GetSystemData().window_y / black_back_images.GetSize().y);

}

void PrologueStringImage::Updata(DiploidEngineScreen& screen)
{
	for (int count = 0; count != 13; count++)
	{
		if (string_alpha[count] > 255)
		{
			string_alpha[count] = 255;
		}
	}

	if (fead_flag == false)
	{
		zyo_images.SetAlpha(string_alpha[10]);
		string_alpha[10] += (alpha_speed / 2) * screen.GetFrameTime();

		prologue_images.SetAlpha(string_alpha[11]);
		string_alpha[11] += (alpha_speed / 2) * screen.GetFrameTime();

		black_back_images.SetAlpha(string_alpha[12]);
		string_alpha[12] = 255;


		if (string_alpha[11] >= 255)
		{
			string_alpha[0] += alpha_speed * screen.GetFrameTime();

			if (string_alpha[0] > 100)
			{
				string_alpha[1] += (alpha_speed * 2) * screen.GetFrameTime();
			}

			if (string_alpha[1] > 100)
			{
				string_alpha[2] += (alpha_speed * 2) * screen.GetFrameTime();
			}

			if (string_alpha[2] > 100)
			{
				string_alpha[3] += (alpha_speed * 2) * screen.GetFrameTime();
			}

			if (string_alpha[3] > 100)
			{
				string_alpha[4] += (alpha_speed * 2) * screen.GetFrameTime();

			}

			if (string_alpha[4] > 100)
			{
				string_alpha[5] += (alpha_speed * 2) * screen.GetFrameTime();

			}

			if (string_alpha[5] > 100)
			{
				string_alpha[6] += (alpha_speed * 2) * screen.GetFrameTime();

			}

			if (string_alpha[6] > 100)
			{
				string_alpha[7] += (alpha_speed * 2) * screen.GetFrameTime();

			}

			if (string_alpha[7] > 100)
			{
				string_alpha[8] += (alpha_speed * 2) * screen.GetFrameTime();

			}

			if (string_alpha[8] > 100)
			{
				string_alpha[9] += (alpha_speed * 2) * screen.GetFrameTime();
			}

			//フェードアウトフラグを立てる
			if (string_alpha[9] >= 255)
			{
				fead_flag = true;
			}
		}
	}
	else//フェードアウト処理
	{
		if (fead_count >= next_fead_time)//カウントがnext_fead_time以上になったら
		{
			for (int count = 0; count != 12; count++)
			{
				string_alpha[count] -= alpha_speed * screen.GetFrameTime();
			}

			//string_alpha[11]のアルファ値が０以下だったら
			if (string_alpha[11] <= 0)
			{
				//string_alpha[12]のアルファ値を減らす
				string_alpha[12] -= alpha_speed * screen.GetFrameTime();
			}

			//アルファ値が0以下だったらfinishフラグを立てる
			if (string_alpha[12] <= 0)
			{
				finish = true;
			}
		}
		else
		{
			fead_count += 100 * screen.GetFrameTime();//カウントを進める
		}
	}
}

void PrologueStringImage::Draw(bool draw, bool debug)
{
	if (draw == true)
	{
		black_back_images.Draw(draw);
		black_back_images.SetAlpha(string_alpha[12]);

		zyo_images.Draw(draw);
		zyo_images.SetAlpha(string_alpha[10]);

		prologue_images.Draw(draw);
		prologue_images.SetAlpha(string_alpha[11]);

		for (int count = 0; count != 10; count++)
		{
			string_images[count].SetAlpha(string_alpha[count]);
			string_images[count].Draw(draw);
		}

	}
}

void PrologueStringImage::NextAnimation()
{
	if (fead_flag == false)
	{
		for (int count = 0; count != 13; count++)
		{
			string_alpha[count] = 255;
		}
	}
	else
	{
		for (int count = 0; count != 13; count++)
		{
			string_alpha[count] = 0;
		}

		finish = true;
	}
}

void PrologueStringImage::Reset()
{
	for (int count = 0; count != 13; count++)
	{
		string_alpha[count] = 0;
	}

	fead_flag = false;
	fead_count = 0;

	finish = false;
}

bool PrologueStringImage::GetFinish()
{
	return finish;
}