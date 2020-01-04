#pragma once
#include <memory>
#include "DxLib.h"
#include "ver2.0/Main/Transform.h"

class DiploidBoxV2 : public Transform//2Dの四角を描画します。
{
private:

protected:

public:
	DiploidBoxV2();//デフォルトコンストラクタ
	DiploidBoxV2(VECTOR position, VECTOR size);//コンストラクタ(位置と大きさを指定したBOXを作成)

	void DrawGraphics(bool draw = true);//図形を描画します。

};