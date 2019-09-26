#pragma once
#include "DxLib.h"
#include "diploidObject/DiploidEngineObject.h"

class DiploidPanel
{
private:

	VECTOR translate_position[6];//éOäpå`ÇªÇÃÇP
	VECTOR scale_position[6];//éOäpå`ÇªÇÃÇQ
	VECTOR rotate_x_position[6];//éOäpå`ÇªÇÃÇQ
	VECTOR rotate_y_position[6];//éOäpå`ÇªÇÃÇQ
	VECTOR rotate_z_position[6];//éOäpå`ÇªÇÃÇQ


	VERTEX3D vertex[6];

	MATRIX translate;
	MATRIX scale;
	MATRIX rotate_x;
	MATRIX rotate_y;
	MATRIX rotate_z;

	DiploidObject object;

public:
	DiploidPanel();

	VECTOR triangle_one[3];
	VECTOR triangle_two[3];

	bool impacted = false;
	unsigned int color;

	void Load(const char* path);
	void Init(VECTOR size);
	void Update();
	void Draw(bool wire = false);

	void Scale(VECTOR scale = { 1.0f,1.0f,1.0f });//ÇPî‘(ägëÂèkè¨)
	void RotateX(float rotate = 0.0f);//ÇQî‘(Xé≤ÇÃâÒì])
	void RotateY(float rotate = 0.0f);//ÇQî‘(Yé≤ÇÃâÒì])
	void RotateZ(float rotate = 0.0f);//ÇQî‘(Zé≤ÇÃâÒì])	
	void Translate(VECTOR trans = { 0.0f,0.0f,0.0f });//ÇRî‘(ïΩçsà⁄ìÆ)

	VECTOR GetCenter();
	void isGetTriangles();
};