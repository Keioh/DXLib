#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	//マウスオブジェクト
	point.Init(VGet(0, 0, 0));
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);

	for (int n = 0; n < 500; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(30) + 10);
		circle.move_size = 0.1f;
		//circle.mouse_point_move_flag = false;
		circle.destory = false;
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{	
	diploidEngineImpact.Updata();

	diploidEngineImpact.DestoryCircle();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();
}