#include "diploidImpact\DiploidEngineImpact.h"

void DiploidEngineImpact::GetSize()
{
	circle_size = circle_vector.size();
	point_size = point_vector.size();
	box_size = box_vector.size();	
	
	circle_byte = circle_size * sizeof(DiploidCircle);
	point_byte = point_size * sizeof(DiploidPoint);
	box_byte = box_size * sizeof(DiploidBox);
}

void DiploidEngineImpact::PushCircle(DiploidCircle circle)
{
	circle_vector.push_back(circle);
}

void DiploidEngineImpact::PushPoint(DiploidPoint point)
{
	point_vector.push_back(point);
}

void DiploidEngineImpact::PushBox(DiploidBox box)
{
	box_vector.push_back(box);
}

void DiploidEngineImpact::PopBackCircle()
{
	if (!circle_vector.empty())
	{
		circle_vector.pop_back();
	}
}

void DiploidEngineImpact::PopBackPoint()
{
	if (!point_vector.empty())
	{
		point_vector.pop_back();
	}
}

void DiploidEngineImpact::PopBackBox()
{
	if (!box_vector.empty())
	{
		box_vector.pop_back();
	}
}

void DiploidEngineImpact::DestoryCircle()
{	
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if ((circle->impacted == true) && (circle->destory == true))
			{
				circle_vector.erase(circle);
				circle = circle_vector.begin();
			}
		}
	}
}

void DiploidEngineImpact::DestoryPoint()
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if ((point->impacted == true) && (point->destory == true))
			{
				point_vector.erase(point);
				point = point_vector.begin();
			}
		}
	}
}

void DiploidEngineImpact::DestoryBox()
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if ((box->impacted == true) && (box->destory == true))
			{
				box_vector.erase(box);
				box = box_vector.begin();
			}
		}
	}
}

