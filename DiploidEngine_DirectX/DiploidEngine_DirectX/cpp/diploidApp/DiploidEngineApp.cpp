#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	//マウスオブジェクト
	circle.Init(VGet(0, 0, 0), 30);
	circle.mouse_point_move_flag = true;
	//diploidEngineImpact.PushCircle(circle);

	for (int n = 0; n < 5; n++)
	{
		circle.Init(VGet(WindowSize().x / 2 + n * 50, WindowSize().y / 2, 0), 30);
		circle.mouse_point_move_flag = false;
		//circle.destory = true;
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{
	//diploidEngineImpact.DestoryCircle();
	diploidEngineImpact.Updata();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();
}