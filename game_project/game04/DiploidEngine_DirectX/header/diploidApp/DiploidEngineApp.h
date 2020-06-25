//�����ł��B
#pragma once
#include <list>
#include <memory>
#include <unordered_map>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib��������C++�W���������͂��̑��̐��w���C�u�����̎g�p�𐄏�)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"//��񂾂��f�[�^��ǂݍ��ނ��߂̏����Q

#include "ver2.0/Graphics/DiploidCircleV2.h"//Ver2.0�̉~�N���X
#include "ver2.0/Main/Collision.h"//Ver2.0�̓����蔻�菈��
#include "ver2.0/Main/Camera.h"//Ver2.0��2D�ɂ�����J��������
#include "ver2.0/Graphics/DiploidImageV2.h"//Ver2.0�ɂ�����摜�N���X
#include "ver2.0/Graphics/DiploidBoxV2.h"//Ver2.0�ɂ�����l�p�N���X


//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
#include "data/res_data/player/player.h"
#include "data/res_data/field/ground_line.h"
#include "data/res_data/enemy/enemy_manager.h"
#include "data/res_data/enemy/test_enemy.h"
#include "data/res_data/UI/hp_ui.h"
#include "data/res_data/UI/dp_ui.h"
#include "data/res_data/UI/enemy_destory_ui.h"
#include "data/res_data/UI/hp_recovery_ui.h"
#include "data/res_data/UI/cp_recovery_ui.h"


using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	DiploidEngineInput input;
	DiploidCollision collision;

	EnemyManager enemy_manager;//�G�̊Ǘ�
	_TestEnemy test_enemy;//�G�I�u�W�F�N�g
	EnemyData enemy_data;

	Player player;//�v���C���[
	GroundLine ground_line;//�O���E���h���C��

	HpUI hp_ui;
	DpUI dp_ui;
	EnemyDestoryUI enemy_destory_ui;
	HpRecoveryUI hp_recovery_ui;
	CpRecoveryUI cp_recovery_ui;

	DiploidImageV2 forest;


	DiploidImageV2 test[9];
	Animation anime;

public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void Destory();//�폜���鏈���B
	void End();//engine�I���O�����B
};