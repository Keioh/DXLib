#include "diploidLayer\DiploidEngineLayer.h"

void DiploidEngineLayer::GetSize()
{
	top_size = image_top_vector.size();
	mid_size = image_mid_vector.size();
	bot_size = image_bot_vector.size();

	top_byte = top_size * sizeof(DiploidImage);
	mid_byte = mid_size * sizeof(DiploidImage);
	bot_byte = bot_size * sizeof(DiploidImage);
}

void DiploidEngineLayer::PushTopGraphics(DiploidImage image)
{
	image_top_vector.push_back(image);
}

void DiploidEngineLayer::PushMidGraphics(DiploidImage image)
{
	image_mid_vector.push_back(image);
}

void DiploidEngineLayer::PushBotGraphics(DiploidImage image)
{
	image_bot_vector.push_back(image);
}

void DiploidEngineLayer::Updata()
{
	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			image->Updata();
		}
	}

	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			image->Updata();
		}
	}	
	
	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			image->Updata();
		}
	}
}

void DiploidEngineLayer::Draw(bool debug, bool draw)
{
	GetSize();//�e�z��̑傫�����擾

	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	//�f�o�b�O���
	if (debug == true)
	{
		DrawFormatString(0, 80, GetColor(255, 255, 255), "top layer vector size : %.6f MB   objects : %d", top_byte / 1000000, top_size);
		DrawFormatString(0, 100, GetColor(255, 255, 255), "mid layer vector size : %.6f MB   objects : %d", mid_byte / 1000000, mid_size);
		DrawFormatString(0, 120, GetColor(255, 255, 255), "bot layer vector size : %.6f MB   objects ; %d", bot_byte / 1000000, bot_size);
		DrawFormatString(0, 140, GetColor(255, 255, 255), "all layer vector size : %.6f MB   all object ; %d", (top_byte + mid_byte + bot_byte) / 1000000, top_size + mid_size + bot_size);
	}
}

void DiploidEngineLayer::Destory()
{
	DestoryTop();//top�z�񂩂�v�f���폜
	DestoryMid();//mid�z�񂩂�v�f���폜
	DestoryBot();//bot�z�񂩂�v�f���폜
}

void DiploidEngineLayer::DestoryTop()
{
	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_top_vector.erase(image);
				image = image_top_vector.begin();
			}
		}
	}
}

void DiploidEngineLayer::DestoryMid()
{
	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_mid_vector.erase(image);
				image = image_mid_vector.begin();
			}
		}
	}
}

void DiploidEngineLayer::DestoryBot()
{
	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_bot_vector.erase(image);
				image = image_bot_vector.begin();
			}
		}
	}
}