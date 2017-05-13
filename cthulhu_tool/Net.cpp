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
		connection[i] = -1;		//�ڑ����
		net[i] = -1;			//�l�b�g���[�N�n���h���ۑ��p

		char_buffer_00[i];//�o�b�t�@�[
		char_buffer_01[i];//�o�b�t�@�[
		char_buffer_02[i];//�o�b�t�@�[
		char_buffer_03[i];//�o�b�t�@�[
		char_buffer_04[i];//�o�b�t�@�[
		char_buffer_05[i];//�o�b�t�@�[
		char_buffer_06[i];//�o�b�t�@�[
		char_buffer_07[i];//�o�b�t�@�[
	}
}

void NET_GAMING::NetListen(int host_flag, FILER_S host_info)
{
	if (host_flag == 1)
	{
		PreparationListenNetWork(host_info.port);//�ڑ����󂯂����Ԃɂ���B
	}
	else
	{
		StopListenNetWork();//�ڑ����󂯂����Ԃ���������B
	}
}

void NET_GAMING::NetConnectionData()
{
	//�ڑ���Ԃ𓾂�B
	connection[0] = GetNetWorkAcceptState(net[0]);
	connection[1] = GetNetWorkAcceptState(net[1]);
	connection[2] = GetNetWorkAcceptState(net[2]);
	connection[3] = GetNetWorkAcceptState(net[3]);
	connection[4] = GetNetWorkAcceptState(net[4]);
	connection[5] = GetNetWorkAcceptState(net[5]);
	connection[6] = GetNetWorkAcceptState(net[6]);
	connection[7] = GetNetWorkAcceptState(net[7]);

	//�R�l�N�V�����m�F
	DrawFormatString(80, 100, GetColor(0, 0, 0), "�ڑ���� PC1 %d", connection[0]);
	DrawFormatString(80, 120, GetColor(0, 0, 0), "�ڑ���� PC2 %d", connection[1]);
	DrawFormatString(80, 140, GetColor(0, 0, 0), "�ڑ���� PC3 %d", connection[2]);
	DrawFormatString(80, 160, GetColor(0, 0, 0), "�ڑ���� PC4 %d", connection[3]);
	DrawFormatString(80, 180, GetColor(0, 0, 0), "�ڑ���� PC5 %d", connection[4]);
	DrawFormatString(80, 200, GetColor(0, 0, 0), "�ڑ���� PC6 %d", connection[5]);
	DrawFormatString(80, 220, GetColor(0, 0, 0), "�ڑ���� PC7 %d", connection[6]);
	DrawFormatString(80, 240, GetColor(0, 0, 0), "�ڑ���� PC8 %d", connection[7]);
}

