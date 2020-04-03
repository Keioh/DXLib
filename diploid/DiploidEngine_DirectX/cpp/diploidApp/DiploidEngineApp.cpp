#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Load();
		}
	}
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	input.Init();//�C���v�b�g�̏�����

	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Init(VGet(one * (1024 * 0.125f), two * (1024 * 0.125f), 0), 0.125f);
			fild[two][one].SetTerrainType(GetRand(1));
		}
	}

	fild[2][8].SetBuildingType(1);//�����_�̌���
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();//�C���v�b�g�̍X�V

	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Updata(&input);
		}
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	for (int one = 0; one != 10; ++one)
	{
		for (int two = 0; two != 5; ++two)
		{
			fild[two][one].Draw();
		}
	}
}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}