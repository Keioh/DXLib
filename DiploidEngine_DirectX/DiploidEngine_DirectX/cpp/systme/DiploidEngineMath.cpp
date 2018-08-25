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

float DiploidEngineMath::DotProduct(float a, float b, float angle)
{
	float A = 0.0f, B = 0.0f;

	A = a * cos(angle);
	B = A * b;

	return B;
}

float DiploidEngineMath::CrossProduct(float a, float b)
{
	float vec = 0.0f;

	return vec;
}

float DiploidEngineMath::DotProduct(Vector2 a, Vector2 b)
{
	float vec = 0.0f;

	vec = (a.x * b.x) + (a.y * b.y);

	return vec;
}

float DiploidEngineMath::ThreeSquares(float a, float b)
{
	float C = 0.0f, c = 0.0f;

	C = pow(a, 2) + pow(b, 2);

	c = sqrt(C);

	return c;
}

float DiploidEngineMath::DotProductPointAndLine(VECTOR point, VECTOR a, float angle)
{
	float ans = 0.0f;
	float X = 0.0f, Y = 0.0f;
	float B = 0.0f;
	float vec = 0.0f;//aì_Ç©ÇÁpointÇ…êLÇ—ÇÈí∑Ç≥

	X = point.x - a.x;
	Y = point.y - a.y;

	B = pow(X, 2) + pow(Y, 2);
	vec = sqrt(B);

	ans = vec * cos(angle);

	return ans;
}

float DiploidEngineMath::ToDegree(float angle)
{
	float ans = 0.0f;

	ans = angle * (180 / DX_PI);

	return ans;
}