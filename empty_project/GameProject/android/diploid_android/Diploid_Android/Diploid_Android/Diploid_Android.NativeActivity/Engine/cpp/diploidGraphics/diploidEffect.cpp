#include "diploidGraphics/diploidEffect.h"

void DiploidEffect::PushImage(DiploidImageV2 image)
{
	//画像データをプッシュ
	image_vector.push_back(image);
}

void DiploidEffect::PushCirlce(DiploidCircleV2 circle)
{
	//円データをプッシュ
	circle_vector.push_back(circle);
}

void DiploidEffect::PushBox(DiploidBoxV2 box)
{
	//箱データをプッシュ
	box_vecter.push_back(box);
}



void DiploidEffect::UpdateImage()
{
	if (!image_vector.empty())
	{
		for (auto itr = image_vector.begin(); itr != image_vector.end(); itr++)
		{
			itr->MoveUpdate();//移動のアップデート
		}
	}
}

void DiploidEffect::UpdateCircle()
{
	if (!circle_vector.empty())
	{
		for (auto itr = circle_vector.begin(); itr != circle_vector.end(); itr++)
		{
			itr->MoveUpdate();
		}
	}
}

void DiploidEffect::UpdateBox()
{
	if (!box_vecter.empty())
	{
		for (auto itr = box_vecter.begin(); itr != box_vecter.end(); itr++)
		{
			itr->SizeUpdate();
			itr->MoveUpdate();

			itr->SubLife(1);

			if (itr->GetLife() <= 0)
			{
				itr->SetSize(itr->GetOriginalSize());

			}
		}
	}
}


void DiploidEffect::DrawImage(bool draw, bool debug)
{
	if (!image_vector.empty())
	{
		for (auto itr = image_vector.begin(); itr != image_vector.end(); itr++)
		{
			itr->Draw(draw);
		}
	}
}

void DiploidEffect::DrawCircle(bool draw, bool debug)
{
	if (!circle_vector.empty())
	{
		for (auto itr = circle_vector.begin(); itr != circle_vector.end(); itr++)
		{
			itr->Draw(draw);
		}
	}
}

void DiploidEffect::DrawBox(bool draw, bool debug)
{
	if (!box_vecter.empty())
	{
		for (auto itr = box_vecter.begin(); itr != box_vecter.end(); itr++)
		{
			itr->Draw(draw);
		}
	}
}