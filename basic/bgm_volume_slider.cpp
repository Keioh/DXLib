#include "bgm_volume_slider.h"

BGMVolumeSlider::BGMVolumeSlider()
{
	BGMVolumeSlider::init();
}

void BGMVolumeSlider::init()
{
	bgm_volume_slider.Init();
}

void BGMVolumeSlider::LoadGraphics()
{
	bgm_volume_slider.Load("pack/UI/ButtonUI/wheel_horizontal.png");
}

float BGMVolumeSlider::DrawBGMVolumeSlider(int x, int y, unsigned int color, Filer data, bool wire)
{
	bgm_volume_slider.BoxUI_WheelHorizontal(x, y, color, wire);

	volume = bgm_volume_slider.wheel_volume_buffer;

	DrawFormatString(x + 10, y + 10, GetColor(120, 120, 255), "%s", data.string_data.bgm_volume);
	DrawFormatString(x + 120, y + 10, GetColor(120, 120, 255), "%d", volume);

	return volumeF = bgm_volume_slider.wheel_volume_buffer;
}