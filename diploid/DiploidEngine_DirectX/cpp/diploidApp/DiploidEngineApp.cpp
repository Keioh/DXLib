#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	object.map.Load("texter/MAP/map.png", 10, 6);
	object.image.Load("texter/map_chip/イラスト4.png");
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	object.map.SetMapChipSize(128);
	object.map.Create();

	object.box.Init(VGet(1280 - (128 * 3), 720 - 128 -80, 0), VGet(64, 128, 0));
	object.box.name_tag = "player_box";
	object.box.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushBox(object.box);


	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))
		{
			object.box.Init(VGet(count->x * count->size, count->y * count->size, 0), VGet(count->size, count->size, 0));
			object.box.name_tag = "ground_box";
			object.box.layer_number = DIPLOID_LAYER_00;
			diploidEngineImpact.PushBox(object.box);

			object.image.Init(VGet(count->x * count->size + 64, count->y * count->size + 64, 0));
			object.image.name_tag = "ground_image";
			object.box.layer_number = DIPLOID_LAYER_00;
			diploidEngineLayer.PushMidGraphics(object.image);
		}
	}

	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//重力処理
	if (diploidEngineImpact.GetBoxImpactFlag_Sreach_Name_Tag("ground_box") == false)
	{
		diploidEngineImpact.SetBoxPositionAnimationY_Sreach_Object_Name("player_box", -object.physics.Gravity());
	}
	else
	{
		object.physics.GravityReset();
		diploidEngineImpact.SetBoxPositionAnimationY_Sreach_Object_Name("player_box", 0.0f);
	}

	//右移動
	if (diploidEngineInput.GetKey(KEY_INPUT_RIGHT) == true)
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", 3.0f);
	}
	//左移動
	else if (diploidEngineInput.GetKey(KEY_INPUT_LEFT) == true)
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", -3.0f);
	}
	else
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", 0.0f);
	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "center_val = %d", diploidEngineInput.GetWhellVolume());
	DrawFormatString(0, 20, GetColor(0, 0, 0), "scale_val = %.2f", diploidEngineInput.GetWhellVolume_Scale());

}

void DiploidEngineApp::End()//engine終了前処理。
{

}