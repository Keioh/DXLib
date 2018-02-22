#include "Line3D.h"

void Line3D::Draw(VECTOR pos1, VECTOR pos2, unsigned int color)
{
	DrawTriangle3D({ pos1.x, pos1.y, pos1.z + z1}, { pos1.x + x1, pos1.y, pos1.z + z1}, { pos2.x, pos2.y, pos2.z + z2}, color, TRUE);//左の三角形
	DrawTriangle3D({ pos2.x, pos2.y, pos2.z + z2}, { pos2.x + x2, pos2.y, pos2.z + z2}, { pos1.x + x1, pos1.y, pos1.z + z1}, color, TRUE);//右の三角形
}