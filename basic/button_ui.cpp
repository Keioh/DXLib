#include "button_ui.h"

ButtonUI::ButtonUI()
{
	ButtonUI::Init();
}

void ButtonUI::Load(char* path)
{
	graphics = LoadGraph(path);
}

void ButtonUI::Init()
{
	switch_flag = -1;
	box_collision.hit = 0;
}

int ButtonUI::BoxUI_Button(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)
{	
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraph(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

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

	return click_flag;//クリック判定の結果を返す。
}

int ButtonUI::BoxUI_Button_Continuation(int pos_x, int pos_y, float scale_x, float scale_y, int input, bool wire)//バグにつきスケールの値は1.0fで使うこと。（戻り値はクリックフラグが返る。1でクリック、0でクリックしていない。)
{
	GetGraphSize(graphics, &size_x, &size_y);//画像サイズを習得

	SetDrawBright(red_a, green_a, blue_a);//ヒットしている場合、画像の輝度を255にする。(ヒットしていない場合は200)
	DrawExtendGraph(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

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
	DrawExtendGraph(pos_x, pos_y, (pos_x + size_x) * scale_x, (pos_y + size_y) * scale_y, graphics, TRUE);//画像を縮小拡大表示

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
	DrawExtendGraph(pos_x - (size_x/2), pos_y - (size_y/2), pos_x + (size_x / 2), pos_y + (size_y / 2), graphics, TRUE);//画像を縮小拡大表示

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
