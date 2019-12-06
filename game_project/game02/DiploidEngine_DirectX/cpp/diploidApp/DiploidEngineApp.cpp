#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{	
	kaitaku.SwitchButtonBOX_Load("texter/command/kaitaku.png", 128, 64);//開拓ボタンの画像をロード
	nougyou.SwitchButtonBOX_Load("texter/command/nougyou.png", 128, 64);//農業区ボタンの画像をロード
	sangyou.SwitchButtonBOX_Load("texter/command/sangyou.png", 128, 64);//産業区ボタンの画像をロード
	syougyou.SwitchButtonBOX_Load("texter/command/syougyou.png", 128, 64);//商業区ボタンの画像をロード
	sarati.SwitchButtonBOX_Load("texter/command/sarati.png", 128, 64);//更地区ボタンの画像をロード
	zikkou.OneClickButtonBOX_Load("texter/command/zikkou.png", 128, 64);//実行ボタンの画像をロード
	play.OneClickButtonBOX_Load("texter/command/teisi.png", "texter/command/sokudo_1.png", "texter/command/sokudo_2.png", 128, 64);//プレイボタンの画像をロード

	for (int count = 0; count < 9; ++count)
	{	
		field[count].SwitchButtonBOX_Load("texter/field/nasi.png", "texter/field/nouku.png", "texter/field/sanku.png", "texter/field/syouku.png", 128, 128);//各区域の初期画像をロード
	}
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{
	mouse_point.point.mouse_point_move_flag = TRUE;
	diploidEngineImpact.PushPoint(mouse_point.point);

	field_position = VGet(1280 / 2 - 64, 720 / 2 - 32, 0);
	ku_position = VGet(0, 128, 0);

	kaitaku.SwitchButtonBOX_Init(VGet(ku_position.x, ku_position.y, 0), VGet(128, 64, 0), "kaitaku");//開拓ボタンの初期化
	nougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y, 0), VGet(128, 64, 0), "nougyou");//農業区ボタンの初期化
	sangyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + 64, 0), VGet(128, 64, 0), "sangyou");//産業区ボタンの初期化
	syougyou.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 2), 0), VGet(128, 64, 0), "syougyou");//商業区の初期化
	sarati.SwitchButtonBOX_Init(VGet(ku_position.x + 128, ku_position.y + (64 * 3), 0), VGet(128, 64, 0), "sarati");//更地の初期化

	zikkou.OneClickButtonBOX_Init(VGet(ku_position.x + (128 * 2), ku_position.y, 0), VGet(128, 64, 0), "zikkou");//実行ボタンの初期化

	play.OneClickButtonBOX_Init(VGet(1280 - 128, 720 - 64, 0), VGet(128, 64, 0), "play");//プレイボタンの初期化
	play.OneClickButtonBOX_Push(diploidEngineImpact);//プレイボタンの追加

	//空の区域の初期化(4が中央)
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
			play_type = 0;
		}
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

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput) == true)//実行ボタンのアップデート
					{
						field_type[count] = 1;//農区に変更
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

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
					{
						field_type[count] = 2;//産区に変更
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

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
					{
						field_type[count] = 3;//商区に変更
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

					if (zikkou.OneClickButtonBOX_Update(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput))//実行ボタンのアップデート
					{
						field_type[count] = 0;//更地に変更
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
		if (field[count].GetSwitchButton_Flag() == true)
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

		//区域の描画
		field[count].SwitchButtonBOX_Draw(field_type[count]);
	}
}

void DiploidEngineApp::End()//engine終了前処理。
{

}