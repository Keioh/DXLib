//�����ł��B
#pragma once
#include <vector>
#include <memory>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib��������C++�W���������͂��̑��̐��w���C�u�����̎g�p�𐄏�)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"//��񂾂��f�[�^��ǂݍ��ނ��߂̏����Q

#include "ver2.0/Graphics/DiploidCircleV2.h"//Ver2.0�̉~�N���X
#include "ver2.0/Main/Collision.h"//Ver2.0�̓����蔻�菈��

//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
#include "data/number.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidCollision collision;
	DiploidCircleV2 test_one, test_two;

	float anime;

public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void LoadUpdata();//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(��)
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void End();//engine�I���O�����B
};

//�ڕW�F�O���C�Y�Œe���čU������A�c�����̃V���[�e�B���O�Q�[��