#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::SoundLoad(DiploidEngineApp* app)
{

}

void DiploidEngineApp::GraphicsLoad(DiploidEngineApp* app)
{	
	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
	option_scene.Load();
	file_scene.Load();
}

void DiploidEngineApp::SoundInit(DiploidEngineApp* app)
{

}

void DiploidEngineApp::GraphicsInit(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init();
	game_scene.Init(app->diploidEngineSetting);
	option_scene.Init(app->diploidEngineSetting);
	file_scene.Init(app->diploidEngineSetting);
}

void DiploidEngineApp::Updata(DiploidEngineApp* app)
{	
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Updata(app->diploidEngineScreen);
	}
	else
	{		
		//�X�^�[�g�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_START)
		{	
			game_scene.SetInGameFlag(true);//�Q�[�����t���O��true�ɂ���
			game_scene.Updata(app->diploidEngineInput, app->diploidEngineScreen);//�Q�[����ʂ��X�V

			//�I�v�V�����{�^����������Ă�����
			if (game_scene.GetOptionButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_OPTION);//�V�[���ύX
			}
		}

		//���[�h�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_FILE)
		{
			file_scene.Updata(app->diploidEngineInput, app->diploidEngineSetting, app->diploidEngineScreen);

			if (file_scene.GetReturnButton() == GAME_TITLE)
			{
				title_scene.SetSecne(GAME_TITLE);//�V�[���ύX
			}
		}

		//�I�v�V�����{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{
			option_scene.Updata(app->diploidEngineInput, app->diploidEngineSetting, app->diploidEngineScreen, game_scene.GetInGameFlag());//�I�v�V������ʂ��X�V(�Ō�̈����ɂ�game_scene��InGameflag������B)		

			//�߂�{�^���������Ă�����
			switch (option_scene.GetReturnFlag())
			{
			//�^�C�g���ɖ߂�B
			case GAME_TITLE:game_scene.SetOptionButtonFlag(-1);//game_scene�̃I�v�V�����{�^���̑I���t���O��-1�ɕύX(�{�^����������)	
							game_scene.SetInGameFlag(false);//�Q�[�����t���O��false�ɂ���
							game_scene.Reset();//�Q�[�������Z�b�g����B
							title_scene.SetSecne(GAME_TITLE);//�V�[���ύX
							break;
			//�Q�[���ɖ߂�B
			case GAME_START:game_scene.SetOptionButtonFlag(-1);//game_scene�̃I�v�V�����{�^���̑I���t���O��-1�ɕύX(�{�^����������)	
							game_scene.SetInGameFlag(true);//�Q�[�����t���O��false�ɂ���
							title_scene.SetSecne(GAME_START);//�V�[���ύX
							break;
			default:break;
			}
		}

		//�I���{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_EXIT)
		{
			app->diploidEngineSetting.SetExit(1);//�I������B
		}

		//���������Ă��Ȃ���
		if (title_scene.GetFinalScene() == GAME_TITLE)
		{
			title_scene.Updata(app->diploidEngineScreen);//�^�C�g����ʂ��X�V
		}
	}
}

void DiploidEngineApp::Draw(DiploidEngineApp* app)
{
	//���S�V�[�����܂��`�撆�Ȃ�
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Draw();
	}
	else//�`�悪�������Ă�����(�^�C�g����ʂ̕\������̑J��)
	{
		//���������Ă��Ȃ���
		if (title_scene.GetFinalScene() == GAME_TITLE)
		{
			title_scene.Draw(app->diploidEngineScreen);
		}

		//�X�^�[�g�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_START)
		{
			game_scene.Draw(app->diploidEngineScreen);
		}

		//���[�h�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_FILE)
		{
			file_scene.Draw(app->diploidEngineScreen);
		}

		//�I�v�V�����{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{
			option_scene.Draw(app->diploidEngineScreen);
		}
	}

	//DrawFormatString(100, 100, GetColor(150, 150, 150), "frame = %f", app->diploidEngineScreen.GetFrameTime());
	//DrawFormatString(0, 200, GetColor(100, 100, 100), "scene = %d", title_scene.GetFinalScene());
	//DrawFormatString(0, 220, GetColor(100, 100, 100), "%d", game_scene.GetOptionButtonFlag());

}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}