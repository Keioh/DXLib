#include "diploidImpact\DiploidEngineImpact.h"

DiploidEngineImpact::DiploidEngineImpact()
{

}

DiploidEngineImpact::~DiploidEngineImpact()
{

}


void DiploidEngineImpact::GetSize()
{
	circle_size = circle_vector.size();
	point_size = point_vector.size();
	box_size = box_vector.size();	
	line_size = line_vector.size();

	circle_byte = circle_size * sizeof(DiploidCircle);
	point_byte = point_size * sizeof(DiploidPoint);
	box_byte = box_size * sizeof(DiploidBox);
	line_byte = line_size * sizeof(DiploidLine);
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

void DiploidEngineImpact::PushLine(DiploidLine line)
{
	line_vector.push_back(line);
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

void DiploidEngineImpact::PopBackLine()
{
	if (!line_vector.empty())
	{
		line_vector.pop_back();
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

void DiploidEngineImpact::DestoryLine()
{
	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			if ((line->impacted == true) && (line->destory == true))
			{
				line_vector.erase(line);
				line = line_vector.begin();
			}
		}
	}
}


void DiploidEngineImpact::ImpactCirclePoint()
{
	if (!point_vector.empty() || !circle_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
			{
				//�~����ʓ��ɂ�������
				if ((circle->position.x >= -200 - circle->position.x) && (circle->position.y >= -200 - circle->position.y) && (circle->position.x <= screen_size_x + circle->position.x) && (circle->position.y <= screen_size_y + circle->position.y))
				{
					//�_����ʓ��ɂ�������
					if ((point->position.x >= -200) && (point->position.y >= -200) && (point->position.x <= screen_size_x) && (point->position.y <= screen_size_y))
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
				//box����ʓ��ɂ�������
				if ((box->position.x >= -200) && (box->position.y >= -200) && (box->position.x + box->size.x <= screen_size_x) && (box->position.y + box->size.y <= screen_size_y))
				{
					//point����ʓ��ɂ�������
					if ((point->position.x >= -200) && (point->position.y >= -200) && (point->position.x <= screen_size_x) && (point->position.y <= screen_size_y))
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
	}
}

void DiploidEngineImpact::ImpactBoxBox()
{
	if (!box_vector.empty())
	{
		for (auto box_one = box_vector.begin(); box_one != box_vector.end(); ++box_one)
		{
			for (auto box_two = box_vector.begin(); box_two != box_vector.end(); ++box_two)
			{
				//���ʔԍ��������Ȃ�
				if (box_one->layer_number == box_two->layer_number)
				{
					if (box_one == box_two)//�����l�Ȃ�v�Z���Ȃ�
					{

					}
					else
					{
						//one����ʓ��ɂ�������
						if ((box_one->position.x >= -200) && (box_one->position.y >= -200) && (box_one->position.x + box_one->size.x <= screen_size_x) && (box_one->position.y + box_one->size.y <= screen_size_y))
						{
							//two����ʓ��ɂ�������
							if ((box_two->position.x >= -200) && (box_two->position.y >= -200) && (box_two->position.x + box_two->size.x <= screen_size_x) && (box_two->position.y + box_two->size.y <= screen_size_y))
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
				//���ʔԍ��������Ȃ�
				if (box->layer_number == circle->layer_number)
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
}

void DiploidEngineImpact::ImpactCircleLine()
{
	if (!line_vector.empty() || !circle_vector.empty())
	{
		//LINE
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			//Circle
			for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
			{
				//���ʔԍ��������Ȃ�
				if (line->layer_number == circle->layer_number)
				{
					if (HitCheck_Line_Sphere(line->Position_one, line->Position_two, circle->position, circle->size.z) == true)
					{
						line->impacted = true;
						circle->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactPointLine()
{
	if (!line_vector.empty() || !point_vector.empty())
	{
		//LINE
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			//POINT
			for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
			{
				//���ʔԍ��������Ȃ�
				if (point->layer_number == line->layer_number)
				{
					if (Segment_Point_MinLength(line->Position_one, line->Position_two, point->position) < 2)
					{
						line->impacted = true;
						point->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactLineLine()
{
	if (!line_vector.empty())
	{
		for (auto line_one = line_vector.begin(); line_one != line_vector.end(); ++line_one)
		{
			for (auto line_two = line_vector.begin(); line_two != line_vector.end(); ++line_two)
			{
				float x = 0, y = 0, r = 0;

				if (line_one == line_two)//�����l�Ȃ�v�Z���Ȃ�
				{
					//x = 0;
					//y = 0;
					//r = 0;
				}
				else if (Segment_Segment_MinLength(line_one->Position_one, line_one->Position_two, line_two->Position_one, line_two->Position_two) < 1)
				{
					//���ʔԍ��������Ȃ�
					if (line_one->layer_number == line_two->layer_number)
					{
						line_one->impacted = true;
						line_two->impacted = true;
					}
				}
			}
		}
	}
}

void DiploidEngineImpact::ImpactLineBox()
{
	if (!line_vector.empty() || !box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
			{
				//���ʔԍ��������Ȃ�
				if (box->layer_number == line->layer_number)
				{
					float hit_a, hit_b;

					VECTOR pos_a, pos_b, pos_c, pos_d;

					//����
					pos_a.x = box->position.x;
					pos_a.y = box->position.y;
					pos_a.z = 0.0f;

					//����
					pos_b.x = box->position.x;
					pos_b.y = box->position.y + box->size.y;
					pos_b.z = 0.0f;

					//�E��
					pos_c.x = box->position.x + box->size.x;
					pos_c.y = box->position.y;
					pos_c.z = 0.0f;

					//�E��
					pos_d.x = box->position.x + box->size.x;
					pos_d.y = box->position.y + box->size.y;
					pos_d.z = 0.0f;

					//�����蔻��
					hit_a = Segment_Triangle_MinLength(line->Position_one, line->Position_two, pos_a, pos_b, pos_c);
					hit_b = Segment_Triangle_MinLength(line->Position_one, line->Position_two, pos_d, pos_b, pos_c);


					if (hit_a < 1)
					{
						if (line->impacted == false)
						{
							line->impacted = true;
						}

						if (box->impacted == false)
						{
							box->impacted = true;
						}
					}
					
					if (hit_b < 1)
					{
						if (line->impacted == false)
						{
							line->impacted = true;
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

	//�����̍X�V����
	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			line->Update();//�A�j���A�v�f
		}
	}

	ImpactCirclePoint();//�~�Ɠ_�̏Փˌv�Z
	ImpactBoxPoint();//�l�p�Ɠ_�̏Փˌv�Z
	ImpactCircleCircle();//�~�Ɖ~�̏Փˌv�Z
	ImpactBoxBox();//�l�p�Ǝl�p�̏Փˌv�Z
	ImpactBoxCircle();//�l�p�Ɖ~�̏Փˌv�Z
	ImpactPointLine();//�_�Ɛ����̏Փ˔���
	ImpactCircleLine();//�~�Ɛ����̏Փ˔���
	ImpactLineLine();//�����Ɛ����̏Փ˔���
	ImpactLineBox();//�����Ǝl�p�̏Փ˔���
}

void DiploidEngineImpact::AutoNumber()
{
	//�e�z��̃J�E���g����ۑ�����ϐ�
	int box_count = 0;
	int point_count = 0;
	int circle_count = 0;
	int line_count = 0;

	//box
	for (auto count = box_vector.begin(); count != box_vector.end(); ++count)
	{
		count->number = box_count;//�I�u�W�F�N�g�ԍ���ύX
		box_count += 1;//�I�u�W�F�N�g�ԍ��𑫂��B
	}

	point_count = box_count;//box_count�̒l��point_count�Ɉ����p��

	//point
	for (auto count = point_vector.begin(); count != point_vector.end(); ++count)
	{
		count->number = point_count + box_count;//�I�u�W�F�N�g�ԍ���ύX
		point_count += 1;//�I�u�W�F�N�g�ԍ��𑫂��B
	}

	circle_count = point_count;//point_count�̒l��circle_count�Ɉ����p��

	//circle
	for (auto count = circle_vector.begin(); count != circle_vector.end(); ++count)
	{
		count->number = circle_count + box_count + point_count;//�I�u�W�F�N�g�ԍ���ύX
		circle_count += 1;//�I�u�W�F�N�g�ԍ��𑫂��B
	}

	line_count = circle_count;//point_count�̒l��circle_count�Ɉ����p��

	//line
	for (auto count = line_vector.begin(); count != line_vector.end(); ++count)
	{
		count->number = line_count + box_count + point_count + circle_count;//�I�u�W�F�N�g�ԍ���ύX
		line_count += 1;//�I�u�W�F�N�g�ԍ��𑫂��B
	}

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

	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			//�������q�b�g���Ă�����
			if (line->impacted == true)
			{
				line->impacted = false;
			}
		}
	}
}

void DiploidEngineImpact::Draw(bool wire, bool debug)
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

	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			//�������q�b�g���Ă�����
			if (line->impacted == true)
			{
				line->color = GetColor(255, 0, 0);
			}
			else
			{
				line->color = GetColor(0, 0, 255);
			}

			line->Draw(wire);
		}
	}

	if (debug == true)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "circle vector size : %.6f MB   objects : %d", circle_byte / 1000000, circle_size);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "point vector size : %.6f MB   objects : %d", point_byte / 1000000, point_size);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "box vector size : %.6f MB   objects ; %d", box_byte / 1000000, box_size);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "line vector size : %.6f MB   objects ; %d", line_byte / 1000000, line_size);
		DrawFormatString(0, 80, GetColor(255, 255, 255), "all vector size : %.6f MB   all object ; %d", (box_byte + point_byte + circle_byte + line_byte) / 1000000, box_size + point_size + circle_size + line_size);
	}
}

void DiploidEngineImpact::Destory()
{
	DestoryCircle();//�~���q�b�g���Ă�����~�z�񂩂�폜
	DestoryPoint();//�_���q�b�g���Ă�����_�z�񂩂�폜
	DestoryBox();//�l�p���q�b�g���Ă�����l�p�z�񂩂�폜
	DestoryLine();//�������q�b�g���Ă���������z�񂩂�폜
}


void DiploidEngineImpact::SetBoxPositionAnimation(int number, VECTOR move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{							  
				box->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationX(int number, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationY(int number, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->move_speed.y = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationZ(int number, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->move_speed.z = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetBoxPositionAnimation_Sreach_Object_Name(std::string name_tag, VECTOR move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->name_tag == name_tag)
			{
				box->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationX_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->name_tag == name_tag)
			{
				box->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationY_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->name_tag == name_tag)
			{
				box->move_speed.y = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionAnimationZ_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->name_tag == name_tag)
			{
				box->move_speed.z = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetCirclePositionAnimation(int number, VECTOR move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				circle->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetCirclePositionAnimationX(int number, float move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				circle->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetCirclePositionAnimationY(int number, float move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				circle->move_speed.y = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetCirclePositionAnimation_Sreach_Object_Name(std::string name_tag, VECTOR move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->name_tag == name_tag)
			{
				circle->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetCirclePositionAnimationX_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->name_tag == name_tag)
			{
				circle->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetCirclePositionAnimationY_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->name_tag == name_tag)
			{
				circle->move_speed.y = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetPointPositionAnimation(int number, VECTOR move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				point->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetPointPositionAnimationX(int number, float move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				point->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetPointPositionAnimationY(int number, float move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				point->move_speed.y = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetPointPositionAnimation_Sreach_Object_Name(std::string name_tag, VECTOR move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->name_tag == name_tag)
			{
				point->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetPointPositionAnimationX_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->name_tag == name_tag)
			{
				point->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineImpact::SetPointPositionAnimationY_Sreach_Object_Name(std::string name_tag, float move_speed)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->name_tag == name_tag)
			{
				point->move_speed.y = move_speed;
			}
		}
	}
}


void DiploidEngineImpact::SetBoxSizeAnimation(int number, VECTOR move_size)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->move_size = move_size;
			}
		}
	}
}

void DiploidEngineImpact::SetCircleSizeAnimation(int number, float move_size)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				circle->move_size.z = move_size;
			}
		}
	}
}


void DiploidEngineImpact::SetBoxPositionAdd(int number, VECTOR position)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->position.x += position.x;
				box->position.y += position.y;
				box->position.z += position.z;
			}
		}
	}
}

void DiploidEngineImpact::SetBoxPositionYAdd(int number, float position)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->position.y += position;
			}
		}
	}
}


void DiploidEngineImpact::SetBoxPosition(int number, VECTOR position)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				box->position.x = position.x;
				box->position.y = position.y;
				box->position.z = position.z;
			}
		}
	}
}


void DiploidEngineImpact::SetCirclePositionAdd(int number, VECTOR position)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				circle->position.x += position.x;
				circle->position.y += position.y;
				circle->position.z += position.z;
			}
		}
	}
}

