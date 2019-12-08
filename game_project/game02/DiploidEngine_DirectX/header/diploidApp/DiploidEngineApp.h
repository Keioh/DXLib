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
	//����
	int sakumotu = 50;//�앨
	int sikinn = 1000;//����
	int sannsyutu = 10;//�Y�o
	int jinkou = 10;//�l��

	float sakumotu_scale[9];//�앨���n�̔{��
	float sikinn_scale[9];//�������W�̔{��
	float sannsyutu_scale[9];//�Y�o�̔{��
	float all_basic_scale = 0.025f;//�i�K���Ƃ̔{���ݒ�
	float zeiritu_scale = 0.0f;//�ŗ�

	int sakumotu_syuunyuu;//�앨�̎������
	int sikin_syuunyuu;//�����̎������
	int sannsyutu_syuunyuu;//�Y�o�̎������
	int jinkou_zouka;//�l�������ʂ̏��
	int sakumotu_syouhi;//�앨�̏�����

	DiploidObject status;//�X�e�[�^�X�摜
	DiploidObject status_down;//�X�e�[�^�X�����̉摜

	int fps_time;//�t���[�����[�g�̎���(60fps)
	int second;//�b
	int minute;//��
	int hour;//��
	int day;//��

	bool second_flag;//��b�i�񂾂�true�ɂȂ�
	bool minute_flag;//�ꕪ�i�񂾂�true�ɂȂ�
	bool hour_flag;//�ꎞ�i�񂾂�true�ɂȂ�
	bool day_flag;//����i�񂾂�true�ɂȂ�

	//UI
	VECTOR ku_position;//UI�̃|�W�V����
	DiploidSystem kaitaku_system;//�J�񃏃��V���b�g���[�h
	DiploidSystem nougyou_system;//�_�Ƌ惏���V���b�g���[�h
	DiploidSystem syougyou_system;//���Ƌ惏���V���b�g���[�h
	DiploidSystem sangyou_system;//�Y�Ƌ惏���V���b�g���[�h
	DiploidSystem zikkou_system;//���s�����V���b�g���[�h
	DiploidSystem sarati_system;//�X�n�����V���b�g���[�h
	DiploidSystem siren_system;//���������V���b�g���[�h
	DiploidSystem seisaku_system;//���􃏃��V���b�g���[�h
	DiploidSystem zeiritu_system;//�ŗ������V���b�g���[�h
	DiploidSystem per_0_system;//0%�����V���b�g���[�h
	DiploidSystem per_5_system;//5%�����V���b�g���[�h
	DiploidSystem per_10_system;//10%�����V���b�g���[�h
	DiploidSystem per_15_system;//15%�����V���b�g���[�h
	DiploidSystem per_20_system;//20%�����V���b�g���[�h
	DiploidUI nougyou;//�_�Ƌ�{�^��
	DiploidUI sangyou;//�Y�Ƌ�{�^��
	DiploidUI syougyou;//���Ƌ�{�^��
	DiploidUI sarati;//�X�n�{�^��
	DiploidUI kaitaku;//�J��{�^��
	DiploidUI zikkou;//���s�{�^��
	DiploidUI siren;//�����{�^��
	DiploidUI seisaku;//����{�^��
	DiploidUI zeiritu;//�ŗ��{�^��
	DiploidUI per_0;//0%�{�^��
	DiploidUI per_5;//5%�{�^��
	DiploidUI per_10;//10%�{�^��
	DiploidUI per_15;//15%�{�^��
	DiploidUI per_20;//20%�{�^��
	DiploidUI play;//�v���C�{�^��
	bool nougyou_sangyou_syougou_flags;//�_�Ƌ�ƎY�Ƌ�Ə��Ƌ�̃{�^���̃t���O��ۑ��B(�S��0�Ȃ�0��Ԃ��āA�ǂꂩ��ł�1�������1��Ԃ�)
	int play_type;//�Q�[�����x�̃t���O

	DiploidObject kaitaku_nouku[9];//�_����J�񒆂̉摜
	DiploidObject kaitaku_syouku[9];//������J�񒆂̉摜
	DiploidObject kaitaku_sanku[9];//�Y����J�񒆂̉摜
	DiploidObject kaitaku_sarati[9];//�X�n���J�񒆂̉摜
	DiploidObject double_1_025[9];//1.025�{�̉摜
	DiploidObject double_1_05[9];//1.05�{�̉摜
	DiploidObject nouku_setumei;//�_��̐����摜
	DiploidObject syouku_setumei;//����̐����摜
	DiploidObject sanku_setumei;//�Y��̐����摜
	DiploidObject kaitaku_setumei;//�J��̐����摜
	DiploidObject sarati_setumei;//�X�n�̐����摜
	DiploidObject play_setumei;//�v���C�{�^���̐����摜

	//�t�B�[���h
	VECTOR field_position;//���̃|�W�V����
	DiploidUI field[9];//���
	bool field_all_flag;//���̑I���t���O��ۑ�(�S��0�Ȃ�0��Ԃ��āA�ǂꂩ��ł�1�������1��Ԃ�)
	int field_type[9];//���̃^�C�v(����Ȃ̂��Y��Ȃ̂��_��Ȃ̂�)
	int kaitaku_time[9];//�J�񎞊�
	int kaitaku_type[9];//�J��̃^�C�v�i����Ȃ̂��Y��Ȃ̂��_��Ȃ̂��j

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