#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//ゲーム起動時にロードするデータ
{	

	object.image.Load("texter/test.png");//テクスチャを読み込む

}

void DiploidEngineApp::Init()//最初に一回だけ初期化したい処理を記述。
{	
/*
	//マウス追従設定のBOXオブジェクトを一つ作成
	object.circle.Init(VGet(0, 0, 0), 25);
	object.circle.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//判定したい識別番号を代入
	object.circle.mouse_point_move_flag = true;//マウスに追従するように設定
	diploidEngineImpact.PushCircle(object.circle);//衝突判定を行うBOX配列にBOXオブジェクトをプッシュ

	//BOXに画像を付け、それを50個ランダムな位置に作成
	for (int count = 0; count < 50; ++count)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);//ランダム値取得
		pos.y = GetRand(WindowSize().y);

		object.box.Init(VGet(pos.x, pos.y, 0), VGet(50, 50, 0));
		object.box.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//識別番号をゲームオブジェクトに設定
		object.box.number += 1;//BOXオブジェクトに１ループにつき+1オブジェクト番号を付与
		object.box.mouse_point_move_flag = false;//For文の前でtrueにしているのでfalseに設定
		object.box.destory = true;//ヒット判定があった場合、対象を削除するフラグをセット

		object.image.Init(VGet(pos.x, pos.y, 0), 0.2f);
		object.image.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//BOXと同じ識別番号を指定
		object.image.number += 1;//BOXオブジェクトと同じ番号を付与
		object.image.destory = true;//ヒット判定があった場合、対象を削除

		diploidEngineLayer.PushTopGraphics(object.image);//表示レイヤーのトップ(一番上)にイメージをプッシュ
		diploidEngineImpact.PushBox(object.box);//衝突判定を行うBOX配列にBOXオブジェクトをプッシュ
	}
	*/

	for (int count = 0; count < 500; ++count)
	{
		object.line.Init(VGet(200 + count, 200, 0), VGet(400 + count, 500, 0));
		object.line.destory = true;
		diploidEngineImpact.PushLine(object.line);
	}

	object.circle.Init(VGet(0, 0, 0), 25);
	object.circle.mouse_point_move_flag = true;

	diploidEngineImpact.PushCircle(object.circle);

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。
{

}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//DrawFormatStringF(0, 500, GetColor(255, 255, 255), "test = %.2f", math.DotProduct(20, 2));
}


//以下未実装
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
