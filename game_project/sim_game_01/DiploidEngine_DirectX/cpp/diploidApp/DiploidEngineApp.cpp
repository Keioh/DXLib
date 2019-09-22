#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	my_castle.Load();//�����_�̃��[�h

	command_ui.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	//�}�E�X�J�[�\��
	mouse_point.point.Init(VGet(0, 0, 0));
	mouse_point.point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(mouse_point.point);

	//�����̋��_
	my_castle.Inti(VGet(GetWindowSize().x / 2, GetWindowSize().y / 2, 0), 50);
	my_castle.Push(diploidEngineImpact);

	//�R�}���hUI
	command_ui.Init(VGet(0, 200, 0));
	command_ui.Push(diploidEngineImpact);

	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	my_castle.Updata(diploidEngineImpact, diploidEngineInput);//�����_�A�b�v�f�[�g

	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	my_castle.Draw(true,true);//�����_�̕`��
	command_ui.Draw();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}