#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	dice_1.image.Load("texter/dice/dice_1.png");
	dice_2.image.Load("texter/dice/dice_2.png");
	dice_3.image.Load("texter/dice/dice_3.png");
	dice_4.image.Load("texter/dice/dice_4.png");
	dice_5.image.Load("texter/dice/dice_5.png");
	dice_6.image.Load("texter/dice/dice_6.png");

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	dice_1.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_2.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_3.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_4.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_5.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_6.image.Init(VGet(100, 720 / 4, 0), 4.f);

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//dice_1.image.Draw();
	//dice_2.image.Draw();
	//dice_3.image.Draw();
	//dice_4.image.Draw();
	//dice_5.image.Draw();
	dice_6.image.Draw();

}

void DiploidEngineApp::End()//engine終了前処理。
{

}