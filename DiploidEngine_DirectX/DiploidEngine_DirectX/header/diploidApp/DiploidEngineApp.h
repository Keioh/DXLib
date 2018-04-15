//中枢です。

#pragma once
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"

class DiploidEngineApp : public DiploidEngineMain
{
private:
	float r;
	
public:
	void Init();//最初に一回だけ初期化したい処理を記述。
	void Update();//アニメーションなど連続して行いたい処理。
	void Draw();//結果を描写する処理.


	//↓未実装かつどうするか考え中
	void Create();//新しくオブジェクトを作成するときに一回だけ呼ばれる。
	void Destory();//オブジェクトを削除するときに一回だけ呼ばれる。
};