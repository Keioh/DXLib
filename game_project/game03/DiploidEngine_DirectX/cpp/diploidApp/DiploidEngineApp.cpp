#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	test_one.Init(VGet(GetWindowSize().x / 2, GetWindowSize().y / 2, 0.0f), 50.0f, GetColor(255, 255, 255));
	test_two.Init(VGet(200, GetWindowSize().y / 2, 0.0f), 50.0f, GetColor(255, 255, 255));

}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	anime += 2.5f;

	test_one.SetRadius(anime);

	collision.CircleAndCircleCollisionUpdata(&test_one, &test_two);

	if (test_one.GetHitFlag() == true)
	{
		test_one.SetColor(GetColor(0, 0, 0));
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	test_one.Draw();
	test_two.Draw();

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}