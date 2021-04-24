#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//�߂�{�^���̓ǂݍ���
	back_button.Load();

	//�ۑ��{�^���̓ǂݍ���
	save_button.Load();

	//�^�C�g���{�^���̓ǂݍ���
	title_button.Load();

	//���Z�b�g�{�^���̓ǂݍ���
	reset_button.Load();


	//�E�B���h�E�T�C�Y�ύX�{�^���̉摜�ǂݍ���
	window_resize_button_960_540.Load("texter/basic/button/display/960_540.png");
	window_resize_button_1280_720.Load("texter/basic/button/display/1280_720.png");
	window_resize_button_1600_900.Load("texter/basic/button/display/1600_900.png");
	window_resize_button_1920_1080.Load("texter/basic/button/display/1920_1080.png");

	//�����\�����x�ƃI�[�g���x�̕ύXUI�Q
	text_speed_auto_setting_ui.Load();

	//Option�̃^�C�g���摜
	option_string_image.Load();

	//Option��Display�摜
	display_string_image.Load();
	
	//Option��GamePlay�摜
	game_play_string_image.Load();		
}

void OptionScene::Init(DiploidEngineSetting& setting)
{	
	//�G���W������ݒ�f�[�^���擾�B
	system_data = setting.GetSystemData();

	//�O�p�`�̓��I�w�i
	continuous_triangle.Init(VGet(0, 0, 0), 50, 100, 30);

	//Option�̃^�C�g���摜
	option_string_image.Init(VGet(0, 0, 0));

	//Option��Display�摜
	display_string_image.Init(VGet(window_resize_button_position_x, window_resize_button_position_y, 0));

	//Option��GamePlay�摜
	game_play_string_image.Init(VGet(string_speed_button_position_x, string_speed_button_position_y, 0));

	//�t�F�[�h�pBOX
	box.Init(VGet(0, 0, 0), VGet(setting.GetSystemData().window_x, setting.GetSystemData().window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//�߂�{�^��
	back_button.Init(VGet(setting.GetSystemData().window_x - (128 + 4), setting.GetSystemData().window_y - (32 + 4), 0));

	//�ۑ��{�^��
	save_button.Init(VGet(setting.GetSystemData().window_x - ((128 * 2) + 4), setting.GetSystemData().window_y - (32 + 4), 0));

	//�^�C�g���{�^��
	title_button.Init(VGet(setting.GetSystemData().window_x - ((128 * 3) + 4), setting.GetSystemData().window_y - (32 + 4), 0));

	//���Z�b�g�{�^��
	reset_button.Init(VGet(4, setting.GetSystemData().window_y - (32 + 4), 0));



	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.SetWindowSize(960, 540);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.SetWindowSize(1280, 720);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)	
	window_resize_button_1600_900.SetWindowSize(1600, 900);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)	
	window_resize_button_1920_1080.SetWindowSize(1920, 1080);//�^�[�Q�b�g�ƂȂ�E�B���h�E�T�C�Y���w��
	window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

	//�����\�����x�ƃI�[�g���x�̕ύXUI�Q
	text_speed_auto_setting_ui.Init(VGet(string_speed_button_position_x, string_speed_button_position_y, 0));
	text_speed_auto_setting_ui.SetParameterDrawSpeed(system_data.string_draw_speed);//�����`�摬�x
	text_speed_auto_setting_ui.SetParameterAutoSpeed(system_data.string_auto_speed);//�I�[�g���x
	text_speed_auto_setting_ui.SetParameterBackGroundAlpha(system_data.string_background_alpha);//���ߓx

}

void OptionScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag)
{
	SetBackgroundColor(0, 0, 0);//Window�w�i�F�𔒐F�ɕύX

	in_game_flag_buffer = in_game_flag;//�Q�[�������̃t���O��ۑ�

	//�O�p�`�̓��I�w�i
	continuous_triangle.Updata(input, screen);

	//Option�̃^�C�g���摜
	option_string_image.Updata();

	//Option��Display�摜
	display_string_image.Updata();

	//Option��GamePlay�摜
	game_play_string_image.Updata();

	//�����\�����x�ƃI�[�g���x�̕ύXUI�Q
	text_speed_auto_setting_ui.Update(screen);


	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	window_resize_button_1600_900.Update(input);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)
	window_resize_button_1920_1080.Update(input);


	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_960_540.GetClick() == true)
	{
		window_resize_button_960_540.SetSelectedFlag(1);

		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1280_720.GetClick() == true)
	{
		window_resize_button_1280_720.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1600_900.GetClick() == true)
	{
		window_resize_button_1600_900.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1920_1080.SetSelectedFlag(-1);
	}

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)���N���b�N���ꂽ�Ƃ�
	if (window_resize_button_1920_1080.GetClick() == true)
	{
		window_resize_button_1920_1080.SetSelectedFlag(1);

		window_resize_button_960_540.SetSelectedFlag(-1);
		window_resize_button_1280_720.SetSelectedFlag(-1);
		window_resize_button_1600_900.SetSelectedFlag(-1);
	}


	save_button.Update(input);//�ۑ��{�^���̍X�V����

	if ((save_button.GetClick() == true) && (save_button.GetHit() == true))//�ۑ��{�^�����������Ƃ�
	{
		//�E�B���h�E�T�C�Y960_540���I����ԂȂ�
		if (window_resize_button_960_540.GetSelected() == 1)
		{
			setting.SetWindowSize(960, 540);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1280_720���I����ԂȂ�
		if (window_resize_button_1280_720.GetSelected() == 1)
		{
			setting.SetWindowSize(1280, 720);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1600_900���I����ԂȂ�
		if (window_resize_button_1600_900.GetSelected() == 1)
		{
			setting.SetWindowSize(1600, 900);//�𑜓x��ύX
		}

		//�E�B���h�E�T�C�Y1920_1080���I����ԂȂ�
		if (window_resize_button_1920_1080.GetSelected() == 1)
		{
			setting.SetWindowSize(1920, 1080);//�𑜓x��ύX
		}

		//�����`�摬�x�ƃI�[�g���x��ύX���ĕۑ�����B
		draw_speed = text_speed_auto_setting_ui.GetParameterAbsoluteDrawSpeed();//�����`�摬�x
		auto_speed = text_speed_auto_setting_ui.GetParameterAbsoluteAutoSpeed();//�I�[�g���x
		background_alpha = text_speed_auto_setting_ui.GetParameterAbsoluteBackGroundAlpha();//���ߓx

		//�e�l���ꎞ�ݒ�f�[�^�Ƃ��ĕۑ�
		system_data.window_x = setting.GetSystemData().window_x;
		system_data.window_y = setting.GetSystemData().window_y;
		system_data.string_draw_speed = draw_speed;
		system_data.string_auto_speed = auto_speed;
		system_data.string_background_alpha = background_alpha;

		//�t�@�C���ɏ�������(setting����������ł��鍀�ڂ͂��̃I�v�V�������ŕύX��������������)
		file.WriteOpen("data/system_config.txt");

		if (file.GetFileOutAdr())
		{
			file.SetLine("window_x", system_data.window_x);
			file.SetLine("window_y", system_data.window_y);
			file.SetLine("simulation_window_x", setting.GetSystemData().simulation_window_x);
			file.SetLine("simulation_window_y", setting.GetSystemData().simulation_window_y);
			file.SetLine("refreshrate", setting.GetSystemData().refreshrate);
			file.SetLine("window_mode", setting.GetSystemData().window_mode);
			file.SetLine("vsync", setting.GetSystemData().vsync);

			file.SetLine("string_draw_speed", system_data.string_draw_speed);
			file.SetLine("string_auto_speed", system_data.string_auto_speed);
			file.SetLine("string_background_alpha", system_data.string_background_alpha);
		}

		file.FileOutClose();
	}


	back_button.Update(input);//�߂�{�^���̍X�V����

	if (back_button.GetClick() == true)//�߂�{�^�����N���b�N���ꂽ��
	{
		//���݂̉𑜓x�̃{�^���Ƀ`�F�b�N��t���Ȃ����B
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

		//�����`�摬�x�ƃI�[�g���x��ۑ������ݒ�ɖ߂��B
		text_speed_auto_setting_ui.SetParameterDrawSpeed(system_data.string_draw_speed);//�����`�摬�x
		text_speed_auto_setting_ui.SetParameterAutoSpeed(system_data.string_auto_speed);//�I�[�g���x
		text_speed_auto_setting_ui.SetParameterBackGroundAlpha(system_data.string_background_alpha);//���ߓx

		back_button.SetSelectedFlag(1);//�I����Ԃ�1���ێ�
		box_draw_flag = 2;//�t�F�[�h�C�����n�߂�
	}


	reset_button.Update(input);//���Z�b�g�{�^���̍X�V����

	if (reset_button.GetClick() == true)//���Z�b�g�{�^�����N���b�N���ꂽ��
	{
		//�����`�摬�x�ƃI�[�g���x��1�O�ɕۑ������ݒ�ɖ߂��B
		text_speed_auto_setting_ui.SetParameterDrawSpeed(system_data.string_draw_speed);//�����`�摬�x
		text_speed_auto_setting_ui.SetParameterAutoSpeed(system_data.string_auto_speed);//�I�[�g���x
		text_speed_auto_setting_ui.SetParameterBackGroundAlpha(system_data.string_background_alpha);//���ߓx

		//���݂̉𑜓x�̃{�^���Ƀ`�F�b�N��t���Ȃ����B
		window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
		window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
		window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
		window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);
	}


	//�Q�[������flag��true��������
	if (in_game_flag_buffer == true)
	{
		title_button.Update(input);//�^�C�g���{�^���̍X�V����

		if (title_button.GetClick() == true)//�^�C�g���{�^�����N���b�N���ꂽ��
		{
			//���݂̉𑜓x�̃{�^���Ƀ`�F�b�N��t���Ȃ����B
			window_resize_button_960_540.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4), 0), setting);
			window_resize_button_1280_720.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + (32 + 4) * 2, 0), setting);
			window_resize_button_1600_900.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 3), 0), setting);
			window_resize_button_1920_1080.Init(VGet(window_resize_button_position_x, window_resize_button_position_y + ((32 + 4) * 4), 0), setting);

			//�����`�摬�x�ƃI�[�g���x��ۑ������ݒ�ɖ߂��B
			text_speed_auto_setting_ui.SetParameterDrawSpeed(draw_speed);//�����`�摬�x
			text_speed_auto_setting_ui.SetParameterAutoSpeed(auto_speed);//�I�[�g���x
			text_speed_auto_setting_ui.SetParameterBackGroundAlpha(background_alpha);//���ߓx

			title_button.SetSelectedFlag(1);//�I����Ԃ�1���ێ�
			box_draw_flag = 2;//�t�F�[�h�C�����n�߂�
		}
	}

	//�V�[�����n�܂�����
	if (box_draw_flag == 0)//�t�F�[�h�A�E�g�n��
	{
		alpha -= alpha_speed * screen.GetFrameTime();//���ߒl��ύX

		if (alpha <= 0)//���ߒl�t���[����
		{
			alpha = 0;
			box_draw_flag = 1;//�t�F�[�h�A�E�g����
		}
	}

	if (box_draw_flag == 2)//�t�F�[�h�C���n��
	{
		alpha += alpha_speed * screen.GetFrameTime();//���ߒl��ύX

		if (alpha > 255)//���ߒl�t���[����
		{
			alpha = 255;
			box_draw_flag = 3;//�t�F�[�h�C������
		}
	}
}

