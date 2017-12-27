#include "LoadingScene.h"

void LoadingScene::Init()
{
	loading_scene_flag = 0;
	loading.inti();
}

void LoadingScene::LoadGraphics()
{
	loading.LoadGraphics();
}

void LoadingScene::DrawLoadingScene(int x, int y)
{
	while (loading_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetBackgroundColor(0, 0, 0);//背景色を黒に設定

		loading.DrawLoading(x, y);//ローディング画像を表示

		if (GetASyncLoadNum() == 0)//読み込みが終わったらループを抜ける。
		{
			SetBackgroundColor(255, 255, 255);//背景色を白に設定
			LoadingScene::Init();//初期化
			loading_scene_flag = 1;//ループを抜ける。
		}
	}
}
