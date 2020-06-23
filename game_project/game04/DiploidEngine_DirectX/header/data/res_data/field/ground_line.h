#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidImageV2.h"

class GroundLine
{
private:
	VECTOR ground_line_pos;

	DiploidImageV2 image;

public:
	void LoadGraphics();

	void Init(float line_pos);
	void Updata();
	void Draw(bool draw = true);

	void SetGroundLine(float new_line);//新しくグランドラインを設定します。

	float GetGroundLine();
};