#include "data/custom_number.h"

CustomNumber::CustomNumber()
{

}

void CustomNumber::Load()
{
	plus.image.Load("texter/button/custom_number/plus.png");
	minus.image.Load("texter/button/custom_number/minus.png");
	clear.image.Load("texter/button/custom_number/clear.png");
	in.image.Load("texter/button/custom_number/in.png");
	back_3.image.Load("texter/button/custom_number/back_4.png");


	back_1.image.Load("texter/button/custom_number/back_1.png");
	edge_1.image.Load("texter/button/custom_number/edge_1.png");
	mark_1.image.Load("texter/button/custom_number/mark_1.png");

	back_1_copy.image.Load("texter/button/custom_number/back_1.png");
	edge_1_copy.image.Load("texter/button/custom_number/edge_1.png");
	mark_1_copy.image.Load("texter/button/custom_number/mark_1.png");



	back_2.image.Load("texter/button/custom_number/back_2.png");
	edge_2.image.Load("texter/button/custom_number/edge_2.png");
	mark_2.image.Load("texter/button/custom_number/mark_2.png");	

	back_2_copy.image.Load("texter/button/custom_number/back_2.png");
	edge_2_copy.image.Load("texter/button/custom_number/edge_2.png");
	mark_2_copy.image.Load("texter/button/custom_number/mark_2.png");

	number_1.Load();
	number_2.Load();
	number_3.Load();
	number_4.Load();

}

void CustomNumber::Init(VECTOR pos, float scale)
{
	number_1.Init(VAdd(pos, VGet(0 + (24 * scale), -48, 0)), scale);
	number_2.Init(VAdd(pos, VGet(-24 + (24 * scale), -48, 0)), scale);
	number_3.Init(VAdd(pos, VGet(-48 + (24 * scale), -48, 0)), scale);
	number_4.Init(VAdd(pos, VGet(-72 + (24 * scale), -48, 0)), scale);

	plus.image.Init(VAdd(pos, VGet(36 * scale, 0, 0)), scale);
	minus.image.Init(VAdd(pos, VGet(36 * scale, 24 * scale, 0)), scale);
	clear.image.Init(VAdd(pos, VGet(0 * scale, 24 * scale, 0)), scale);
	in.image.Init(VAdd(pos, VGet(0 * scale, 0 * scale, 0)), scale);

	back_3.image.Init(VAdd(pos, VGet(24, -48, 0)), scale);


	back_1.image.Init(pos, scale);
	edge_1.image.Init(pos, scale);
	mark_1.image.Init(pos, scale);

	back_1_copy.image.Init(VAdd(pos, VGet(0 * scale, 24 * scale, 0)), scale);
	edge_1_copy.image.Init(VAdd(pos, VGet(0 * scale, 24 * scale, 0)), scale);
	mark_1_copy.image.Init(VAdd(pos, VGet(0 * scale, 24 * scale, 0)), scale);


	back_2.image.Init(VAdd(pos, VGet(36 * scale, 0, 0)), scale);
	edge_2.image.Init(VAdd(pos, VGet(36 * scale, 0, 0)), scale);
	mark_2.image.Init(VAdd(pos, VGet(36 * scale, 0, 0)), scale);

	back_2_copy.image.Init(VAdd(pos, VGet(36 * scale, 24 * scale, 0)), scale);
	edge_2_copy.image.Init(VAdd(pos, VGet(36 * scale, 24 * scale, 0)), scale);
	mark_2_copy.image.Init(VAdd(pos, VGet(36 * scale, 24 * scale, 0)), scale);


}