void DiploidEngineImpact::SetPointPositionAdd(int number, VECTOR position)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				point->position.x += position.x;
				point->position.y += position.y;
				point->position.z += position.z;
			}
		}
	}
}


VECTOR DiploidEngineImpact::GetBoxCenterPosition(int number)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				return box->GetCenterPosition();
			}
		}
	}
}

VECTOR DiploidEngineImpact::GetCircleCenterPosition(int number)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				return circle->GetCenterPosition();
			}
		}
	}
}

VECTOR DiploidEngineImpact::GetPointPosition(int number)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				return point->position;
			}
		}
	}
}


int DiploidEngineImpact::GetEndBox()
{
	if (!box_vector.empty())
	{
		return box_vector.size();
	}

	return -1;
}

int DiploidEngineImpact::GetEndCircle()
{
	if (!circle_vector.empty())
	{
		return circle_vector.size();
	}

	return -1;
}

int DiploidEngineImpact::GetEndPoint()
{
	if (!point_vector.empty())
	{
		return point_vector.size();
	}

	return -1;
}

int DiploidEngineImpact::GetEndLine()
{
	if (!line_vector.empty())
	{
		return line_vector.size();
	}

	return -1;
}


int DiploidEngineImpact::GetMaxBoxNumber()
{
	size_t point_buffer = -1;
	size_t circle_buffer = -1;
	size_t line_buffer = -1;

	//box�z��
	if (!box_vector.empty())
	{
		if (box_vector.size() > point_vector.size())//�_�z��
		{
			point_buffer = box_vector.size();
		}

		if (box_vector.size() > circle_vector.size())//�~�z��
		{
			circle_buffer = box_vector.size();
		}

		if (box_vector.size() > line_vector.size())//���z��
		{
			line_buffer = box_vector.size();
		}

		//�_�z��Ɖ~�z��Ŕ�ׂ��ꍇ
		if (line_buffer && point_buffer && circle_buffer)
		{
			return box_vector.size();
		}
	}

	return -1;
}

