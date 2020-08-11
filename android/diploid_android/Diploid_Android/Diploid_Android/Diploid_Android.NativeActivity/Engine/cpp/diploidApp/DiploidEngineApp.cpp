#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{		
	box.Init(VGet(200, 1000, 0), VGet(500, 300, 0), GetColor(255, 255, 255));
	box.SetFill(true);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();
	
	if (collision.BoxAndTouchCollisionUpdate(&box, input.GetTouchPositionX(), input.GetTouchPositionY()) == true)
	{			
		if (input.GetReleaseTouch() == true)
		{
			box.SetColor(GetColor(255, 255, 255));
		}
		else
		{
			box.SetColor(GetColor(255, 0, 0));
		}
	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	box.Draw();

	SetFontSize(50);

	DrawFormatStringF(0, 50, GetColor(255, 255, 255), "touch_release = %d", input.GetTouchReleaseFlag());
	DrawFormatStringF(0, 50 * 2, GetColor(255, 255, 255), "touch_x = %d", input.GetTouchPositionX());
	DrawFormatStringF(0, 50 * 3, GetColor(255, 255, 255), "touch_y = %d", input.GetTouchPositionY());

}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g(ver1.0)������ꍇ�͂����ō폜�����������B
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}