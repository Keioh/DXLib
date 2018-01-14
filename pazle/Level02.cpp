#include "Level02.h"

void Level02::init()
{
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

void Level02::Draw(int pos_x, int pos_y, bool wire)
{
	//描写
	object[0].Draw(200, 150, wire);//上
	object[1].Draw(150, 250, wire);//中左
	object[2].Draw(250, 250, wire);//中右
	object[3].Draw(200, 350, wire);//下

	//二列目
	object[4].Draw(300, 150, wire);//上
	object[5].Draw(350, 250, wire);//中
	object[6].Draw(300, 350, wire);//下

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

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1) &&
		(object[4].object_switch_flag == -1) && (object[5].object_switch_flag == -1) && (object[6].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}