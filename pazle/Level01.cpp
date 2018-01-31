#include "Level01.h"

void Level01::init()
{
	line_color_flag = false;
	clear_flag = false;
	anime_alph = 255;
	rand_power = 10;
	line_anime = 0;
	timer = 0;

	for (int n = 0; n < 4; n++)
	{
		random_pos[n] = { GetRand(80),GetRand(80), 0 };

		//初期化
		object[n].init();
		box_number[n] = 0;
	}

	triangle_number = 3;

	//もともとスイッチがオンになっているところを1にする。
	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;

}

void Level01::Load()
{
	for (int n = 0; n < 4; n++)
	{
		object[n].Load();
	}
}

void Level01::ClickEvent()
{
	//以下ボタン押したときの処理
	//[0]をクリックした瞬間だけ処理する
	if (object[0].switch_object.mouse_input.click == true)
	{
		//[0]を押したときの処理
		if (object[0].switch_object.switch_flag == 1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
		else if (object[0].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
	}

	//[1]をクリックした瞬間だけ処理する
	if (object[1].switch_object.mouse_input.click == true)
	{
		//[1]を押したときの処理
		if (object[1].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
		else if (object[1].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
	}

	//[2]をクリックした瞬間だけ処理する
	if (object[2].switch_object.mouse_input.click == true)
	{
		//[2]を押したときの処理
		if (object[2].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
		else if (object[2].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
	}

	//[3]をクリックした瞬間だけ処理する
	if (object[3].switch_object.mouse_input.click == true)
	{
		//[3]を押したときの処理
		if (object[3].switch_object.switch_flag == 1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
	}
}

void Level01::HitEvent()
{

	//色の上限値を設定して、それを超えないように処理
	for (int n = 0; n < 4; n++)
	{
		if (line_color[n] >= 250)
		{
			line_color[n] = 250;
			line_color_flag = true;
		}
		else if (line_color[n] <= 5)
		{
			line_color[n] = 5;
			line_color_flag = false;
		}
	}

	//色を変える処理
	if (line_color_flag == false)
	{
		for (int n = 0; n < 4; n++)
		{
			line_color[n] += 5;
		}
	}
	else if (line_color_flag == true)
	{
		for (int n = 0; n < 4; n++)
		{
			line_color[n] -= 5;
		}
	}

	//object[0]にヒットしたとき
	if (object[0].switch_object.circle_collision.hit == true)
	{
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[0].pos.x, object[0].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[0], line_color[0], line_color[0]), 5);//[1]へ延びる線
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[0], line_color[0], line_color[0]), 5);//[2]へ延びる線

	}
	else
	{
		line_color[0] = 0;//色を0で処理
	}

	//object[1]にヒットしたとき
	if (object[1].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[1].pos.x, object[1].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[1], line_color[1], line_color[1]), 5);//[2]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[1], line_color[1], line_color[1]), 5);//[3]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[1], line_color[1], line_color[1]), 5);//[0]へ延びる線

	}
	else
	{
		line_color[1] = 0;
	}

	//object[2]にヒットしたとき
	if (object[2].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[2].pos.x, object[2].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[2], line_color[2], line_color[2]), 5);//[0]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[2], line_color[2], line_color[2]), 5);//[1]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[2], line_color[2], line_color[2]), 5);//[3]へ延びる線

		
	}
	else
	{
		line_color[2] = 0;
	}

	//object[3]にヒットしたとき
	if (object[3].switch_object.circle_collision.hit == true)
	{
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[3].pos.x, object[3].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[3], line_color[3], line_color[3]), 5);//[1]へ延びる線
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[3], line_color[3], line_color[3]), 5);//[2]へ延びる線

	}
	else
	{
		line_color[3] = 0;
	}

}

