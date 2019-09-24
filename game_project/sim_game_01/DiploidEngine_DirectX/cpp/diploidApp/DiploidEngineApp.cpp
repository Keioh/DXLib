#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	command_ui.Load();//�R�}���hUI�̃��[�h
	season_panel.Load();//�G�߃p�l���̃��[�h
	status_bar.Load();//�X�e�[�^�X�o�[�̃��[�h

	test.Load("texter/game/map/wall.png");
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

	//�X�e�[�^�X�o�[�̏������ƃv�b�V��
	status_bar.Init(VGet(0, 0, 0));
	//status_bar.Push(diploidEngineImpact);//���̂Ƃ��뒆�g�Ȃ�

	//test.Init(VGet(1280.0f/2, 720.0f/ 2, 0.0f));
	test.Scale(VGet(64.0f * 2,64.0f * 2, 0.0f));
	//test.RotateY(30.0f);
	test.Translate(VGet(1280.0f/2, 720.0f/2, 10.0f));

	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//�R�}���hUI�̃A�b�v�f�[�g
	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);

	//�X�e�[�^�X�o�[�̃A�b�v�f�[�g
	status_bar.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p

	//�G�߃p�l���̃A�b�v�f�[�g
	season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p

	static int count;
	count++;

	if (count > 5)
	{
		season_panel.NextDays();
		count = 0;
	}


	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{	
	//�R�}���hUI�̕`��
	command_ui.Draw();

	//�X�e�[�^�X�o�[�̕`��
	status_bar.Draw();

	//�G�߃p�l���̕`��
	season_panel.Draw();


	test.Draw();
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}