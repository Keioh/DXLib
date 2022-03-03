#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0//Graphics/DiploidCircleV2.h"

class DiploidRoundedBox
{
private:
	DiploidBoxV2 box[5];//0=左、1=上、2=右、3=下、4=中央
	DiploidCircleV2 circle[4];//0=左上、1=右上、2=右下、3=左下

	VECTOR return_size;
	VECTOR _size, _position;
	float _roundness;
	unsigned int _color;

public:

	void Init(VECTOR position, VECTOR size, unsigned int color, float roundness = 20.0f) ;
	void Update();
	void Draw(bool debug = false, bool draw = true);

	void SetSize(VECTOR new_size);
	void SetRoundness(float new_roundness);
	void SetColor(unsigned int new_color);

	VECTOR GetSize();
};