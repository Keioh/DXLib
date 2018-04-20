#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	object.Init(VGet(0, 0, 0), 50.0f);
	object.color = GetColor(255, 255, 255);
	object.fill = true;
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{
	object.Update(VGet(0.0f, 0.0f, 0.0f), 0.0f, true);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	object.Draw();
}
