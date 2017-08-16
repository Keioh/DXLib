#include "button_ui.h"


ButtonUI::ButtonUI()
{

}

int ButtonUI::Load(char* path)
{
	graphics = LoadGraph(path);
	GetGraphSize(graphics, &size_x, &size_y);//1画像サイズを習得

	return graphics;
}

int ButtonUI::BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, bool wire)
{

	DrawExtendGraph(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

	return box_collision.BoxColliderMouse(pos_x, size_x * scale_x, pos_y, size_y * scale_y, wire);//コリジョンヒット判定
}
