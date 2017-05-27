#include <iostream>
#include "DxLib.h"
#include "System.h"
#include "Main_Game.h"


Main_Game::Main_Game()
{
}

void Main_Game::Main_Load()
{
	back_screen = LoadGraph("pack/ui/start_screen.png");
	main_sound.Load();
	main_dice.Load();
}

void Main_Game::Main_Init()
{
	main_filer.FileOpen_Config();
	main_net.init();
	main_dice.init();
}

void Main_Game::Main_Game_Loop()
{
	Main_Init();
	Main_Load();

	main_net.NetListen(main_filer.F_B.host, main_filer.F_B);//ネットワーク接続待機変更処理
	main_net.NetWork_wait(main_filer.F_B.host, main_filer.F_B);//ネットワーク接続または待機処理


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawGraph(0, 0, back_screen, TRUE);//背景表示


		dice_role = main_dice.Dice_role_oneDhundred(50, 50);//1d100のダイスロールボタン
		dice_role_custom = main_dice.Dice_role_custom(50, 100);
		main_dice.Critical_Fumble_Screen();//クリファン判定


		//ネットワーク処理
		if (main_filer.F_B.host == 1)//ホストの時の処理
		{
			if (CheckHitKey(KEY_INPUT_0) == 1)//音楽停止
			{
				sound_number = main_sound.stop;
			}
			else if (CheckHitKey(KEY_INPUT_1) == 1)//音楽再生　待機
			{
				sound_number = main_sound.wait;
			}
			else if (CheckHitKey(KEY_INPUT_2) == 1)//音楽再生　静かな戦闘
			{
				sound_number = main_sound.quiet_battle;
			}
			else if (CheckHitKey(KEY_INPUT_3) == 1)//音楽再生　激しい戦闘
			{
				sound_number = main_sound.intense_battle;
			}
			else if (CheckHitKey(KEY_INPUT_4) == 1)//音楽再生　平常
			{
				sound_number = main_sound.normal_time_in_game;
			}
			else if (CheckHitKey(KEY_INPUT_5) == 1)//音楽再生　神格遭遇
			{
				sound_number = main_sound.deity;
			}
			else if (CheckHitKey(KEY_INPUT_6) == 1)//音楽再生　推理
			{
				sound_number = main_sound.reasoning;
			}
			else if (CheckHitKey(KEY_INPUT_7) == 1)//音楽再生　恐怖
			{
				sound_number = main_sound.fear;
			}
			else if (CheckHitKey(KEY_INPUT_8) == 1)//音楽再生　クライマックス
			{
				sound_number = main_sound.climax;
			}

			main_net.NetSend(&dice_role, main_filer.F_B);//1d100ボタンが押されたら結果を送信
			main_net.NetSend(&main_dice.start, main_filer.F_B);//startを送信
			main_net.NetSend(&main_dice.end, main_filer.F_B);//endを送信
			main_net.NetSend(&dice_role_custom, main_filer.F_B);//カスタムダイスボタンが押されたら結果を送信
			main_net.NetSend(&main_dice.graph_drawing_flag, main_filer.F_B);//ボタンが押されたらオンにするデータを送信

			switch (sound_number)//サウンド番号を送信
			{
			case 0:	main_net.NetSend(&main_sound.stop, main_filer.F_B); break;

			case 1:	main_net.NetSend(&main_sound.wait, main_filer.F_B); break;

			case 2: main_net.NetSend(&main_sound.quiet_battle, main_filer.F_B); break;

			case 3: main_net.NetSend(&main_sound.intense_battle, main_filer.F_B); break;

			case 4: main_net.NetSend(&main_sound.normal_time_in_game, main_filer.F_B); break;

			case 5: main_net.NetSend(&main_sound.deity, main_filer.F_B); break;

			case 6: main_net.NetSend(&main_sound.reasoning, main_filer.F_B); break;

			case 7: main_net.NetSend(&main_sound.fear, main_filer.F_B); break;

			case 8: main_net.NetSend(&main_sound.climax, main_filer.F_B); break;
					
			default:
				break;
			}

			main_sound.Play(sound_number);//音楽再生

			main_net.NetConnectionData(20,300);//接続状態を確認

			//DrawFormatString(0, 0, GetColor(0, 0, 0), "click = %d", main_dice.oneD100_click);
			
		}
		else if (main_filer.F_B.host == 0)//ホストでないときの処理
		{
			main_net.NetRead(&main_dice.oneDhundred);//1d100のダイスロールの結果を受信してoneDhundred代入。
			main_net.NetRead(&main_dice.start);//startを受信してoneDhundred代入。
			main_net.NetRead(&main_dice.end);//endを受信してoneDhundred代入。
			main_net.NetRead(&main_dice.customDcustom);//1d100のダイスロールの結果を受信してoneDhundred代入。
			main_net.NetRead(&main_dice.graph_drawing_flag);//クリファン画像表示のフラグを受信してgraph_drawing_flag代入。

			main_net.NetRead(&sound_name);//受信してsound_nameに代入

			main_sound.Play(sound_name);//sound_nameをPlayに代入して音楽を再生


			/*DrawFormatString(0, 0, GetColor(0, 0, 0), "1d100 = %d", main_dice.oneDhundred);
			DrawFormatString(0, 20, GetColor(0, 0, 0), "graph_drawing_flag = %d", main_dice.graph_drawing_flag);
			DrawFormatString(0, 40, GetColor(0, 0, 0), "sound_name = %d", main_dice.oneDhundred);*/

		}


		/*DrawFormatString(0, 600, GetColor(0, 0, 0), "HOST = %d", main_filer.F_B.host);
		DrawFormatString(0, 620, GetColor(0, 0, 0), "IP_01 = %d", main_filer.F_B.ips.d1);
		DrawFormatString(0, 640, GetColor(0, 0, 0), "IP_02 = %d", main_filer.F_B.ips.d2);
		DrawFormatString(0, 660, GetColor(0, 0, 0), "IP_03 = %d", main_filer.F_B.ips.d3);
		DrawFormatString(150, 640, GetColor(0, 0, 0), "IP_04 = %d", main_filer.F_B.ips.d4);
		DrawFormatString(150, 660, GetColor(0, 0, 0), "PORT = %d", main_filer.F_B.port);*/
	}
}