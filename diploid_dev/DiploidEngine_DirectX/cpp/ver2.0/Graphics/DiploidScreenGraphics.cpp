#include  "ver2.0/Graphics/DiploidScreenGraphics.h"

//void DiploidScreenGraphics::Creat(float scale)

void DiploidScreenGraphics::Draw(float scale)
{

	SetUseASyncLoadFlag(FALSE);

	make_graphics_handl = MakeGraph(setting.GetSystemData().window_x, setting.GetSystemData().window_y);

	GetDrawScreenGraph(0, 0, setting.GetSystemData().window_x, setting.GetSystemData().window_y, make_graphics_handl);

	DrawExtendGraph(0, 0, setting.GetSystemData().window_x * scale, setting.GetSystemData().window_y * scale, make_graphics_handl, FALSE);//èkè¨ï`âÊ


	graphics_handle = MakeGraph(setting.GetSystemData().window_x * scale, setting.GetSystemData().window_y * scale);

	GetDrawScreenGraph(0, 0, setting.GetSystemData().window_x * scale, setting.GetSystemData().window_y * scale, graphics_handle);

	//final_graphics = DerivationGraph(0, 0, setting.window_x * scale, setting.window_y * scale, graphics_handle);

	DrawExtendGraph(0, 0, setting.GetSystemData().window_x, setting.GetSystemData().window_y, graphics_handle, FALSE);//ägëÂï`âÊ


	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", make_graphics_handl);

	DeleteGraph(make_graphics_handl);
	DeleteGraph(graphics_handle);

	SetUseASyncLoadFlag(TRUE);

}