#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{

}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	object->box.Init(VGet(100, 300, 0), VGet(20, 60, 0));
	object->box.name_tag = "test_object";
	object->box.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushBox(object->box);

	object->box.Init(VGet(100, 300, 0), VGet(20, 60, 0));
	object->box.name_tag = "test_object_1";
	object->box.layer_number = DIPLOID_LAYER_01;
	diploidEngineImpact.PushBox(object->box);

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	diploidEngineImpact.SetBoxPositionAnimation_Sreach_Object_Name("test_object", VGet(0.5f, 0, 0));
	diploidEngineImpact.SetBoxPositionAnimation_Sreach_Object_Name("test_object_1", VGet(0.1f, 0.1f, 0));

}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}