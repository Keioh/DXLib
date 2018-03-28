#include "world.h"

void World::Init()
{
	test1.Init();
	test2.Init();
	test3.Init();
	test4.Init();

	test1.building0_money = 200;
	test1.building0_time = 1;
}

void World::Load()
{
	test1.Load();
	test2.Load();
	test3.Load();
	test4.Load();

}

void World::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	test1.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.0f));
	test2.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.5f));
	test3.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(-0.5f, 0.1f, 0.0f));
	test4.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(-0.5f, 0.1f, 0.5f));

}

void World::Draw(MODE mode, bool wire)
{
	test1.Draw(mode, wire);
	test2.Draw(mode, wire);
	test3.Draw(mode, wire);
	test4.Draw(mode, wire);
}

void World::DrawUI(int window_x, int window_y, MODE mode, Filer config, bool wire)
{
	//どの地域を選択しているかの処理
	if (test1.object_click == 1)select = 1;
	if (test2.object_click == 1)select = 2;
	if (test3.object_click == 1)select = 3;
	if (test4.object_click == 1)select = 4;


	//表示するUIを変更
	switch (select)
	{
	case 1:
		test1.DrawUI(window_x, window_y, mode, config, wire);//UIを表示
		test2.window_flag = -1;//上記以外のUIを閉じる
		test3.window_flag = -1;//上記以外のUIを閉じる
		test4.window_flag = -1;//上記以外のUIを閉じる


		break;

	case 2:
		test1.window_flag = -1;
		test2.DrawUI(window_x, window_y, mode, config, wire);
		test3.window_flag = -1;
		test4.window_flag = -1;
		break;

	case 3:
		test1.window_flag = -1;//上記以外のUIを閉じる
		test2.window_flag = -1;//上記以外のUIを閉じる
		test3.DrawUI(window_x, window_y, mode, config, wire);//UIを表示		
		test4.window_flag = -1;//上記以外のUIを閉じる
		break;

	case 4:
		test1.window_flag = -1;
		test2.window_flag = -1;
		test3.window_flag = -1;
		test4.DrawUI(window_x, window_y, mode, config, wire);

	default:
		break;
	}
}