bool Level01::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	for (int n = 0; n < 4; n++)
	{
		random_pos[n].x -= 5;
		random_pos[n].y -= 5;
		random_pos[n].z = 0;

		if (random_pos[n].x < 0)
		{
			random_pos[n].x = 0;
		}
		if (random_pos[n].y < 0)
		{
			random_pos[n].y = 0;
		}
	}

	//三角へとつながる線
	if ((box_number[0] + box_number[1] + box_number[2]) == triangle_number)
	{
		line_anime++;
		if (line_anime > 75)//線が三角へとつながったら
		{
			line_anime = 75;
		}
		DrawLineAA(pos_x + 200, pos_y + 100, pos_x + (200 + line_anime), pos_y + 100, GetColor(80, 80, 255), 6);
	}
	else
	{
		line_anime--;
		if (line_anime < 0)
		{
			line_anime = 0;
		}
	}

	//四角へとつながる線
	DrawLineAA(object[0].pos.x + random_pos[0].x, object[0].pos.y + -random_pos[0].y, pos_x - 16 + 150, pos_y, GetColor(255, 50, 50), 4);
	DrawLineAA(object[2].pos.x + random_pos[2].x, object[2].pos.y + -random_pos[2].y, pos_x - 16 + 150, pos_y + 100, GetColor(255, 50, 50), 4);
	DrawLineAA(object[3].pos.x + random_pos[3].x, object[3].pos.y + -random_pos[3].y, pos_x - 16 + 150, pos_y + 200, GetColor(255, 50, 50), 4);
	DrawLineAA(object[2].pos.x + random_pos[2].x, object[2].pos.y + -random_pos[2].y, object[1].pos.x + random_pos[1].x, object[1].pos.y + -random_pos[1].y, GetColor(255, 50, 50), 4);

	DrawLineAA(pos_x + 150, pos_y, pos_x + 200, pos_y, GetColor(255, 50, 50), 4);
	DrawLineAA(pos_x + 150, pos_y + 100, pos_x + 200, pos_y + 100, GetColor(255, 50, 50), 4);
	DrawLineAA(pos_x + 150, pos_y + 200, pos_x + 200, pos_y + 200, GetColor(255, 50, 50), 4);
	DrawLineAA(pos_x + 198, pos_y, pos_x + 198, pos_y + 200, GetColor(255, 50, 50), 4);

	//三角描写と文字描写
	DrawTriangleAA(pos_x + 300, pos_y + 75, pos_x + 300, pos_y + 125, pos_x + 265, pos_y + 100, GetColor(50, 200, 50), TRUE);
	DrawFormatString(pos_x + 285, pos_y + 92, GetColor(255, 255, 255), "%d", triangle_number);


	//ヒットしたときの処理
	Level01::HitEvent();

	//クリックしたときの処理
	Level01::ClickEvent();

	//四角(横の合計と四角描写と数字描写の処理)
	box_number[0] = object[0].number;
	box_number[1] = object[1].number + object[2].number;
	box_number[2] = object[3].number;

	DrawBox(pos_x - 16 + 150, pos_y - 16, pos_x + 16 + 150, pos_y + 16, GetColor(150, 150, 150), TRUE);
	DrawFormatString(pos_x + 150 - 4, pos_y - 8, GetColor(255, 255, 255), "%d", box_number[0]);

	DrawBox(pos_x - 16 + 150, pos_y - 16 + 100, pos_x + 16 + 150, pos_y + 16 + 100, GetColor(150, 150, 150), TRUE);
	DrawFormatString(pos_x + 150 - 4, pos_y - 8 + 100, GetColor(255, 255, 255), "%d", box_number[1]);

	DrawBox(pos_x - 16 + 150, pos_y - 16 + 200, pos_x + 16 + 150, pos_y + 16 + 200, GetColor(150, 150, 150), TRUE);
	DrawFormatString(pos_x + 150 - 4, pos_y - 8 + 200, GetColor(255, 255, 255), "%d", box_number[2]);


	//描写
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, anime_alph);
	object[0].Draw(pos_x + random_pos[0].x, pos_y + -random_pos[0].y, config, wire);//上
	object[1].Draw(pos_x - 50 + random_pos[1].x, pos_y + 100 + random_pos[1].y, config, wire);//左
	object[2].Draw(pos_x + 50 + random_pos[2].x, pos_y + 100 + random_pos[2].y, config, wire);//右
	object[3].Draw(pos_x + random_pos[3].x, pos_y + 200 + random_pos[3].y, config, wire);//下
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	//全部黒だったらクリアフラグを立てる
	if ((object[0].object_switch_flag == -1) &&
		(object[1].object_switch_flag == -1) &&
		(object[2].object_switch_flag == -1) &&
		(object[3].object_switch_flag == -1))
	{
		if (line_anime == 75)//線が三角形につながっていたら
		{
			return clear_flag = true;
		}
	}
}
