#include "GameScene.h"

GameScene::GameScene()
{
	GameScene::Init();
}

void GameScene::Init()
{
	game_scene_flag = 0;

	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();

}

void GameScene::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();

}

void GameScene::DrawGameScene(int window_x, int window_y, bool wire)
{
	SetBackgroundColor(255, 255, 255);

	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;

	while (game_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawString(0, 0, "GameScene", GetColor(0, 0, 0));

		object[0].Draw(200, 150, wire);//上
		object[1].Draw(150, 250, wire);//左
		object[2].Draw(250, 250, wire);//右
		object[3].Draw(200, 350, wire);//下

		//[0]をクリックした瞬間だけ処理する
		if (object[0].switch_object.mouse_input.click == true)
		{
			//[0]を押したときの処理
			if (object[0].switch_object.switch_flag == 1)
			{
				object[1].switch_object.switch_flag *= -1;
				object[2].switch_object.switch_flag *= -1;
			}
			else if(object[0].switch_object.switch_flag == -1)
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
			DrawString(0, 20, "Clear",GetColor(0, 0, 0) );
		}

	}
}