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


public:
	void FileCreate();//ゲーム起動時に一度だけファイルを作る処理。
	void Load();//ゲーム起動時にロードするデータ
	void Init();//最初に一回だけ初期化したい処理を記述。
	void Updata();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理

};