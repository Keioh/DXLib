#include "Level01.h"

void Level01::init()
{
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

void Level01::Draw(int pos_x, int pos_y, bool wire)
{
	//描写
	object[0].Draw(pos_x, pos_y, wire);//上
	object[1].Draw(pos_x - 50, pos_y + 100, wire);//左
	object[2].Draw(pos_x + 50, pos_y + 100, wire);//右
	object[3].Draw(pos_x, pos_y + 200, wire);//下

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

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}