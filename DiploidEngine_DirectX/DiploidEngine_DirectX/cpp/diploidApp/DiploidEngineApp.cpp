#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	//image.Load("texter/test.png");

	//sound.Load("sound/01.wav");
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{	
	/*
	
	point.mouse_point_move_flag = true;
	point.layer_number = DIPLOID_ENGINE_UI;
	diploidEngineImpact.PushPoint(point);
	
	for (int n = 0; n < 50; n++)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		//pos.z = 0;

		image.Init(pos, 0.3f);
		circle.Init(pos, 150 * 0.3f);

		//�ԍ��͓����̂��Ȃ�ׂ��g�p���Ȃ��B(�I�u�W�F�N�g���폜����Ƃ��ɓ����ԍ����Ƃ�������ɏ����܂�)
		image.layer_number = DIPLOID_ENGINE_UI;
		image.number += 1;

		circle.layer_number = DIPLOID_ENGINE_UI;
		circle.number += 1;

		image.destory = circle.destory = true;

		diploidEngineImpact.PushCircle(circle);
		diploidEngineLayer.PushMidGraphics(image);
	}
	*/


	//DiploidObject���g�p�����ꍇ

	object.circle.Init(VGet(WindowSize().x / 2, 300, 0), 25);
	diploidEngineImpact.PushCircle(object.circle);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	//sound.Play();
	diploidEngineInput.GetPressKey(KEY_INPUT_A);
	diploidEngineInput.GetPressMouse(MOUSE_INPUT_LEFT);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}

DiploidObject DiploidEngineApp::FindObject(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�I�u�W�F�N�g������)
{
	DiploidObject diploid_object;


	return diploid_object;
}

DiploidEngineImpact DiploidEngineApp::FindImpactBOX(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
}

DiploidEngineImpact DiploidEngineApp::FindImpactCIRCLE(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
}

DiploidEngineImpact DiploidEngineApp::FindImpactPOINT(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
{
	DiploidEngineImpact diploid_impact;


	return diploid_impact;
}

DiploidEngineLayer DiploidEngineApp::FindImageTOP(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}

DiploidEngineLayer DiploidEngineApp::FindImageMID(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}

DiploidEngineLayer DiploidEngineApp::FindImageBOT(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�摜������)
{
	DiploidEngineLayer diploid_layer;


	return diploid_layer;
}
