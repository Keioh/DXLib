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
				float x = 0, y = 0;

				x = (circle->position.x - point->position.x);
				y = (circle->position.y - point->position.y);

				if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(circle->size.z, 2))
				{
					//識別番号が同じなら
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

				if (circle_one == circle_two)//同じ値なら計算しない
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
						//識別番号が同じなら
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
						//識別番号が同じなら
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
			for (auto box_two = box_vector.begin(); box_two != box_vector.end(); ++box_two)
			{
				//識別番号が同じなら
				if (box_one->layer_number == box_two->layer_number)
				{
					if (box_one == box_two)//同じ値なら計算しない
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
				//識別番号が同じなら
				if (box->layer_number == circle->layer_number)
				{
					//y方向への面積計算(A)
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

					//X方向への面積計算(B)
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

					//BOX左上の面積計算(C)
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

					//BOX右上の面積計算(D)
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

					//BOX右下の面積計算(E)
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

					//BOX左下の面積計算(F)
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
				//識別番号が同じなら
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
				//識別番号が同じなら
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

				if (line_one == line_two)//同じ値なら計算しない
				{
					//x = 0;
					//y = 0;
					//r = 0;
				}
				else if (Segment_Segment_MinLength(line_one->Position_one, line_one->Position_two, line_two->Position_one, line_two->Position_two) < 1)
				{
					//識別番号が同じなら
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
				//識別番号が同じなら
				if (box->layer_number == line->layer_number)
				{
					float hit_a, hit_b;

					VECTOR pos_a, pos_b, pos_c, pos_d;

					//左上
					pos_a.x = box->position.x;
					pos_a.y = box->position.y;
					pos_a.z = 0.0f;

					//左下
					pos_b.x = box->position.x;
					pos_b.y = box->position.y + box->size.y;
					pos_b.z = 0.0f;

					//右上
					pos_c.x = box->position.x + box->size.x;
					pos_c.y = box->position.y;
					pos_c.z = 0.0f;

					//右下
					pos_d.x = box->position.x + box->size.x;
					pos_d.y = box->position.y + box->size.y;
					pos_d.z = 0.0f;

					//当たり判定
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
	//円の更新処理
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			circle->Update();//アニメアプデ
		}
	}

	//点の更新処理
	if (!point_vector.empty())
	{
		for (auto point = point_vector.begin(); point != point_vector.end(); ++point)
		{
			point->Update();//アニメアプデ
		}
	}

	//四角の更新処理
	if (!box_vector.empty())
	{
		for (auto box = box_vector.begin(); box != box_vector.end(); ++box)
		{
			box->Update();//アニメアプデ
		}
	}

	//線分の更新処理
	if (!line_vector.empty())
	{
		for (auto line = line_vector.begin(); line != line_vector.end(); ++line)
		{
			line->Update();//アニメアプデ
		}
	}

	ImpactCirclePoint();//円と点の衝突計算
	ImpactBoxPoint();//四角と点の衝突計算
	ImpactCircleCircle();//円と円の衝突計算
	ImpactBoxBox();//四角と四角の衝突計算
	ImpactBoxCircle();//四角と円の衝突計算

	ImpactPointLine();//点と線分の衝突判定
	ImpactCircleLine();//円と線分の衝突判定
	ImpactLineLine();//線分と線分の衝突判定
	ImpactLineBox();//線分と四角の衝突判定
}

void DiploidEngineImpact::Init()
{
	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//円がヒットしていたら
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
			//点がヒットしていたら
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
			//四角がヒットしていたら
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
			//線分がヒットしていたら
			if (line->impacted == true)
			{
				line->impacted = false;
			}
		}
	}
}

void DiploidEngineImpact::Draw(bool wire)
{
	GetSize();//各配列の大きさを取得

	if (!circle_vector.empty())
	{
		for (auto circle = circle_vector.begin(); circle != circle_vector.end(); ++circle)
		{
			//円がヒットしていたら
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
			//点がヒットしていたら
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
			//四角がヒットしていたら
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
			//線分がヒットしていたら
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

	DrawFormatString(0, 0, GetColor(255, 255, 255), "circle vector size : %.6f MB   objects : %d", circle_byte / 1000000, circle_size);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "point vector size : %.6f MB   objects : %d", point_byte / 1000000, point_size);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "box vector size : %.6f MB   objects ; %d", box_byte / 1000000, box_size);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "line vector size : %.6f MB   objects ; %d", line_byte / 1000000, line_size);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "all vector size : %.6f MB   all object ; %d", (box_byte + point_byte + circle_byte + line_byte) / 1000000, box_size + point_size + circle_size + line_size);
}

void DiploidEngineImpact::Destory()
{
	DestoryCircle();//円がヒットしていたら円配列から削除
	DestoryPoint();//点がヒットしていたら点配列から削除
	DestoryBox();//四角がヒットしていたら四角配列から削除
	DestoryLine();//線分がヒットしていたら線分配列から削除
}