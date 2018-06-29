//オブジェクトまとめ

#pragma once
#include "DxLib.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidImage.h"

class DiploidObject
{
private:
	DiploidBox box;//四角
	DiploidCircle circle;//円
	DiploidPoint point;//点

	DiploidImage image;//画像

public:

	void Init();
	void Updata();
	void Draw(bool debug = true);

};