#include "ver2.0/Objects/GameScene.h"

void GameScene::Load()
{
	jp.Load();
}

void GameScene::Init()
{

}

void GameScene::Updata()
{
	input.Update();

	if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
	{
		if (jp.string[click].GetEnd() == 0)//�Ō�܂ŕ\������Ă��Ȃ�������
		{
			jp.string[click].AllIn();//�Ō�̕����܂ŕ\��
		}
		else
		{
			if ((jp.string.size() - 1) != click)
			{
				click++;//���̕���\��
			}
		}
	}
}

void GameScene::Draw()
{
	jp.string[click].Draw();
}