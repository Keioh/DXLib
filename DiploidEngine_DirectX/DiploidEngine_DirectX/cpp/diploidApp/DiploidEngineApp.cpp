#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	

	object.image.Load("texter/test.png");//�e�N�X�`����ǂݍ���

}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{	
/*
	//�}�E�X�Ǐ]�ݒ��BOX�I�u�W�F�N�g����쐬
	object.circle.Init(VGet(0, 0, 0), 25);
	object.circle.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//���肵�������ʔԍ�����
	object.circle.mouse_point_move_flag = true;//�}�E�X�ɒǏ]����悤�ɐݒ�
	diploidEngineImpact.PushCircle(object.circle);//�Փ˔�����s��BOX�z���BOX�I�u�W�F�N�g���v�b�V��

	//BOX�ɉ摜��t���A�����50�����_���Ȉʒu�ɍ쐬
	for (int count = 0; count < 50; ++count)
	{
		VECTOR pos;
		pos.x = GetRand(WindowSize().x);//�����_���l�擾
		pos.y = GetRand(WindowSize().y);

		object.box.Init(VGet(pos.x, pos.y, 0), VGet(50, 50, 0));
		object.box.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//���ʔԍ����Q�[���I�u�W�F�N�g�ɐݒ�
		object.box.number += 1;//BOX�I�u�W�F�N�g�ɂP���[�v�ɂ�+1�I�u�W�F�N�g�ԍ���t�^
		object.box.mouse_point_move_flag = false;//For���̑O��true�ɂ��Ă���̂�false�ɐݒ�
		object.box.destory = true;//�q�b�g���肪�������ꍇ�A�Ώۂ��폜����t���O���Z�b�g

		object.image.Init(VGet(pos.x, pos.y, 0), 0.2f);
		object.image.layer_number = DIPLOID_ENGINE_GAMEOBJECT;//BOX�Ɠ������ʔԍ����w��
		object.image.number += 1;//BOX�I�u�W�F�N�g�Ɠ����ԍ���t�^
		object.image.destory = true;//�q�b�g���肪�������ꍇ�A�Ώۂ��폜

		diploidEngineLayer.PushTopGraphics(object.image);//�\�����C���[�̃g�b�v(��ԏ�)�ɃC���[�W���v�b�V��
		diploidEngineImpact.PushBox(object.box);//�Փ˔�����s��BOX�z���BOX�I�u�W�F�N�g���v�b�V��
	}
	*/

	for (int count = 0; count < 500; ++count)
	{
		object.line.Init(VGet(200 + count, 200, 0), VGet(400 + count, 500, 0));
		object.line.destory = true;
		diploidEngineImpact.PushLine(object.line);
	}

	object.circle.Init(VGet(0, 0, 0), 25);
	object.circle.mouse_point_move_flag = true;

	diploidEngineImpact.PushCircle(object.circle);

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{

}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//DrawFormatStringF(0, 500, GetColor(255, 255, 255), "test = %.2f", math.DotProduct(20, 2));
}


//�ȉ�������
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
