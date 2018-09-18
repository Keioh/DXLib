#include "law\law_button.h"

void LawButton::LoadTexter(const char* path)
{
	DiploidObject::image.Load(path);
}

void LawButton::LoadSound(const char* path)
{
	DiploidObject::sound.Load(path);
}

void LawButton::Updata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	InputUpadata(impact, layer, input);
}

void LawButton::Draw()
{
	DiploidObject::image.Draw();
}

void LawButton::SelectLawButton(DiploidEngineImpact& impact, DiploidEngineLayer& layer)
{
	//衝突情報を検索
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//レイヤー情報を検索(topレイヤー)
		for (auto layer_count = layer.image_top_vector.begin(); layer_count != layer.image_top_vector.end(); ++layer_count)
		{
			//レイヤー番号が同じなら
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_UI)
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

void LawButton::BoxAndTopImageUpdata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	//衝突を判定
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//衝突していた対象のイメージ画像に変化を与える(topレイヤー)
		for (auto layer_count = layer.image_top_vector.begin(); layer_count != layer.image_top_vector.end(); ++layer_count)
		{
			//レイヤー番号が同じなら
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_UI)
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
								for (auto layer_count_2 = layer.image_top_vector.begin(); layer_count_2 != layer.image_top_vector.end(); ++layer_count_2)
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
						layer_count->red_bright = 255 / 2;
						layer_count->green_bright = 255 / 2;
						layer_count->blue_bright = 255 / 2;
					}
				}
			}
		}
	}

}

void LawButton::InputUpadata(DiploidEngineImpact& impact, DiploidEngineLayer& layer, DiploidEngineInput& input)
{
	SelectLawButton(impact, layer);
	BoxAndTopImageUpdata(impact, layer, input);
}