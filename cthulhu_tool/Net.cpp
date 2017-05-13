#include "Net.h"

NET_GAMING::NET_GAMING()
{
	break_flag = true;
	count = 0;
	false_flag = false;
	bool_buffer = true;		
	int_buffer = 0;
}

void NET_GAMING::init()
{
	for (int i = 0; i >= 256; i++)
	{
		connection[i] = -1;		//接続状態
		net[i] = -1;			//ネットワークハンドル保存用

		char_buffer_00[i];//バッファー
		char_buffer_01[i];//バッファー
		char_buffer_02[i];//バッファー
		char_buffer_03[i];//バッファー
		char_buffer_04[i];//バッファー
		char_buffer_05[i];//バッファー
		char_buffer_06[i];//バッファー
		char_buffer_07[i];//バッファー
	}
}

void NET_GAMING::NetListen(int host_flag, FILER_S host_info)
{
	if (host_flag == 1)
	{
		PreparationListenNetWork(host_info.port);//接続を受けられる状態にする。
	}
	else
	{
		StopListenNetWork();//接続を受けられる状態を解除する。
	}
}

void NET_GAMING::NetConnectionData()
{
	//接続状態を得る。
	connection[0] = GetNetWorkAcceptState(net[0]);
	connection[1] = GetNetWorkAcceptState(net[1]);
	connection[2] = GetNetWorkAcceptState(net[2]);
	connection[3] = GetNetWorkAcceptState(net[3]);
	connection[4] = GetNetWorkAcceptState(net[4]);
	connection[5] = GetNetWorkAcceptState(net[5]);
	connection[6] = GetNetWorkAcceptState(net[6]);
	connection[7] = GetNetWorkAcceptState(net[7]);

	//コネクション確認
	DrawFormatString(80, 100, GetColor(0, 0, 0), "接続状態 PC1 %d", connection[0]);
	DrawFormatString(80, 120, GetColor(0, 0, 0), "接続状態 PC2 %d", connection[1]);
	DrawFormatString(80, 140, GetColor(0, 0, 0), "接続状態 PC3 %d", connection[2]);
	DrawFormatString(80, 160, GetColor(0, 0, 0), "接続状態 PC4 %d", connection[3]);
	DrawFormatString(80, 180, GetColor(0, 0, 0), "接続状態 PC5 %d", connection[4]);
	DrawFormatString(80, 200, GetColor(0, 0, 0), "接続状態 PC6 %d", connection[5]);
	DrawFormatString(80, 220, GetColor(0, 0, 0), "接続状態 PC7 %d", connection[6]);
	DrawFormatString(80, 240, GetColor(0, 0, 0), "接続状態 PC8 %d", connection[7]);
}

