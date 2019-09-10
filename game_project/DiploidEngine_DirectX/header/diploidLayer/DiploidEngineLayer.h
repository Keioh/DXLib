//�I�u�W�F�N�g��`�ʂ��鏇�Ԃ����߂邽�߂̃��C���[�V�X�e��

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidGraphics\diploidImage.h"

class DiploidEngineLayer
{
private:
	float top_byte;
	float mid_byte;
	float bot_byte;
	int top_size;
	int mid_size;
	int bot_size;

public:
	std::vector<DiploidImage> image_top_vector;
	std::vector<DiploidImage> image_mid_vector;
	std::vector<DiploidImage> image_bot_vector;

	void GetSize();//�e�z��̑傫�����擾

	void PushTopGraphics(DiploidImage image);
	void PushMidGraphics(DiploidImage image);
	void PushBotGraphics(DiploidImage image);

	void Updata();
	void Draw(bool debug = false, bool draw = true);
	void Destory();//destory�ϐ���ture�̏ꍇ�A�v�f���폜

	void DestoryTop();//top�z�񂩂�v�f���폜
	void DestoryMid();//mid�z�񂩂�v�f���폜
	void DestoryBot();//bot�z�񂩂�v�f���폜


	//�A�j���[�V�����l��ύX����֐��B
	//TOP(Position)
	void SetTOPAnimationPosition(int number, VECTOR move_speed = { 0.0f,0.0f,0.0f });//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̍��W�A�j���[�V�����l��ύX����B
	void SetTOPAnimationPositionX(int number, float move_speed = 0.0f);//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜��X���W�A�j���[�V�����l��ύX����B
	void SetTOPAnimationPositionY(int number, float move_speed = 0.0f);//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜��Y���W�A�j���[�V�����l��ύX����B

	void SetTOPPositionYAdd(int number, float move_speed = 0.0f);//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜��Y���W�ɒl�������B

	void SetTOPPosition(int number, VECTOR position = {0.0f,0.0f,0.0f});//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̍��W���Z�b�g����B


	void SetMIDAnimationPosition(int number, VECTOR move_speed = { 0,0,0 });//mid�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̍��W�A�j���[�V�����l��ύX����B
	void SetBOTAnimationPosition(int number, VECTOR move_speed = { 0,0,0 });//bot�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̍��W�A�j���[�V�����l��ύX����B

	void SetTOPAnimationAngle(int number, float angle = 0.0f);//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̉�]�A�j���[�V�����l��ύX����B
	void SetMIDAnimationAngle(int number, float angle = 0.0f);//mid�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̉�]�A�j���[�V�����l��ύX����B
	void SetBOTAnimationAngle(int number, float angle = 0.0f);//bot�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̉�]�A�j���[�V�����l��ύX����B

	void SetTOPAnimationSize(int number, VECTOR size = { 0,0,0 });//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̑傫���A�j���[�V�����l��ύX����B
	void SetMIDAnimationSize(int number, VECTOR size = { 0,0,0 });//mid�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̑傫���A�j���[�V�����l��ύX����B
	void SetBOTAnimationSize(int number, VECTOR size = { 0,0,0 });//bot�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̑傫���A�j���[�V�����l��ύX����B

	void SetTOPAnimationScale(int number, float scale = 0.0f);//top�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̊g��k���A�j���[�V�����l��ύX����B(�g�p�񐄏��B�T�C�Y�ύX����ꍇ�͏�L��Size()�֐����g������)
	void SetMIDAnimationScale(int number, float scale = 0.0f);//mid�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̊g��k���A�j���[�V�����l��ύX����B(�g�p�񐄏��B�T�C�Y�ύX����ꍇ�͏�L��Size()�֐����g������)
	void SetBOTAnimationScale(int number, float scale = 0.0f);//bot�z��̎w��̃I�u�W�F�N�g�ԍ��̉摜�̊g��k���A�j���[�V�����l��ύX����B(�g�p�񐄏��B�T�C�Y�ύX����ꍇ�͏�L��Size()�֐����g������)


	//�I�u�W�F�N�g�ԍ��𒲂ׂ�֐��B
	int GetTOPNumber(int target);//top�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B
	int GetMIDNumber(int target);//mid�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B
	int GetBOTNumber(int target);//bot�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B

	//�w��̃I�u�W�F�N�g�ԍ���ύX����֐��B(�v����)
	void SetTOPNumber(int target_number, int set_number);//top�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetMIDNumber(int target_number, int set_number);//mid�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetBOTNumber(int target_number, int set_number);//bot�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)


	//���C���[�ԍ��𒲂ׂ�֐��B
	int GetTOPLayerNumber(int target);//top�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B
	int GetMIDLayerNumber(int target);//mid�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B
	int GetBOTLayerNumber(int target);//bot�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B

	//�w��̃��C���[�ԍ���ύX����֐��B(�v����)
	void SetTOPLayerNumber(int target_number, int set_number);//top�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetMIDLayerNumber(int target_number, int set_number);//mid�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetBOTLayerNumber(int target_number, int set_number);//bot�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)

};