#pragma once
#include "DxLib.h"
#include <vector>

class DiploidEngineNetwork
{
private:
	std::vector<int> tcp_network_handl;//�ᑬ���i���ʐMTCP
	std::vector<int> udp_network_handl;//������i���ʐMUDP

	IPDATA network_ip[100];//�ő�100��IP��ۑ��\

	void OtherComputerConnect();//����PC����̐ڑ���҂�
	void GetNetStats();//����PC�̏��𓾂�

public:
	int tcp_port = 6600;//�|�[�g�ԍ�
	int udp_port = 6666;
	//int connect_max = 8;//�ڑ��ő吔���w��

	int connections;//�ڑ����̊m�F

	void Init();
	void Update();
	void End();
	void Draw(bool debug = true);
};