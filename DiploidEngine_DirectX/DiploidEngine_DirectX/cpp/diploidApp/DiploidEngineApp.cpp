#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	box.Init(VGet(0, 0, 0), VGet(200, 100, 0));
	box.mouse_point_move_flag = true;
	box.color = GetColor(255, 255, 255);
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{	
	//diploidEngineImpact.Updata();

	box.Update();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//diploidEngineImpact.Draw();

	box.Draw();
}