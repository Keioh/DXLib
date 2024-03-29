#pragma once
#include "DxLib.h"
#include "diploidObject\DiploidEngineObjectInformation.h"

class DiploidPanel : public DiploidEngineObjectInformation
{
private:
	VERTEX3D vertex[6], vertex_x[6], vertex_y[6], vertex_z[6], vertex_trans[6], vertex_scale[6];//頂点情報
	int handl;

	MATRIX rota_x;
	MATRIX rota_y;
	MATRIX rota_z;
	MATRIX translate;
	MATRIX m_scale;

public:
	void Init(VECTOR position, VECTOR rotation, VECTOR scale);//初期化
	void Load(const char* paht);//画像読み込み

	void Draw();//描画
};