void DiploidEngineImpact::ImpactCirclePoint()
{
	if (!point_vector.empty() && !circle_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
			{
				float x = 0, y = 0;

				x = (circle->position.x - point->position.x);
				y = (circle->position.y - point->position.y);

				if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(circle->size.z, 2))
				{
					//���ʔԍ��������Ȃ�
					if (circle->layer_number == point->layer_number)
					{
						circle->impacted = true;
						point->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactCircleCircle()
{
	if (!circle_vector.empty())
	{
		for (size_t circle_one = 0; circle_one != circle_vector.size(); ++circle_one)
		{
			for (size_t circle_two = 1; circle_two != circle_vector.size(); ++circle_two)
			{
				float x = 0, y = 0, r = 0;

				if (circle_one == circle_two)//�����l�Ȃ�v�Z���Ȃ�
				{
					//x = 0;
					//y = 0;
					//r = 0;
				}
				else if(circle_vector[circle_one].impacted == false)
				{
					x = (circle_vector[circle_one].position.x - circle_vector[circle_two].position.x);
					y = (circle_vector[circle_one].position.y - circle_vector[circle_two].position.y);
					r = (circle_vector[circle_one].size.z + circle_vector[circle_two].size.z);

					if ((std::pow(x, 2) + std::pow(y, 2)) <= std::pow(r, 2))
					{
						//���ʔԍ��������Ȃ�
						if (circle_vector[circle_one].layer_number == circle_vector[circle_two].layer_number)
						{
							circle_vector[circle_one].impacted = true;
							circle_vector[circle_two].impacted = true;
						}
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactBoxPoint()
{
	if (!point_vector.empty() && !box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
			{
				if ((box->position.x <= point->position.x) && ((box->position.x + box->size.x) >= point->position.x))
				{
					if ((box->position.y <= point->position.y) && ((box->position.y + box->size.y) >= point->position.y))
					{
						//���ʔԍ��������Ȃ�
						if (point->layer_number == box->layer_number)
						{
							point->impacted = true;
							box->impacted = true;
						}
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactBoxBox()
{
	if (!box_vector.empty())
	{
		for (auto box_one = box_vector.begin(); box_one != box_vector.end(); ++box_one)
		{
			for (auto box_two = box_vector.begin() + 1; box_two != box_vector.end(); ++box_two)
			{
				//���ʔԍ��������Ȃ�
				if (box_one->layer_number == box_two->layer_number)
				{
					if (box_one == box_two)//�����l�Ȃ�v�Z���Ȃ�
					{

					}
					else
					{
						//one
						if (box_one->position.x < (box_two->position.x + box_two->size.x) && box_one->position.y < (box_two->position.y + box_two->size.y))
						{
							//two
							if (box_two->position.x < (box_one->position.x + box_one->size.x) && box_two->position.y < (box_one->position.y + box_one->size.y))
							{
								box_two->impacted = true;
								box_one->impacted = true;
							}
						}
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactBoxCircle()
{	
	if (!box_vector.empty() || !circle_vector.empty())
	{

		//BOX
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			//Circle
			for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
			{
				//y�����ւ̖ʐόv�Z(A)
				if ((circle->position.x > box->position.x) &&
					(circle->position.x < (box->position.x + box->size.x)) &&
					(circle->position.y > (box->position.y - circle->size.z)) &&
					(circle->position.y < ((box->position.y + box->size.y) + circle->size.z)))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}

				//X�����ւ̖ʐόv�Z(B)
				if ((circle->position.x > (box->position.x - circle->size.z)) &&
					(circle->position.x < ((box->position.x + box->size.x) + circle->size.z) &&
					(circle->position.y > box->position.y) &&
						(circle->position.y < (box->position.y + box->size.y))))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}

				//BOX����̖ʐόv�Z(C)
				if ((std::pow((box->position.x - circle->position.x), 2) + std::pow((box->position.y - circle->position.y), 2)) < std::pow(circle->size.z, 2))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}

				//BOX�E��̖ʐόv�Z(D)
				if ((std::pow(((box->position.x + box->size.x) - circle->position.x), 2) + std::pow((box->position.y - circle->position.y), 2)) < std::pow(circle->size.z, 2))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}

				//BOX�E���̖ʐόv�Z(E)
				if ((std::pow(((box->position.x + box->size.x) - circle->position.x), 2) + std::pow(((box->position.y + box->size.y) - circle->position.y), 2)) < std::pow(circle->size.z, 2))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}

				//BOX�����̖ʐόv�Z(F)
				if ((std::pow((box->position.x - circle->position.x), 2) + std::pow(((box->position.y + box->size.y) - circle->position.y), 2)) < std::pow(circle->size.z, 2))
				{
					if (circle->impacted == false)
					{
						circle->impacted = true;
					}

					if (box->impacted == false)
					{
						box->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::Updata()
{
	//�~�̍X�V����
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			circle->Update();//�A�j���A�v�f
		}
	}

	//�_�̍X�V����
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			point->Update();//�A�j���A�v�f
		}
	}

	//�l�p�̍X�V����
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			box->Update();//�A�j���A�v�f
		}
	}

	//�_
	ImpactCirclePoint();//�~�Ɠ_�̏Փˌv�Z
	ImpactBoxPoint();//�l�p�Ɠ_�̏Փˌv�Z

	//�~
	ImpactCircleCircle();//�~�Ɖ~�̏Փˌv�Z

	//�l�p
	ImpactBoxBox();//�l�p�Ǝl�p�̏Փˌv�Z
	ImpactBoxCircle();//�l�p�Ɖ~�̏Փˌv�Z
}

void DiploidEngineImpact::Init()
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//�~���q�b�g���Ă�����
			if (circle->impacted == true)
			{
				circle->impacted = false;
			}
		}
	}

	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			//�_���q�b�g���Ă�����
			if (point->impacted == true)
			{
				point->impacted = false;
			}
		}
	}

	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			//�l�p���q�b�g���Ă�����
			if (box->impacted == true)
			{
				box->impacted = false;
			}
		}
	}
}

void DiploidEngineImpact::Draw(bool wire)
{
	GetSize();//�e�z��̑傫�����擾

	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//�~���q�b�g���Ă�����
			if (circle->impacted == true)
			{
				circle->color = GetColor(255, 0, 0);
			}
			else
			{
				circle->color = GetColor(0, 0, 255);
			}	
			
			circle->Draw(wire);
		}
	}

	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			//�_���q�b�g���Ă�����
			if (point->impacted == true)
			{
				point->color = GetColor(255, 0, 0);
			}
			else
			{
				point->color = GetColor(0, 0, 255);
			}	
			
			point->Draw(wire);
		}
	}

	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			//�l�p���q�b�g���Ă�����
			if (box->impacted == true)
			{
				box->color = GetColor(255, 0, 0);
			}
			else
			{
				box->color = GetColor(0, 0, 255);
			}

			box->Draw(wire);
		}
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "circle vector size : %.6f MB   objects : %d", circle_byte / 1000000, circle_size);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "point vector size : %.6f MB   objects : %d", point_byte / 1000000, point_size);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "box vector size : %.6f MB   objects ; %d", box_byte / 1000000, box_size);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "all vector size : %.6f MB   all object ; %d", (box_byte + point_byte + circle_byte) / 1000000, box_size + point_size + circle_size);
}

void DiploidEngineImpact::Destory()
{
	DestoryCircle();//�~���q�b�g���Ă�����~�z�񂩂�폜
	DestoryPoint();//�_���q�b�g���Ă�����_�z�񂩂�폜
	DestoryBox();//�l�p���q�b�g���Ă�����l�p�z�񂩂�폜
}