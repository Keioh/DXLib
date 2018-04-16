//�I�u�W�F�N�g��`�ʂ��鏇�Ԃ����߂邽�߂̃��C���[�V�X�e��

#pragma once
#include <vector>
#include "DxLib.h"
#include "diploidObject\DiploidEngineObject.h"
#include "diploidGraphics\diploidCircle.h"

class DiploidEngineLayer
{
private:
	//���ۃI�u�W�F�N�g�x�N�^�[
	std::vector<DiploidEngineObject> layer_top_object_simple;//��ԏ�̃��C���[�I�u�W�F�N�g(��Ԏ�O)
	std::vector<DiploidEngineObject> layer_mid_object_simple;//�^�񒆂̃��C���[�I�u�W�F�N�g(�^��)
	std::vector<DiploidEngineObject> layer_bot_object_simple;//��ԉ��̃��C���[�I�u�W�F�N�g(��ԉ�)

	//�~�I�u�W�F�N�g�x�N�^�[
	std::vector<DiploidCircle> layer_top_object_circle;//��ԏ�̃��C���[�I�u�W�F�N�g(��Ԏ�O)
	std::vector<DiploidCircle> layer_mid_object_circle;//�^�񒆂̃��C���[�I�u�W�F�N�g(�^��)
	std::vector<DiploidCircle> layer_bot_object_circle;//��ԉ��̃��C���[�I�u�W�F�N�g(��ԉ�)

public:

	void UpdataLayerObject();//�S�Ẵ��C���[���X�V
	void DrawLayerObject();//�S�Ẵ��C���[��`��

	//���ۃI�u�W�F�N�g�v�b�V��
	void PushBackTopObject_simple(DiploidEngineObject object);//TOP���C���[�ɃI�u�W�F�N�g��ǉ�
	void PushBackMidObject_simple(DiploidEngineObject object);//MID���C���[�ɃI�u�W�F�N�g��ǉ�
	void PushBackBotObject_simple(DiploidEngineObject object);//BOT���C���[�ɃI�u�W�F�N�g��ǉ�


	//�~�I�u�W�F�N�g�v�b�V��
	void PushBackTopObject_circle(DiploidCircle object);//TOP���C���[�ɃI�u�W�F�N�g��ǉ�
	void PushBackMidObject_circle(DiploidCircle object);//MID���C���[�ɃI�u�W�F�N�g��ǉ�
	void PushBackBotObject_circle(DiploidCircle object);//BOT���C���[�ɃI�u�W�F�N�g��ǉ�

	//�~�I�u�W�F�N�g�|�b�v
	void PopBackTopObject_circle(int object_number);//TOP���C���[����I�u�W�F�N�g���폜(object_number�͏��������v�f�ւ̃C�e���[�^�[)
	void PopBackMidObject_circle(int object_number);//MID���C���[����I�u�W�F�N�g���폜(object_number�͏��������v�f�ւ̃C�e���[�^�[)
	void PopBackBotObject_circle(int object_number);//BOT���C���[����I�u�W�F�N�g���폜(object_number�͏��������v�f�ւ̃C�e���[�^�[)


	//���ۃI�u�W�F�N�g�̃A�b�v�f�[�g�ƕ`��
	void UpdateLayerObject_simple();//���C���[�ɒǉ������I�u�W�F�N�g���A�b�v�f�[�g
	void DrawLayerObject_simple();//���C���[�ɒǉ������I�u�W�F�N�g��`��

	//�~�I�u�W�F�N�g�̃A�b�v�f�[�g�ƕ`��
	void UpdateLayerObject_circle();//���C���[�ɒǉ������I�u�W�F�N�g���A�b�v�f�[�g
	void DrawLayerObject_circle();//���C���[�ɒǉ������I�u�W�F�N�g��`��
};