void NET_GAMING::NetWork_Loop(int host_flag, FILER_S host_info)
{
	while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0 && break_flag == true)
	{
		static float animation;//���[�h�A�j���[�V�����p�ϐ�
		DrawCircleAA(1280 - 30, 720 - 30, 20, 8, GetColor(animation, animation, animation), TRUE);//�ҋ@�A�j���[�V����
		animation += 2.5;			//2.5�����₷�B
		if (animation >= 255) animation = 0;//�A�j���[�V�����ϐ���255�ȏ�ɂȂ�����ɂ���

		if (host_flag == 1)//�z�X�g�̎�
		{
			DrawString(0, 0, "�ڑ���҂��Ă��܂��BEnter�őҋ@���������^�C�g���ֈړ����܂��B�ȍ~�A�Q�[���ċN���܂ŐV�K�ڑ��͎󂯕t�����܂���B", GetColor(0, 0, 0));

			net[count] = GetNewAcceptNetWork();			//�V�����m�������l�b�g���[�N�n���h���𓾂�B
			if (net[count] >= 0)count++;				//count���񂷂��ċ�ɂȂ��Ă���ϐ��ɂ���B
			if (count > host_info.member)count = 0;		//count���ő�܂ōs�����珉��������B

			NetConnectionData();	//�ڑ���Ԃ𓾂�B

			//�o�b�t�@�[�Ƀf�[�^�����邩���ׂ����ƃf�[�^�[�����݂�����A�f�[�^��ǂݍ��ݕ\������B
			if (GetNetWorkDataLength(net[0]) >= 0)NetWorkRecv(net[0], char_buffer_00, 8);
			if (GetNetWorkDataLength(net[1]) >= 0)NetWorkRecv(net[1], char_buffer_01, 8);
			if (GetNetWorkDataLength(net[2]) >= 0)NetWorkRecv(net[2], char_buffer_02, 8);
			if (GetNetWorkDataLength(net[3]) >= 0)NetWorkRecv(net[3], char_buffer_03, 8);
			if (GetNetWorkDataLength(net[4]) >= 0)NetWorkRecv(net[4], char_buffer_04, 8);
			if (GetNetWorkDataLength(net[5]) >= 0)NetWorkRecv(net[5], char_buffer_05, 8);
			if (GetNetWorkDataLength(net[6]) >= 0)NetWorkRecv(net[6], char_buffer_06, 8);
			if (GetNetWorkDataLength(net[7]) >= 0)NetWorkRecv(net[7], char_buffer_07, 8);
			
			//�o�b�t�@�[�̕�����\��
			if (connection[0] == 1)DrawFormatString(300, 100, GetColor(0, 0, 0), char_buffer_00);
			if (connection[1] == 1)DrawFormatString(300, 120, GetColor(0, 0, 0), char_buffer_01);
			if (connection[2] == 1)DrawFormatString(300, 140, GetColor(0, 0, 0), char_buffer_02);
			if (connection[3] == 1)DrawFormatString(300, 160, GetColor(0, 0, 0), char_buffer_03);
			if (connection[4] == 1)DrawFormatString(300, 180, GetColor(0, 0, 0), char_buffer_04);
			if (connection[5] == 1)DrawFormatString(300, 200, GetColor(0, 0, 0), char_buffer_05);
			if (connection[6] == 1)DrawFormatString(300, 220, GetColor(0, 0, 0), char_buffer_06);
			if (connection[7] == 1)DrawFormatString(300, 240, GetColor(0, 0, 0), char_buffer_07);


			//�G���^�[����������
			if (CheckHitKey(KEY_INPUT_RETURN) == 1)
			{
				//�v���[���[�l�������M����B
				for (int i = 0; i < host_info.member; i++)
				{
					NetWorkSend(net[i], &false_flag, 1);	//����PC�Ƀl�b�g���[�N���[�v�𔲂��鏈���𑗂�B
				}
				break_flag = false;
			}

		}
		else if (host_flag == 0)//�z�X�g�łȂ���
		{
			host_connection = GetNetWorkAcceptState(host_handl);	//�ڑ���Ԃ��m�F

			DrawFormatString(80, 100, GetColor(0, 0, 0), "�ڑ����  %d", host_connection);

			if (host_connection != 1)//�������������͐ڑ����s
			{			
				host_handl = ConnectNetWork_ASync(host_info.ips, host_info.port);//�z�X�g�ɐڑ�

				DrawString(0, 0, "Host���������ł��B���΂炭�҂��Ă��ω����Ȃ��ꍇ�͐ݒ������������Ń\�t�g�E�F�A���ċN�����Ă������B", GetColor(0, 0, 0));

			}
			else if (host_connection == 1)//�ڑ�����
			{
				DrawString(0, 0, "Host�ɐڑ����܂����BHost���v���O�������J�n����̂�҂��Ă��܂��B", GetColor(0, 0, 0));
				NetWorkSend(host_handl, "�ڑ�����", 8);

				if (GetNetWorkDataLength(host_handl) >= 0) NetWorkRecv(host_handl, &bool_buffer, 1);//��M�f�[�^����int�o�b�t�@�[�Ƀf�[�^���ڂ��B
				break_flag = bool_buffer;//�z�X�g�����break����������B
			}
		}
	}
}

void NET_GAMING::NetSendHost(int* data)//�z�X�g�֑��鏈��
{
	NetWorkSend(host_handl, &data, GetNetWorkSendDataLength(host_handl));	//Host�Ƀf�[�^�𑗂�
}

void NET_GAMING::NetSend(int* data, FILER_S host_info)//�z�X�g�����瑗�鏈��
{
	//�v���[���[�l�������M����B
	for (int i = 0; i > host_info.member; i++)
	{
		NetWorkSend(net[i], &data, GetNetWorkSendDataLength(net[i]));	//����PC�Ƀf�[�^�𑗂�
	}
}

int NET_GAMING::NetReadHost(int* data, FILER_S host_info)//�z�X�g���̓ǂݍ��ݏ���
{
	//�v���[���[�l������M����B
	for (int i = 0; i < host_info.member; i++)
	{
		if (GetNetWorkDataLength(net[i]) >= 0) return NetWorkRecv(net[i], &data, GetNetWorkDataLength(net[i]));//��M�f�[�^����int�o�b�t�@�[�Ƀf�[�^���ڂ��B
	}
}

int NET_GAMING::NetRead(int* data)//�z�X�g����̓ǂݍ��ݏ���
{
	if (GetNetWorkDataLength(host_handl) >= 0) return NetWorkRecv(host_handl, &data, GetNetWorkDataLength(host_handl));//��M�f�[�^����int�o�b�t�@�[�Ƀf�[�^���ڂ��B
}