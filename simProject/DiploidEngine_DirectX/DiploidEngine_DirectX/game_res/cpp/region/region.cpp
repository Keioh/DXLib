#include "region\region.h"

void Region::SetObjectNumber(int object_number)
{
	DiploidObject::image.number = DiploidObject::box.number = DiploidObject::circle.number = object_number;
}

void Region::SetLayerNumber(int layer_number)
{
	DiploidObject::image.layer_number = DiploidObject::box.layer_number = DiploidObject::circle.layer_number = layer_number;
}

void Region::LoadTexter(const char* path)
{
	DiploidObject::image.Load(path);
}

void Region::LoadSound(const char* path)
{
	DiploidObject::sound.Load(path);
}

void Region::Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	Region::BoxAndImageUpdata(impact, layer);
}

void Region::Draw()
{
	DiploidObject::image.Draw();
}

void Region::BoxAndImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	//衝突を判定
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//衝突していたら
		if (impact_count->impacted == true)
		{
			//衝突していた対象のイメージ画像に変化を与える
			for (auto layer_count = layer.image_bot_vector.begin(); layer_count != layer.image_bot_vector.end(); ++layer_count)
			{
				//レイヤー番号が同じなら
				if (impact_count->layer_number == layer_count->layer_number)
				{
					//オブジェクト番号も同じなら
					if (impact_count->number == layer_count->number)
					{
						layer_count->blend_volume = 100;
					}
				}
			}
		}
		else
		{
			for (auto layer_count = layer.image_bot_vector.begin(); layer_count != layer.image_bot_vector.end(); ++layer_count)
			{
				layer_count->blend_volume = 255;
			}
		}
	}
}

DiploidImage Region::GetImage()
{
	DiploidImage ans;

	ans = DiploidObject::image;

	return ans;
}

DiploidBox Region::GetBox()
{
	DiploidBox ans;

	ans = DiploidObject::box;

	return ans;
}

DiploidCircle Region::GetCircle()
{
	DiploidCircle ans;

	ans = DiploidObject::circle;

	return ans;
}