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
	object.box.Init(VGet(300, 300, 0), VGet(100,100,0));
	diploidEngineImpact.PushBox(object.box);

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