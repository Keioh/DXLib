#include "se_volume_slider.h"

SEVolumeSlider::SEVolumeSlider()
{
	SEVolumeSlider::init();
}

void SEVolumeSlider::init()
{
	se_volume_slider.Init();
}

void SEVolumeSlider::LoadGraphics()
{
	se_volume_slider.Load("pack/UI/ButtonUI/wheel_horizontal.png");
}

float SEVolumeSlider::DrawSEVolumeSlider(int x, int y, unsigned int color, Filer data, bool wire)
{
	se_volume_slider.BoxUI_WheelHorizontal(x, y, color, wire);

	volume = se_volume_slider.wheel_volume_buffer;

	DrawFormatString(x + 10, y + 10, GetColor(120, 120, 255), "%s", data.string_data.se_volume);
	DrawFormatString(x + 120, y + 10, GetColor(120, 120, 255), "%d", volume);

	return volumeF = se_volume_slider.wheel_volume_buffer;
}