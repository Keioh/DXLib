#include "diploidNetwork\DiploidEngineNetwork.h"

void DiploidEngineNetwork::Init()
{
	//WSAStartup(MAKEWORD(2, 0), &winsock2);//winsock2�̏�����

}

IPDATA DiploidEngineNetwork::GetMyAddr_IPv4()//������IP�A�h���X(IPv4)���擾���܂��B
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
	//WSACleanup();//winsock2�̏I������

}