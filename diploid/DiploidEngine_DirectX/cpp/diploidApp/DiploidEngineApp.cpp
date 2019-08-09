#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	dice.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	dice.Init(VGet(50, 50, 0));//�_�C�X�I�u�W�F�N�g������

	//�}�E�X�|�C���g
	object.point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(object.point);

	//�����N���b�N�{�^��
	ui.OneClickButton_Init(VGet(50,50,0),VGet(50,50,0), "one_click_button");//������
	ui.OneClickButton_Push(diploidEngineImpact);//�����蔻��̔z��Ƀf�[�^���v�b�V��

	diploidEngineImpact.AutoNumber();//�I�u�W�F�N�g�ԍ��������ŐU�蕪��
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//�����N���b�N�{�^���̍X�V
	if (ui.OneClickButton_Update(diploidEngineImpact, diploidEngineInput) == true)
	{
		dice.Roll();
	}

	dice.Update();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//�摜���g��Ȃ��ꍇ�ABOX��`�ʂ��邱�Ƃ��ł��܂��B(�������AdiploidEngineImpact�ɂ����OneClickButton_Draw��position�͕ϓ����܂���B)
	ui.OneClickButton_Draw();

	dice.Draw();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}