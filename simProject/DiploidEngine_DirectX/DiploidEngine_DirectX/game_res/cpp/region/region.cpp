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

void Region::Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	InputUpadata(impact, layer, input);
}

void Region::Draw()
{
	DiploidObject::image.Draw();
}



void Region::BoxAndBotImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//衝突を判定
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{							
		//衝突していた対象のイメージ画像に変化を与える(botレイヤー)
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{	
			//レイヤー番号が同じなら
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_GAMEOBJECT)
			{
				//オブジェクト番号も同じなら
				if (impact_count->number == layer_count->number)
				{
					//衝突していたら
					if (impact_count->impacted == true)
					{
						layer_count->red_bright = 200;
						layer_count->green_bright = 200;
						layer_count->blue_bright = 200;

						//クリックしたら選択状態にする
						if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
						{
							impact_count->Selected = true;
							layer_count->Selected = true;
							
							//クリックされた所以外のオブジェクト選択を解除
							for (auto impact_count_2 = impact.box_vector.begin(); impact_count_2 != impact.box_vector.end(); ++impact_count_2)
							{
								for (auto layer_count_2 = layer.image_mid_vector.begin(); layer_count_2 != layer.image_mid_vector.end(); ++layer_count_2)
								{
									if (impact_count->number != impact_count_2->number)
									{
										if (layer_count->number != layer_count_2->number)
										{
											impact_count_2->Selected = false;
											layer_count_2->Selected = false;
										}
									}
								}
							}
						}
					}
					else
					{
						layer_count->red_bright = 255/2;
						layer_count->green_bright = 255/2;
						layer_count->blue_bright = 255/2;
					}
				}
			}
		}
	}
}

void Region::SelectRegion(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	//衝突情報を検索
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//レイヤー情報を検索(botレイヤー)
		for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
		{
			//レイヤー番号が同じなら
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_GAMEOBJECT)
			{
				//オブジェクト番号も同じなら
				if (impact_count->number == layer_count->number)
				{

					if (impact_count->Selected == true)
					{
						if (layer_count->Selected == true)
						{
							layer_count->red_bright = 255;
							layer_count->green_bright = 255;
							layer_count->blue_bright = 255;
						}
					}
				}
			}
		}
	}
}

void Region::InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{	
	BoxAndBotImageUpdata(impact, layer, input);
	SelectRegion(impact, layer);

	//右クリックをしたらすべての選択を解除
	if (input.GetPressMouse(MOUSE_INPUT_RIGHT) == true)
	{
		for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
		{
			for (auto layer_count = layer.image_mid_vector.begin(); layer_count != layer.image_mid_vector.end(); ++layer_count)
			{
				impact_count->Selected = false;
				layer_count->Selected = false;
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