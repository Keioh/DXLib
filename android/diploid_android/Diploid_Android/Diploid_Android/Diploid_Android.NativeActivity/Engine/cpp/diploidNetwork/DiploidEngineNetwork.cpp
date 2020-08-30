#include "diploidNetwork\DiploidEngineNetwork.h"

void DiploidEngineNetwork::Init()
{
	//WSAStartup(MAKEWORD(2, 0), &winsock2);//winsock2の初期化

}

IPDATA DiploidEngineNetwork::GetMyAddr_IPv4()//自分のIPアドレス(IPv4)を取得します。
{
	IPDATA buffer = {0,0,0,0};
	return buffer;
}

void DiploidEngineNetwork::Draw(bool debug)
{
	if (debug == true)
	{

	}
}

void DiploidEngineNetwork::End()
{
	//WSACleanup();//winsock2の終了処理

}