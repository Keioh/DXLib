#include "button_ui.h"

ButtonUI::ButtonUI()
{
	ButtonUI::Init();
}

void ButtonUI::Load(char* path, char* switch_path)
{
	graphics = LoadGraph(path);
	switch_graphics = LoadGraph(switch_path);
}

void ButtonUI::Init()
{
	mouse_input.init();
	//color = GetColor(100, 100, 100);
	wheel_volume_buffer = 0;
	wheel_volume = 0;
	switch_flag = -1;
	box_collision.hit = 0;
	circle_collision.hit = 0;
}

void ButtonUI::ColliderOff()
{
	box_collision.active = false;
	circle_collision.active = false;
}

void ButtonUI::ColliderOn()
{
	box_collision.active = true;
	circle_collision.active = true;
}

int ButtonUI::BoxUI_Button_BOX(int pos_x, int pos_y, float Size_x, float Size_y, int input, bool wire)//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
{
	SetDrawBright(255, 255, 255);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawBox(pos_x, pos_y, pos_x + Size_x, pos_y + Size_y, color, TRUE);
	DrawExtendGraphF(pos_x, pos_y, (pos_x + Size_x) * scale_x, (pos_y + Size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

	if (box_collision.BoxColliderMouse(pos_x, Size_x, pos_y, Size_y, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (Size_x - double_line)), (pos_y + (Size_y - double_line)), GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}
	SetDrawBright(255, 255, 255);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)

	return click_flag;//クリック判定の結果を返す。
}

int ButtonUI::BoxUI_Button(int pos_x, int pos_y, int input, bool wire)
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	//DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示
	DrawRotaGraph3(pos_x + size_x/2, pos_y + size_y/2, size_x/2, size_y/2, scale_x, scale_y, rotate * DX_PI_F / 180, graphics, TRUE, graph_turn);//画像を縮小拡大表示

	if (box_collision.BoxColliderMouse(pos_x * scale_x, size_x * scale_x, pos_y * scale_y, size_y * scale_y, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line) * scale_x, (pos_y + double_line) * scale_y, (pos_x + (size_x - double_line)) * scale_x, (pos_y + (size_y - double_line)) * scale_y, GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	SetDrawBright(255, 255, 255);//この処理を入れないと画像表示がバグります。(画面輝度を最大に設定)

	return click_flag;//クリック判定の結果を返す。
}

int ButtonUI:: BoxUI_WheelHorizontal(int pos_x, int pos_y, unsigned int color, bool wire)//横方向へのスライダー
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraphF(pos_x, pos_y, pos_x + size_x, pos_y + size_y, graphics, TRUE);//画像を縮小拡大表示

	if ((pos_x + wheel_volume_buffer) <= pos_x)
	{
		wheel_volume_buffer = 0;
	}

	if ((pos_x + wheel_volume_buffer) >= pos_x + size_x)
	{
		wheel_volume_buffer = size_x;
	}

	DrawBox(pos_x + wheel_volume_buffer, pos_y, pos_x, pos_y + size_y, color, TRUE);

	if (box_collision.BoxColliderMouse(pos_x, size_x, pos_y, size_y, wire) == true)//コリジョンヒット判定
	{
		if (mouse_input.MouseClickContinuation(MOUSE_INPUT_LEFT) == 1)
		{
			GetMousePoint(&mouse_x, &mouse_y);
			wheel_volume_buffer = (mouse_x - pos_x);
		}
		red_a = 255;
		green_a = 255;
		blue_a = 255;
		click_flag = 1;
		wheel_volume = GetMouseWheelRotVol();
		wheel_volume_buffer += wheel_volume;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
		click_flag = 0;
	}

	if (wheel_volume != 0)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (size_x - double_line)), (pos_y + (size_y - double_line)), GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	return click_flag;
}

