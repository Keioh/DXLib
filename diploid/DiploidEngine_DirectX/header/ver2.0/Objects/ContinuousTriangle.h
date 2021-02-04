#pragma once
#include <vector>
#include "DxLib.h"
#include "system/DiploidEngineMath.h"
#include "diploidInput\DiploidEngineInput.h"
#include "ver2.0/Graphics/DiploidTriangle.h"

//�A�������O�p�`�̕`��
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

	unsigned int color;
	float max_color_scale = 0.3f;

	VECTOR pos;//��������p
	float sin_anime, sin_add;


	int triangle_size_x = 16, triangle_size_y = 9;

public:
	void Init(VECTOR pos, float lenght ,int size_x, int size_y);
	void Updata(DiploidEngineInput& input);
	void Draw(bool draw = true, bool debug = false);
};