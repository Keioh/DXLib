#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{
	
}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	dice_3d6n.Load();
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	dice_3d6n.Init(diploidEngineImpact, VGet(50, 720 / 4, 0));

	//マウスポインター用
	point.mouse_point_move_flag = true;
	point.number = OBJECT_NUMBER_POINT;
	diploidEngineImpact.PushPoint(point);
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	dice_3d6n.Update(diploidEngineImpact, diploidEngineInput);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	dice_3d6n.Draw(diploidEngineImpact);
}

void DiploidEngineApp::End()//engine終了前処理。
{

}