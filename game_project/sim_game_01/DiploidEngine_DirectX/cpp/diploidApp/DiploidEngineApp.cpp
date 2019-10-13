#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	command_ui.Load();//�R�}���hUI�̃��[�h
	season_panel.Load();//�G�߃p�l���̃��[�h
	status_bar.Load();//�X�e�[�^�X�o�[�̃��[�h
	clock.Load();//���v

	test_map.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{	

	//�}�E�X�J�[�\��(UI���)
	mouse_point.point.Init(VGet(0, 0, 0));
	mouse_point.point.mouse_point_move_flag = true;
	mouse_point.point.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushPoint(mouse_point.point);

	//�R�}���hUI�̏������ƃv�b�V��
	command_ui.Init(VGet(0, 128, 0));
	command_ui.Push(diploidEngineImpact);

	//�G�߃p�l���̏������ƃv�b�V��
	season_panel.Init(VGet(0, 0, 0));
	//season_panel.Push(diploidEngineImpact);//���̂Ƃ��뒆�g�Ȃ�


	//���v
	clock.Init();


	//�X�e�[�^�X�o�[�̏������ƃv�b�V��
	status_bar.Init(VGet(0, 0, 0));
	//status_bar.Push(diploidEngineImpact);//���̂Ƃ��뒆�g�Ȃ�


	test_map.Init(VGet(1280/2, 720/2, 0));
	test_map.Push(diploidEngineImpact);

	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//���v
	clock.Update();

	//�R�}���hUI�̃A�b�v�f�[�g
	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);

	//�X�e�[�^�X�o�[�̃A�b�v�f�[�g
	status_bar.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p
	status_bar.StatusUpdate(command_ui.information_command);//�X�e�[�^�X�o�[�̐��l���R�}���hUI����̏���p���čX�V

	//�G�߃p�l���̃A�b�v�f�[�g
	season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p
	
	//����i�߂�
	if (clock.isDayFlag() == true)
	{
		season_panel.NextDays();
	}


	//�R�}���hUI���I�t�Ȃ�
	if (command_ui.GetUIFlag() == false)
	{
		test_map.Updata(diploidEngineImpact, diploidEngineInput, command_ui, status_bar, clock);//�}�b�v�̃A�b�v�f�[�g(�ړ��Ȃ�)
	}

	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{	
	//�e�X�g�}�b�v�̕`��(�v���C���[�������Ɋ܂܂��)
	test_map.Draw();


	//�R�}���hUI�̕`��
	command_ui.Draw();

	//�X�e�[�^�X�o�[�̕`��
	status_bar.Draw();
	status_bar.StatusDraw(command_ui.information_command);//�X�e�[�^�X�o�[�ɃR�}���hUI����̐��l���o��

	//�G�߃p�l���̕`��
	season_panel.Draw();

	//���v
	clock.Draw();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}