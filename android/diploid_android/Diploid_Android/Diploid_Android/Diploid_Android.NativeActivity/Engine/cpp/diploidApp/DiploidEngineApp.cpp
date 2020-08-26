#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{		
	button.Init(VGet(400, 1000, 0), VGet(400, 300, 0));
	button.SetTouchFlag(true);
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	input.Update();

	button.Updata(&input);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{	
	DrawBox(0, 0, test.GetScreenSizeX(), test.GetScreenSizeY(), GetColor(100, 100, 100), TRUE);

	button.Draw(true, true);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "Touch Time:%d", button.GetTime());
	DrawFormatString(0, 120, GetColor(255, 255, 255), "ScreenSizeX:%d", test.GetScreenSizeX());
	DrawFormatString(0, 180, GetColor(255, 255, 255), "ScreenSizeY:%d", test.GetScreenSizeY());

}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクト(ver1.0)がある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}