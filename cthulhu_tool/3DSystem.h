#pragma once
#include "DxLib.h"

typedef class D3DSystem
{
private:

public:	
	VERTEX3D boxVertex[6], box[6];
	VERTEX3D halfCubeVertex[18], halfCube[18];

	//MATRIX scale, translate, rot, max, MAX;
	//MATRIX boxScale;

	//D3DSystem();
	//~D3DSystem();
	void BoxVer_Init(COLOR_U8 df, COLOR_U8 spc);
	void HalfCubeVer_Init(COLOR_U8 df, COLOR_U8 spc);

	void DrawBox3D(VECTOR Scale, VECTOR Translate, VECTOR Axis, float Rotate, int Handle, int flag);
	void DrawHalfCube(VECTOR Scale, VECTOR Translate, VECTOR Axis, float Rotate, int Handle, int flag);

}D3DSYSTEM, D3DSYS;
