#include "system\DiploidEngineMath.h"

float DiploidEngineMath::VectorAdd(float a, float b)
{
	float vec = 0.0f;

	vec = a + b;

	return vec;
}

float DiploidEngineMath::VectorSub(float a, float b)
{
	float vec = 0.0f;

	vec = a - b;

	return vec;
}

float DiploidEngineMath::ThreeSquares(float a, float b)
{
	float C = 0.0f, c = 0.0f;

	C = powf(a, 2) + powf(b, 2);

	c = sqrtf(C);

	return c;
}

float DiploidEngineMath::ToDegree(float radian_angle)
{
	float ans = 0.0f;

	ans = radian_angle * (180 / DX_PI);

	return ans;
}

float DiploidEngineMath::ToRadian(float degree_angle)
{
	float ans = 0.0f;

	ans = degree_angle * (DX_PI / 180);

	return ans;
}

float DiploidEngineMath::EquilateralTriangleHeight(float length)
{
	float ans = 0.0f;

	ans = (sqrt(3) / 2) * length;

	return ans;
}

float DiploidEngineMath::EquilateralTriangleLength(float height)
{
	float ans = 0.0f;

	ans = (2 * height) / sqrt(3);

	return ans;
}