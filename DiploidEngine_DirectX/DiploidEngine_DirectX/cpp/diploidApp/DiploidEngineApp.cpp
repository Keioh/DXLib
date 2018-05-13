#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	for (int n = 0; n < 1000; ++n)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(30) + 10);
		point.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0));
		box.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), VGet(GetRand(50) + 10, GetRand(50) + 10, 0));

		diploidEngineImpact.PushCircle(circle);
		diploidEngineImpact.PushPoint(point);
		diploidEngineImpact.PushBox(box);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{	
	diploidEngineImpact.Updata();

	diploidEngineImpact.PopBackCircle();
	diploidEngineImpact.PopBackPoint();
	diploidEngineImpact.PopBackBox();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();
}