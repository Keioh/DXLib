#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	test.image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	for (int a = 0; a <= 10; ++a)
	{
		test.box.Init(VGet(a * 10, 300, 0), VGet(300, 300, 0));
		test.box.number = a;
		diploidEngineImpact.PushBox(test.box);

		test.image.Init(VGet((a * 10) + 150, 300 + 150, 0));
		test.image.number = a;
		diploidEngineLayer.PushTopGraphics(test.image);
	}

	/*
	for (int a = 0; a <= 10; ++a)
	{
		test.point.Init(VGet(300,100,0));
		test.point.number = a + 150;

		diploidEngineImpact.PushPoint(test.point);
	}
	*/

	//diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//diploidEngineImpact.SetPointAnimation(0, VGet(0, 0, 0));
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Box object number = %d", diploidEngineImpact.GetBoxNumber(10));
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Point object number = %d", diploidEngineImpact.GetPointNumber(0));

}