#include "ver2.0/UI/SwitchButtonBoxV2.h"


void SwitchButtonBoxV2::Init(VECTOR pos, VECTOR size, int mouse_button)
{
	//マウスボタンを保存
	mouse_button_type = mouse_button;

	//BOXの初期化
	box.Init(pos, size, GetColor(255, 255, 255));
	//box.SetFill(TRUE);
}

void SwitchButtonBoxV2::Update()
{
	//インプットアップデート
	input.Update();

	//当たり判定処理(マウスとBOX)
	if (collision.BoxAndMouseCollisionUpdate(&box, input.GetMousePosition().x, input.GetMousePosition().y) == true)
	{
		//ボタンに当たっているかのフラグをtrueに
		button_hit_flag = true;

		//青色に変更
		box.SetColor(GetColor(0, 0, 255));

		//マウスのクリック判定
		if (input.GetPressMouse(mouse_button_type) == true)
		{
			//ボタンをクリックしたかのフラグをtrueに
			button_click_flag = true;

			//ボタンを選択中かのフラグを変更
			button_selected_flag *= -1;

			//button_selected_flagが1なら
			if (button_selected_flag == -1)
			{
				//緑色に変更
				box.SetColor(GetColor(0, 255, 0));
			}
			else
			{
				//赤色に変更
				box.SetColor(GetColor(255, 0, 0));
			}
		}
		else
		{
			//ボタンをクリックしたかのフラグをfalseに
			button_click_flag = false;
		}
	}
	else
	{
		//明るい灰色に変更
		box.SetColor(GetColor(200, 200, 200));


		//ボタンに当たっているかのフラグをfalseに
		button_hit_flag = false;
	}
}

void SwitchButtonBoxV2::Draw(bool draw )
{
	if (draw == true)
	{
		//当たり判定BOXの表示
		box.Draw(draw);
	}
}


bool SwitchButtonBoxV2::GetHit()
{
	return button_hit_flag;
}

bool SwitchButtonBoxV2::GetClick()
{
	return button_click_flag;
}

int SwitchButtonBoxV2::GetSelected()
{
	return button_selected_flag;
}


DiploidBoxV2& SwitchButtonBoxV2::GetBoxPtr()
{
	return box;
}