void NET_GAMING::NetWork_Loop(int host_flag, FILER_S host_info)
{
	while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0 && break_flag == true)
	{
		static float animation;//ロードアニメーション用変数
		DrawCircleAA(1280 - 30, 720 - 30, 20, 8, GetColor(animation, animation, animation), TRUE);//待機アニメーション
		animation += 2.5;			//2.5ずつ増やす。
		if (animation >= 255) animation = 0;//アニメーション変数が255以上になったらにする

		if (host_flag == 1)//ホストの時
		{
			DrawString(0, 0, "接続を待っています。Enterで待機を解除しタイトルへ移動します。以降、ゲーム再起動まで新規接続は受け付けられません。", GetColor(0, 0, 0));

			net[count] = GetNewAcceptNetWork();			//新しく確立したネットワークハンドルを得る。
			if (net[count] >= 0)count++;				//countを回すして空になっている変数にする。
			if (count > host_info.member)count = 0;		//countが最大まで行ったら初期化する。

			NetConnectionData();	//接続状態を得る。

			//バッファーにデータがあるか調べたあとデーターが存在したら、データを読み込み表示する。
			if (GetNetWorkDataLength(net[0]) >= 0)NetWorkRecv(net[0], char_buffer_00, 8);
			if (GetNetWorkDataLength(net[1]) >= 0)NetWorkRecv(net[1], char_buffer_01, 8);
			if (GetNetWorkDataLength(net[2]) >= 0)NetWorkRecv(net[2], char_buffer_02, 8);
			if (GetNetWorkDataLength(net[3]) >= 0)NetWorkRecv(net[3], char_buffer_03, 8);
			if (GetNetWorkDataLength(net[4]) >= 0)NetWorkRecv(net[4], char_buffer_04, 8);
			if (GetNetWorkDataLength(net[5]) >= 0)NetWorkRecv(net[5], char_buffer_05, 8);
			if (GetNetWorkDataLength(net[6]) >= 0)NetWorkRecv(net[6], char_buffer_06, 8);
			if (GetNetWorkDataLength(net[7]) >= 0)NetWorkRecv(net[7], char_buffer_07, 8);
			
			//バッファーの文字を表示
			if (connection[0] == 1)DrawFormatString(300, 100, GetColor(0, 0, 0), char_buffer_00);
			if (connection[1] == 1)DrawFormatString(300, 120, GetColor(0, 0, 0), char_buffer_01);
			if (connection[2] == 1)DrawFormatString(300, 140, GetColor(0, 0, 0), char_buffer_02);
			if (connection[3] == 1)DrawFormatString(300, 160, GetColor(0, 0, 0), char_buffer_03);
			if (connection[4] == 1)DrawFormatString(300, 180, GetColor(0, 0, 0), char_buffer_04);
			if (connection[5] == 1)DrawFormatString(300, 200, GetColor(0, 0, 0), char_buffer_05);
			if (connection[6] == 1)DrawFormatString(300, 220, GetColor(0, 0, 0), char_buffer_06);
			if (connection[7] == 1)DrawFormatString(300, 240, GetColor(0, 0, 0), char_buffer_07);


			//エンターを押したら
			if (CheckHitKey(KEY_INPUT_RETURN) == 1)
			{
				//プレーヤー人数分送信する。
				for (int i = 0; i < host_info.member; i++)
				{
					NetWorkSend(net[i], &false_flag, 1);	//他のPCにネットワークループを抜ける処理を送る。
				}
				break_flag = false;
			}

		}
		else if (host_flag == 0)//ホストでない時
		{
			host_connection = GetNetWorkAcceptState(host_handl);	//接続状態を確認

			DrawFormatString(80, 100, GetColor(0, 0, 0), "接続状態  %d", host_connection);

			if (host_connection != 1)//検索中もしくは接続失敗
			{			
				host_handl = ConnectNetWork_ASync(host_info.ips, host_info.port);//ホストに接続

				DrawString(0, 0, "Hostを検索中です。しばらく待っても変化がない場合は設定を見直した上でソフトウェアを再起動してくだい。", GetColor(0, 0, 0));

			}
			else if (host_connection == 1)//接続成功
			{
				DrawString(0, 0, "Hostに接続しました。Hostがプログラムを開始するのを待っています。", GetColor(0, 0, 0));
				NetWorkSend(host_handl, "接続完了", 8);

				if (GetNetWorkDataLength(host_handl) >= 0) NetWorkRecv(host_handl, &bool_buffer, 1);//受信データからintバッファーにデータを移す。
				break_flag = bool_buffer;//ホストからのbreak情報を代入する。
			}
		}
	}
}

void NET_GAMING::NetSendHost(int* data)//ホストへ送る処理
{
	NetWorkSend(host_handl, &data, GetNetWorkSendDataLength(host_handl));	//Hostにデータを送る
}

void NET_GAMING::NetSend(int* data, FILER_S host_info)//ホスト側から送る処理
{
	//プレーヤー人数分送信する。
	for (int i = 0; i > host_info.member; i++)
	{
		NetWorkSend(net[i], &data, GetNetWorkSendDataLength(net[i]));	//他のPCにデータを送る
	}
}

int NET_GAMING::NetReadHost(int* data, FILER_S host_info)//ホスト側の読み込み処理
{
	//プレーヤー人数分受信する。
	for (int i = 0; i < host_info.member; i++)
	{
		if (GetNetWorkDataLength(net[i]) >= 0) return NetWorkRecv(net[i], &data, GetNetWorkDataLength(net[i]));//受信データからintバッファーにデータを移す。
	}
}

int NET_GAMING::NetRead(int* data)//ホストからの読み込み処理
{
	if (GetNetWorkDataLength(host_handl) >= 0) return NetWorkRecv(host_handl, &data, GetNetWorkDataLength(host_handl));//受信データからintバッファーにデータを移す。
}