#include "Level01.h"

void Level01::init()
{
	rand_power = 10;

	for (int n = 0; n < 4; n++)
	{
		random_pos[n] = { GetRand(80),GetRand(80),0 };
	}

	//初期化
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();

	//もともとスイッチがオンになっているところを1にする。
	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;

}

void Level01::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
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
	//object[0]にヒットしたとき
	if (object[0].switch_object.circle_collision.hit == true)
	{
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[0].pos.x, object[0].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[1]へ延びる線
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[2]へ延びる線

	}
	else
	{
		line_color[0] = 0;
	}

	//object[1]にヒットしたとき
	if (object[1].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[1].pos.x, object[1].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[2]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[3]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[0]へ延びる線

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

		DrawLineAA(object[2].pos.x, object[2].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[0]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[1]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[3]へ延びる線

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

		DrawLineAA(object[3].pos.x, object[3].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[1]へ延びる線
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[2]へ延びる線

	}
	else
	{
		line_color[3] = 0;
	}

}

void Level01::Draw(int pos_x, int pos_y, Filer config, bool wire)
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

	//ヒットしたときの処理
	Level01::HitEvent();

	//クリックしたときの処理
	Level01::ClickEvent();

	//描写
	object[0].Draw(pos_x + random_pos[0].x, pos_y + -random_pos[0].y, config, wire);//上
	object[1].Draw(pos_x - 50 + random_pos[1].x, pos_y + 100 + random_pos[1].y, config, wire);//左
	object[2].Draw(pos_x + 50 + random_pos[2].x, pos_y + 100 + random_pos[2].y, config, wire);//右
	object[3].Draw(pos_x + random_pos[3].x, pos_y + 200 + random_pos[3].y, config, wire);//下

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}