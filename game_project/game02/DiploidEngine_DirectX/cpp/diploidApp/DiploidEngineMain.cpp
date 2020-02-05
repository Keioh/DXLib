#include "diploidApp\DiploidEngineMain.h"


VECTOR DiploidEngineMain::GetWindowSize()
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
	LayerMID_ImapctBOX_Sync();//�l�p�ƃ��C���[MID�̏���
	LayerBOT_ImapctBOX_Sync();//�l�p�ƃ��C���[BOT�̏���
	LayerUI_ImapctBOX_Sync();//�l�p�ƃ��C���[UI�̏���

	LayerTOP_ImapctCIRCLE_Sync();//�~�ƃ��C���[TOP�̏���
	LayerMID_ImapctCIRCLE_Sync();//�~�ƃ��C���[MID�̏���
	LayerBOT_ImapctCIRCLE_Sync();//�~�ƃ��C���[BOT�̏���
	LayerUI_ImapctCIRCLE_Sync();//�~�ƃ��C���[UI�̏���

	LayerTOP_ImapctPOINT_Sync();//�_�ƃ��C���[TOP�̏���
	LayerMID_ImapctPOINT_Sync();//�_�ƃ��C���[MID�̏���
	LayerBOT_ImapctPOINT_Sync();//�_�ƃ��C���[BOT�̏���
	LayerUI_ImapctPOINT_Sync();//�_�ƃ��C���[UI�̏���

	LayerTOP_ImapctLINE_Sync();//�����ƃ��C���[TOP�̏���
	LayerMID_ImapctLINE_Sync();//�����ƃ��C���[MID�̏���
	LayerBOT_ImapctLINE_Sync();//�����ƃ��C���[BOT�̏���
	LayerUI_ImapctLINE_Sync();//�����ƃ��C���[UI�̏���
}


void DiploidEngineMain::LayerTOP_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_top_vector.erase(image);
									diploidEngineImpact.point_vector.erase(impact);

									image = diploidEngineLayer.image_top_vector.begin();
									impact = diploidEngineImpact.point_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.point_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_mid_vector.erase(image);
									diploidEngineImpact.point_vector.erase(impact);

									image = diploidEngineLayer.image_mid_vector.begin();
									impact = diploidEngineImpact.point_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.point_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_bot_vector.erase(image);
									diploidEngineImpact.point_vector.erase(impact);

									image = diploidEngineLayer.image_bot_vector.begin();
									impact = diploidEngineImpact.point_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerUI_ImapctPOINT_Sync()
{
	if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.point_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_ui_vector.begin(); image != diploidEngineLayer.image_ui_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.point_vector.begin(); impact != diploidEngineImpact.point_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.point_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_ui_vector.erase(image);
									diploidEngineImpact.point_vector.erase(impact);

									image = diploidEngineLayer.image_ui_vector.begin();
									impact = diploidEngineImpact.point_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}


void DiploidEngineMain::LayerTOP_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_top_vector.erase(image);
									diploidEngineImpact.circle_vector.erase(impact);

									image = diploidEngineLayer.image_top_vector.begin();
									impact = diploidEngineImpact.circle_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_mid_vector.erase(image);
									diploidEngineImpact.circle_vector.erase(impact);

									image = diploidEngineLayer.image_mid_vector.begin();
									impact = diploidEngineImpact.circle_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_bot_vector.erase(image);
									diploidEngineImpact.circle_vector.erase(impact);

									image = diploidEngineLayer.image_bot_vector.begin();
									impact = diploidEngineImpact.circle_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerUI_ImapctCIRCLE_Sync()
{
	if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.circle_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_ui_vector.begin(); image != diploidEngineLayer.image_ui_vector.end(); ++image)
		{
			//�~�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.circle_vector.begin(); impact != diploidEngineImpact.circle_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.circle_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_ui_vector.erase(image);
									diploidEngineImpact.circle_vector.erase(impact);

									image = diploidEngineLayer.image_ui_vector.begin();
									impact = diploidEngineImpact.circle_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}


