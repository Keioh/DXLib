#include "Level01.h"

void Level01::init()
{
	//������
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();

	//���Ƃ��ƃX�C�b�`���I���ɂȂ��Ă���Ƃ����1�ɂ���B
	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;

}

void Level01::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
}

void Level01::Draw(int pos_x, int pos_y, bool wire)
{
	//�`��
	object[0].Draw(pos_x, pos_y, wire);//��
	object[1].Draw(pos_x - 50, pos_y + 100, wire);//��
	object[2].Draw(pos_x + 50, pos_y + 100, wire);//�E
	object[3].Draw(pos_x, pos_y + 200, wire);//��

	//�ȉ��{�^���������Ƃ��̏���
	//[0]���N���b�N�����u�Ԃ�����������
	if (object[0].switch_object.mouse_input.click == true)
	{
		//[0]���������Ƃ��̏���
		if (object[0].switch_object.switch_flag == 1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
		else if (object[0].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
	}

	//[1]���N���b�N�����u�Ԃ�����������
	if (object[1].switch_object.mouse_input.click == true)
	{
		//[1]���������Ƃ��̏���
		if (object[1].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
		else if (object[1].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
	}

	//[2]���N���b�N�����u�Ԃ�����������
	if (object[2].switch_object.mouse_input.click == true)
	{
		//[2]���������Ƃ��̏���
		if (object[2].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
		else if (object[2].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
		}
	}

	//[3]���N���b�N�����u�Ԃ�����������
	if (object[3].switch_object.mouse_input.click == true)
	{
		//[3]���������Ƃ��̏���
		if (object[3].switch_object.switch_flag == 1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
		}
	}

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}