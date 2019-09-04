#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{
	object.map.Load("texter/MAP/map.png", 10, 6);
	object.image.Load("texter/map_chip/�C���X�g4.png");
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	object.map.SetMapChipSize(128);
	object.map.Create();

	object.box.Init(VGet(1280 - (128 * 3), 720 - 128 -80, 0), VGet(64, 128, 0));
	object.box.name_tag = "player_box";
	object.box.layer_number = DIPLOID_LAYER_00;
	diploidEngineImpact.PushBox(object.box);


	for (auto count = object.map.MAP.begin(); count != object.map.MAP.end(); ++count)
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))
		{
			object.box.Init(VGet(count->x * count->size, count->y * count->size, 0), VGet(count->size, count->size, 0));
			object.box.name_tag = "ground_box";
			object.box.layer_number = DIPLOID_LAYER_00;
			diploidEngineImpact.PushBox(object.box);

			object.image.Init(VGet(count->x * count->size + 64, count->y * count->size + 64, 0));
			object.image.name_tag = "ground_image";
			object.box.layer_number = DIPLOID_LAYER_00;
			diploidEngineLayer.PushMidGraphics(object.image);
		}
	}

	diploidEngineImpact.AutoNumber();
}

void DiploidEngineApp::LoadUpdata()//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(�Q�[�����Ƀ��[�h�������f�[�^�Ȃ�)
{
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	//�d�͏���
	if (diploidEngineImpact.GetBoxImpactFlag_Sreach_Name_Tag("ground_box") == false)
	{
		diploidEngineImpact.SetBoxPositionAnimationY_Sreach_Object_Name("player_box", -object.physics.Gravity());
	}
	else
	{
		object.physics.GravityReset();
		diploidEngineImpact.SetBoxPositionAnimationY_Sreach_Object_Name("player_box", 0.0f);
	}

	//�E�ړ�
	if (diploidEngineInput.GetKey(KEY_INPUT_RIGHT) == true)
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", 3.0f);
	}
	//���ړ�
	else if (diploidEngineInput.GetKey(KEY_INPUT_LEFT) == true)
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", -3.0f);
	}
	else
	{
		diploidEngineImpact.SetBoxPositionAnimationX_Sreach_Object_Name("player_box", 0.0f);
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "center_val = %d", diploidEngineInput.GetWhellVolume());
	DrawFormatString(0, 20, GetColor(0, 0, 0), "scale_val = %.2f", diploidEngineInput.GetWhellVolume_Scale());

}

void DiploidEngineApp::End()//engine�I���O�����B
{

}