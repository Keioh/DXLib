#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{		
	box.Init(VGet(200, 1000, 0), VGet(500, 300, 0), GetColor(255, 255, 255));
	box.SetFill(true);
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	input.Update();
	
	if (collision.BoxAndTouchCollisionUpdate(&box, input.GetTouchPositionX(), input.GetTouchPositionY()) == true)
	{			
		if (input.GetReleaseTouch() == true)
		{
			box.SetColor(GetColor(255, 255, 255));
		}
		else
		{
			box.SetColor(GetColor(255, 0, 0));
		}
	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));
	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	box.Draw();

	SetFontSize(50);

	DrawFormatStringF(0, 50, GetColor(255, 255, 255), "touch_release = %d", input.GetTouchReleaseFlag());
	DrawFormatStringF(0, 50 * 2, GetColor(255, 255, 255), "touch_x = %d", input.GetTouchPositionX());
	DrawFormatStringF(0, 50 * 3, GetColor(255, 255, 255), "touch_y = %d", input.GetTouchPositionY());

}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクト(ver1.0)がある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}