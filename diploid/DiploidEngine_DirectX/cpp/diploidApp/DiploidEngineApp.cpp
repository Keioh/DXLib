#include "diploidApp\DiploidEngineApp.h"

void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{
	
}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	
	dice_3d6n.Load();
}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	dice_3d6n.Init(diploidEngineImpact, VGet(50, 720 / 4, 0));

	//�}�E�X�|�C���^�[�p
	point.mouse_point_move_flag = true;
	point.number = OBJECT_NUMBER_POINT;
	diploidEngineImpact.PushPoint(point);
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	dice_3d6n.Update(diploidEngineImpact, diploidEngineInput);
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	dice_3d6n.Draw(diploidEngineImpact);
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}