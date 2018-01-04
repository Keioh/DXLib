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

float SEVolumeSlider::DrawSEVolumeSlider(int x, int y, unsigned int color, bool wire)
{
	se_volume_slider.BoxUI_WheelHorizontal(x, y, color, wire);

	volume = se_volume_slider.wheel_volume_buffer;

	DrawFormatString(x + 10, y + 10, GetColor(100, 100, 255), "SE VOLUME %d", volume);

	return volumeF = se_volume_slider.wheel_volume_buffer;
}