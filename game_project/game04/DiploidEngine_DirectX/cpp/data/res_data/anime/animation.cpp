#include "data/res_data/anime/animation.h"


void Animation::LoadPushImageV2(DiploidImageV2 imageV2)
{
	image_list.push_back(imageV2);
}

void Animation::LoadHandles(int handle)
{
	_image.SetHandl(handle);
	image_list.push_back(_image);
}

void Animation::Init(VECTOR pos, float play_speed, float scale, bool shift_flag)
{
	play = play_speed;

	if (!image_list.empty())
	{		
		for (auto image = image_list.begin(); image != image_list.end(); ++image)
		{

			image->Init(pos, shift_flag);
			image->SetScale(scale, scale);
		}
	}
}

void Animation::SetGraphicsTrun(bool new_flag)
{
	if (!image_list.empty())
	{
		for (auto image = image_list.begin(); image != image_list.end(); ++image)
		{
			image->SetTurnFlag(new_flag);
		}
	}
}

void Animation::SetPosition(VECTOR new_pos)
{
	if (!image_list.empty())
	{
		for (auto image = image_list.begin(); image != image_list.end(); ++image)
		{
			image->SetPosition(new_pos);
		}
	}
}

void Animation::SetGraphicsAngle(bool new_angle)
{
	if (!image_list.empty())
	{
		for (auto image = image_list.begin(); image != image_list.end(); ++image)
		{
			image->SetAngle(new_angle);
		}
	}
}

void Animation::Updata()
{

}

void Animation::Draw(bool draw)
{
	if (!image_list.empty())
	{
		if (image_list_itr == image_list.end())
		{			
			image_list_itr = image_list.begin();
		}

		++time;

		image_list_itr->Draw(draw);

		if (time >= play)
		{
			++image_list_itr;
			time = 0;
		}
	}
}


std::list<DiploidImageV2>* Animation::GetImageListPtr()
{
	return& image_list;
}

std::list<DiploidImageV2>::iterator Animation::isGetItr()
{
	return image_list_itr;
}
