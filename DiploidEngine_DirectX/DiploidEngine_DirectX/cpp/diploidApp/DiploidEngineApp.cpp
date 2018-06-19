#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{	
	for (int n = 0; n < 100; n++)
	{
		image.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 0.3f);
		//image.scale = 1.0f;
		image.move_angle = DX_PI / 180 * 1;
		//image.move_size = 0.1f;
		//image.mouse_point_move_flag = true;
		diploidEngineLayer.PushTopGraphics(image);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{	
	//diploidEngineImpact.Updata();
	diploidEngineLayer.Updata();
	//image.Updata();

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//diploidEngineImpact.Draw();
	diploidEngineLayer.Draw();
	//image.Draw();
}