#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{		

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	DrawCircleAA(GetWindowSize().x / 2, GetWindowSize().y / 2, 200, 64, GetColor(255, 255, 255));
}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクト(ver1.0)がある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}