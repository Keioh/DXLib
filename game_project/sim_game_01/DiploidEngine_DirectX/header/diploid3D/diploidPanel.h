#pragma once
#include "DxLib.h"
#include "diploidObject/DiploidEngineObject.h"

class DiploidPanel : public DiploidEngineObjectInformation
{
private:

	VECTOR translate_position[5];//三角形その１
	VECTOR scale_position[5];//三角形その２
	VECTOR rotate_x_position[5];//三角形その２
	VECTOR rotate_y_position[5];//三角形その２
	VECTOR rotate_z_position[5];//三角形その２


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

	void Load(const char* path);
	void Init(VECTOR size);
	void Updata();
	void Draw(bool draw = true);

	void Scale(VECTOR scale = { 1.0f,1.0f,1.0f });//１番(拡大縮小)
	void RotateX(float rotate = 0.0f);//２番(X軸の回転)
	void RotateY(float rotate = 0.0f);//２番(Y軸の回転)
	void RotateZ(float rotate = 0.0f);//２番(Z軸の回転)	
	void Translate(VECTOR trans = { 0.0f,0.0f,0.0f });//３番(平行移動)

};