void OptionScene::Draw(DiploidEngineScreen& screen, bool draw, bool debug)
{	
	//�O�p�`�̓��I�w�i
	continuous_triangle.Draw(draw, debug);

	//Option�̃^�C�g���摜
	option_string_image.Draw(draw, debug);

	//Option��Display�摜
	display_string_image.Draw(draw, debug);

	//Option��GamePlay�摜
	game_play_string_image.Draw(draw, debug);


	//�E�B���h�E�T�C�Y�ύX�{�^��(960_540)
	window_resize_button_960_540.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1280_720)
	window_resize_button_1280_720.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1600_900)
	window_resize_button_1600_900.Draw(draw, debug);

	//�E�B���h�E�T�C�Y�ύX�{�^��(1920_1080)
	window_resize_button_1920_1080.Draw(draw, debug);

	//�����\�����x�ƃI�[�g���x�̕ύXUI�Q
	text_speed_auto_setting_ui.Draw(screen.GetFrameTime(), draw, debug);


	//�ۑ��{�^��
	save_button.Draw(screen.GetFrameTime(), draw, debug);

	//�߂�{�^��
	back_button.Draw(screen.GetFrameTime(), draw, debug);

	//���Z�b�g�{�^��
	reset_button.Draw(screen.GetFrameTime(), draw, debug);

	//�^�C�g���{�^��
	if (in_game_flag_buffer == true)
	{
		title_button.Draw(screen.GetFrameTime(), draw, debug);
	}

	//�t�F�[�h�A�E�g�pBOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


	//DrawFormatString(300, 0, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetSelected());
	//DrawFormatString(300, 20, GetColor(0, 0, 0), "%d", window_resize_button_1280_720.GetSelected());
	//DrawFormatString(300, 40, GetColor(0, 0, 0), "%d", window_resize_button_1600_900.GetSelected());
	//DrawFormatString(300, 60, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetHit());
	//DrawFormatString(300, 80, GetColor(0, 0, 0), "%d", window_resize_button_960_540.GetClick());
	//DrawFormatString(300, 100, GetColor(0, 0, 0), "%f", test.GetParameter().x);
	//DrawFormatString(3000, 120, GetColor(0, 0, 0), "%f", (float)system_data.string_auto_speed * 0.8f);

}


