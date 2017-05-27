#include "Dice.h"

DICE::DICE()
{
	font_size = 50;
	font_thick = 4;

	oneDhundred = 50;

	critical_init = 5;
	fumble_init = 95;

	graph_drawing_flag = 1;
}

void DICE::init()
{
	font_handl = CreateFontToHandle(NULL, font_size, font_thick, DX_FONTTYPE_ANTIALIASING_8X8);//新しいフォントセットを作る。
}

void DICE::Load()
{
	graph_1D100 = LoadGraph("pack/ui/1d100.png");
	graph_1D100_hit = LoadGraph("pack/ui/1d100_hit.png");
	graph_critical = LoadGraph("pack/ui/critical.png");
	graph_fumble = LoadGraph("pack/ui/fumble.png");

}

int DICE::Dice_role_oneDhundred(int x, int y)
{		

	GetMousePoint(&mouse_x, &mouse_y);//マウスカーソル位置を習得

	DrawGraph(x, y, graph_1D100, TRUE);

	if (x < mouse_x && y < mouse_y)//カーソルがこれらの内側なら
	{
		if (x + 100 > mouse_x && y + 50 > mouse_y)
		{	
			seed_count += GetRand(100) + 1;//seedを変える

			DrawGraph(x, y, graph_1D100_hit, TRUE);

			if ((oneD100_click = Mouse_Cilck(MOUSE_INPUT_LEFT, 0)) == true)//瞬間クリックすると同時に変数へクリック判定を代入
			{
				SRand(seed_count);
				oneDhundred = GetRand(100);//0~100の乱数を取得
				graph_drawing_flag = 1;//クリファン画像表示フラグをオンにする
				seed_count = 0;
			}
		}
	}

	if (oneDhundred <= 0)oneDhundred = 1;//ダイスロールの結果が0以下だったら1にする。

	DrawFormatStringToHandle(x + 24, y, GetColor(0, 0, 0), font_handl, "%d", oneDhundred);//結果を描写

	return oneDhundred;
}

int DICE::Dice_role_custom(int x, int y)
{
	DrawBox(x, y, x + 50, y + 50, GetColor(150, 150, 150), TRUE);
	DrawBox(x + 70, y, x + 120, y + 50, GetColor(150, 150, 150), TRUE);
	DrawBox(x + 120, y, x + 170, y + 50, GetColor(150, 150, 150), TRUE);

	if (start > 10)start = 10;
	if (start <= 0)start = 1;
	if (end > 10)end = 10;
	if (end <= 0)end = 1;

	//?D?の最初の?の部分
	if (x < mouse_x && y < mouse_y)//カーソルがこれらの内側なら
	{
		if (x + 50 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x, y, x + 50, y + 50, GetColor(200, 200, 200), TRUE);
			start += GetMouseWheelRotVol();//マウスの回転量を得る
		}
	}

	//?D?の最後の?の部分
	if (x + 70 < mouse_x && y < mouse_y)//カーソルがこれらの内側なら
	{
		if (x + 120 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x + 70, y, x + 120, y + 50, GetColor(200, 200, 200), TRUE);
			end += GetMouseWheelRotVol();//マウスの回転量を得る
		}
	}

	//?D?の結果表示ボタンの部分
	if (x + 120 < mouse_x && y < mouse_y)//カーソルがこれらの内側なら
	{
		if (x + 170 > mouse_x && y + 50 > mouse_y)
		{
			DrawBox(x + 120, y, x + 170, y + 50, GetColor(200, 200, 200), TRUE);
			seed_count += GetRand(100) + 1;//seedを変える

			if ((Mouse_Cilck(MOUSE_INPUT_LEFT, 0)) == true)//瞬間クリックすると同時に変数へクリック判定を代入
			{
				SRand(seed_count);
				customDcustom = GetRand(start * end);//startとendを掛けた乱数を取得
				graph_drawing_flag = 1;//クリファン画像表示フラグをオンにする
				seed_count = 0;

			}
		}
	}

	if (customDcustom <= 0)customDcustom = 1;

	DrawFormatStringToHandle(x + 5, y, GetColor(0, 0, 0), font_handl, "%d", start);//最初のダイス
	DrawFormatStringToHandle(x + 75, y, GetColor(0, 0, 0), font_handl, "%d", end);//最後のダイス
	DrawFormatStringToHandle(x + 170, y, GetColor(0, 0, 0), font_handl, "%d", customDcustom);//結果の表示


	return customDcustom;
}

void DICE::Critical_Fumble_Screen()
{
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) graph_drawing_flag = 0;//右クリックしたらクリファン画像の表示をオフにする。

	if (graph_drawing_flag == 1)
	{
		if (oneDhundred < critical_init)DrawGraph(0, 0, graph_critical, TRUE);
		if (oneDhundred > fumble_init)DrawGraph(0, 0, graph_fumble, TRUE);
	}
}