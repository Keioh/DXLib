#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{

	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);


	for (int n = 0; n < 10; n++)
	{	
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		pos.z = 0;

		//VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0),0.3f
		image.Init(pos, 0.3f);
		box.Init(VGet(pos.x - (150 * 0.3f), pos.y - (150 * 0.3f), 0), VGet(300 * 0.3f, 300 * 0.3f, 0));
		image.number += 1;
		box.number += 1;

		diploidEngineImpact.PushBox(box);
		diploidEngineLayer.PushTopGraphics(image);
	}
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{	

}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}