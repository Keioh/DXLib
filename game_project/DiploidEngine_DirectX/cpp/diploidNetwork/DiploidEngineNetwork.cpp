#include "diploidNetwork\DiploidEngineNetwork.h"

void DiploidEngineNetwork::Init()
{

}

void DiploidEngineNetwork::OtherComputerConnect()
{
	if (PreparationListenNetWork(tcp_port) == 0)//�ڑ���t�ɐ���������
	{
		tcp_network_handl.push_back(GetNewAcceptNetWork());//�V���Ȑڑ����m�F�������������ꍇ�A�n���h�����擾
	}
	else
	{
		PreparationListenNetWork(tcp_port);
	}
}

void DiploidEngineNetwork::GetNetStats()//����
{
	if (!tcp_network_handl.empty())
	{
		for (auto handl = tcp_network_handl.begin(); handl != tcp_network_handl.end(); ++handl)
		{
			if (GetNetWorkAcceptState(*handl) == 1)
			{
				connections += 1;//�ڑ������m�F
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
	OtherComputerConnect();//����PC����̐ڑ���҂�
	GetNetStats();//����PC�̐ڑ���Ԃ��m�F
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
				CloseNetWork(*handl);//�ڑ���f��
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
			DeleteUDPSocket(*handl);//�ڑ���f��
		}
	}
}

void DiploidEngineNetwork::Draw(bool debug)
{
	if (debug == true)
	{

	}
}