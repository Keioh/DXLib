#include "ver2.0/Objects/string_image/option/game_play_string_image.h"

void GamePlayStringImage::Load()
{
	option_string_images[0].Load("texter/basic/option/game_play/line.png");
	option_string_images[1].Load("texter/basic/option/game_play/g.png");
	option_string_images[2].Load("texter/basic/option/game_play/g_a.png");
	option_string_images[3].Load("texter/basic/option/game_play/m.png");
	option_string_images[4].Load("texter/basic/option/game_play/e.png");
	option_string_images[5].Load("texter/basic/option/game_play/p.png");
	option_string_images[6].Load("texter/basic/option/game_play/l.png");
	option_string_images[7].Load("texter/basic/option/game_play/p_a.png");
	option_string_images[8].Load("texter/basic/option/game_play/y.png");

}

void GamePlayStringImage::Init(VECTOR pos)
{
	position = pos;

	for (int count = 0; count != 9; count++)
	{
		position_animation_x[count] = anime_pos_init;
		option_string_alpha[count] = 0;
		option_string_images[count].Init(position);
	}
}

void GamePlayStringImage::Updata()
{
	for (int count = 0; count != 9; count++)
	{
		if (option_string_alpha[count] > 255)
		{
			option_string_alpha[count] = 255;
		}

		if (position_animation_x[count] > 0)
		{
			position_animation_x[count] = 0;
		}
	}

	option_string_images[0].SetPosition(VGet(position.x, position_animation_x[0] + position.y, 0));
	option_string_alpha[0] += alpha_speed;
	position_animation_x[0] += animation_speed;

	if (option_string_alpha[0] > 20)
	{
		option_string_images[1].SetPosition(VGet(position.x, position_animation_x[1] + position.y, 0));
		option_string_alpha[1] += alpha_speed;
		position_animation_x[1] += animation_speed;
	}

	if (option_string_alpha[1] > 20)
	{
		option_string_images[2].SetPosition(VGet(position.x, position_animation_x[2] + position.y, 0));
		option_string_alpha[2] += alpha_speed;
		position_animation_x[2] += animation_speed;
	}

	if (option_string_alpha[2] > 20)
	{
		option_string_images[3].SetPosition(VGet(position.x, position_animation_x[3] + position.y, 0));
		option_string_alpha[3] += alpha_speed;
		position_animation_x[3] += animation_speed;
	}

	if (option_string_alpha[3] > 20)
	{
		option_string_images[4].SetPosition(VGet(position.x, position_animation_x[4] + position.y, 0));
		option_string_alpha[4] += alpha_speed;
		position_animation_x[4] += animation_speed;
	}

	if (option_string_alpha[4] > 20)
	{
		option_string_images[5].SetPosition(VGet(position.x, position_animation_x[5] + position.y, 0));
		option_string_alpha[5] += alpha_speed;
		position_animation_x[5] += animation_speed;
	}

	if (option_string_alpha[5] > 20)
	{
		option_string_images[6].SetPosition(VGet(position.x, position_animation_x[6] + position.y, 0));
		option_string_alpha[6] += alpha_speed;
		position_animation_x[6] += animation_speed;
	}

	if (option_string_alpha[6] > 20)
	{
		option_string_images[7].SetPosition(VGet(position.x, position_animation_x[7] + position.y, 0));
		option_string_alpha[7] += alpha_speed;
		position_animation_x[7] += animation_speed;
	}

	if (option_string_alpha[7] > 20)
	{
		option_string_images[8].SetPosition(VGet(position.x, position_animation_x[8] + position.y, 0));
		option_string_alpha[8] += alpha_speed;
		position_animation_x[8] += animation_speed;
	}
}

void GamePlayStringImage::Draw(bool draw, bool debug)
{
	if (draw == true)
	{
		for (int count = 0; count != 9; count++)
		{
			option_string_images[count].SetAlpha(option_string_alpha[count]);
			option_string_images[count].Draw(draw);
		}
	}
}

void GamePlayStringImage::Reset()
{
	for (int count = 0; count != 9; count++)
	{
		position_animation_x[count] = anime_pos_init;
		option_string_alpha[count] = 0;
	}
}