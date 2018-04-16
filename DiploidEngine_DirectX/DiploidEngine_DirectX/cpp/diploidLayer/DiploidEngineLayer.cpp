#include "diploidLayer\DiploidEngineLayer.h"

//�S�Ẵ��C���[���X�V
void DiploidEngineLayer::UpdataLayerObject()
{
	//bot
	for (int n = 0; n != layer_bot_object_simple.size(); n++)//����
	{
		layer_bot_object_simple[n].Update();
	}

	for (int n = 0; n != layer_bot_object_circle.size(); n++)//�~
	{
		layer_bot_object_circle[n].Update();
	}

	//mid
	for (int n = 0; n != layer_mid_object_simple.size(); n++)//����
	{
		layer_mid_object_simple[n].Update();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Update();
	}

	//top
	for (int n = 0; n != layer_top_object_simple.size(); n++)//����
	{
		layer_top_object_simple[n].Update();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)//�~
	{
		layer_top_object_circle[n].Update();
	}
}

//�S�Ẵ��C���[��`��
void DiploidEngineLayer::DrawLayerObject()
{
	//bot
	for (int n = 0; n != layer_bot_object_simple.size(); n++)//����
	{
		layer_bot_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_bot_object_circle.size(); n++)//�~
	{
		layer_bot_object_circle[n].Draw();
	}

	//mid
	for (int n = 0; n != layer_mid_object_simple.size(); n++)//����
	{
		layer_mid_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)//�~
	{
		layer_mid_object_circle[n].Draw();
	}

	//top
	for (int n = 0; n != layer_top_object_simple.size(); n++)//����
	{
		layer_top_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)//�~
	{
		layer_top_object_circle[n].Draw();
	}
}


//���ۃv�b�V��
void DiploidEngineLayer::PushBackTopObject_simple(DiploidEngineObject object)
{
	layer_top_object_simple.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}

void DiploidEngineLayer::PushBackMidObject_simple(DiploidEngineObject object)
{
	layer_mid_object_simple.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}

void DiploidEngineLayer::PushBackBotObject_simple(DiploidEngineObject object)
{
	layer_bot_object_simple.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}


//�~�v�b�V��
void DiploidEngineLayer::PushBackTopObject_circle(DiploidCircle object)
{
	layer_top_object_circle.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}

void DiploidEngineLayer::PushBackMidObject_circle(DiploidCircle object)
{
	layer_mid_object_circle.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}

void DiploidEngineLayer::PushBackBotObject_circle(DiploidCircle object)
{
	layer_bot_object_circle.push_back(object);//���C���[�ɃI�u�W�F�N�g��ǉ�
}

//�~�|�b�v
void DiploidEngineLayer::PopBackTopObject_circle(int object_number)
{
	layer_top_object_circle.erase(layer_top_object_circle.begin() + (object_number));//���C���[����I�u�W�F�N�g���폜
}

void DiploidEngineLayer::PopBackMidObject_circle(int object_number)
{
	layer_mid_object_circle.erase(layer_mid_object_circle.begin() + (object_number));//���C���[����I�u�W�F�N�g���폜
}

void DiploidEngineLayer::PopBackBotObject_circle(int object_number)
{
	layer_bot_object_circle.erase(layer_bot_object_circle.begin() + (object_number));//���C���[����I�u�W�F�N�g���폜
}

//���ۃA�v�f
void DiploidEngineLayer::UpdateLayerObject_simple()
{
	for (int n = 0; n != layer_bot_object_simple.size(); n++)
	{
		layer_bot_object_simple[n].Update();
	}

	for (int n = 0; n != layer_mid_object_simple.size(); n++)
	{
		layer_mid_object_simple[n].Update();
	}

	for (int n = 0; n != layer_top_object_simple.size(); n++)
	{
		layer_top_object_simple[n].Update();
	}
}

//���ە`��
void DiploidEngineLayer::DrawLayerObject_simple()
{
	for (int n = 0; n != layer_bot_object_simple.size(); n++)
	{
		layer_bot_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_simple.size(); n++)
	{
		layer_mid_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_top_object_simple.size(); n++)
	{
		layer_top_object_simple[n].Draw();
	}
}

//�~�A�v�f
void DiploidEngineLayer::UpdateLayerObject_circle()
{
	for (int n = 0; n != layer_bot_object_circle.size(); n++)
	{
		layer_bot_object_circle[n].Update();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Update();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)
	{
		layer_top_object_circle[n].Update();
	}
}

//�~�`��
void DiploidEngineLayer::DrawLayerObject_circle()
{
	for (int n = 0; n != layer_bot_object_circle.size(); n++)
	{
		layer_bot_object_circle[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Draw();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)
	{
		layer_top_object_circle[n].Draw();
	}
}