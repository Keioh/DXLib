#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	object.file.LoadJSON("json/test.json");	//json�t�@�C���ǂݍ���
	json_test = object.file.GetJSON()["test"];//"test"�̃f�[�^��ǂݎ��B
	json_pi = object.file.GetJSON()["pi"];//"pi"�̃f�[�^��ǂݎ��B
	json_string = object.file.GetJSON()["world"].dump();//������͕��������B�Ȃ������{�ꂾ��release�����Ƃ������������Ȃ��B�Ȃ�ł�B

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{

}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", json_test);//"test"�̒��g���o��
	DrawFormatString(0, 20, GetColor(0, 0, 0), "%f", json_pi);//"pi"�̒��g���o��
	DrawFormatString(0, 40, GetColor(0, 0, 0), "%s", json_string);//��������

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}