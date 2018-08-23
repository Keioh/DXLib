#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	
	//image.Load("texter/test.png");

	//sound.Load("sound/01.wav");
}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{	
	/*
	
	point.mouse_point_move_flag = true;
	point.layer_number = DIPLOID_ENGINE_UI;
	diploidEngineImpact.PushPoint(point);
	
	for (int n = 0; n < 50; n++)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		//pos.z = 0;

		image.Init(pos, 0.3f);
		circle.Init(pos, 150 * 0.3f);

		//番号は同じのをなるべく使用しない。(オブジェクトを削除するときに同じ番号だといっしょに消えます)
		image.layer_number = DIPLOID_ENGINE_UI;
		image.number += 1;

		circle.layer_number = DIPLOID_ENGINE_UI;
		circle.number += 1;

		image.destory = circle.destory = true;

		diploidEngineImpact.PushCircle(circle);
		diploidEngineLayer.PushMidGraphics(image);
	}
	*/


	//DiploidObjectを使用した場合

	object.circle.Init(VGet(WindowSize().x / 2, 300, 0), 25);
	diploidEngineImpact.PushCircle(object.circle);
}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{	
	//sound.Play();
	diploidEngineInput.GetPressKey(KEY_INPUT_A);
	diploidEngineInput.GetPressMouse(MOUSE_INPUT_LEFT);
}

void DiploidEngineApp::Draw()//結果を描写する処理
{

}

DiploidObject DiploidEngineApp::FindObject(int layer_number, int number)//指定番号からオブジェクトを取得(オブジェクトを検索)
{
	DiploidObject diploid_object;


	return diploid_object;
}

DiploidEngineImpact DiploidEngineApp::FindImpactBOX(int layer_number, int number)//指定番号からオブジェクトを取得(衝突を検索)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
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