void CustomNumber::Push(DiploidEngineImpact& impact, VECTOR pos, float scale)
{
	box.Init(VAdd(pos, VGet(24 * scale, -12 * scale, 0)), VScale(VGet(24, 24, 0), scale));
	box.number = OBJECT_NUMBER_PLUS_BUTTON;
	box.name_tag = "plus_button";
	impact.PushBox(box);

	box.Init(VAdd(pos, VGet(24 * scale, 12 * scale, 0)), VScale(VGet(24, 24, 0), scale));
	box.number = OBJECT_NUMBER_MINUS_BUTTON;
	box.name_tag = "minus_button";
	impact.PushBox(box);

	box.Init(VAdd(pos, VGet(-24 * scale, -12 * scale, 0)), VScale(VGet(48, 24, 0), scale));
	box.number = OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON;
	box.name_tag = "custom_number_button";
	impact.PushBox(box);

	box.Init(VAdd(pos, VGet(-24 * scale, 12 * scale, 0)), VScale(VGet(48, 24, 0), scale));
	box.number = OBJECT_NUMBER_CLEAR_BUTTON;
	box.name_tag = "clear_button";
	impact.PushBox(box);

}

void CustomNumber::Update(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//プラスボタンを押したとき
	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_PLUS_BUTTON) == true)
	{
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			custom_number += 1;//数字を増やす。
		}
	}

	//マイナスボタンを押したとき
	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_MINUS_BUTTON) == true)
	{
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			custom_number -= 1;//数字を減らす。
		}
	}

	//クリアボタンを押したとき
	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_CLEAR_BUTTON) == true)
	{
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			custom_number = 0;//数字を初期化。
		}
	}

	//インボタンを押したとき
	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON) == true)
	{
		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			if (in_active == false)
			{

				key_input_handl = MakeKeyInput(3, TRUE, TRUE, TRUE);

				in_active = true;
			}
			else
			{
				DeleteKeyInput(custom_number);

				in_active = false;
			}
		}
	}


	//数値を入力
	if (in_active == true)
	{
		DrawBox(0, (720 / 2) - 24, 1280 / 2, 720 / 2, GetColor(20, 20, 20), TRUE);

		SetActiveKeyInput(key_input_handl);

		SetDrawArea(0, (720 / 2) - 20, 1280 / 2, 720 / 2);
		DrawKeyInputString(10, (720 / 2) - 20, key_input_handl);
		SetDrawAreaFull();

		custom_number = GetKeyInputNumber(key_input_handl);


		if ((input.GetPressKey(KEY_INPUT_RETURN) == true) || (input.GetPressKey(KEY_INPUT_ESCAPE) == true))
		{
			DeleteKeyInput(custom_number);

			in_active = false;
		}
	}


	//マイナスの数値を取らないようにする。
	if (custom_number < 0)
	{
		custom_number = 0;
	}

	//999を超えない様にする
	if (custom_number > 999)
	{
		custom_number = 999;
	}
}


void CustomNumber::Draw(DiploidEngineImpact& impact, bool draw)
{
	//プラス
	back_2.image.Draw(draw);
	edge_2.image.Draw(draw);

	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_PLUS_BUTTON) == true)
	{
		mark_2.image.Draw(draw);
	}

	plus.image.Draw();


	//マイナス
	back_2_copy.image.Draw(draw);
	edge_2_copy.image.Draw(draw);

	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_MINUS_BUTTON) == true)
	{
		mark_2_copy.image.Draw(draw);
	}

	minus.image.Draw();


	//カスタム入力
	back_1.image.Draw(draw);
	edge_1.image.Draw(draw);

	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON) == true)
	{
		mark_1.image.Draw(draw);
	}

	in.image.Draw();


	//入力初期化
	back_1_copy.image.Draw(draw);
	edge_1_copy.image.Draw(draw);

	if (impact.GetBoxImpactFlag(OBJECT_NUMBER_CLEAR_BUTTON) == true)
	{
		mark_1_copy.image.Draw(draw);
	}

	clear.image.Draw();

	back_3.image.Draw();

	if (custom_number >= 0)
	{
		number_1.Draw(custom_number % 10);//数字を表示

		if (custom_number >= 10)
		{
			number_2.Draw((custom_number / 10) % 10);//数字を表示

			if (custom_number >= 100)
			{
				number_3.Draw((custom_number / 100) % 10);//数字を表示

				if (custom_number >= 1000)
				{
					number_4.Draw((custom_number / 1000) % 10);//数字を表示
				}
			}
		}
	}


	//DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", custom_number);
}
