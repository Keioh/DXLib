#include "diploidLayer\DiploidEngineLayer.h"

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

void DiploidEngineLayer::Draw(bool draw)
{
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
}