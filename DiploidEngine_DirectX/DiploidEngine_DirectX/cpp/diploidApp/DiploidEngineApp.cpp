#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	box.Init(VGet(0, 0, 0), VGet(50,50,0));
	box.mouse_point_move_flag = true;
	diploidEngineImpact.PushBox(box);

	box.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), VGet(GetRand(100) + 50, GetRand(100) + 50, 0));
	box.mouse_point_move_flag = false;
	diploidEngineImpact.PushBox(box);
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{	
	diploidEngineImpact.Updata();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineImpact.Draw();
}