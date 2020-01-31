#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	test.circle.Init(VGet(GetWindowSize().x / 2, GetWindowSize().y / 2, 0.0f), 50.0f, GetColor(255, 255, 255), FALSE);
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	anime += 0.5f;

	test.circle.SetRadius(anime);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	test.circle.Draw();
}

void DiploidEngineApp::End()//engine終了前処理。
{

}