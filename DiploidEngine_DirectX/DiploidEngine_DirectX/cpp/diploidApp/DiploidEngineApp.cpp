#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	r = 50.0f;
}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{
	DrawCircleAA(WindowSize().x / 2, WindowSize().y / 2, r, 64, GetColor(255, 255, 255), TRUE);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}
