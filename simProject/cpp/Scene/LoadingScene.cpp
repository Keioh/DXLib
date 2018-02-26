#include "LoadingScene.h"

LoadingScene::LoadingScene()
{
	LoadingScene::Init();
}

void LoadingScene::Init()
{
	loading_scene_flag = 0;
	loading.inti();
}

void LoadingScene::Load()
{
	loading.LoadGraphics();
}

void LoadingScene::DrawLoadingScene(int x, int y)
{
	SetDrawScreen(DX_SCREEN_BACK);//����ʂɕ`��

	while (loading_scene_flag == 0 && ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetBackgroundColor(0, 0, 0);//�w�i�F�����ɐݒ�

		loading.DrawLoading(x, y);//���[�f�B���O�摜��\��

		if (GetASyncLoadNum() == 0)//�ǂݍ��݂��I������烋�[�v�𔲂���B
		{
			SetBackgroundColor(255, 255, 255);//�w�i�F�𔒂ɐݒ�
			LoadingScene::Init();//������
			loading_scene_flag = 1;//���[�v�𔲂���B
		}
	}
}