int DiploidEngineImpact::GetMaxPointNumber()
{
	size_t box_buffer = -1;
	size_t circle_buffer = -1;
	size_t line_buffer = -1;

	//point�z��
	if (!point_vector.empty())
	{
		if (point_vector.size() > box_vector.size())//���z��
		{
			box_buffer = point_vector.size();
		}

		if (point_vector.size() > circle_vector.size())//�~�z��
		{
			circle_buffer = point_vector.size();
		}

		if (point_vector.size() > line_vector.size())//���z��
		{
			line_buffer = point_vector.size();
		}

		//�_�z��Ɖ~�z��Ŕ�ׂ��ꍇ
		if (line_buffer && box_buffer && circle_buffer)
		{
			return point_vector.size();
		}
	}
	return -1;
}

int DiploidEngineImpact::GetMaxCircleNumber()
{
	size_t box_buffer = -1;
	size_t point_buffer = -1;
	size_t line_buffer = -1;

	//point�z��
	//if (!point_vector.empty())
	{
		if (circle_vector.size() > box_vector.size())//���z��
		{
			box_buffer = circle_vector.size();
		}

		if (circle_vector.size() > point_vector.size())//�_�z��
		{
			point_buffer = circle_vector.size();
		}

		if (circle_vector.size() > line_vector.size())//���z��
		{
			line_buffer = circle_vector.size();
		}

		//�_�z��Ɖ~�z��Ŕ�ׂ��ꍇ
		if (line_buffer && box_buffer && point_buffer)
		{
			return circle_vector.size();
		}
	}

	return -1;
}

