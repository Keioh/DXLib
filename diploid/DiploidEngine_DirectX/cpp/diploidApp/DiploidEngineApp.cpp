#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	map.Load();//マップのロード
	ui.Load();
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	input.Init();//インプットの初期化

	map.Init(VGet(0, 0, 0));//マップの初期化

	ui.Init(VGet(0, 128, 0), 0.2f);
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	input.Update();//インプットの更新

	map.Updata(&input);//マップのアップデート

	//タイル情報を得る
	if (map.GetHitFildInfomation().GetHit() == true)
	{
		ui_info_type = map.GetHitFildInfomation().GetTerrainType();
	}
	else
	{
		ui_info_type = TERRAIN_TYPE_NOTHING;
	}

	//選択したマップから情報を得る
	if (map.GetClickedFildInfomation().GetClick() == 1)//マップのどこかをクリックしていたら
	{

		//自拠点が建っていた時のUIフラグを立てる
		if (map.GetClickedFildInfomation().GetBuildingType() == BUILDING_TYPE_MY_BASE)
		{
			ui_type = UI_MY_BASE;//自拠点UIの表示フラグを立てる
		}
		else
		{
			ui_type = UI_NO_SELECTED;
			ui.ResetFlag();//コマンドフラグを全てリセット
		}

		//UI_NO_SELECTEDでなければ
		if (ui_type > UI_NO_SELECTED)
		{
			//UIの更新
			ui.Updata(&input);
		}

		//UIにカーソルがあっていた時にマップを選択したないようにする処理
		if (ui.GetHit() == true)
		{
			map.SetCollisionActiveFlag(false);
		}
		else
		{
			map.SetCollisionActiveFlag(true);
		}
	}
	else
	{
		//どこもクリックしていない
		ui_type = UI_NO_SELECTED;
		ui.ResetFlag();//コマンドフラグを全てリセット
	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	bool debug = true;

	map.Draw(true, debug);//マップの描画

	//UIの表示
	if (ui_type == UI_MY_BASE)//自拠点用UI
	{
		ui.Draw(true, debug);
	}

	//選択したタイルの情報(仮)
	if (ui_info_type == TERRAIN_TYPE_GRASS)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);
		DrawString(10, 5, "地形タイプ : 草原", GetColor(0, 0, 0));
	}

	if (ui_info_type == TERRAIN_TYPE_ROCKS)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);

		DrawString(10, 5, "地形タイプ : 岩石", GetColor(0, 0, 0));
	}

	if (ui_info_type == TERRAIN_TYPE_MOUNTAIN)
	{
		DrawBoxAA(0, 0, 200, 30, GetColor(200, 200, 200), TRUE);

		DrawString(10, 5, "地形タイプ : 山岳", GetColor(0, 0, 0));
	}

}

void DiploidEngineApp::Destory()//ループ中に削除したいオブジェクトがある場合はここで削除処理を書く。
{

}

void DiploidEngineApp::End()//engine終了前処理。
{

}