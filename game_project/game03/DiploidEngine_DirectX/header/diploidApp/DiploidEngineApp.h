//�����ł��B
#pragma once
#include <list>
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
	DiploidCollision collision;//�����蔻��̏����N���X

	DiploidCircleV2 player_main;//�v���C���[�{��
	DiploidCircleV2 player_grays;//�v���C���[�̃O���C�Y��
	DiploidCircleV2 player_bullet;//�v���C���[�̒e��
	list<DiploidCircleV2> player_bullet_list;//�v���C���[�̒e�ۂ̃��X�g

	DiploidCircleV2 grays_bullet;//�O���C�Y�p�̒e��
	list<DiploidCircleV2> grays_bullet_list;//�G�ɓ�����Ȃ��O���C�Y�p�̒e�ۂ̃��X�g

	DiploidEngineInput input;

	float slow = 1.0f;//�v���C���[�̈ړ����x�̔{��

	int is_count = 20;//�v���C���[�e�̔��˕p�x�����p
	int grays_count = 0, grays_is_count = 10;//�O���C�Y�̃J�E���g���B

public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void Destory();//�폜���鏈���B
	void End();//engine�I���O�����B
};

//�ڕW�F�O���C�Y�Œe���čU������A�c�����̃V���[�e�B���O�Q�[��