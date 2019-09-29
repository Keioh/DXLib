#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	command_ui.Load();//�R�}���hUI�̃��[�h
	season_panel.Load();//�G�߃p�l���̃��[�h
	status_bar.Load();//�X�e�[�^�X�o�[�̃��[�h

	//���v
	test_clock_back.image.Load("texter/game/clock/back.png");
	test_clock_hour_hand.image.Load("texter/game/clock/hour_hand.png");
	test_clock_minute_hand.image.Load("texter/game/clock/minute_hand.png");
	test_clock_second_hand.image.Load("texter/game/clock/second_hand.png");


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
	test_clock_back.image.Init(VGet(1280 - 128/2, 0 + 320/2, 0));
	test_clock_hour_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_minute_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));
	test_clock_second_hand.image.Init(VGet(1280 - 128 / 2, 0 + 320 / 2, 0));



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
	timer++;
	if (timer > 59 * 2)
	{
		second += 1;
		
		test_clock_second_hand.image.move_speed.x = 2;

		timer = 0;
	}

	if (second > 29)
	{
		minute += 1;

		test_clock_minute_hand.image.move_speed.y = 18;

		test_clock_second_hand.image.move_speed.x = -(2 * 29);
		
		
		second = 0;	
	}

	if (minute > 11)
	{
		hour += 1;

		test_clock_hour_hand.image.move_speed.y = 24;

		test_clock_minute_hand.image.move_speed.y = -(18 * 11);
		
		
		minute = 0;	
	}

	if (hour > 7)
	{
		test_clock_hour_hand.image.move_speed.y = -(24 * 7);


		hour = 0;
	}

	test_clock_second_hand.image.Updata();		
	test_clock_minute_hand.image.Updata();	
	test_clock_hour_hand.image.Updata();


	//�R�}���hUI�̃A�b�v�f�[�g
	command_ui.Updata(MOUSE_INPUT_LEFT, diploidEngineImpact, diploidEngineInput);

	//�X�e�[�^�X�o�[�̃A�b�v�f�[�g
	status_bar.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p
	status_bar.StatusUpdate(command_ui.information_command);//�X�e�[�^�X�o�[�̐��l���R�}���hUI����̏���p���čX�V

	//�G�߃p�l���̃A�b�v�f�[�g
	season_panel.Updata(MOUSE_INPUT_RIGHT, diploidEngineImpact, diploidEngineInput);//���݂͓����蔻��͎g���ĂȂ����ǁA�A�j���[�V�����Ŏg�p

	static int count;
	count++;

	if (count > 5)
	{
		season_panel.NextDays();
		count = 0;
	}

	//�R�}���hUI���I�t�Ȃ�
	if (command_ui.GetUIFlag() == false)
	{
		test_map.Updata(diploidEngineImpact, diploidEngineInput);
	}

	//�I�u�W�F�N�g�ԍ��̎����U�蕪��
	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{	
	test_map.Draw();

	//�R�}���hUI�̕`��
	command_ui.Draw();

	//�X�e�[�^�X�o�[�̕`��
	status_bar.Draw();
	status_bar.StatusDraw(command_ui.information_command);//�X�e�[�^�X�o�[�ɃR�}���hUI����̐��l���o��

	//�G�߃p�l���̕`��
	season_panel.Draw();

	//���v
	test_clock_back.image.Draw();
	test_clock_hour_hand.image.Draw();
	test_clock_minute_hand.image.Draw();
	test_clock_second_hand.image.Draw();

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}