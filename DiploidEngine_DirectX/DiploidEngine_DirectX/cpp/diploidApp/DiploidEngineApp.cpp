#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N�����Ƀ��[�h����f�[�^
{	
	object.map.Load("texter/MAP/test_map.png", 256, 256);
}

void DiploidEngineApp::Init()//�ŏ��Ɉ�񂾂��������������������L�q�B
{
	object.map.SetMapChipSize(10);
	//object.map.SetPosition(100.0f, 0.0f);
	object.map.Create();

	object.box.Init(VGet(WindowSize().x / 2, (WindowSize().y / 2), 0), VGet(40, 80, 0));
	object.box.layer_number = DIPLOID_ENGINE_GAMEOBJECT;
	object.box.number = DIPLOID_ENGINE_PLAYER;
	diploidEngineImpact.PushBox(object.box);



	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))
		{
			object.box.Init(VGet((count->x) * count->size, (count->y) * count->size, 0), VGet(count->size, count->size, 0));
			object.box.layer_number = DIPLOID_ENGINE_GAMEOBJECT;
			object.box.number = DIPLOID_ENGINE_MAP_CHIP_001;
			diploidEngineImpact.PushBox(object.box);
		}
	}

}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B
{
	for (auto count = diploidEngineImpact.box_vector.begin(); count != diploidEngineImpact.box_vector.end(); ++count)
	{
		if (count->number == DIPLOID_ENGINE_PLAYER)
		{
			if (diploidEngineInput.GetKey(KEY_INPUT_D) == true)
			{
				count->anime_position.x += 10;
			}

			if (diploidEngineInput.GetKey(KEY_INPUT_A) == true)
			{
				count->anime_position.x -= 10;
			}

			if (diploidEngineInput.GetKey(KEY_INPUT_W) == true)
			{
				count->anime_position.y -= 10;
			}

			if (diploidEngineInput.GetKey(KEY_INPUT_S) == true)
			{
				count->anime_position.y += 10;
			}
		}
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//object.map.Draw(true);
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