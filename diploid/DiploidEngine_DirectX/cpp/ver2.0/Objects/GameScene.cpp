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
		if (jp.string[click].GetEnd() == 0)//最後まで表示されていなかったら
		{
			jp.string[click].AllIn();//最後の文字まで表示
		}
		else
		{
			if ((jp.string.size() - 1) != click)
			{
				click++;//次の文を表示
			}
		}
	}
}

void GameScene::Draw()
{
	jp.string[click].Draw();
}