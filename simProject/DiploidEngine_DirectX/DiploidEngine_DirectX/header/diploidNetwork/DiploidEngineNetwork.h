#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineNetwork
{
private:
	std::vector<int> tcp_network_handl;//低速高品質通信TCP
	std::vector<int> udp_network_handl;//光速低品質通信UDP

	IPDATA network_ip[100];//最大100のIPを保存可能

	void OtherComputerConnect();//他のPCからの接続を待つ
	void GetNetStats();//他のPCの情報を得る

public:
	int tcp_port = 6600;//ポート番号
	int udp_port = 6666;
	//int connect_max = 8;//接続最大数を指定

	int connections;//接続数の確認

	void Init();
	void Update();
	void End();
	void Draw(bool debug = true);
};