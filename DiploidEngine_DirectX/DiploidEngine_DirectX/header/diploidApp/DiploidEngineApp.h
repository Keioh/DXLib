//中枢です。

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidCircle circle;
	

public:
	void Init();//最初に一回だけ初期化したい処理を記述。
	void Update();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理.
};