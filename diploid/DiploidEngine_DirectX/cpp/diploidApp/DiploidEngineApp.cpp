#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	object.box.SetSize(VGet(100, 100, 0));
	object.box.SetPosition(VGet(1280 / 2, 720 / 2, 0));
	object.box.SetColorGreen(150);
	object.box.SetColorRed(150);
	object.box.SetColorBlue(150);
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	object.box.DrawGraphics();
}

void DiploidEngineApp::End()//engine終了前処理。
{

}