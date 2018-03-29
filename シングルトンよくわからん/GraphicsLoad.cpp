#include "GraphicsLoad.h"

int GraphicsLoad::Load(const char* path)
{
	graphics_handl = LoadGraph(path);//画像を読み込む

	GetGraphSizeF(graphics_handl, &width, &height);//画像の大きさを取得

	return graphics_handl;//グラフィックハンドルを返す。
}