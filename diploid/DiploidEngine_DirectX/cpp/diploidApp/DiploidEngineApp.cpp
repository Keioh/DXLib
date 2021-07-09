#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::OnceLoad(DiploidEngineApp* app)
{	

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{		
	test.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	test.Create("�Ȃ������͂����ɂ���̂��A�ǂ�����ė����̂��A�肩�ł͂Ȃ��B������A�m���Ȃ��Ƃ͖ڂ̑O�ɂ��鏭���̌��t�Ɏ����X���鎖�����������B");

	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
	option_scene.Load();
	file_scene.Load();
}

void DiploidEngineApp::OnceInit(DiploidEngineApp* app)
{		
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	test.Init(100, 100);

	logo_scene.Init();
	title_scene.Init(app->diploidEngineSetting);
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
			game_scene.SetSystemData(option_scene.GetSystemData());//option����̃V�X�e���ݒ���擾
			game_scene.SetInGameFlag(true);//�Q�[�����t���O��true�ɂ���
			game_scene.Updata(app->diploidEngineInput, app->diploidEngineScreen);//�Q�[����ʂ��X�V

			//�I�v�V�����{�^����������Ă�����
			if (game_scene.GetOptionButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_OPTION);//�V�[���ύX
			}

			//���[�h�{�^����������Ă�����
			if (game_scene.GetLoadButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_FILE);//�V�[���ύX
			}

			//�Z�[�u�{�^����������Ă�����
			if (game_scene.GetSaveButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_FILE);//�V�[���ύX
			}
		}

		//���[�h�{�^�����������Ƃ�
		if (title_scene.GetFinalScene() == GAME_FILE)
		{
			file_scene.Updata(app->diploidEngineInput, app->diploidEngineSetting, app->diploidEngineScreen, game_scene.GetInGameFlag(), game_scene.GetSelectedScene());

			//�߂�{�^���������Ă�����
			switch (file_scene.GetReturnButton())
			{
			//�^�C�g���ɖ߂�B
			case GAME_TITLE:
				title_scene.SetSecne(GAME_TITLE);//�V�[���ύX
				break;
			//�Q�[���ɖ߂�B
			case GAME_START:
				title_scene.SetSecne(GAME_START);//�V�[���ύX
				break;
			default:break;
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
							game_scene.SetInGameFlag(true);//�Q�[�����t���O��true�ɂ���
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

	test.Draw();
	//DrawFormatString(100, 100, GetColor(150, 150, 150), "frame = %f", app->diploidEngineScreen.GetFrameTime());
	//DrawFormatString(0, 200, GetColor(100, 100, 100), "scene = %d", title_scene.GetFinalScene());
	//DrawFormatString(0, 220, GetColor(100, 100, 100), "%d", game_scene.GetOptionButtonFlag());
}

void DiploidEngineApp::CreateShadowModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::CreateShadowPassiveModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}