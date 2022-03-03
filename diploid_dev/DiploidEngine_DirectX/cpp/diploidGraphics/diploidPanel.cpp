#include "diploidGraphics\diploidPanel.h"

void DiploidPanel::Init(VECTOR position, VECTOR rotation, VECTOR scale)
{
	//頂点位置
	vertex[0].pos = VGet(-1.0f, 1.0f, 0.0f);
	vertex[1].pos = VGet(1.0f, 1.0f, 0.0f);
	vertex[2].pos = VGet(-1.0f, -1.0f, 0.0f);

	vertex[3].pos = VGet(1.0f, 1.0f, 0.0f);
	vertex[4].pos = VGet(-1.0f, -1.0f, 0.0f);
	vertex[5].pos = VGet(1.0f, -1.0f, 0.0f);


	//法線
	vertex[0].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[1].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[2].norm = VGet(0.0f, 0.0f, -1.0f);

	vertex[3].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[4].norm = VGet(0.0f, 0.0f, -1.0f);
	vertex[5].norm = VGet(0.0f, 0.0f, -1.0f);


	//デフューズカラー
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);

	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);


	//テクスチャー位置
	vertex[0].u = 0.0f;//左上
	vertex[0].v = 0.0f;

	vertex[1].u = 1.0f;//右上
	vertex[1].v = 0.0f;

	vertex[2].u = 0.0f;//左下
	vertex[2].v = 1.0f;


	vertex[3].u = 1.0f;//右上
	vertex[3].v = 0.0f;

	vertex[4].u = 0.0f;//右上
	vertex[4].v = 1.0f;

	vertex[5].u = 1.0f;//右下
	vertex[5].v = 1.0f;


	translate = MGetTranslate(position);

	for (int count = 0; count < 6; ++count)
	{
		vertex_trans[count].pos = VTransform(vertex[count].pos, translate);
	}

	rota_x = MGetRotX(rotation.x);

	for (int count = 0; count < 6; ++count)
	{
		vertex_x[count].pos = VTransform(vertex_trans[count].pos, rota_x);
	}

	rota_y = MGetRotY(rotation.y);

	for (int count = 0; count < 6; ++count)
	{
		vertex_y[count].pos = VTransform(vertex_x[count].pos, rota_y);
	}

	rota_z = MGetRotZ(rotation.z);

	for (int count = 0; count < 6; ++count)
	{
		vertex_z[count].pos = VTransform(vertex_y[count].pos, rota_z);
	}

	m_scale = MGetScale(scale);

	for (int count = 0; count < 6; ++count)
	{
		vertex_scale[count].pos = VTransform(vertex_z[count].pos, m_scale);
	}


	//数値を返還
	for (int count = 0; count < 6; ++count)
	{
		vertex[count].pos = vertex_scale[count].pos;
	}
}

void DiploidPanel::Load(const char* paht)
{
	handl = LoadGraph(paht);
}

void DiploidPanel::Draw()
{
	SetUseLighting(FALSE);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -10), VGet(0,1,0));
	DrawPolygon3D(vertex, 2, handl, TRUE);
}