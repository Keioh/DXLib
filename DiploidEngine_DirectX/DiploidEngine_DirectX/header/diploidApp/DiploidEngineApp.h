//中枢です。

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidImage.h"
#include "diploidSound\diploidEnigneSound.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	//DiploidCircle circle;
	//DiploidPoint point;
	//DiploidBox box;

	//DiploidImage image;

	//DiploidEngineSound sound;

	DiploidObject object;

public:
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理

	DiploidObject FindObject(int layer_number, int number);//指定番号からオブジェクトを取得(オブジェクトを検索)
	DiploidEngineImpact FindImpact(int layer_number, int number);//指定番号からオブジェクトを取得(衝突を検索)
	DiploidEngineLayer FindImage(int layer_number, int number);//指定番号からオブジェクトを取得(画像を検索)

};