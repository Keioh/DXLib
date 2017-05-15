#pragma once
#include "DxLib.h"
#include "FileInput.h"

class NET_GAMING
{
private:

	int count;			//カウントするための変数
	bool false_flag;	//falseと同義

public:
	bool break_flag;//初期のネットワークループを抜けるフラグ。

	int host_handl;		//ホストの情報
	int host_connection;//ホストとの接続状態

	int connection[16];		//接続状態
	int net[128];			//ネットワークハンドル保存用

	int int_buffer;//バッファー
	bool bool_buffer;//バッファー

	char char_buffer_00[256];//バッファー
	char char_buffer_01[256];//バッファー
	char char_buffer_02[256];//バッファー
	char char_buffer_03[256];//バッファー
	char char_buffer_04[256];//バッファー
	char char_buffer_05[256];//バッファー
	char char_buffer_06[256];//バッファー
	char char_buffer_07[256];//バッファー

	NET_GAMING();	//コンストラクタ

	void init();	//初期化

	void NetWork_wait(int host_flag, FILER_S host_info);//ネット処理をするかのフラグ、ホストかのフラグ、ホスト情報を保存したファイルの読み込み
	void NetListen(int host_flag, FILER_S host_info);//ホストするときに接続を受けられる状態にするかどうかの処理
	void NetConnectionData();//接続状態を確認

	void NetSendHost(int* data);//ホストへ送る処理
	void NetSend(int* data, FILER_S host_info);//ホスト側から送る処理
	int NetReadHost(int* data, FILER_S host_info);//ホスト側の読み込み処理(dataは保存する変数)
	int NetRead(int* data);//ホストからの読み込み処理(dataは保存する変数)

};