void DiploidEngineMain::LayerTOP_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_top_vector.erase(image);
									diploidEngineImpact.box_vector.erase(impact);

									image = diploidEngineLayer.image_top_vector.begin();
									impact = diploidEngineImpact.box_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_mid_vector.erase(image);
									diploidEngineImpact.box_vector.erase(impact);

									image = diploidEngineLayer.image_mid_vector.begin();
									impact = diploidEngineImpact.box_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_bot_vector.erase(image);
									diploidEngineImpact.box_vector.erase(impact);

									image = diploidEngineLayer.image_bot_vector.begin();
									impact = diploidEngineImpact.box_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerUI_ImapctBOX_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.box_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_ui_vector.begin(); image != diploidEngineLayer.image_ui_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.box_vector.begin(); impact != diploidEngineImpact.box_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.box_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_ui_vector.erase(image);
									diploidEngineImpact.box_vector.erase(impact);

									image = diploidEngineLayer.image_ui_vector.begin();
									impact = diploidEngineImpact.box_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}


void DiploidEngineMain::LayerTOP_ImapctLINE_Sync()
{
	if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.line_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_top_vector.begin(); image != diploidEngineLayer.image_top_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.line_vector.begin(); impact != diploidEngineImpact.line_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_top_vector.empty() || !diploidEngineImpact.line_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_top_vector.erase(image);
									diploidEngineImpact.line_vector.erase(impact);

									image = diploidEngineLayer.image_top_vector.begin();
									impact = diploidEngineImpact.line_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerMID_ImapctLINE_Sync()
{
	if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.line_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_mid_vector.begin(); image != diploidEngineLayer.image_mid_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.line_vector.begin(); impact != diploidEngineImpact.line_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_mid_vector.empty() || !diploidEngineImpact.line_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_mid_vector.erase(image);
									diploidEngineImpact.line_vector.erase(impact);

									image = diploidEngineLayer.image_mid_vector.begin();
									impact = diploidEngineImpact.line_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerBOT_ImapctLINE_Sync()
{
	if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.line_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_bot_vector.begin(); image != diploidEngineLayer.image_bot_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.line_vector.begin(); impact != diploidEngineImpact.line_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_bot_vector.empty() || !diploidEngineImpact.line_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_bot_vector.erase(image);
									diploidEngineImpact.line_vector.erase(impact);

									image = diploidEngineLayer.image_bot_vector.begin();
									impact = diploidEngineImpact.line_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineMain::LayerUI_ImapctLINE_Sync()
{
	if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.line_vector.empty())
	{
		//�摜TOP
		for (auto image = diploidEngineLayer.image_ui_vector.begin(); image != diploidEngineLayer.image_ui_vector.end(); ++image)
		{
			//�l�p�q�b�g�{�b�N�X
			for (auto impact = diploidEngineImpact.line_vector.begin(); impact != diploidEngineImpact.line_vector.end(); ++impact)
			{
				//�G���[����̂��߂̏���
				if (!diploidEngineLayer.image_ui_vector.empty() || !diploidEngineImpact.line_vector.empty())
				{
					//���ʔԍ��������Ȃ�
					if (image->layer_number == impact->layer_number)
					{
						//�ŏ��F�g�b�v�z��摜�I�u�W�F�N�g�ԍ��ƏՓ˔z��l�p�I�u�W�F�N�g�ԍ����ꏏ�@���@�Ō�F�l�p�I�u�W�F�N�g�Ƀq�b�g���Ă�����
						if ((image->number == impact->number))
						{
							if (impact->impacted == true)
							{
								if ((impact->destory == true) && (image->destory == true))
								{
									diploidEngineLayer.image_ui_vector.erase(image);
									diploidEngineImpact.line_vector.erase(impact);

									image = diploidEngineLayer.image_ui_vector.begin();
									impact = diploidEngineImpact.line_vector.begin();
								}
							}
						}
					}
				}
			}
		}
	}
}