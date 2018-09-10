#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{
	test.Load();
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	//�}�E�X�ݒ�
	mouse.layer_number = DIPLOID_ENGINE_GAMEOBJECT;
	mouse.mouse_point_move_flag = true;
	diploidEngineImpact.PushPoint(mouse);

	//�I�u�W�F�N�g�ǉ�
	test.Init(VGet(1280 / 2,720/2,0));
	test.Push(diploidEngineImpact, diploidEngineLayer);
	//diploidEngineImpact.PushBox(test.region_01.GetBox());
	//diploidEngineLayer.PushBotGraphics(test.region_01.GetImage());

	//diploidEngineImpact.PushBox(test.region_02.GetBox());
	//diploidEngineLayer.PushBotGraphics(test.region_02.GetImage());

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	test.Updata(diploidEngineImpact, diploidEngineLayer, diploidEngineInput);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	test.Draw();
}


//�ȉ�������
DiploidObject DiploidEngineApp::FindObject(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�I�u�W�F�N�g������)
{
	DiploidObject diploid_object;


	return diploid_object;
}

DiploidBox DiploidEngineApp::FindImpactBOX(int layer_number, int number)//�w��ԍ�����I�u�W�F�N�g���擾(�Փ˂�����)
{
	DiploidBox diploid_box;

	for (auto box = diploidEngineImpact.box_vector.begin(); box != diploidEngineImpact.box_vector.end(); box++)
	{
		if (box->layer_number == layer_number)
		{
			if (box->number == number)
			{
				diploid_box.position = box->position;
				diploid_box.layer_number = box->layer_number;
				diploid_box.number = box->number;
				diploid_box.anime_position = box->anime_position;
				diploid_box.anime_size = box->anime_size;
			}
		}
	}

	return diploid_box;
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