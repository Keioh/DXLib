#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	dice_1.image.Load("texter/dice/dice_1.png");
	dice_2.image.Load("texter/dice/dice_2.png");
	dice_3.image.Load("texter/dice/dice_3.png");
	dice_4.image.Load("texter/dice/dice_4.png");
	dice_5.image.Load("texter/dice/dice_5.png");
	dice_6.image.Load("texter/dice/dice_6.png");

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	dice_1.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_2.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_3.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_4.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_5.image.Init(VGet(100, 720 / 4, 0), 4.f);
	dice_6.image.Init(VGet(100, 720 / 4, 0), 4.f);

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//dice_1.image.Draw();
	//dice_2.image.Draw();
	//dice_3.image.Draw();
	//dice_4.image.Draw();
	//dice_5.image.Draw();
	dice_6.image.Draw();

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}