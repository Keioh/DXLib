#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	for (int n = 0; n < 5; n++)
	{
		object.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		object.position.x = (WindowSize().x / 2) + (n * 30);
		object.position.y = (WindowSize().y / 2);
		object.fill = FALSE;
		object.size.z = 100;
		object.thickness = 15;
		diploidEngineLayer.PushBackTopObject_circle(object);
	}

}

void DiploidEngineApp::Update()//アニメーションなど連続して行いたい処理。
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	diploidEngineLayer.DrawLayerObject();//レイヤーシステムにあるオブジェクトを描写
}
