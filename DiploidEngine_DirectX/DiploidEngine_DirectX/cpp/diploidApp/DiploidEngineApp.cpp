#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 5; n++)
	{
		object.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		object.position.x = (WindowSize().x / 2) + (n * 30);
		object.position.y = (WindowSize().y / 2);
		object.fill = FALSE;
		object.size.z = 100;
		object.thickness = 15;
		diploidEngineLayer.PushBackTopObject_circle(object);
	}

}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineLayer.DrawLayerObject();//���C���[�V�X�e���ɂ���I�u�W�F�N�g��`��
}
