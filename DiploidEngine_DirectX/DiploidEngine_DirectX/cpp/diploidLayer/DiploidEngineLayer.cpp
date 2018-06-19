#include "diploidLayer\DiploidEngineLayer.h"

void DiploidEngineLayer::PushTopGraphics(DiploidImage image)
{
	image_top_vector.push_back(image);
}

void DiploidEngineLayer::Updata()
{
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
	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}
}