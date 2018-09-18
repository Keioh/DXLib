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
	//�Փˏ�������
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//���C���[��������(top���C���[)
		for (auto layer_count = layer.image_top_vector.begin(); layer_count != layer.image_top_vector.end(); ++layer_count)
		{
			//���C���[�ԍ��������Ȃ�
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_UI)
			{
				//�I�u�W�F�N�g�ԍ��������Ȃ�
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
	//�Փ˂𔻒�
	for (auto impact_count = impact.box_vector.begin(); impact_count != impact.box_vector.end(); ++impact_count)
	{
		//�Փ˂��Ă����Ώۂ̃C���[�W�摜�ɕω���^����(top���C���[)
		for (auto layer_count = layer.image_top_vector.begin(); layer_count != layer.image_top_vector.end(); ++layer_count)
		{
			//���C���[�ԍ��������Ȃ�
			if ((impact_count->layer_number && layer_count->layer_number) == DIPLOID_ENGINE_UI)
			{
				//�I�u�W�F�N�g�ԍ��������Ȃ�
				if (impact_count->number == layer_count->number)
				{
					//�Փ˂��Ă�����
					if (impact_count->impacted == true)
					{
						layer_count->red_bright = 200;
						layer_count->green_bright = 200;
						layer_count->blue_bright = 200;

						//�N���b�N������I����Ԃɂ���
						if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
						{
							impact_count->Selected = true;
							layer_count->Selected = true;

							//�N���b�N���ꂽ���ȊO�̃I�u�W�F�N�g�I��������
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