#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータなど)
{	
	test.image.Load("texter/test.png");
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	test.box.Init(VGet(100, 250, 0), VGet(100,120,0));
	test.box.mouse_point_move_flag = false;
	test.box.number = 0;
	test.box.destory = false;

	test.image.Init();
	test.image.mouse_point_move_flag = false;
	test.image.number = 1;
	test.image.destory = false;

	diploidEngineImpact.PushBox(test.box);
	diploidEngineLayer.PushTopGraphics(test.image);

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//test.box.Update();
	//test.image.Updata();
	diploidEngineImpact.SetBoxAnimation(0, VGet(1, 0, 0), VGet(0, 1, 0));
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//test.box.Draw();
	//test.image.Draw();

}