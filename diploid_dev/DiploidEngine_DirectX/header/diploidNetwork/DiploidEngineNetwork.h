#pragma once
#include "DxLib.h"
#include <vector>
//#include <WinSock2.h>

class DiploidEngineNetwork
{
private:
	//WSADATA winsock2;//winsock2のデータ構造体
	//sockaddr_in winsock2_adr;//winsock2のアドレス構造体

public:
	IPDATA GetMyAddr_IPv4();//自分のIPアドレス(IPv4)を取得します。

	void Init();
	void Update() {};
	void End();
	void Draw(bool debug = true);
};