#include "Level02.h"

void Level02::init()
{
	rand_power = 10;

	//������
	object[0].init();
	object[1].init();
	object[2].init();
	object[3].init();
	object[4].init();
	object[5].init();
	object[6].init();

	//���Ƃ��ƃX�C�b�`���I���ɂȂ��Ă���Ƃ����1�ɂ���B
	object[1].switch_object.switch_flag = 1;
	object[2].switch_object.switch_flag = 1;
	object[5].switch_object.switch_flag = 1;

}

void Level02::Load()
{
	object[0].Load();
	object[1].Load();
	object[2].Load();
	object[3].Load();
	object[4].Load();
	object[5].Load();
	object[6].Load();

}

void Level02::ClickEvent()
{
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
		}
		else if (object[3].switch_object.switch_flag == -1)
		{
			object[1].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
	}

	//[4]���N���b�N�����u�Ԃ�����������
	if (object[4].switch_object.mouse_input.click == true)
	{
		//[3]���������Ƃ��̏���
		if (object[4].switch_object.switch_flag == 1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
		else if (object[4].switch_object.switch_flag == -1)
		{
			object[0].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[5].switch_object.switch_flag *= -1;
		}
	}

	//[5]���N���b�N�����u�Ԃ�����������
	if (object[5].switch_object.mouse_input.click == true)
	{
		//[3]���������Ƃ��̏���
		if (object[5].switch_object.switch_flag == 1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
		else if (object[5].switch_object.switch_flag == -1)
		{
			object[4].switch_object.switch_flag *= -1;
			object[2].switch_object.switch_flag *= -1;
			object[6].switch_object.switch_flag *= -1;
		}
	}

	//[6]���N���b�N�����u�Ԃ�����������
	if (object[6].switch_object.mouse_input.click == true)
	{
		//[3]���������Ƃ��̏���
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
}

void Level02::HitEvent()
{
	//object[0]�Ƀq�b�g�����Ƃ�
	if (object[0].switch_object.circle_collision.hit == true)
	{
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[0].pos.x, object[0].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[1]�։��т��
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[2]�։��т��
		DrawLineAA(object[0].pos.x, object[0].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[0]++, line_color[0]++, line_color[0]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[0] = 0;
	}

	//object[1]�Ƀq�b�g�����Ƃ�
	if (object[1].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[1].pos.x, object[1].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[1]�։��т��
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[2]�։��т��
		DrawLineAA(object[1].pos.x, object[1].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[1]++, line_color[1]++, line_color[1]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[1] = 0;
	}

	//object[2]�Ƀq�b�g�����Ƃ�
	if (object[2].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[2].pos.x, object[2].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[1]�։��т��
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[2]�։��т��
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]�։��т��
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]�։��т��
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]�։��т��
		DrawLineAA(object[2].pos.x, object[2].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[2]++, line_color[2]++, line_color[2]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[2] = 0;
	}

	//object[3]�Ƀq�b�g�����Ƃ�
	if (object[3].switch_object.circle_collision.hit == true)
	{
		object[1].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[3].pos.x, object[3].pos.y, object[1].pos.x, object[1].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[1]�։��т��
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[2]�։��т��
		DrawLineAA(object[3].pos.x, object[3].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[3]++, line_color[3]++, line_color[3]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[3] = 0;
	}

	//object[4]�Ƀq�b�g�����Ƃ�
	if (object[4].switch_object.circle_collision.hit == true)
	{
		object[0].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[4].pos.x, object[4].pos.y, object[0].pos.x, object[0].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[1]�։��т��
		DrawLineAA(object[4].pos.x, object[4].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[2]�։��т��
		DrawLineAA(object[4].pos.x, object[4].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[4]++, line_color[4]++, line_color[4]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[4] = 0;
	}

	//object[5]�Ƀq�b�g�����Ƃ�
	if (object[5].switch_object.circle_collision.hit == true)
	{
		object[4].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[6].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[5].pos.x, object[5].pos.y, object[4].pos.x, object[4].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[1]�։��т��
		DrawLineAA(object[5].pos.x, object[5].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[2]�։��т��
		DrawLineAA(object[5].pos.x, object[5].pos.y, object[6].pos.x, object[6].pos.y, GetColor(line_color[5]++, line_color[5]++, line_color[5]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[5] = 0;
	}

	//object[6]�Ƀq�b�g�����Ƃ�
	if (object[6].switch_object.circle_collision.hit == true)
	{
		object[3].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[2].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };
		object[5].rand_pos = { GetRand(rand_power),GetRand(rand_power),GetRand(rand_power) };

		DrawLineAA(object[6].pos.x, object[6].pos.y, object[3].pos.x, object[3].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[1]�։��т��
		DrawLineAA(object[6].pos.x, object[6].pos.y, object[2].pos.x, object[2].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[2]�։��т��
		DrawLineAA(object[6].pos.x, object[6].pos.y, object[5].pos.x, object[5].pos.y, GetColor(line_color[6]++, line_color[6]++, line_color[6]++), 5);//[4]�։��т��

	}
	else
	{
		line_color[6] = 0;
	}

}

void Level02::Draw(int pos_x, int pos_y, Filer config, bool wire)
{
	//�q�b�g�����Ƃ��̏���
	Level02::HitEvent();

	//�N���b�N�����Ƃ��̏���
	Level02::ClickEvent();

	//�`��
	object[0].Draw(pos_x, pos_y, config, wire);//��
	object[1].Draw(pos_x - 50, pos_y + 100, config, wire);//��
	object[2].Draw(pos_x + 50, pos_y + 100, config, wire);//�E
	object[3].Draw(pos_x, pos_y + 200, config, wire);//��

	//����
	object[4].Draw(pos_x + 100, pos_y, config, wire);//��
	object[5].Draw(pos_x + 150, pos_y + 100, config, wire);//��
	object[6].Draw(pos_x + 100, pos_y + 200, config, wire);//��

	if ((object[0].object_switch_flag == -1) && (object[1].object_switch_flag == -1) && (object[2].object_switch_flag == -1) && (object[3].object_switch_flag == -1) &&
		(object[4].object_switch_flag == -1) && (object[5].object_switch_flag == -1) && (object[6].object_switch_flag == -1))
	{
		DrawString(0, 20, "Clear", GetColor(0, 0, 0));
	}
}