//�����ł��B
#pragma once
#include <vector>
#include "DxLib.h"//Dxlib�{��
#include "diploidApp\DiploidEngineMain.h"//�S������(�K���Ă�)
#include "diploidObject\DiploidEngineObject.h"//�~��l�p��摜�≹�ȂǁA�I�u�W�F�N�g�S��
#include "system\DiploidEngineMath.h"//���w���֘A(DxLib��������C++�W���������͂��̑��̐��w���C�u�����̎g�p�𐄏�)
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"

//�X�^���h�A���[���֘A
#include "diploidStandalone\standalone.h"//������

//�Q�[���f�[�^�֘A
#include "data/number.h"


class DiploidEngineApp : public DiploidEngineMain
{
private:
	//UI
	DiploidSystem kaitaku_system;//�J�񃏃��V���b�g���[�h
	DiploidSystem nougyou_system;//�_�Ƌ惏���V���b�g���[�h
	DiploidSystem syougyou_system;//���Ƌ惏���V���b�g���[�h
	DiploidSystem sangyou_system;//�Y�Ƌ惏���V���b�g���[�h
	DiploidSystem zikkou_system;//���s�����V���b�g���[�h
	DiploidSystem sarati_system;//�X�n�����V���b�g���[�h
	VECTOR ku_position;//UI�̃|�W�V����
	DiploidUI nougyou;//�_�Ƌ�{�^��
	DiploidUI sangyou;//�Y�Ƌ�{�^��
	DiploidUI syougyou;//���Ƌ�{�^��
	DiploidUI sarati;//�X�n�{�^��
	DiploidUI kaitaku;//�J��{�^��
	DiploidUI zikkou;//���s�{�^��
	DiploidUI play;//�v���C�{�^��
	bool nougyou_sangyou_syougou_flags;//�_�Ƌ�ƎY�Ƌ�Ə��Ƌ�̃{�^���̃t���O��ۑ��B(�S��0�Ȃ�0��Ԃ��āA�ǂꂩ��ł�1�������1��Ԃ�)
	int play_type;//�Q�[�����x�̃t���O

	//�t�B�[���h
	VECTOR field_position;//���̃|�W�V����
	DiploidUI field[9];//���
	bool field_all_flag;//���̑I���t���O��ۑ�(�S��0�Ȃ�0��Ԃ��āA�ǂꂩ��ł�1�������1��Ԃ�)
	int field_type[9];//���̃^�C�v(����Ȃ̂��Y��Ȃ̂��_��Ȃ̂�)

	DiploidObject mouse_point;//�}�E�X�|�C���g�p


public:
	void FileCreate();//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
	void Load();//�Q�[���N�����Ƀ��[�h����f�[�^
	void Init();//�ŏ��Ɉ�񂾂��������������������L�q�B	
	void LoadUpdata();//���[�v���Ɉ�x�����f�[�^�����[�h�������������L�q�B(��)
	void Updata();//�A�j���[�V�����ȂǘA�����čs�����������B
	void Draw();//���ʂ�`�ʂ��鏈��
	void End();//engine�I���O�����B
};