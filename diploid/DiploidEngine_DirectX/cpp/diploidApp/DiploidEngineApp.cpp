#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	object->box.Init(VGet(100, 300, 0), VGet(20, 60, 0));
	object->box.name_tag = "test_object";
	object->box.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushBox(object->box);

	object->box.Init(VGet(100, 300, 0), VGet(20, 60, 0));
	object->box.name_tag = "test_object_1";
	object->box.layer_number = DIPLOID_LAYER_01;
	diploidEngineImpact.PushBox(object->box);

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	diploidEngineImpact.SetBoxPositionAnimation_Sreach_Object_Name("test_object", VGet(0.5f, 0, 0));
	diploidEngineImpact.SetBoxPositionAnimation_Sreach_Object_Name("test_object_1", VGet(0.1f, 0.1f, 0));

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}