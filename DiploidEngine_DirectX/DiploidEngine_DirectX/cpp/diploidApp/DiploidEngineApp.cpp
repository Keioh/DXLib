#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	for (int n = 0; n < 1000; n++)
	{	
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0),0.1f);
		image.move_angle = DX_PI / 180 * (GetRand(4)+1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushTopGraphics(image);
	}

	for (int n = 0; n < 1000; n++)
	{
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 0.2f);
		image.move_angle = DX_PI / 180 * (GetRand(4) + 1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushMidGraphics(image);
	}

	for (int n = 0; n < 1000; n++)
	{
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 0.3f);
		image.move_angle = DX_PI / 180 * (GetRand(4) + 1);
		image.destory = GetRand(1);

		diploidEngineLayer.PushBotGraphics(image);
	}
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{	

}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}