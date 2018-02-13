#include "Box3D.h"

void Box3D::Load(char* path)
{
	graphic_handle = LoadGraph(path);
	
	vertex[0].pos = VGet(-1.0f, -1.0f, 0.0f);
	vertex[0].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].spc = GetColorU8(255, 255, 255, 255);
	vertex[0].u = 0.0f;
	vertex[0].v = 1.0f;
	vertex[0].su = 0.0f;
	vertex[0].sv = 0.0f;

	vertex[1].pos = VGet(-1.0f, 1.0f, 0.0f);
	vertex[1].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].spc = GetColorU8(255, 255, 255, 255);
	vertex[1].u = 0.0f;
	vertex[1].v = 0.0f;
	vertex[1].su = 0.0f;
	vertex[1].sv = 0.0f;

	vertex[2].pos = VGet(1.0f, 1.0f, 0.0f);
	vertex[2].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(255, 255, 255, 255);
	vertex[2].u = 1.0f;
	vertex[2].v = 0.0f;
	vertex[2].su = 0.0f;
	vertex[2].sv = 0.0f;

	vertex[3].pos = VGet(1.0f, 1.0f, 0.0f);
	vertex[3].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(255, 255, 255, 255);
	vertex[3].u = 1.0f;
	vertex[3].v = 0.0f;
	vertex[3].su = 0.0f;
	vertex[3].sv = 0.0f;

	vertex[4].pos = VGet(1.0f, -1.0f, 0.0f);
	vertex[4].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].spc = GetColorU8(255, 255, 255, 255);
	vertex[4].u = 1.0f;
	vertex[4].v = 1.0f;
	vertex[4].su = 0.0f;
	vertex[4].sv = 0.0f;

	vertex[5].pos = VGet(-1.0f, -1.0f, 0.0f);
	vertex[5].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].spc = GetColorU8(255, 255, 255, 255);
	vertex[5].u = 0.0f;
	vertex[5].v = 1.0f;
	vertex[5].su = 0.0f;
	vertex[5].sv = 0.0f;
}

void Box3D::Draw()
{
	DrawPolygon3D(vertex, 2, graphic_handle, FALSE);	
	DrawFormatString(500, 100, GetColor(255, 255, 255), "%f", vertex[0].pos.x);
}

void Box3D::Transform(VECTOR scale, float rotate_x, float rotate_y, float rotate_z, VECTOR trans)
{
	scale_matrix = MGetScale(scale);

	rotate_x_matrix = MGetRotX(rotate_x * (DX_PI_F / 180));
	rotate_y_matrix = MGetRotX(rotate_y * (DX_PI_F / 180));
	rotate_z_matrix = MGetRotX(rotate_z * (DX_PI_F / 180));

	translate_matrix = MGetTranslate(trans);


	for (int n = 0; n < 6; n++)
	{
		scale_vecter[n] = VTransform(vertex[n].pos, scale_matrix);

		rotate_x_vecter[n] = VTransform(scale_vecter[n], rotate_x_matrix);
		rotate_y_vecter[n] = VTransform(rotate_x_vecter[n], rotate_y_matrix);
		rotate_z_vecter[n] = VTransform(rotate_y_vecter[n], rotate_z_matrix);

		translate_vecter[n] = VTransform(rotate_z_vecter[n], translate_matrix);

		vertex[n].pos = translate_vecter[n];
	}
}