int OptionScene::GetReturnFlag()
{
	//�Q�[�����łȂ��A���߂�{�^������������
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == false))
	{
		option_string_image.Reset();//Option�^�C�g���摜�̃A�j���[�V���������Z�b�g
		display_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g
		game_play_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g

		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		back_button.SetSelectedFlag(-1);//�{�^���̑I����Ԃ�-1(������)�ɂ���B
		title_button.SetSelectedFlag(-1);
		return GAME_TITLE;//�^�C�g���ɖ߂�
	}

	//�Q�[�������߂�{�^������������
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == true))
	{
		option_string_image.Reset();//Option�^�C�g���摜�̃A�j���[�V���������Z�b�g
		display_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g
		game_play_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g

		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		back_button.SetSelectedFlag(-1);//�{�^���̑I����Ԃ�-1(������)�ɂ���B
		title_button.SetSelectedFlag(-1);
		return GAME_START;//�Q�[���ɖ߂�
	}

	//�Q�[�������^�C�g���{�^������������
	if ((title_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == true))
	{
		option_string_image.Reset();//Option�^�C�g���摜�̃A�j���[�V���������Z�b�g
		display_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g
		game_play_string_image.Reset();//Option:Display�摜�̃A�j���[�V���������Z�b�g

		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		back_button.SetSelectedFlag(-1);//�{�^���̑I����Ԃ�-1(������)�ɂ���B
		title_button.SetSelectedFlag(-1);
		return GAME_TITLE;//�^�C�g���ɖ߂�
	}

	return GAME_NONE;
}

SystemData OptionScene::GetSystemData()
{
	return system_data;
}