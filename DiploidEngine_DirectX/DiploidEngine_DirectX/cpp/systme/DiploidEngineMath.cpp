#include "system\DiploidEngineMath.h"

Vector2 DiploidEngineMath::VectorAdd(Vector2 one, Vector2 two)
{
	Vector2 vec2 = { 0,0 };

	vec2.x = one.x + two.x;
	vec2.y = one.y + two.y;

	return vec2;
}

Vector2 DiploidEngineMath::VectorSub(Vector2 one, Vector2 two)
{
	Vector2 vec2 = { 0,0 };

	vec2.x = one.x - two.x;
	vec2.y = one.y - two.y;

	return vec2;
}

float DiploidEngineMath::DotProduct(float a, float b)
{
	float vec1 = 0.0f;

	vec1 = a * b * (b / a);

	return vec1;
}

float DiploidEngineMath::CrossProduct(float a, float b)
{
	float vec1 = 0.0f;

	return vec1;
}

float DiploidEngineMath::ThreeSquares(float a, float b)
{
	float C = 0.0f, c = 0.0f;

	C = pow(a, 2) + pow(b, 2);

	c = sqrt(C);

	return c;
}