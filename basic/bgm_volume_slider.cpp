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

float BGMVolumeSlider::DrawBGMVolumeSlider(int x, int y, unsigned int color, bool wire)
{
	bgm_volume_slider.BoxUI_WheelHorizontal(x, y, color, wire);

	volume = bgm_volume_slider.wheel_volume_buffer;

	DrawFormatString(x + 10, y + 10, GetColor(100,100,255), "BGM VOLUME %d", volume);

	return volumeF = bgm_volume_slider.wheel_volume_buffer;
}