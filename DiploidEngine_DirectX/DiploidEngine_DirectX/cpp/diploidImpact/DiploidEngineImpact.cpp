#include "diploidImpact\DiploidEngineImpact.h"

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
				//‰~‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
				if ((circle->position.x >= 0 - circle->position.x) && (circle->position.y >= 0 - circle->position.y) && (circle->position.x <= 1920 + circle->position.x) && (circle->position.y <= 1080 + circle->position.y))
				{
					//“_‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
					if ((point->position.x >= 0) && (point->position.y >= 0) && (point->position.x <= 1920) && (point->position.y <= 1080))
					{
						float x = 0, y = 0;

						x = (circle->position.x - point->position.x);
						y = (circle->position.y - point->position.y);

						if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(circle->size.z, 2))
						{
							//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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

				if (circle_one == circle_two)//“¯‚¶’l‚È‚çŒvŽZ‚µ‚È‚¢
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
						//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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
				//box‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
				if ((box->position.x >= 0) && (box->position.y >= 0) && (box->position.x + box->size.x <= 1920) && (box->position.y + box->size.y <= 1080))
				{
					//point‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
					if ((point->position.x >= 0) && (point->position.y >= 0) && (point->position.x <= 1920) && (point->position.y <= 1080))
					{

						if ((box->position.x <= point->position.x) && ((box->position.x + box->size.x) >= point->position.x))
						{
							if ((box->position.y <= point->position.y) && ((box->position.y + box->size.y) >= point->position.y))
							{
								//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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
				//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
				if (box_one->layer_number == box_two->layer_number)
				{
					if (box_one == box_two)//“¯‚¶’l‚È‚çŒvŽZ‚µ‚È‚¢
					{

					}
					else
					{
						//one‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
						if ((box_one->position.x >= 0) && (box_one->position.y >= 0) && (box_one->position.x + box_one->size.x <= 1920) && (box_one->position.y + box_one->size.y <= 1080))
						{
							//two‚ª‰æ–Ê“à‚É‚ ‚Á‚½‚ç
							if ((box_two->position.x >= 0) && (box_two->position.y >= 0) && (box_two->position.x + box_two->size.x <= 1920) && (box_two->position.y + box_two->size.y <= 1080))
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
				//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
				if (box->layer_number == circle->layer_number)
				{
					//y•ûŒü‚Ö‚Ì–ÊÏŒvŽZ(A)
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

					//X•ûŒü‚Ö‚Ì–ÊÏŒvŽZ(B)
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

					//BOX¶ã‚Ì–ÊÏŒvŽZ(C)
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

					//BOX‰Eã‚Ì–ÊÏŒvŽZ(D)
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

					//BOX‰E‰º‚Ì–ÊÏŒvŽZ(E)
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

					//BOX¶‰º‚Ì–ÊÏŒvŽZ(F)
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
				//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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
				//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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

				if (line_one == line_two)//“¯‚¶’l‚È‚çŒvŽZ‚µ‚È‚¢
				{
					//x = 0;
					//y = 0;
					//r = 0;
				}
				else if (Segment_Segment_MinLength(line_one->Position_one, line_one->Position_two, line_two->Position_one, line_two->Position_two) < 1)
				{
					//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
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
				//Ž¯•Ê”Ô†‚ª“¯‚¶‚È‚ç
				if (box->layer_number == line->layer_number)
				{
					float hit_a, hit_b;

					VECTOR pos_a, pos_b, pos_c, pos_d;

					//¶ã
					pos_a.x = box->position.x;
					pos_a.y = box->position.y;
					pos_a.z = 0.0f;

					//¶‰º
					pos_b.x = box->position.x;
					pos_b.y = box->position.y + box->size.y;
					pos_b.z = 0.0f;

					//‰Eã
					pos_c.x = box->position.x + box->size.x;
					pos_c.y = box->position.y;
					pos_c.z = 0.0f;

					//‰E‰º
					pos_d.x = box->position.x + box->size.x;
					pos_d.y = box->position.y + box->size.y;
					pos_d.z = 0.0f;

					//“–‚½‚è”»’è
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
	//‰~‚ÌXVˆ—
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			circle->Update();//ƒAƒjƒƒAƒvƒf
		}
	}

	//“_‚ÌXVˆ—
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			point->Update();//ƒAƒjƒƒAƒvƒf
		}
	}

	//ŽlŠp‚ÌXVˆ—
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			box->Update();//ƒAƒjƒƒAƒvƒf
		}
	}

	//ü•ª‚ÌXVˆ—
	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			line->Update();//ƒAƒjƒƒAƒvƒf
		}
	}

	ImpactCirclePoint();//‰~‚Æ“_‚ÌÕ“ËŒvŽZ
	ImpactBoxPoint();//ŽlŠp‚Æ“_‚ÌÕ“ËŒvŽZ
	ImpactCircleCircle();//‰~‚Æ‰~‚ÌÕ“ËŒvŽZ
	ImpactBoxBox();//ŽlŠp‚ÆŽlŠp‚ÌÕ“ËŒvŽZ
	ImpactBoxCircle();//ŽlŠp‚Æ‰~‚ÌÕ“ËŒvŽZ
	ImpactPointLine();//“_‚Æü•ª‚ÌÕ“Ë”»’è
	ImpactCircleLine();//‰~‚Æü•ª‚ÌÕ“Ë”»’è
	ImpactLineLine();//ü•ª‚Æü•ª‚ÌÕ“Ë”»’è
	ImpactLineBox();//ü•ª‚ÆŽlŠp‚ÌÕ“Ë”»’è
}

void DiploidEngineImpact::Init()
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//‰~‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//“_‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//ŽlŠp‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//ü•ª‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
			if (line->impacted == true)
			{
				line->impacted = false;
			}
		}
	}
}

void DiploidEngineImpact::Draw(bool wire, bool debug)
{
	GetSize();//Še”z—ñ‚Ì‘å‚«‚³‚ðŽæ“¾

	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//‰~‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//“_‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//ŽlŠp‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
			//ü•ª‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç
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
	DestoryCircle();//‰~‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç‰~”z—ñ‚©‚çíœ
	DestoryPoint();//“_‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚ç“_”z—ñ‚©‚çíœ
	DestoryBox();//ŽlŠp‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚çŽlŠp”z—ñ‚©‚çíœ
	DestoryLine();//ü•ª‚ªƒqƒbƒg‚µ‚Ä‚¢‚½‚çü•ª”z—ñ‚©‚çíœ
}

void DiploidEngineImpact::SetBoxAnimation(int number, VECTOR move_speed, VECTOR move_size)
{
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			if (box->number == number)
			{							  
				box->move_speed = move_speed;
				box->move_size = move_size;
			}
		}
	}
}