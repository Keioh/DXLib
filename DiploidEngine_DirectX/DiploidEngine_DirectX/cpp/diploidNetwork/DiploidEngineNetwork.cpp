#include "diploidNetwork\DiploidEngineNetwork.h"

void DiploidEngineNetwork::Init()
{

}

void DiploidEngineNetwork::OtherComputerConnect()
{
	if (PreparationListenNetWork(tcp_port) == 0)//接続受付に成功したら
	{
		tcp_network_handl.push_back(GetNewAcceptNetWork());//新たな接続を確認しもしあった場合、ハンドルを取得
	}
	else
	{
		PreparationListenNetWork(tcp_port);
	}
}

void DiploidEngineNetwork::GetNetStats()//未完
{
	if (!tcp_network_handl.empty())
	{
		for (auto handl = tcp_network_handl.begin(); handl != tcp_network_handl.end(); ++handl)
		{
			if (GetNetWorkAcceptState(*handl) == 1)
			{
				connections += 1;//接続数を確認
			}
			else
			{
				connections += 0;
			}
		}
	}
}

void DiploidEngineNetwork::Update()
{
	OtherComputerConnect();//他のPCからの接続を待つ
	GetNetStats();//他のPCの接続状態を確認
}

void DiploidEngineNetwork::End()
{
	//TCP
	if (StopListenNetWork() == 1)
	{
		if (!tcp_network_handl.empty())
		{
			for (auto handl = tcp_network_handl.begin(); handl != tcp_network_handl.end(); ++handl)
			{
				CloseNetWork(*handl);//接続を断つ
			}
		}
	}
	else
	{
		StopListenNetWork();
	}

	//UDP
	if (!udp_network_handl.empty())
	{
		for (auto handl = udp_network_handl.begin(); handl != udp_network_handl.end(); ++handl)
		{
			DeleteUDPSocket(*handl);//接続を断つ
		}
	}
}

void DiploidEngineNetwork::Draw(bool debug)
{
	if (debug == true)
	{

	}
}