int DiploidEngineImpact::GetMaxLineNumber()
{
	size_t box_buffer = -1;
	size_t point_buffer = -1;
	size_t circle_buffer = -1;

	//point�z��
	//if (!point_vector.empty())
	{
		if (line_vector.size() > box_vector.size())//���z��
		{
			box_buffer = line_vector.size();
		}

		if (line_vector.size() > point_vector.size())//�_�z��
		{
			point_buffer = line_vector.size();
		}

		if (line_vector.size() > circle_vector.size())//�~�z��
		{
			circle_buffer = line_vector.size();
		}

		//�_�z��Ɖ~�z��Ŕ�ׂ��ꍇ
		if (circle_buffer && box_buffer && point_buffer)
		{
			return circle_vector.size();
		}
	}

	return -1;
}


int DiploidEngineImpact::GetMaxArrayNumber()
{
	//box�
	if ((GetMaxBoxNumber() > GetMaxPointNumber()) && (GetMaxBoxNumber() > GetMaxCircleNumber()) && (GetMaxBoxNumber() > GetMaxLineNumber()))
	{
		return GetMaxBoxNumber();
	}

	//circle�
	if ((GetMaxCircleNumber() > GetMaxBoxNumber()) && (GetMaxCircleNumber() > GetMaxPointNumber()) && (GetMaxCircleNumber() > GetMaxLineNumber()))
	{
		return GetMaxCircleNumber();
	}

	//point�
	if ((GetMaxPointNumber() > GetMaxBoxNumber()) && (GetMaxPointNumber() > GetMaxCircleNumber()) && (GetMaxPointNumber() > GetMaxLineNumber()))
	{
		return GetMaxPointNumber();
	}

	//line�
	if ((GetMaxLineNumber() > GetMaxBoxNumber()) && (GetMaxLineNumber() > GetMaxCircleNumber()) && (GetMaxLineNumber() > GetMaxPointNumber()))
	{
		return GetMaxLineNumber();
	}

	return -1;
}

