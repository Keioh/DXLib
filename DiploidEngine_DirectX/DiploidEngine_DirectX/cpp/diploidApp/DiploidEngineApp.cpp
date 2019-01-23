#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	object.map.Load("texter/MAP/test_map.png", 128, 128);//�}�b�v�摜�f�[�^��ǂݍ���(�Ō��x,y�͉摜�̑傫�����w��)
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	object.map.SetMapChipSize(100);//�摜��1�h�b�g���ǂꂾ���g�傷�邩�w��
	object.map.Create();//�摜�f�[�^����}�b�v�f�[�^���쐬

	object.box.Init(VGet(300,400,0), VGet(50,100,0));//point�O���t�B�b�N���}�E�X�ɒǏ]������
	object.box.layer_number = 0;
	object.box.number = 0;
	diploidEngineImpact.PushBox(object.box);//point�O���t�B�b�N��Impact�z��ɒǉ�

	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)//map.MAP�z���size_t(auto)�Ŏ擾��MAP.end()�܂ŉ��L�̂��Ƃ��J��Ԃ�
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//���l��255�̎������̎�
		{
			object.box.Init(VGet(count->x * count->size, count->y * count->size, 0), VGet(count->size, count->size, 0));
			object.box.layer_number = 0;
			object.box.number += 1;
			diploidEngineImpact.PushBox(object.box);
		}
	}
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	if (diploidEngineImpact.GetBoxImpactFlag(0) == 0)//�Փ˂��Ă��Ȃ��Ƃ��̏���
	{
		for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, -4, 0));
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, -4, 0));
			}
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, -4, 0));
			}
		}
	}
	else//�Փ˂��Ă���Ƃ��̏���
	{
		for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
		{
			diploidEngineImpact.SetBoxPositionAnimation(count, VGet(0, 0, 0));
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_D) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(-4, 0, 0));
			}
		}

		if (diploidEngineInput.GetPressKey(KEY_INPUT_A) == 1)
		{
			for (int count = 1; count != diploidEngineImpact.box_vector.size(); ++count)
			{
				diploidEngineImpact.SetBoxPositionAnimation(count, VGet(4, 0, 0));
			}
		}
	}



}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}