#include "Level03.h"

void Level03::init()
{
	//������
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();
	object[4].init();
	object[5].init();
	object[6].init();
	object[7].init();
	object[8].init();

	//���Ƃ��ƃX�C�b�`���I���ɂȂ��Ă���Ƃ����1�ɂ���B
	object[1].switch_object.switch_flag = 1;
	//object[2].switch_object.switch_flag = 1;
	object[5].switch_object.switch_flag = 1;
	object[7].switch_object.switch_flag = 1;
	object[8].switch_object.switch_flag = 1;

}

void Level03::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
	object[4].Load();
	object[5].Load();
	object[6].Load();
	object[7].Load();
	object[8].Load();

}

void Level03::Draw(int pos_x, int pos_y, bool wire)
{
	//�`��
	object[0].Draw(200, 150, wire);//��
	object[1].Draw(150, 250, wire);//����
	object[2].Draw(250, 250, wire);//���E
	object[3].Draw(200, 350, wire);//��

								   //����
	object[4].Draw(300, 150, wire);//��
	object[5].Draw(350, 250, wire);//��
	object[6].Draw(300, 350, wire);//��

	object[7].Draw(100, 350, wire);//��
	object[8].Draw(400, 150, wire);//��

								   //�ȉ��{�^���������Ƃ��̏���
								   //[0]���N���b�N�����u�Ԃ�����������
	if (object[0].switch_object.mouse_input.click == true)
	{
		//[0]���������Ƃ��̏���
		if (object[0].switch_object.switch_flag == 1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
		}
		else if (object[0].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
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
			object[7].switch_object.switch_flag *= -1;
		}
		else if (object[1].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
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
			object[4].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;

		}
		else if (object[2].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
			object[3].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
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
			object[6].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
			object[7].switch_object.switch_flag *= -1;
		}
	}

	//[4]���N���b�N�����u�Ԃ�����������
	if (object[4].switch_object.mouse_input.click == true)
	{
		//[4]���������Ƃ��̏���
		if (object[4].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
		else if (object[4].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
	}

	//[5]���N���b�N�����u�Ԃ�����������
	if (object[5].switch_object.mouse_input.click == true)
	{
		//[5]���������Ƃ��̏���
		if (object[5].switch_object.switch_flag == 1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
		else if (object[5].switch_object.switch_flag == -1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
			object[8].switch_object.switch_flag *= -1;
		}
	}

	//[6]���N���b�N�����u�Ԃ�����������
	if (object[6].switch_object.mouse_input.click == true)
	{
		//[6]���������Ƃ��̏���
		if (object[6].switch_object.switch_flag == 1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
		else if (object[6].switch_object.switch_flag == -1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
	}

	//[7]���N���b�N�����u�Ԃ�����������
	if (object[7].switch_object.mouse_input.click == true)
	{
		//[7]���������Ƃ��̏���
		if (object[7].switch_object.switch_flag == 1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
		}
		else if (object[7].switch_object.switch_flag == -1)
		{
			object[3].switch_object.switch_flag *= -1;
			object[1].switch_object.switch_flag *= -1;
		}
	}

	//[8]���N���b�N�����u�Ԃ�����������
	if (object[8].switch_object.mouse_input.click == true)
	{
		//[8]���������Ƃ��̏���
		if (object[8].switch_object.switch_flag == 1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
		else if (object[8].switch_object.switch_flag == -1)
		{
			object[5].switch_object.switch_flag *= -1;
			object[4].switch_object.switch_flag *= -1;
		}
	}


	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1) &&
		(object[4].object_switch_flag == -1) && (object[5].object_switch_flag == -1) && (object[6].object_switch_flag == -1) &&
		(object[7].object_switch_flag == -1) && (object[8].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}