int ButtonUI::BoxUI_WheelVertical(int pos_x, int pos_y, unsigned int color, bool wire)//バグあり
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraphF(pos_x, pos_y, pos_x + size_x, pos_y + size_y, graphics, TRUE);//画像を縮小拡大表示

	if ((pos_y + size_y + wheel_volume_buffer) <= pos_y)
	{
		wheel_volume_buffer = size_y;
	}

	if ((pos_y + size_y + wheel_volume_buffer) >= pos_y + size_y)
	{
		wheel_volume_buffer = 0;
	}

	DrawBox(pos_x, pos_y + size_y + wheel_volume_buffer, pos_x, pos_y + size_y, color, TRUE);

	if (box_collision.BoxColliderMouse(pos_x, size_x, pos_y, size_y, wire) == true)//コリジョンヒット判定
	{
		if (mouse_input.MouseClickContinuation(MOUSE_INPUT_LEFT) == 1)
		{
			GetMousePoint(&mouse_x, &mouse_y);
			wheel_volume_buffer = (mouse_y - (pos_y));
		}
		red_a = 255;
		green_a = 255;
		blue_a = 255;
		click_flag = 1;
		wheel_volume = GetMouseWheelRotVol();
		wheel_volume_buffer -= wheel_volume;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
		click_flag = 0;
		wheel_volume = 0;
	}

	if (wheel_volume != 0)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox((pos_x + double_line), (pos_y + double_line), (pos_x + (size_x - double_line)), (pos_y + (size_y - double_line)), GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	return click_flag;
}

int ButtonUI::BoxUI_Button_Continuation(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。)
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

	if (box_collision.BoxColliderMouse(pos_x, size_x * scale_x, pos_y, size_y * scale_y, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseClickContinuation(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox(pos_x + double_line, pos_y + double_line, pos_x + (size_x - double_line), pos_y + (size_y - double_line), GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	return click_flag;//クリック判定の結果を返す。
}

int ButtonUI::BoxUI_Button_Switch(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraphF(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

	if (box_collision.BoxColliderMouse(pos_x, size_x * scale_x, pos_y, size_y * scale_y, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		switch_flag *= -1;
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawBox(pos_x + double_line, pos_y + double_line, pos_x + (size_x - double_line), pos_y + (size_y - double_line), GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	if (switch_flag == 1)
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "sitch_flag = %d", switch_flag);

	return switch_flag;//クリック判定の結果を返す。
}

int ButtonUI::CircleUI_Button(int pos_x, int pos_y, int size_r, int input, bool wire)//(戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraphF(pos_x - (size_x/2), pos_y - (size_y/2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//画像を縮小拡大表示

	if (circle_collision.CircleColliderMouse(pos_x, pos_y, size_r, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;

		click_flag = false;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawCircle(pos_x, pos_y, size_r - double_line, GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	return click_flag;//クリック判定の結果を返す。
}

int ButtonUI::CircleUI_Button_Switch(int pos_x, int pos_y, int size_r, int input, bool wire)//戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。）
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	//DrawExtendGraph(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//画像を縮小拡大表示

	if (circle_collision.CircleColliderMouse(pos_x, pos_y, size_r, wire) == true)//コリジョンヒット判定
	{
		red_a = 255;
		green_a = 255;
		blue_a = 255;

		click_flag = mouse_input.MouseCilck(input);//クリック判定
	}
	else
	{
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	if (click_flag == 1)//クリックされたときwireフラグがtrueだったらグリンーんワイヤーを表示
	{
		switch_flag *= -1;
		if (wire == true)
		{
			for (int double_line = 0; double_line < 3; double_line++)
			{
				DrawCircle(pos_x, pos_y, size_r - double_line, GetColor(0, 255, 0), FALSE);//ワイヤーを表示(ヒットしたら赤で表示。for文は線を太くする処理)
			}
		}
	}

	if (switch_flag == 1)
	{
		DrawExtendGraphF(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//画像を縮小拡大表示
		red_a = 255;
		green_a = 255;
		blue_a = 255;
	}
	else
	{
		DrawExtendGraphF(pos_x - (size_x / 2), pos_y - (size_y / 2), pos_x + (size_x / 2), pos_y + (size_y / 2), switch_graphics, TRUE);//画像を縮小拡大表示
		red_a = 200;
		green_a = 200;
		blue_a = 200;
	}

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "sitch_flag = %d", switch_flag);

	return switch_flag;//クリック判定の結果を返す。
}