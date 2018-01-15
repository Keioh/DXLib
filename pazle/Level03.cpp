#include "Level03.h"

void Level03::init()
{
	//初期化
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();
	object[4].init();
	object[5].init();
	object[6].init();
	object[7].init();
	object[8].init();

	//もともとスイッチがオンになっているところを1にする。
	//object[1].switch_object.switch_flag = 1;
	//object[2].switch_object.switch_flag = 1;
	//object[5].switch_object.switch_flag = 1;
	object[7].switch_object.switch_flag = 1;
	object[8].switch_object.switch_flag = 1;

}

void Level03::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
	object[4].Load();
	object[5].Load();
	object[6].Load();
	object[7].Load();
	object[8].Load();

}

void Level03::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	//描写
	object[0].Draw(pos_x, pos_y, config, wire);//上
	object[1].Draw(pos_x - 50, pos_y + 100, config,  wire);//左
	object[2].Draw(pos_x + 50, pos_y + 100, config, wire);//右
	object[3].Draw(pos_x, pos_y + 200, config, wire);//下

											 //二列目
	object[4].Draw(pos_x + 100, pos_y, config, wire);//上
	object[5].Draw(pos_x + 150, pos_y + 100, config, wire);//中
	object[6].Draw(pos_x + 100, pos_y + 200, config, wire);//下

	object[7].Draw(pos_x + 50, pos_y + 300, config, wire);//下
	object[8].Draw(pos_x + 50, pos_y - 100, config, wire);//上

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
			object[8].switch_object.switch_flag *= -1;
		}
		else if (object[0].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
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
			object[7].switch_object.switch_flag *= -1;
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
		}
	}

	//[4]をクリックした瞬間だけ処理する
	if (object[4].switch_object.mouse_input.click == true)
	{
		//[4]を押したときの処理
		if (object[4].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
		else if (object[4].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
	}

	//[5]をクリックした瞬間だけ処理する
	if (object[5].switch_object.mouse_input.click == true)
	{
		//[5]を押したときの処理
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
		//[6]を押したときの処理
		if (object[6].switch_object.switch_flag == 1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
		}
		else if (object[6].switch_object.switch_flag == -1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
		}
	}

	//[7]をクリックした瞬間だけ処理する
	if (object[7].switch_object.mouse_input.click == true)
	{
		//[7]を押したときの処理
		if (object[7].switch_object.switch_flag == 1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
		else if (object[7].switch_object.switch_flag == -1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
	}

	//[8]をクリックした瞬間だけ処理する
	if (object[8].switch_object.mouse_input.click == true)
	{
		//[8]を押したときの処理
		if (object[8].switch_object.switch_flag == 1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[0].switch_object.switch_flag *= -1;
		}
		else if (object[8].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
		}
	}


	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1) &&
		(object[4].object_switch_flag == -1) && (object[5].object_switch_flag == -1) && (object[6].object_switch_flag == -1) &&
		(object[7].object_switch_flag == -1) && (object[8].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}