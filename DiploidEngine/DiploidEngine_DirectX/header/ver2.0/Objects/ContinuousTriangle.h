#pragma once
#include <vector>
#include "DxLib.h"
#include "system/DiploidEngineMath.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidTriangle.h"
#include "diploidScreen\DiploidEngineScreen.h"

//˜A‘±‚µ‚½ŽOŠpŒ`‚Ì•`‰æ
class ContinuousTriangle
{
private:
	DiploidEngineMath math;

	//std::vector<DiploidTriangle> triangle_vector;
	std::vector<std::vector<DiploidTriangle>> triangle_vector;

	TRIANGLE triangle_data;
	DiploidTriangle triangle;

	float triangle_height;
	float triangle_lenght;
	float size = 50;

	unsigned int color;
	float max_color_scale = 0.7f;

	VECTOR pos;//‹——£‘ª‚é—p
	float sin_anime, sin_add;


	int triangle_size_x = 16, triangle_size_y = 9;

public:
	void Init(VECTOR pos, float length,int size_x, int size_y);
	void Updata(DiploidEngineInput& input, DiploidEngineScreen& screen);
	void Draw(bool draw = true, bool debug = false);

	void SetSize();

};