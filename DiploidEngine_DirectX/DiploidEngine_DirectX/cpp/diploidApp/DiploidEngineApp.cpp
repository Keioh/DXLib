#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	for (int n = 0; n < 10000; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 50.0f);
		circle.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		circle.fill = true;
		circle.mouse_point_move_flag = false;

		circle.move_size = 0.01f;
		circle.origin_size = GetRand(10);
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{
	diploidEngineImpact.Updata();

	//object.Update(VGet(0.0f, 0.0f, 0.0f), 0.0f, true);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();

	//object.Draw();
}
