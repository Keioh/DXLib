#pragma once
#include "DxLib.h"
#include "FileInput.h"

class NET_GAMING
{
private:

	int count;			//�J�E���g���邽�߂̕ϐ�
	bool false_flag;	//false�Ɠ��`

public:
	bool break_flag;//�����̃l�b�g���[�N���[�v�𔲂���t���O�B

	int host_handl;		//�z�X�g�̏��
	int host_connection;//�z�X�g�Ƃ̐ڑ����

	int connection[16];		//�ڑ����
	int net[128];			//�l�b�g���[�N�n���h���ۑ��p

	int int_buffer;//�o�b�t�@�[
	bool bool_buffer;//�o�b�t�@�[

	char char_buffer_00[256];//�o�b�t�@�[
	char char_buffer_01[256];//�o�b�t�@�[
	char char_buffer_02[256];//�o�b�t�@�[
	char char_buffer_03[256];//�o�b�t�@�[
	char char_buffer_04[256];//�o�b�t�@�[
	char char_buffer_05[256];//�o�b�t�@�[
	char char_buffer_06[256];//�o�b�t�@�[
	char char_buffer_07[256];//�o�b�t�@�[

	NET_GAMING();	//�R���X�g���N�^

	void init();	//������

	void NetWork_wait(int host_flag, FILER_S host_info);//�l�b�g���������邩�̃t���O�A�z�X�g���̃t���O�A�z�X�g����ۑ������t�@�C���̓ǂݍ���
	void NetListen(int host_flag, FILER_S host_info);//�z�X�g����Ƃ��ɐڑ����󂯂����Ԃɂ��邩�ǂ����̏���
	void NetConnectionData();//�ڑ���Ԃ��m�F

	void NetSendHost(int* data);//�z�X�g�֑��鏈��
	void NetSend(int* data, FILER_S host_info);//�z�X�g�����瑗�鏈��
	int NetReadHost(int* data, FILER_S host_info);//�z�X�g���̓ǂݍ��ݏ���(data�͕ۑ�����ϐ�)
	int NetRead(int* data);//�z�X�g����̓ǂݍ��ݏ���(data�͕ۑ�����ϐ�)

};