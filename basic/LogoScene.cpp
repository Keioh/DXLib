#include "LogoScene.h"

void LogoScene::init()
{
	logo.Inti();
	logo_scene_flag = 0;
}

void LogoScene::LoadGraphics()
{
	logo.LoadGraphics();
	logo_sound_handl = LoadSoundMem("pack/Logo/sound/logo_sound.wav");//���ǂݍ���
}

void LogoScene::DrawLogoScene(int x, int y)
{
	while (logo_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{

		if (CheckSoundMem(logo_sound_handl) == 0)PlaySoundMem(logo_sound_handl, DX_PLAYTYPE_BACK);//���ǂݍ���

		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)//�}�E�X�����N���b�N������
		{
			LogoScene::init();//������
			logo_scene_flag = 1;//���S�V�[���𔲂���
		}

		logo.DrawLogo(x, y);//���S��\��	

		if (logo.anime_pos_x >= logo.anime_x)
		{
			LogoScene::init();//������
			logo_scene_flag = 1;//���S�V�[���𔲂���
		}
	}
}