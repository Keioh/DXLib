#pragma once
#include "DxLib.h"
#include <vector>
//#include <WinSock2.h>

class DiploidEngineNetwork
{
private:
	//WSADATA winsock2;//winsock2�̃f�[�^�\����
	//sockaddr_in winsock2_adr;//winsock2�̃A�h���X�\����

public:
	IPDATA GetMyAddr_IPv4();//������IP�A�h���X(IPv4)���擾���܂��B

	void Init();
	void Update() {};
	void End();
	void Draw(bool debug = true);
};