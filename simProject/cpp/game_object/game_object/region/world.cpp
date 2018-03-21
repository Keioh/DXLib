#include "world.h"

void World::Init()
{
	test1.Init();
	test2.Init();
}

void World::Load()
{
	test1.Load();
	test2.Load();
}

void World::Transform(VECTOR scale, float rote_x, float rote_y, float rote_z, VECTOR pos)
{
	test1.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.0f));
	test2.Transform(VGet(0.1f, 0.1f, 0.1f), 0.0f, 0.0f, 0.0f, VGet(0.5f, 0.1f, 0.5f));

}

void World::Draw(MODE mode, bool wire)
{
	test1.Draw(mode, wire);
	test2.Draw(mode, wire);
}

void World::DrawUI(int window_x, int window_y, MODE mode, Filer config, bool wire)
{
	//�ǂ̒n���I�����Ă��邩�̏���
	if (test1.object_click == 1)select = 1;
	if (test2.object_click == 1)select = 2;


	//�\������UI��ύX
	switch (select)
	{
	case 1:
		test1.DrawUI(window_x, window_y, mode, config, wire);//UI��\��
		test2.window_flag = -1;//��L�ȊO��UI�����
		break;

	case 2:
		test1.window_flag = -1;
		test2.DrawUI(window_x, window_y, mode, config, wire);

		break;

	default:
		break;
	}
}