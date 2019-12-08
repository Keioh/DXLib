#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	status.image.Load("texter/ui/status.png");//ステータス画像のロード
	status_down.image.Load("texter/ui/status_down.png");//ステータス下部の画像のロード
	nouku_setumei.image.Load("texter/ui/nouku_setumei.png");//ステータス下部の農区説明画像のロード
	sanku_setumei.image.Load("texter/ui/sanku_setumei.png");//ステータス下部の産区説明画像のロード
	syouku_setumei.image.Load("texter/ui/syouku_setumei.png");//ステータス下部の商区説明画像のロード
	kaitaku_setumei.image.Load("texter/ui/kaitaku_setumei.png");//ステータス下部の開拓説明画像のロード
	sarati_setumei.image.Load("texter/ui/sarati_setumei.png");//ステータス下部の更地説明画像のロード
	play_setumei.image.Load("texter/ui/play_setumei.png");//ステータス下部のプレイボタン説明画像のロード

	kaitaku.SwitchButtonBOX_Load("texter/command/kaitaku.png", 128, 64);//開拓ボタンの画像をロード
	nougyou.SwitchButtonBOX_Load("texter/command/nougyou.png", 128, 64);//農業区ボタンの画像をロード
	sangyou.SwitchButtonBOX_Load("texter/command/sangyou.png", 128, 64);//産業区ボタンの画像をロード
	syougyou.SwitchButtonBOX_Load("texter/command/syougyou.png", 128, 64);//商業区ボタンの画像をロード
	sarati.SwitchButtonBOX_Load("texter/command/sarati.png", 128, 64);//更地区ボタンの画像をロード
	zikkou.OneClickButtonBOX_Load("texter/command/zikkou.png", 128, 64);//実行ボタンの画像をロード
	play.OneClickButtonBOX_Load("texter/command/teisi.png", "texter/command/sokudo_1.png", "texter/command/sokudo_2.png", 128, 64);//プレイボタンの画像をロード

	for (int count = 0; count < 9; ++count)
	{
		kaitaku_nouku[count].image.Load("texter/field/nouku_kaitaku_tyu.png");//農区を開拓中画像のロード
		kaitaku_syouku[count].image.Load("texter/field/syouku_kaitaku_tyu.png");//商区を開拓中画像のロード
		kaitaku_sanku[count].image.Load("texter/field/sanku_kaitaku_tyu.png");//産区を開拓中画像のロード
		kaitaku_sarati[count].image.Load("texter/field/sarati_kaitaku_tyu.png");//更地を開拓中画像のロード
		double_1_05[count].image.Load("texter/field/1_05.png");//1.05倍画像のロード
		double_1_025[count].image.Load("texter/field/1_025.png");//1.025倍画像のロード

		if (count == 4)
		{
			field[4].SwitchButtonBOX_Load("texter/field/tyuuou.png", 128, 128);//中央区ボタンの画像をロード
		}
		else
		{
			field[count].SwitchButtonBOX_Load("texter/field/nasi.png", "texter/field/nouku.png", "texter/field/sanku.png", "texter/field/syouku.png", 128, 128);//各区域の初期画像をロード
		}
	}
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	for (int count = 0; count < 9; ++count)
	{
		sakumotu_scale[count] = 1.0f;
		sikinn_scale[count] = 1.0f;
		sannsyutu_scale[count] = 1.0f;
	}

	status.image.Init(VGet(384/2, 64, 0));//ステータス画像の初期化
	status_down.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部画像の初期化
	nouku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部の農区説明画像の初期化
	sanku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部の産区説明画像の初期化
	syouku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部の商区説明画像の初期化
	kaitaku_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部の開拓説明画像の初期化
	sarati_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部の更地説明画像の初期化
	play_setumei.image.Init(VGet(1280 / 2, 720 - 16, 0));//ステータス下部のプレイボタン説明画像の初期化

	mouse_point.point.mouse_point_move_flag = TRUE;
	diploidEngineImpact.PushPoint(mouse_point.point);

	field_position = VGet(1280 / 2 - 64, 720 / 2 - 32, 0);
	ku_position = VGet(0, 128, 0);

	//区域情報画像の初期化
	{
		kaitaku_nouku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[0].image.Init(VGet(field_position.x - 128 + 64, field_position.y - 128 + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[1].image.Init(VGet(field_position.x + 64, field_position.y - 128 + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[2].image.Init(VGet(field_position.x + 128 + 64, field_position.y - 128 + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//更地を開拓中画像の初期化
		double_1_05[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//1.05倍画像の初期化
		double_1_025[3].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//更地を開拓中画像の初期化
		double_1_05[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//1.05倍画像の初期化
		double_1_025[4].image.Init(VGet(field_position.x + 64, field_position.y + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//更地を開拓中画像の初期化
		double_1_05[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//1.05倍画像の初期化
		double_1_025[5].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[6].image.Init(VGet(field_position.x - 128 + 64, field_position.y + 128 + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[7].image.Init(VGet(field_position.x + 64, field_position.y + 128 + 64, 0));//1.025倍画像の初期化

		kaitaku_nouku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//農区を開拓中画像の初期化
		kaitaku_syouku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//商区を開拓中画像の初期化
		kaitaku_sanku[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//産区を開拓中画像の初期化
		kaitaku_sarati[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//更地を開拓中画像の初期化
		double_1_05[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//1.05倍画像の初期化
		double_1_025[8].image.Init(VGet(field_position.x + 128 + 64, field_position.y + 128 + 64, 0));//1.025倍画像の初期化

	}

	kaitaku.SwitchButtonBOX_Init(VGet(ku_position.x, ku_position.y, 0), VGet(128, 64, 0), "kaitaku");//開拓ボタンの初期化
	nougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y, 0), VGet(128, 64, 0), "nougyou");//農業区ボタンの初期化
	sangyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + 64, 0), VGet(128, 64, 0), "sangyou");//産業区ボタンの初期化
	syougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 2), 0), VGet(128, 64, 0), "syougyou");//商業区の初期化
	sarati.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 3), 0), VGet(128, 64, 0), "sarati");//更地の初期化

	zikkou.OneClickButtonBOX_Init(VGet(ku_position.x + (128 * 2), ku_position.y, 0), VGet(128, 64, 0), "zikkou");//実行ボタンの初期化

	play.OneClickButtonBOX_Init(VGet(1280 - 128, 720 - 64 - 32, 0), VGet(128, 64, 0), "play");//プレイボタンの初期化
	play.OneClickButtonBOX_Push(diploidEngineImpact);//プレイボタンの追加

	//空の区域の初期化(4が中央)
	{
		field[0].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_0", DIPLOID_LAYER_00);
		field[0].SwitchButtonBOX_Push(diploidEngineImpact);

		field[1].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_1", DIPLOID_LAYER_00);
		field[1].SwitchButtonBOX_Push(diploidEngineImpact);

		field[2].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y - 128, 0), VGet(128, 128, 0), "main_field_2", DIPLOID_LAYER_00);
		field[2].SwitchButtonBOX_Push(diploidEngineImpact);

		field[3].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y, 0), VGet(128, 128, 0), "main_field_3", DIPLOID_LAYER_00);
		field[3].SwitchButtonBOX_Push(diploidEngineImpact);

		field[4].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y, 0), VGet(128, 128, 0), "main_field_4", DIPLOID_LAYER_00);
		field[4].SwitchButtonBOX_Push(diploidEngineImpact);

		field[5].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y, 0), VGet(128, 128, 0), "main_field_5", DIPLOID_LAYER_00);
		field[5].SwitchButtonBOX_Push(diploidEngineImpact);

		field[6].SwitchButtonBOX_Init(VGet(field_position.x - 128, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_6", DIPLOID_LAYER_00);
		field[6].SwitchButtonBOX_Push(diploidEngineImpact);

		field[7].SwitchButtonBOX_Init(VGet(field_position.x, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_7", DIPLOID_LAYER_00);
		field[7].SwitchButtonBOX_Push(diploidEngineImpact);

		field[8].SwitchButtonBOX_Init(VGet(field_position.x + 128, field_position.y + 128, 0), VGet(128, 128, 0), "main_field_8", DIPLOID_LAYER_00);
		field[8].SwitchButtonBOX_Push(diploidEngineImpact);
	}
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//プレイボタンの処理
	if (play.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
	{
		play_type += 1;

		if (play_type > 2)
		{
			play_type = 0;//停止に戻る。
		}
	}

	if (play_type == 1)//ゲーム速度1倍のときの処理
	{
		//時間の処理
		++fps_time;//時間を増やす。

		if (fps_time >= 5)
		{
			++second;//秒を増やす
			fps_time = 0;//初期化
		}

		if (second >= 1)
		{
			++minute;//分を増やす
			second = 0;//初期化
		}

		if (minute >= 1)
		{
			++hour;//時を増やす。
			minute = 0;//初期化
		}

		if (hour >= 24)
		{
			day_flag = true;//日が増えたフラグをオンにする。
			++day;//日を増やす。
			hour = 0;//初期化
		}

		//日が進んだら(for文前処理)
		if (day_flag == true)
		{
			//収入情報の初期化
			sakumotu_syuunyuu = 0;
			sannsyutu_syuunyuu = 0;
			sikin_syuunyuu = 0;
		}

		//開拓と収入の処理
		for (int count = 0; count < 9; ++count)
		{
			//日が進んだら
			if (day_flag == true)
			{
				if (kaitaku_time[count] != 0)//開拓時間が0でないなら
				{
					--kaitaku_time[count];//開拓時間を減らす
				}

				//収入処理
				switch (count)
				{
				case 0:
					if (field_type[0] == 1)//農区であれば
					{
						sakumotu_scale[0] = 1.0f;

						if (field_type[1] == 1)
						{
							sakumotu_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 1)
						{
							sakumotu_scale[0] += all_basic_scale;
						}	

						sakumotu += 5 * sakumotu_scale[0];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[0];//作物の収入情報を増やす
					}
					if (field_type[0] == 2)//産区であれば
					{
						sannsyutu_scale[0] = 1.0f;

						if (field_type[1] == 2)
						{
							sannsyutu_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 2)
						{
							sannsyutu_scale[0] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[0];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[0];//産出の収入情報を増やす
					}
					if (field_type[0] == 3)//商区であれば
					{
						sikinn_scale[0] = 1.0f;

						if (field_type[1] == 3)
						{
							sikinn_scale[0] += all_basic_scale;
						}
						if (field_type[3] == 3)
						{
							sikinn_scale[0] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[0];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[0];//産出の収入情報を増やす

					}
					break;

				case 1:
					if (field_type[1] == 1)//農区であれば
					{
						sakumotu_scale[1] = 1.0f;

						if (field_type[0] == 1)
						{
							sakumotu_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 1)
						{
							sakumotu_scale[1] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[1];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[1];//作物の収入情報を増やす
					}
					if (field_type[1] == 2)//産区であれば
					{
						sannsyutu_scale[1] = 1.0f;

						if (field_type[0] == 2)
						{
							sannsyutu_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 2)
						{
							sannsyutu_scale[1] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[1];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[1];//産出の収入情報を増やす
					}
					if (field_type[1] == 3)//商区であれば
					{
						sikinn_scale[1] = 1.0f;

						if (field_type[0] == 3)
						{
							sikinn_scale[1] += all_basic_scale;
						}
						if (field_type[2] == 3)
						{
							sikinn_scale[1] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[1];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[1];//産出の収入情報を増やす
					}
					break;

				case 2:
					if (field_type[2] == 1)//農区であれば
					{
						sakumotu_scale[2] = 1.0f;

						if (field_type[1] == 1)
						{
							sakumotu_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 1)
						{
							sakumotu_scale[2] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[2];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[2];//作物の収入情報を増やす
					}
					if (field_type[2] == 2)//産区であれば
					{
						sannsyutu_scale[2] = 1.0f;

						if (field_type[1] == 2)
						{
							sannsyutu_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 2)
						{
							sannsyutu_scale[2] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[2];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[2];//産出の収入情報を増やす
					}
					if (field_type[2] == 3)//商区であれば
					{
						sikinn_scale[2] = 1.0f;

						if (field_type[1] == 3)
						{
							sikinn_scale[2] += all_basic_scale;
						}
						if (field_type[5] == 3)
						{
							sikinn_scale[2] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[2];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[2];//産出の収入情報を増やす
					}

				case 3:
					if (field_type[3] == 1)//農区であれば
					{
						sakumotu_scale[3] = 1.0f;

						if (field_type[0] == 1)
						{
							sakumotu_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 1)
						{
							sakumotu_scale[3] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[3];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[3];//作物の収入情報を増やす
					}
					if (field_type[3] == 2)//産区であれば
					{
						sannsyutu_scale[3] = 1.0f;

						if (field_type[0] == 2)
						{
							sannsyutu_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 2)
						{
							sannsyutu_scale[3] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[3];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[3];//産出の収入情報を増やす
					}
					if (field_type[3] == 3)//商区であれば
					{
						sikinn_scale[3] = 1.0f;

						if (field_type[0] == 3)
						{
							sikinn_scale[3] += all_basic_scale;
						}
						if (field_type[6] == 3)
						{
							sikinn_scale[3] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[3];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[3];//産出の収入情報を増やす
					}
					break;

				case 5:
					if (field_type[5] == 1)//農区であれば
					{
						sakumotu_scale[5] = 1.0f;

						if (field_type[2] == 1)
						{
							sakumotu_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 1)
						{
							sakumotu_scale[5] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[5];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[5];//作物の収入情報を増やす
					}
					if (field_type[5] == 2)//産区であれば
					{
						sannsyutu_scale[5] = 1.0f;

						if (field_type[2] == 2)
						{
							sannsyutu_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 2)
						{
							sannsyutu_scale[5] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[5];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[5];//産出の収入情報を増やす
					}
					if (field_type[5] == 3)//商区であれば
					{
						sikinn_scale[5] = 1.0f;

						if (field_type[2] == 3)
						{
							sikinn_scale[5] += all_basic_scale;
						}
						if (field_type[8] == 3)
						{
							sikinn_scale[5] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[5];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[5];//産出の収入情報を増やす
					}
					break;

				case 6:
					if (field_type[6] == 1)//農区であれば
					{
						sakumotu_scale[6] = 1.0f;

						if (field_type[3] == 1)
						{
							sakumotu_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 1)
						{
							sakumotu_scale[6] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[6];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[6];//作物の収入情報を増やす
					}
					if (field_type[6] == 2)//産区であれば
					{
						sannsyutu_scale[6] = 1.0f;

						if (field_type[3] == 2)
						{
							sannsyutu_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 2)
						{
							sannsyutu_scale[6] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[6];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[6];//産出の収入情報を増やす
					}
					if (field_type[6] == 3)//商区であれば
					{
						sikinn_scale[6] = 1.0f;

						if (field_type[3] == 3)
						{
							sikinn_scale[6] += all_basic_scale;
						}
						if (field_type[7] == 3)
						{
							sikinn_scale[6] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[6];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[6];//産出の収入情報を増やす
					}
					break;

				case 7:
					if (field_type[7] == 1)//農区であれば
					{
						sakumotu_scale[7] = 1.0f;

						if (field_type[6] == 1)
						{
							sakumotu_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 1)
						{
							sakumotu_scale[7] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[7];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[7];//作物の収入情報を増やす
					}
					if (field_type[7] == 2)//産区であれば
					{
						sannsyutu_scale[7] = 1.0f;

						if (field_type[6] == 2)
						{
							sannsyutu_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 2)
						{
							sannsyutu_scale[7] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[7];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[7];//産出の収入情報を増やす
					}
					if (field_type[7] == 3)//商区であれば
					{
						sikinn_scale[7] = 1.0f;

						if (field_type[6] == 3)
						{
							sikinn_scale[7] += all_basic_scale;
						}
						if (field_type[8] == 3)
						{
							sikinn_scale[7] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[7];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[7];//産出の収入情報を増やす
					}
					break;

				case 8:
					if (field_type[8] == 1)//農区であれば
					{
						sakumotu_scale[8] = 1.0f;

						if (field_type[5] == 1)
						{
							sakumotu_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 1)
						{
							sakumotu_scale[8] += all_basic_scale;
						}

						sakumotu += 5 * sakumotu_scale[8];//作物を増やす
						sakumotu_syuunyuu += 5 * sakumotu_scale[8];//作物の収入情報を増やす
					}
					if (field_type[8] == 2)//産区であれば
					{
						sannsyutu_scale[8] = 1.0f;

						if (field_type[5] == 2)
						{
							sannsyutu_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 2)
						{
							sannsyutu_scale[8] += all_basic_scale;
						}

						sannsyutu += 1 * sannsyutu_scale[8];//産出を増やす
						sannsyutu_syuunyuu += 1 * sannsyutu_scale[8];//産出の収入情報を増やす
					}
					if (field_type[8] == 3)//商区であれば
					{
						sikinn_scale[8] = 1.0f;

						if (field_type[5] == 3)
						{
							sikinn_scale[8] += all_basic_scale;
						}
						if (field_type[7] == 3)
						{
							sikinn_scale[8] += all_basic_scale;
						}

						sikinn += 10 * sikinn_scale[8];//産出を増やす
						sikin_syuunyuu += 10 * sikinn_scale[8];//産出の収入情報を増やす
					}
					break;

				default:
					break;
				}
			}

			if (kaitaku_time[count] <= 0)//開拓時間が0になったら
			{
				field_type[count] = kaitaku_type[count];//区域タイプを変更
				kaitaku_time[count] = 0;//開拓時間の初期化
			}
		}

		//日が進んだら(for文後処理)
		if (day_flag == true)
		{
			//人口の処理
			if ((sakumotu - (jinkou * 0.5)) >= jinkou)//作物の保有量が人口の5割を引いた分より多ければ
			{
				sakumotu -= jinkou * 0.5;//人口の5割分の作物を消費
				jinkou += sakumotu * 0.05;//作物の0.5割分の人口を増やす

				jinkou_zouka = sakumotu * 0.05;//人口増加量の情報を代入
				sakumotu_syouhi = -jinkou * 0.5;//作物の消費量情報を代入
			}
			else
			{
				sakumotu -= jinkou * 0.5;//人口の5割分の作物を消費
				jinkou -= jinkou * 0.1;//作物が足りなかったら人口を2割減らす。

				jinkou_zouka = -jinkou * 0.1 - 1;//人口増加量の情報を代入
				sakumotu_syouhi = -jinkou * 0.5;//作物の消費量情報を代入

			}
		}

		if (sakumotu <= 0)//作物が0以下になったら0にする。
		{
			sakumotu = 0;
		}


		day_flag = false;//日が進んだフラグをオフにする。
	}


	for (int count = 0; count < 9; ++count)
	{
		//どれかの区域を選択していれば
		if (field[count].SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
		{
			//クリックした場所以外のフラグをFALSEに変更する
			for (int flag_count = 0; flag_count < 9; ++flag_count)
			{
				if (count != flag_count)
				{
					if (field[flag_count].GetSwitchButton_Flag() == true)
					{
						field[flag_count].SwitchButton_Flag_Change(false);//選択した区域以外の区域の選択を解除

						kaitaku.SwitchButton_Flag_Change(false);//開拓ボタンをFALSEに
						nougyou.SwitchButton_Flag_Change(false);//農業区ボタンをFALSEに
						sangyou.SwitchButton_Flag_Change(false);//産業区ボタンをFALSEに
						syougyou.SwitchButton_Flag_Change(false);//商業区ボタンをFALSEに
						sarati.SwitchButton_Flag_Change(false);//更地ボタンをFALSEに
					}
				}
			}			

			//中央区以外を選択しているときのコマンド
			if (count != 4)
			{
				kaitaku_system.OnePushBOX_Impact(diploidEngineImpact, kaitaku.box);//開拓ボタンの追加
				kaitaku_system.FlagReset_OneDeleteBOX();//開拓ボタンの削除フラグをリセット			

					//開拓ボタン
				if (kaitaku.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
				{
					nougyou_system.OnePushBOX_Impact(diploidEngineImpact, nougyou.box);//農業区ボタンの追加
					sangyou_system.OnePushBOX_Impact(diploidEngineImpact, sangyou.box);//産業区ボタンの追加
					syougyou_system.OnePushBOX_Impact(diploidEngineImpact, syougyou.box);//商業区ボタンの追加
					sarati_system.OnePushBOX_Impact(diploidEngineImpact, sarati.box);//更地ボタンの追加

					nougyou_system.FlagReset_OneDeleteBOX();//農業区ボタンの削除フラグをリセット
					sangyou_system.FlagReset_OneDeleteBOX();//産業区ボタンの削除フラグをリセット
					syougyou_system.FlagReset_OneDeleteBOX();//商業区ボタンの削除フラグをリセット
					sarati_system.FlagReset_OneDeleteBOX();//更地ボタンの削除フラグをリセット

					//農業区域ボタンのアップデート
					if (nougyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
					{
						sangyou.SwitchButton_Flag_Change(false);//産業区のボタンをオフにする。
						syougyou.SwitchButton_Flag_Change(false);//商業区のボタンをオフにする。
						sarati.SwitchButton_Flag_Change(false);//更地のボタンをオフにする。

						zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//実行ボタンの追加
						zikkou_system.FlagReset_OneDeleteBOX();//実行ボタンの削除フラグをリセットする。

						if ((sikinn - 200) >= 0)//資金から200減らしても0にならなければ
						{
							if ((sannsyutu - 2) >= 0)//産出から2減らしても0にならなければ
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)//実行ボタンのアップデート
								{
									kaitaku_time[count] = 7;//開拓時間を90に設定
									kaitaku_type[count] = 1;//農区に変更
									sikinn -= 200;//資金を減らす。
									sannsyutu -= 2;//産出を減らす
								}
							}
						}
					}

					//産業区域ボタンのアップデート
					if (sangyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
					{
						nougyou.SwitchButton_Flag_Change(false);//農業区のボタンをオフにする。
						syougyou.SwitchButton_Flag_Change(false);//商業区のボタンをオフにする。
						sarati.SwitchButton_Flag_Change(false);//更地のボタンをオフにする。

						zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//実行ボタンの追加
						zikkou_system.FlagReset_OneDeleteBOX();//実行ボタンの削除フラグをリセットする。

						if ((sikinn - 300) >= 0)//資金から300減らしても0にならなければ
						{
							if ((sannsyutu - 4) >= 0)//産出から4減らしても0にならなければ
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
								{
									kaitaku_time[count] = 7;//開拓時間を90に設定
									kaitaku_type[count] = 2;//産区に変更
									sikinn -= 300;//資金を減らす。
									sannsyutu -= 4;//産出を減らす
								}
							}
						}
					}

					//商業区域ボタンのアップデート
					if (syougyou.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
					{
						nougyou.SwitchButton_Flag_Change(false);//農業区のボタンをオフにする。
						sangyou.SwitchButton_Flag_Change(false);//産業区のボタンをオフにする。
						sarati.SwitchButton_Flag_Change(false);//更地のボタンをオフにする。

						zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//実行ボタンの追加
						zikkou_system.FlagReset_OneDeleteBOX();//実行ボタンの削除フラグをリセットする。

						if ((sikinn - 500) >= 0)//資金から500減らしても0にならなければ
						{
							if ((sannsyutu - 3) >= 0)//産出から3減らしても0にならなければ
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
								{
									kaitaku_time[count] = 7;//開拓時間を90に設定
									kaitaku_type[count] = 3;//商区に変更
									sikinn -= 500;//資金を減らす。
									sannsyutu -= 3;//産出を減らす
								}
							}
						}
					}

					//更地ボタンのアップデート
					if (sarati.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)
					{
						nougyou.SwitchButton_Flag_Change(false);//農業区のボタンをオフにする。
						sangyou.SwitchButton_Flag_Change(false);//産業区のボタンをオフにする。
						syougyou.SwitchButton_Flag_Change(false);//商業区のボタンをオフにする。

						zikkou_system.OnePushBOX_Impact(diploidEngineImpact, zikkou.box);//実行ボタンの追加
						zikkou_system.FlagReset_OneDeleteBOX();//実行ボタンの削除フラグをリセットする。

						if ((sikinn - 100) >= 0)//資金から100減らしても0にならなければ
						{
							if ((sannsyutu - 2) >= 0)//産出から2減らしても0にならなければ
							{
								if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
								{
									kaitaku_time[count] = 7;//開拓時間を90に設定
									kaitaku_type[count] = 0;//更地に変更
									sikinn -= 100;//資金を減らす。
									sannsyutu -= 2;//産出を減らす
								}
							}
						}
					}

					//区域ボタンのフラグ計算処理
					nougyou_sangyou_syougou_flags = (nougyou.GetSwitchButton_Flag() || sangyou.GetSwitchButton_Flag() || syougyou.GetSwitchButton_Flag() || sarati.GetSwitchButton_Flag());

					if (nougyou_sangyou_syougou_flags == false)//区域ボタンすべてがオフなら
					{
						zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//実行ボタンの削除
						zikkou_system.FlagReset_OnePushBOX();//実行ボタンの追加フラグをリセット
					}
				}
				else//開拓ボタンがオフのとき
				{
					nougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "nougyou");//農業区ボタンの削除
					sangyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "sangyou");//産業区ボタンの削除
					syougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "syougyou");//商業区ボタンの削除
					sarati_system.OneDeleteBOX_Impact(diploidEngineImpact, "sarati");//更地ボタンの削除
					zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//実行ボタンの削除

					nougyou_system.FlagReset_OnePushBOX();//農業区ボタンの追加フラグをリセット
					sangyou_system.FlagReset_OnePushBOX();//産業区ボタンの追加フラグをリセット
					syougyou_system.FlagReset_OnePushBOX();//商業区ボタンの追加フラグをリセット
					sarati_system.FlagReset_OnePushBOX();//更地ボタンの追加フラグをリセット
					zikkou_system.FlagReset_OnePushBOX();//実行ボタンの追加フラグをリセット
				}
			}
			else//コマンドボタンの削除処理を書く。
			{
				kaitaku.SwitchButton_Flag_Change(false);//開拓ボタンをFALSEに
				kaitaku_system.OneDeleteBOX_Impact(diploidEngineImpact, "kaitaku");//開拓ボタンの削除
				kaitaku_system.FlagReset_OnePushBOX();//開拓ボタンの追加フラグをリセット

				nougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "nougyou");//農業区ボタンの削除
				sangyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "sangyou");//産業区ボタンの削除
				syougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "syougyou");//商業区ボタンの削除
				sarati_system.OneDeleteBOX_Impact(diploidEngineImpact, "sarati");//更地ボタンの削除
				zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//実行ボタンの削除

				nougyou_system.FlagReset_OnePushBOX();//農業区ボタンの追加フラグをリセット
				sangyou_system.FlagReset_OnePushBOX();//産業区ボタンの追加フラグをリセット
				syougyou_system.FlagReset_OnePushBOX();//商業区ボタンの追加フラグをリセット
				sarati_system.FlagReset_OnePushBOX();//更地ボタンの追加フラグをリセット
				zikkou_system.FlagReset_OnePushBOX();//実行ボタンの追加フラグをリセット

			}
		}		
	}	

	//区域タイルのフラグの計算処理
	field_all_flag = field[0].GetSwitchButton_Flag() || field[1].GetSwitchButton_Flag() || field[2].GetSwitchButton_Flag() || field[3].GetSwitchButton_Flag() || field[4].GetSwitchButton_Flag() || field[5].GetSwitchButton_Flag() || field[6].GetSwitchButton_Flag() || field[7].GetSwitchButton_Flag() || field[8].GetSwitchButton_Flag();
	
	//ボタン類の削除と初期化処理
	if (field_all_flag == false)
	{
		kaitaku.SwitchButton_Flag_Change(false);//開拓ボタンをFALSEに
		nougyou.SwitchButton_Flag_Change(false);//農業区ボタンをFALSEに
		sangyou.SwitchButton_Flag_Change(false);//産業区ボタンをFALSEに
		syougyou.SwitchButton_Flag_Change(false);//商業区ボタンをFALSEに
		sarati.SwitchButton_Flag_Change(false);//更地ボタンをFALSEに

		kaitaku_system.OneDeleteBOX_Impact(diploidEngineImpact, "kaitaku");//開拓ボタンの削除
		kaitaku_system.FlagReset_OnePushBOX();//開拓ボタンの追加フラグをリセット

		nougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "nougyou");//農業区ボタンの削除
		sangyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "sangyou");//産業区ボタンの削除
		syougyou_system.OneDeleteBOX_Impact(diploidEngineImpact, "syougyou");//商業区ボタンの削除
		sarati_system.OneDeleteBOX_Impact(diploidEngineImpact, "sarati");//更地ボタンの削除
		zikkou_system.OneDeleteBOX_Impact(diploidEngineImpact, "zikkou");//実行ボタンの削除

		nougyou_system.FlagReset_OnePushBOX();//農業区ボタンの追加フラグをリセット
		sangyou_system.FlagReset_OnePushBOX();//産業区ボタンの追加フラグをリセット
		syougyou_system.FlagReset_OnePushBOX();//商業区ボタンの追加フラグをリセット
		zikkou_system.FlagReset_OnePushBOX();//実行ボタンの追加フラグをリセット
		sarati_system.FlagReset_OnePushBOX();//更地ボタンの追加フラグをリセット

	}
}

void DiploidEngineApp::Draw()//結果を描写する処理
{
	//プレイボタンの描画
	play.OneClickButtonBOX_Draw(play_type);

	//区域とコマンドボタンの表示
	for (int count = 0; count < 9; ++count)
	{
		//コマンドの表示
		if (field[count].GetSwitchButton_Flag() == true)
		{
			//中央区以外の区域を選択したとき
			if (count != 4)
			{
				//開拓ボタンの描画
				kaitaku.SwitchButtonBOX_Draw();

				//開拓ボタンがオンなら
				if (kaitaku.GetSwitchButton_Flag() == true)
				{
					nougyou.SwitchButtonBOX_Draw();
					sangyou.SwitchButtonBOX_Draw();
					syougyou.SwitchButtonBOX_Draw();
					sarati.SwitchButtonBOX_Draw();

					if ((nougyou.GetSwitchButton_Flag() || sangyou.GetSwitchButton_Flag() || syougyou.GetSwitchButton_Flag() || sarati.GetSwitchButton_Flag()) == true)
					{
						zikkou.OneClickButtonBOX_Draw();
					}
				}
			}
		}

		//区域の描画
		field[count].SwitchButtonBOX_Draw(field_type[count]);	
		
		//開拓中の情報表示
		if (kaitaku_time[count] != 0)
		{
			//区域の開拓状態によって表示を変える
			switch (count)
			{
			case 0: DrawFormatString(field_position.x - 128 + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[0]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 1: DrawFormatString(field_position.x + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[1]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 2: DrawFormatString(field_position.x + 128 + 60, field_position.y - 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[2]);
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 3: DrawFormatString(field_position.x - 128 + 60, field_position.y + 60, GetColor(0, 0, 0), "%d", kaitaku_time[3]);	
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 4: DrawFormatString(field_position.x, field_position.y, GetColor(0, 0, 0), "%d", kaitaku_time[4]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 5: DrawFormatString(field_position.x + 128 + 60, field_position.y + 60, GetColor(0, 0, 0), "%d", kaitaku_time[5]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 6: DrawFormatString(field_position.x - 128 + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[6]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 7: DrawFormatString(field_position.x + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[7]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			case 8: DrawFormatString(field_position.x + 128 + 60, field_position.y + 128 + 60, GetColor(0, 0, 0), "%d", kaitaku_time[8]); 
					if (kaitaku_type[count] == 0) kaitaku_sarati[count].image.Draw();
					if (kaitaku_type[count] == 1) kaitaku_nouku[count].image.Draw();
					if (kaitaku_type[count] == 2) kaitaku_sanku[count].image.Draw();
					if (kaitaku_type[count] == 3) kaitaku_syouku[count].image.Draw();
					break;
			default:
				break;
			}
		}

		//区域情報の表示
		if ((sakumotu_scale[count] == 1.025f) || (sannsyutu_scale[count] == 1.025f) || (sikinn_scale[count] == 1.025f)) double_1_025[count].image.Draw();
		if ((sakumotu_scale[count] == 1.05f) || (sannsyutu_scale[count] == 1.05f) || (sikinn_scale[count] == 1.05f)) double_1_05[count].image.Draw();
	}

	//ステータスの描画
	status.image.Draw();//ステータス画像の描画
	DrawFormatString(128, 20, GetColor(0, 0, 0), "%d", sikinn);//資金
	DrawFormatString(128, 60, GetColor(0, 0, 0), "%d", sakumotu);//作物
	DrawFormatString(128, 100, GetColor(0, 0, 0), "%d", sannsyutu);//生産
	DrawFormatString(128 * 3 - 90, 100, GetColor(0, 0, 0), "%d", day);//日
	DrawFormatString(128 * 3 - 60, 20, GetColor(0, 0, 0), "%d", jinkou);//人口

	//ステータス下部の描画
	status_down.image.Draw();
	DrawFormatString(100, 698, GetColor(0, 0, 0), "%d", sannsyutu_syuunyuu);//産出収入
	DrawFormatString(128 * 2 - 28, 698, GetColor(0, 0, 0), "%d", sikin_syuunyuu);//資金収入
	DrawFormatString(128 * 3 - 24, 698, GetColor(0, 0, 0), "%d", sakumotu_syuunyuu);//作物収入
	DrawFormatString(128 * 4 + 8, 698, GetColor(0, 0, 0), "%d", jinkou_zouka);//人口増加量
	DrawFormatString(128 * 5 + 34, 698, GetColor(0, 0, 0), "%d", sakumotu_syouhi);//作物消費量

	if (nougyou.GetSwitchButton_HitFlag() == true) nouku_setumei.image.Draw();//農区の説明
	if (sangyou.GetSwitchButton_HitFlag() == true) sanku_setumei.image.Draw();//産区の説明
	if (syougyou.GetSwitchButton_HitFlag() == true) syouku_setumei.image.Draw();//商区の説明
	if (kaitaku.GetSwitchButton_HitFlag() == true) kaitaku_setumei.image.Draw();//開拓コマンドの説明
	if (sarati.GetSwitchButton_HitFlag() == true) sarati_setumei.image.Draw();//更地の説明
	if (play.GetOneClickButton_HitFlag() == true) play_setumei.image.Draw();//プレイボタンの説明

}

void DiploidEngineApp::End()//engine終了前処理。
{

}