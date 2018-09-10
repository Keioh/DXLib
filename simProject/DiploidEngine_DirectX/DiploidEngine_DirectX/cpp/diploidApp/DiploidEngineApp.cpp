#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{
	test.Load();
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{
	//マウス設定
	mouse.layer_number = DIPLOID_ENGINE_GAMEOBJECT;
	mouse.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(mouse);

	//オブジェクト追加
	test.Init(VGet(1280 / 2,720/2,0));
	test.Push(diploidEngineImpact, diploidEngineLayer);
	//diploidEngineImpact.PushBox(test.region_01.GetBox());
	//diploidEngineLayer.PushBotGraphics(test.region_01.GetImage());

	//diploidEngineImpact.PushBox(test.region_02.GetBox());
	//diploidEngineLayer.PushBotGraphics(test.region_02.GetImage());

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{
	test.Updata(diploidEngineImpact, diploidEngineLayer, diploidEngineInput);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	test.Draw();
}


//以下未実装
DiploidObject DiploidEngineApp::FindObject(int layer_number, int number)//指定番号からオブジェクトを取得(オブジェクトを検索)
{
	DiploidObject diploid_object;


	return diploid_object;
}

DiploidBox DiploidEngineApp::FindImpactBOX(int layer_number, int number)//指定番号からオブジェクトを取得(衝突を検索)
{
	DiploidBox diploid_box;

	for (auto box = diploidEngineImpact.box_vector.begin(); box != diploidEngineImpact.box_vector.end(); box++)
	{
		if (box->layer_number == layer_number)
		{
			if (box->number == number)
			{
				diploid_box.position = box->position;
				diploid_box.layer_number = box->layer_number;
				diploid_box.number = box->number;
				diploid_box.anime_position = box->anime_position;
				diploid_box.anime_size = box->anime_size;
			}
		}
	}

	return diploid_box;
}

DiploidEngineImpact DiploidEngineApp::FindImpactCIRCLE(int layer_number, int number)//指定番号からオブジェクトを取得(衝突を検索)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
}

DiploidEngineImpact DiploidEngineApp::FindImpactPOINT(int layer_number, int number)//指定番号からオブジェクトを取得(衝突を検索)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
}

DiploidEngineLayer DiploidEngineApp::FindImageTOP(int layer_number, int number)//指定番号からオブジェクトを取得(画像を検索)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}

DiploidEngineLayer DiploidEngineApp::FindImageMID(int layer_number, int number)//指定番号からオブジェクトを取得(画像を検索)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}

DiploidEngineLayer DiploidEngineApp::FindImageBOT(int layer_number, int number)//指定番号からオブジェクトを取得(画像を検索)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}