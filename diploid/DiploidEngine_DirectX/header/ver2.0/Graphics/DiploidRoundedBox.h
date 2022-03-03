#pragma once
#include "DxLib.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0//Graphics/DiploidCircleV2.h"

class DiploidRoundedBox
{
private:
	DiploidBoxV2 box[5];//0=���A1=��A2=�E�A3=���A4=����
	DiploidCircleV2 circle[4];//0=����A1=�E��A2=�E���A3=����

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