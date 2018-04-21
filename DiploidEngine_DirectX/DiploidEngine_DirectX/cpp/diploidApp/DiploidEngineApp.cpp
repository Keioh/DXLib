#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	for (int n = 0; n < 10000; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), GetRand(25));
		circle.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		circle.fill = true;
		
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{
	//diploidEngineImpact.AnimeUpdata(0.0f,0.0f, VGet(0,0,0.05f));
	diploidEngineImpact.ImpactUpdata();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();
}