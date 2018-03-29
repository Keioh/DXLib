#pragma once
#include "DxLib.h"

class GraphicsLoad
{
public:
	GraphicsLoad() {};

	int graphics_handl;//画像ハンドル
	float height;//画像の高さ
	float width;//画像の幅

	int Load(const char* path);//画像の読み込み(グラフィックハンドルを返す。)
};