int DiploidEngineImpact::GetAllArraySize()
{
	return box_vector.size() + point_vector.size() + circle_vector.size() + line_vector.size();
}


int DiploidEngineImpact::GetBoxNumber(int target)
{
	std::vector<DiploidBox>::iterator box_begin = box_vector.begin() + target;

	if (!box_vector.empty())
	{
		return box_begin->number;
	}
}

int DiploidEngineImpact::GetPointNumber(int target)
{
	std::vector<DiploidPoint>::iterator point_begin = point_vector.begin() + target;

	if (!point_vector.empty())
	{
		return point_begin->number;
	}
}

int DiploidEngineImpact::GetCircleNumber(int target)
{
	std::vector<DiploidCircle>::iterator circle_begin = circle_vector.begin() + target;

	if (!circle_vector.empty())
	{
		return circle_begin->number;
	}
}

int DiploidEngineImpact::GetLineNumber(int target)
{
	std::vector<DiploidLine>::iterator line_begin = line_vector.begin() + target;

	if (!line_vector.empty())
	{
		return line_begin->number;
	}
}


void DiploidEngineImpact::SetBoxNumber(int target_number, int set_number)
{
	std::vector<DiploidBox>::iterator itr = box_vector.begin() + target_number;//box�C�e���[�^
	
	itr->number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetCircleNumber(int target_number, int set_number)
{
	std::vector<DiploidCircle>::iterator itr = circle_vector.begin() + target_number;//circle�C�e���[�^

	itr->number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetPointNumber(int target_number, int set_number)
{
	std::vector<DiploidPoint>::iterator itr = point_vector.begin() + target_number;//point�C�e���[�^

	itr->number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetLineNumber(int target_number, int set_number)
{
	std::vector<DiploidLine>::iterator itr = line_vector.begin() + target_number;//line�C�e���[�^

	itr->number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetNumber(int number)
{

}


int DiploidEngineImpact::GetBoxLayerNumber(int target)
{
	std::vector<DiploidBox>::iterator box_begin = box_vector.begin() + target;

	if (!box_vector.empty())
	{
		return box_begin->layer_number;
	}
}

int DiploidEngineImpact::GetPointLayerNumber(int target)
{
	std::vector<DiploidPoint>::iterator point_begin = point_vector.begin() + target;

	if (!point_vector.empty())
	{
		return point_begin->layer_number;
	}
}

int DiploidEngineImpact::GetCircleLayerNumber(int target)
{
	std::vector<DiploidCircle>::iterator circle_begin = circle_vector.begin() + target;

	if (!circle_vector.empty())
	{
		return circle_begin->layer_number;
	}
}

int DiploidEngineImpact::GetLineLayerNumber(int target)
{
	std::vector<DiploidLine>::iterator line_begin = line_vector.begin() + target;

	if (!line_vector.empty())
	{
		return line_begin->layer_number;
	}
}


void DiploidEngineImpact::SetBoxLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidBox>::iterator itr = box_vector.begin() + target_number;//box�C�e���[�^

	itr->layer_number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetCircleLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidCircle>::iterator itr = circle_vector.begin() + target_number;//circle�C�e���[�^

	itr->layer_number = set_number;//�V�����l����

}

void DiploidEngineImpact::SetPointLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidPoint>::iterator itr = point_vector.begin() + target_number;//point�C�e���[�^

	itr->layer_number = set_number;//�V�����l����
}

void DiploidEngineImpact::SetLineLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidLine>::iterator itr = line_vector.begin() + target_number;//line�C�e���[�^

	itr->layer_number = set_number;//�V�����l����
}


bool DiploidEngineImpact::GetBoxImpactFlag(int number)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{
				return box->impacted;
			}
		}
	}

	return false;
}

bool DiploidEngineImpact::GetPointImpactFlag(int number)
{
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			if (point->number == number)
			{
				return point->impacted;
			}
		}
	}

	return false;
}

bool DiploidEngineImpact::GetCircleImpactFlag(int number)
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			if (circle->number == number)
			{
				return circle->impacted;
			}
		}
	}

	return false;
}

bool DiploidEngineImpact::GetLineImpactFlag(int number)
{
	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			if (line->number == number)
			{
				return line->impacted;
			}
		}
	}

	return false;
}


bool DiploidEngineImpact::GetBoxImpactFlag_Sreach_Name_Tag(std::string name_tag)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->name_tag == name_tag)
			{
				return box->impacted;
			}
		}
	}

	return false;
}


DiploidBox DiploidEngineImpact::GetBoxInfo(int number)
{
	if (!box_vector.empty())
	{
		for (int count = 0; count != box_vector.size(); ++count)
		{
			if (box_vector[count].number == number)
			{
				return box_vector[count];
			}
		}
	}
}