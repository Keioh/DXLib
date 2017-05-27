#pragma once
#include "3DSystem.h"

/*D3DSystem::D3DSystem()
{
	//BoxVer_Init(GetColorU8(255, 255, 255, 0), GetColorU8(255, 255, 255, 0));
}*/

void D3DSystem::BoxVer_Init(COLOR_U8 df, COLOR_U8 spc)
{
	//boxVertex[0] = { (-1.0f, 1.0f, 0.0f), (0.0f, 0.0f, 0.0f), (0.0f, 0.0f, 0.0f), (0.0f, 0.0f, 0.0f), (0.0f, 1.0f), (0.0f, 0.0f) };
	boxVertex[0].pos	 = VGet(-1.0f, -1.0f, 0.0f);
	boxVertex[0].norm	 = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[0].dif	 = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[0].spc	 = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[0].u		 = 0.0f;
	boxVertex[0].v		 = 1.0f;
	boxVertex[0].su		 = 0.0f;
	boxVertex[0].sv		 = 0.0f;


	boxVertex[1].pos = VGet(-1.0f, 1.0f, 0.0f);
	boxVertex[1].norm = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[1].dif = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[1].spc = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[1].u = 0.0f;
	boxVertex[1].v = 0.0f;
	boxVertex[1].su = 0.0f;
	boxVertex[1].sv = 0.0f;


	boxVertex[2].pos = VGet(1.0f, 1.0f, 0.0f);
	boxVertex[2].norm = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[2].dif = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[2].spc = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[2].u = 1.0f;
	boxVertex[2].v = 0.0f;
	boxVertex[2].su = 0.0f;
	boxVertex[2].sv = 0.0f;



	boxVertex[3].pos = VGet(-1.0f, -1.0f, 0.0f);
	boxVertex[3].norm = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[3].dif = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[3].spc = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[3].u = 0.0f;
	boxVertex[3].v = 1.0f;
	boxVertex[3].su = 0.0f;
	boxVertex[3].sv = 0.0f;


	boxVertex[4].pos = VGet(1.0f, -1.0f, 0.0f);
	boxVertex[4].norm = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[4].dif = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[4].spc = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[4].u = 1.0f;
	boxVertex[4].v = 1.0f;
	boxVertex[4].su = 0.0f;
	boxVertex[4].sv = 0.0f;


	boxVertex[5].pos = VGet(1.0f, 1.0f, 0.0f);
	boxVertex[5].norm = VGet(0.0f, 0.0f, -1.0f);
	boxVertex[5].dif = GetColorU8(df.b, df.g, df.r, df.a);
	boxVertex[5].spc = GetColorU8(spc.b, spc.g, spc.r, spc.a);
	boxVertex[5].u = 1.0f;
	boxVertex[5].v = 0.0f;
	boxVertex[5].su = 0.0f;
	boxVertex[5].sv = 0.0f;


	box[0].pos = VGet(-1.0f, -1.0f, 0.0f);
	box[1].pos = VGet(-1.0f, 1.0f, 0.0f);
	box[2].pos = VGet(1.0f, 1.0f, 0.0f);
	box[3].pos = VGet(-1.0f, -1.0f, 0.0f);
	box[4].pos = VGet(1.0f, -1.0f, 0.0f);
	box[5].pos = VGet(1.0f, 1.0f, 0.0f);
}

void D3DSystem::DrawBox3D(VECTOR Scale, VECTOR Translate, VECTOR Axis, float Rotate, int Handle, int flag)
{
	MATRIX scale, translate, rot, max, MAX;

	scale = MGetScale(Scale);
	translate = MGetTranslate(Translate);
	rot = MGetRotAxis(Axis, (DX_PI / 180 * Rotate));

	max = MMult(scale, translate);
	MAX = MMult(rot, max);

	boxVertex[0].pos = VTransform(box[0].pos, MAX);
	boxVertex[1].pos = VTransform(box[1].pos, MAX);
	boxVertex[2].pos = VTransform(box[2].pos, MAX);
	boxVertex[3].pos = VTransform(box[3].pos, MAX);
	boxVertex[4].pos = VTransform(box[4].pos, MAX);
	boxVertex[5].pos = VTransform(box[5].pos, MAX);

	DrawPolygon3D(boxVertex, 2, Handle, flag);
}