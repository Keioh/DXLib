#include "diploidApp\DiploidEngineMain.h"


VECTOR DiploidEngineMain::WindowSize()
{
	VECTOR window_size;

	window_size.x = (float)diploidEngineSetting.window_x;
	window_size.y = (float)diploidEngineSetting.window_y;
	window_size.z = (float)diploidEngineSetting.window_bit;

	return window_size;
}


void DiploidEngineMain::DestorySync()//�Փˏ����ƃ��C���[�����̍폜��������
{
	LayerTOP_ImapctBOX_Sync();//�l�p�ƃ��C���[TOP�̏���
}

void DiploidEngineMain::LayerTOP_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//�摜TOP
		for (auto image_top = diploidEngineLayer.image_top_vector.begin(); image_top != diploidEngineLayer.image_top_vector.end(); ++image_top)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact_box = diploidEngineImpact.box_vector.begin(); impact_box != diploidEngineImpact.box_vector.end(); ++impact_box)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
					if ((image_top->number == impact_box->number))
					{
						if (impact_box->impacted == true)
						{
							if ((impact_box->destory == true) && (image_top->destory == true))
							{
								diploidEngineLayer.image_top_vector.erase(image_top);
								diploidEngineImpact.box_vector.erase(impact_box);

								image_top = diploidEngineLayer.image_top_vector.begin();
								impact_box = diploidEngineImpact.box_vector.begin();
							}
						}
					}
				}
			}
		}
	}
}
