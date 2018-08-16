#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	image.Load("texter/test.png");

	sound.Load("sound/01.wav");
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	
	point.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(point);


	//�T�C�Y�ύX�͉�����
	for (int n = 0; n < 50; n++)
	{	
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		pos.z = 0;

		image.Init(pos, 0.3f);
		box.Init(VGet(pos.x - (150 * 0.3f), pos.y - (150 * 0.3f), 0), VGet(300 * 0.3f, 300 * 0.3f, 0));

		//�ԍ��͓����̂��Ȃ�ׂ��g�p���Ȃ��B(�I�u�W�F�N�g���폜����Ƃ��ɓ����ԍ����Ƃ�������ɏ����܂�)
		image.number += 1;
		box.number += 1;

		image.destory = box.destory = true;

		diploidEngineImpact.PushBox(box);
		diploidEngineLayer.PushTopGraphics(image);
	}
	
	//�ԍ��̈��p��
	circle.number = box.number;
	
	for (int n = 0; n < 50; n++)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);
		pos.y = GetRand(WindowSize().y);
		//pos.z = 0;

		image.Init(pos, 0.3f);
		circle.Init(pos, 150 * 0.3f);

		//�ԍ��͓����̂��Ȃ�ׂ��g�p���Ȃ��B(�I�u�W�F�N�g���폜����Ƃ��ɓ����ԍ����Ƃ�������ɏ����܂�)
		image.number += 1;
		circle.number += 1;

		image.destory = circle.destory = true;

		diploidEngineImpact.PushCircle(circle);
		diploidEngineLayer.PushMidGraphics(image);
	}
	
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{	
	//sound.Play();
	diploidEngineInput.GetMouse(MOUSE_INPUT_LEFT);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}