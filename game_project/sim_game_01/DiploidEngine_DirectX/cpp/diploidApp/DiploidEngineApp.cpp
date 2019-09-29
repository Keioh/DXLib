#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//ゲーム起動時に一度だけファイルを作る処理。
{

}

void DiploidEngineApp::Load()//ゲーム起動時に1回だけロードするデータ(音や画像やセーブデータやマップデータなど)
{
	command_ui.Load();//コマンドUIのロード
	season_panel.Load();//季節パネルのロード
	status_bar.Load();//ステータスバーのロード

	//時計
	test_clock_back.image.Load("texter/game/clock/back.png");
	test_clock_hour_hand.image.Load("texter/game/clock/hour_hand.png");
	test_clock_minute_hand.image.Load("texter/game/clock/minute_hand.png");
	test_clock_second_hand.image.Load("texter/game/clock/second_hand.png");


	test_map.Load();
}

void DiploidEngineApp::Init()//ゲーム起動時に一回だけ初期化したい処理を記述。
{	

	//マウスカーソル(UI画面)
	mouse_point.point.Init(VGet(0, 0, 0));
	mouse_point.point.mouse_point_move_flag = true;
	mouse_point.point.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushPoint(mouse_point.point);

	//コマンドUIの初期化とプッシュ
	command_ui.Init(VGet(0, 128, 0));
	command_ui.Push(diploidEngineImpact);

	//季節パネルの初期化とプッシュ
	season_panel.Init(VGet(0, 0, 0));
	//season_panel.Push(diploidEngineImpact);//今のところ中身なし


	//時計
	test_clock_back.image.Init(VGet(1280 - 128/2, 0 + 320/2, 0));
	test_clock_hour_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_minute_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_second_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));



	//ステータスバーの初期化とプッシュ
	status_bar.Init(VGet(0, 0, 0));
	//status_bar.Push(diploidEngineImpact);//今のところ中身なし


	test_map.Init(VGet(1280/2, 720/2, 0));
	test_map.Push(diploidEngineImpact);

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//ループ中に一度だけデータをロードしたい処理を記述。(ゲーム中にロードしたいデータなど)
{

}

void DiploidEngineApp::Updata()//アニメーションなど連続して行いたい処理。(主に数値処理)
{
	//時計
	timer++;
	if (timer > 59 * 2)
	{
		second += 1;
		
		test_clock_second_hand.image.move_speed.x = 2;

		timer = 0;
	}

	if (second > 29)
	{
		minute += 1;

		test_clock_minute_hand.image.move_speed.y = 18;

		test_clock_second_hand.image.move_speed.x = -(2 * 29);
		
		
		second = 0;	
	}

	if (minute > 11)
	{
		hour += 1;

		test_clock_hour_hand.image.move_speed.y = 24;

		test_clock_minute_hand.image.move_speed.y = -(18 * 11);
		
		
		minute = 0;	
	}

	if (hour > 7)
	{
		test_clock_hour_hand.image.move_speed.y = -(24 * 7);


		hour = 0;
	}

	test_clock_second_hand.image.Updata();		
	test_clock_minute_hand.image.Updata();	
	test_clock_hour_hand.image.Updata();


	//コマンドUIのアップデート
	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);

	//ステータスバーのアップデート
	status_bar.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//現在は当たり判定は使ってないけど、アニメーションで使用
	status_bar.StatusUpdate(command_ui.information_command);//ステータスバーの数値をコマンドUIからの情報を用いて更新

	//季節パネルのアップデート
	season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//現在は当たり判定は使ってないけど、アニメーションで使用

	static int count;
	count++;

	if (count > 5)
	{
		season_panel.NextDays();
		count = 0;
	}

	//コマンドUIがオフなら
	if (command_ui.GetUIFlag() == false)
	{
		test_map.Updata(diploidEngineImpact, diploidEngineInput);
	}

	//オブジェクト番号の自動振り分け
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//結果を描写する処理
{	
	test_map.Draw();

	//コマンドUIの描写
	command_ui.Draw();

	//ステータスバーの描写
	status_bar.Draw();
	status_bar.StatusDraw(command_ui.information_command);//ステータスバーにコマンドUIからの数値を出力

	//季節パネルの描写
	season_panel.Draw();

	//時計
	test_clock_back.image.Draw();
	test_clock_hour_hand.image.Draw();
	test_clock_minute_hand.image.Draw();
	test_clock_second_hand.image.Draw();

}

void DiploidEngineApp::End()//engine終了前処理。
{

}