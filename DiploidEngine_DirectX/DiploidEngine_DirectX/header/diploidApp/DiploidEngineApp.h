//中枢です。

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "system\DiploidEngineMath.h"

#include "diploidInput\DiploidEnigneFile.h"


class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidObject object;

public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理

	DiploidObject FindObject(int layer_number, int number);//指定番号からオブジェクトを取得(オブジェクトを検索)
	DiploidBox FindImpactBOX(int layer_number, int number);//指定番号からオブジェクトを取得(衝突を検索)
	DiploidEngineImpact FindImpactCIRCLE(int layer_number, int number);//指定番号からオブジェクトを取得(衝突を検索)
	DiploidEngineImpact FindImpactPOINT(int layer_number, int number);//指定番号からオブジェクトを取得(衝突を検索)
	DiploidEngineLayer FindImageTOP(int layer_number, int number);//指定番号からオブジェクトを取得(画像を検索)
	DiploidEngineLayer FindImageMID(int layer_number, int number);//指定番号からオブジェクトを取得(画像を検索)
	DiploidEngineLayer FindImageBOT(int layer_number, int number);//指定番号からオブジェクトを取得(画像を検索)

};