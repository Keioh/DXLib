#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	for (int a = 0; a <= 150; ++a)
	{
		test.box.Init(VGet(a * 3, 100, 0), VGet(50,50,0));
		test.box.number = a;

		diploidEngineImpact.PushBox(test.box);
	}

	for (int a = 0; a <= 180; ++a)
	{
		test.point.Init(VGet(a * 3,100,0));
		test.point.number = a + 150;

		diploidEngineImpact.PushPoint(test.point);
	}
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//diploidEngineImpact.SetPointAnimation(0, VGet(0, 0, 0));
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "test = %d", diploidEngineImpact.GetMaxArrayNumber());
}