#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	for (int n = 0; n < 10000; n++)
	{
		circle.Init(VGet(GetRand(WindowSize().x), GetRand(WindowSize().y), 0), 50.0f);
		circle.color = GetColor(GetRand(255), GetRand(255), GetRand(255));
		circle.fill = true;
		circle.mouse_point_move_flag = false;

		circle.move_size = 0.01f;
		circle.origin_size = GetRand(10);
		diploidEngineImpact.PushCircle(circle);
	}
}

void DiploidEngineApp::Update()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	diploidEngineImpact.Updata();

	//object.Update(VGet(0.0f, 0.0f, 0.0f), 0.0f, true);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	diploidEngineImpact.Draw();

	//object.Draw();
}
