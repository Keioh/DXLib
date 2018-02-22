#pragma once
#include "DxLib.h"

class Box3D
{
private:
	VECTOR translate_vecter[6], scale_vecter[6], rotate_x_vecter[6], rotate_y_vecter[6], rotate_z_vecter[6];
	MATRIX scale_matrix;
	MATRIX translate_matrix;
	MATRIX rotate_x_matrix, rotate_y_matrix, rotate_z_matrix;

public:
	int graphic_handle;

	VERTEX3D vertex[6];

	void Load(char* path);//í∏ì_èÓïÒÇÉçÅ[Éh

	void Draw();//{0.0f,0.0f,0.0f}Ç…ï`é 
	void Transform(VECTOR scale = { 0.0f,0.0f,0.0f }, float rotate_x = 0.0f, float rotate_y = 0.0f, float rotate_z = 0.0f, VECTOR trans = { 0.0f,0.0f,0.0f });
};