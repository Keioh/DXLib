#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータなど)
{	

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	test.box.Init(VGet(100, 250, 0), VGet(150, 250, 0));
	test.box.mouse_point_move_flag = false;
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	test.box.Update();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	test.box.Draw();

}
