#include "Level02.h"

void Level02::init()
{
	rand_power = 10;

	//初期化
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();
	object[4].init();
	object[5].init();
	object[6].init();

	//もともとスイッチがオンになっているところを1にする。
	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;
	object[5].switch_object.switch_flag = 1;

}

void Level02::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
	object[4].Load();
	object[5].Load();
	object[6].Load();

}

void Level02::ClickEvent()
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
			object[4].switch_object.switch_flag *= -1;
		}
		else if (object[0].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
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
			object[4].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;

		}
		else if (object[2].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
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
			object[6].switch_object.switch_flag *= -1;
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
	}

	//[4]をクリックした瞬間だけ処理する
	if (object[4].switch_object.mouse_input.click == true)
	{
		//[3]を押したときの処理
		if (object[4].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
		else if (object[4].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
	}

	//[5]をクリックした瞬間だけ処理する
	if (object[5].switch_object.mouse_input.click == true)
	{
		//[3]を押したときの処理
		if (object[5].switch_object.switch_flag == 1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
		else if (object[5].switch_object.switch_flag == -1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
	}

	//[6]をクリックした瞬間だけ処理する
	if (object[6].switch_object.mouse_input.click == true)
	{
		//[3]を押したときの処理
		if (object[6].switch_object.switch_flag == 1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
		else if (object[6].switch_object.switch_flag == -1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
	}
}

void Level02::HitEvent()
{
	//object[0]にヒットしたとき
	if (object[0].switch_object.circle_collision.hit == true)
	{
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[0].pos.x, object[0].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[1]へ延びる線
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[2]へ延びる線
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[4]へ延びる線

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

		DrawLineAA(object[1].pos.x, object[1].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[1]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[2]へ延びる線
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[4]へ延びる線

	}
	else
	{
		line_color[1] = 0;
	}

	//object[2]にヒットしたとき
	if (object[2].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[2].pos.x, object[2].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[1]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[2]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]へ延びる線
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]へ延びる線

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
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[3].pos.x, object[3].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[1]へ延びる線
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[2]へ延びる線
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[4]へ延びる線

	}
	else
	{
		line_color[3] = 0;
	}

	//object[4]にヒットしたとき
	if (object[4].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[4].pos.x, object[4].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[1]へ延びる線
		DrawLineAA(object[4].pos.x, object[4].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[2]へ延びる線
		DrawLineAA(object[4].pos.x, object[4].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[4]へ延びる線

	}
	else
	{
		line_color[4] = 0;
	}

	//object[5]にヒットしたとき
	if (object[5].switch_object.circle_collision.hit == true)
	{
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[5].pos.x, object[5].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[1]へ延びる線
		DrawLineAA(object[5].pos.x, object[5].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[2]へ延びる線
		DrawLineAA(object[5].pos.x, object[5].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[4]へ延びる線

	}
	else
	{
		line_color[5] = 0;
	}

	//object[6]にヒットしたとき
	if (object[6].switch_object.circle_collision.hit == true)
	{
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[6].pos.x, object[6].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[1]へ延びる線
		DrawLineAA(object[6].pos.x, object[6].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[2]へ延びる線
		DrawLineAA(object[6].pos.x, object[6].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[4]へ延びる線

	}
	else
	{
		line_color[6] = 0;
	}

}

void Level02::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	//ヒットしたときの処理
	Level02::HitEvent();

	//クリックしたときの処理
	Level02::ClickEvent();

	//描写
	object[0].Draw(pos_x, pos_y, config, wire);//上
	object[1].Draw(pos_x - 50, pos_y + 100, config, wire);//左
	object[2].Draw(pos_x + 50, pos_y + 100, config, wire);//右
	object[3].Draw(pos_x, pos_y + 200, config, wire);//下

	//二列目
	object[4].Draw(pos_x + 100, pos_y, config, wire);//上
	object[5].Draw(pos_x + 150, pos_y + 100, config, wire);//中
	object[6].Draw(pos_x + 100, pos_y + 200, config, wire);//下

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1) &&
		(object[4].object_switch_flag == -1) && (object[5].object_switch_flag == -1) && (object[6].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}