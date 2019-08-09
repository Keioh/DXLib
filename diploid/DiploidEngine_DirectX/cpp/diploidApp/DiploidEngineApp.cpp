#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	dice.Load();
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	dice.Init(VGet(50, 50, 0));//ダイスオブジェクト初期化

	//マウスポイント
	object.point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(object.point);

	//ワンクリックボタン
	ui.OneClickButton_Init(VGet(50,50,0),VGet(50,50,0), "one_click_button");//初期化
	ui.OneClickButton_Push(diploidEngineImpact);//当たり判定の配列にデータをプッシュ

	diploidEngineImpact.AutoNumber();//オブジェクト番号を自動で振り分け
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//ワンクリックボタンの更新
	if (ui.OneClickButton_Update(diploidEngineImpact, diploidEngineInput) == true)
	{
		dice.Roll();
	}

	dice.Update();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//画像を使わない場合、BOXを描写することができます。(ただし、diploidEngineImpactによってOneClickButton_Drawのpositionは変動しません。)
	ui.OneClickButton_Draw();

	dice.Draw();
}

void DiploidEngineApp::End()//engine終了前処理。
{

}