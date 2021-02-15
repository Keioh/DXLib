#include "ver2.0/Objects/DiploidAnimation.h"

void DiploidAnimation::Load(const char* path)
{
	image.Load(path);

	images.push_back(image);
}

void DiploidAnimation::Init(VECTOR pos, int sheet,  float scale_x, float scale_y)
{
	sheets = sheet;

	if (!images.empty())
	{
		if (images.size() > sheets)
		{
			images.erase(images.begin(), (images.begin() + sheets));//不必要になった配列を削除
		}

		for (int count = 0; count != images.size(); count++)
		{
			images[count].Init(pos);
			images[count].SetScale(scale_x, scale_y);
		}
	}
}


void DiploidAnimation::Update()
{

}

void DiploidAnimation::SetPosition(VECTOR  new_pos)
{
	if (!images.empty())
	{
		for (int count = 0; count != images.size(); count++)
		{
			images[count].SetPosition(new_pos);
		}
	}
}

void DiploidAnimation::SetScale(float new_x, float new_y)
{
	if (!images.empty())
	{
		for (int count = 0; count != images.size(); count++)
		{
			images[count].SetScale(new_x, new_y);
		}
	}
}

void DiploidAnimation::SetNextAnimationTime(int new_time)
{
	next_time = new_time;
}

void DiploidAnimation::SetAnimationSpeed(int new_Speed)
{
	animation_speed = new_Speed;
}

void DiploidAnimation::Reset()
{
	sheets_anime = 0;
	animation_image_number = 1;
	time = 0;
}


int DiploidAnimation::GetAnimationNumber()
{
	return animation_image_number;
}

int DiploidAnimation::GetAnimationSpeed()
{
	return animation_speed;
}


void DiploidAnimation::OneCellDraw(int number, bool draw)
{
	images[number].Draw();
}

void DiploidAnimation::Draw(bool debug)
{
	/*
	if (!images.empty())
	{
		images[animation_image_number].Draw();

		time += animation_speed;

		if (next_time <= time)
		{
			animation_image_number++;

			if ((images.size() + 1) <= animation_image_number)
			{
				animation_image_number = 1;
			}

			time = 0;
		}
	}
	*/

	if (!images.empty())
	{
		images[sheets_anime].Draw();

		time += animation_speed;

		if (next_time <= time)
		{
			sheets_anime++;

			if ((images.size()) <= sheets_anime)
			{
				sheets_anime = 0;
			}

			time = 0;
		}
	}
}

void DiploidAnimation::StackDraw(bool debug)
{	
	if (!images.empty())
	{
		for (int count = 0; count != animation_image_number; count++)
		{
			images[count].Draw();
		}

		time += animation_speed;

		if (next_time <= time)
		{
			animation_image_number++;

			if ((images.size() + 1) <= animation_image_number)
			{
				animation_image_number = 1;
			}

			time = 0;
		}
	}	
}

void DiploidAnimation::AllPop()
{
	if (!images.empty())
	{
		images.clear();
	}
}

size_t DiploidAnimation::GetImagesVectorSize()
{
	return images.size();
}