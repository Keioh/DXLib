#pragma once
#include <vector>
#include <algorithm>
#include "diploidObject\DiploidEngineObject.h"
#include "system\DiploidEngineMath.h"

#include "diploidGraphics\diploidCircle.h"
#include "diploidGraphics\diploidPoint.h"
#include "diploidGraphics\diploidBox.h"
#include "diploidGraphics\diploidLine.h"

class DiploidEngineImpact
{
private:
	DiploidEngineMath math;

	float circle_byte;
	float point_byte;
	float box_byte;
	float line_byte;

	int circle_size;
	int point_size;
	int box_size;
	int line_size;

public:
	DiploidEngineImpact();//�R���X�g���N�^
	~DiploidEngineImpact();//�f�X�g���N�^

	int screen_size_x = 1280 + 200;
	int screen_size_y = 720 + 200;

	std::vector<DiploidCircle> circle_vector;//�~��ۑ����Ă����z��
	std::vector<DiploidPoint> point_vector;//�_��ۑ����Ă����z��
	std::vector<DiploidBox> box_vector;//�l�p��ۑ����Ă����z��
	std::vector<DiploidLine> line_vector;//������ۑ����Ă����z��

	void GetSize();//�e�z��̑傫�����擾

	void PushCircle(DiploidCircle circle);//�~���~�z��Ƀv�b�V�����܂��B
	void PushPoint(DiploidPoint point);//�_��_�z��Ƀv�b�V�����܂��B
	void PushBox(DiploidBox box);//�l�p���l�p�z��Ƀv�b�V�����܂��B
	void PushLine(DiploidLine line);//����������z��Ƀv�b�V�����܂��B

	void PopBackCircle();//�~����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackPoint();//�_����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackBox();//�l�p����Ԍ��̔z�񂩂�폜���܂��B
	void PopBackLine();//��������Ԍ��̔z�񂩂�폜���܂��B

	void DestoryCircle();//�~���q�b�g���Ă�����~�z�񂩂�폜
	void DestoryPoint();//�_���q�b�g���Ă�����_�z�񂩂�폜
	void DestoryBox();//�l�p���q�b�g���Ă�����l�p�z�񂩂�폜
	void DestoryLine();//�������q�b�g���Ă���������z�񂩂�폜

	void Destory();//�z�񂩂�폜

	void Init();//������

	void Updata();//�Փ˔��菈��

	void AutoNumber();//�I�u�W�F�N�g�ԍ���t����̂��߂�ǂ��Ƃ��̎����I�u�W�F�N�g�ԍ��t�^�����B(�S�ẴI�u�W�F�N�g�͔ԍ����قȂ�悤�ɂȂ�B���[�v�����ɑg�ݍ��ނƓ��삪�d���Ȃ邩��)

	void Draw(bool wire = true, bool debug = false);//�`��

	//Updata()���g���ď���������ꍇ�͈ȉ���Impact~�֐����g�p���Ȃ��B
	void ImpactCirclePoint();//�~�Ɠ_�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������){�v�o�O�m�F}
	void ImpactCircleCircle();//�~�Ɖ~�̓����蔻�菈��
	void ImpactBoxPoint();//�l�p�Ɠ_�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������)
	void ImpactBoxBox();//�l�p�Ǝl�p�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������)
	void ImpactBoxCircle();//�l�p�Ɖ~�̓����蔻�菈��
	void ImpactCircleLine();//�~�Ɛ����̓����蔻�菈��
	void ImpactPointLine();//�_�Ɛ����̓����蔻�菈��
	void ImpactLineLine();//�����Ɛ����̓����蔻�菈��
	void ImpactLineBox();//�����Ɣ��̓����蔻�菈��

	//�A�j���[�V�����l��ύX����֐��B
	//BOX(Position)
	void SetBoxPositionAnimation(int number, VECTOR move_speed = { 0.0f,0.0f,0.0f });//box�z�񂩂�����box�������č��W�A�j���[�V�����l��ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetBoxPositionAnimationX(int number, float move_speed = 0.0f);//box�z�񂩂�����box��������X���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetBoxPositionAnimationY(int number, float move_speed = 0.0f);//box�z�񂩂�����box��������Y���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetBoxPositionAnimationZ(int number, float move_speed = 0.0f);//box�z�񂩂�����box��������Z���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)

	//CIRCLE(Position)
	void SetCirclePositionAnimation(int number, VECTOR move_speed = { 0,0,0 });//circle�z�񂩂�����circle�������č��W�A�j���[�V�����l��ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetCirclePositionAnimationX(int number, float move_speed = 0.0f);//circle�z�񂩂�����circle��������X���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetCirclePositionAnimationY(int number, float move_speed = 0.0f);//circle�z�񂩂�����circle��������Y���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)

	//POINT(Position)
	void SetPointPositionAnimation(int number, VECTOR move_speed = { 0,0,0 });//point�z�񂩂�����point�������č��W�A�j���[�V�����l��ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetPointPositionAnimationX(int number, float move_speed = 0.0f);//point�z�񂩂�����point��������X���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetPointPositionAnimationY(int number, float move_speed = 0.0f);//point�z�񂩂�����point��������Y���W�A�j���[�V�����l������ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)


	void SetBoxSizeAnimation(int number, VECTOR move_size = { 0,0,0 });//box�z�񂩂�����box�������Ċg��A�j���[�V�����l��ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetCircleSizeAnimation(int number, float move_size = 0.0f);//circle�z�񂩂�����circle�������Ċg��A�j���[�V�����l��ύX����B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)

	void SetBoxPositionAdd(int number, VECTOR position = { 0,0,0 });//box�z�񂩂�����box�������Č�������W�Ɏw�萔�l�������𑫂��B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetCirclePositionAdd(int number, VECTOR position = { 0,0,0 });//circle�z�񂩂�����circle�������Č�������W�Ɏw�萔�l�������𑫂��B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetPointPositionAdd(int number, VECTOR position = { 0,0,0 });//point�z�񂩂�����point�������Č�������W�Ɏw�萔�l�������𑫂��B(number�ɂ̓I�u�W�F�N�g�ԍ������邱�ƁB�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)

	VECTOR GetBoxCenterPosition(int number);//box�z�񂩂�����box�������Ă���box�̒��S�_�̍��W�𓾂܂��B
	VECTOR GetCircleCenterPosition(int number);//circle�z�񂩂�����circle�������Ă���circle�̒��S�_�̍��W�𓾂܂��B
	VECTOR GetPointPosition(int number);//point�z�񂩂�����point�������Ă���point�̍��W�𓾂܂��B

	//�e�z��̑傫���𓾂�֐�
	int GetEndBox();//box�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndCircle();//circle�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndPoint();//point�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndLine();//line�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)

	//�ǂꂩ�̔z�����ɑ��̔z��Ƒ傫�����r���đ傫����Ί�̔z��̑傫����Ԃ��B
	int GetMaxBoxNumber();//box�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Abox�ȊO�̃I�u�W�F�N�g�Ɣ�r���đ傫����΍ő吔��Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxPointNumber();//point�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Apoint�ȊO�̃I�u�W�F�N�g�Ɣ�r���đ傫����΍ő吔��Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxCircleNumber();//circle�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Acircle�ȊO�̃I�u�W�F�N�g�Ɣ�r���đ傫����΍ő吔��Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxLineNumber();//line�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Aline�ȊO�̃I�u�W�F�N�g�Ɣ�r���đ傫����΍ő吔��Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)

	int GetMaxArrayNumber();//box.point.circle.line�z������ꂼ���ׂĈ�ԑ傫���v�f����Ԃ��B

	int GetAllArraySize();//�S�Ă̔z��̃T�C�Y�̍��v��Ԃ��B

	//�I�u�W�F�N�g�ԍ��𒲂ׂ�֐��B
	int GetBoxNumber(int target);//box�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B
	int GetPointNumber(int target);//point�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B
	int GetCircleNumber(int target);//circle�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B
	int GetLineNumber(int target);//line�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�ԍ����擾����B

	//�w��̃I�u�W�F�N�g�ԍ���ύX����֐��B(�v����)
	void SetBoxNumber(int target_number, int set_number);//box�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetCircleNumber(int target_number, int set_number);//circle�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetPointNumber(int target_number, int set_number);//point�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetLineNumber(int target_number, int set_number);//line�z��̎w��f�[�^�̃I�u�W�F�N�g�ԍ�(number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)

	void SetNumber(int number);//������

	//���C���[�ԍ��𒲂ׂ�֐��B
	int GetBoxLayerNumber(int target);//box�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B
	int GetPointLayerNumber(int target);//point�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B
	int GetCircleLayerNumber(int target);//circle�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B
	int GetLineLayerNumber(int target);//line�z��̍ŏ����琔���Ă��Ԗڂ̃��C���[�ԍ����擾����B

	//�w��̃��C���[�ԍ���ύX����֐��B(�v����)
	void SetBoxLayerNumber(int target_number, int set_number);//box�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetCircleLayerNumber(int target_number, int set_number);//circle�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetPointLayerNumber(int target_number, int set_number);//point�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)
	void SetLineLayerNumber(int target_number, int set_number);//line�z��̎w��f�[�^�̃��C���[�ԍ�(layer_number�ϐ�)��ύX���܂��B(target_number�ɂ͔z�񓪂��琔���ĉ��Ԗڂ̒l��ς���̂����w��Aset_number�ɂ͎��ۂɕς��l)


	//�I�u�W�F�N�g���Փ˂��Ă��邩���ׂ�֐��B
	int GetBoxImpactFlag(int number);//box�z��̃I�u�W�F�N�g�Փ˃t���O���擾����B(number�ɂ̓I�u�W�F�N�g�ԍ��A0�Ńq�b�g�Ȃ��A�P�Ńq�b�g���Ă���)
	int GetPointImpactFlag(int number);//point�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�Փ˃t���O�擾����B(number�ɂ̓I�u�W�F�N�g�ԍ��A0�Ńq�b�g�Ȃ��A�P�Ńq�b�g���Ă���)
	int GetCircleImpactFlag(int number);//circle�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�Փ˃t���O�擾����B(number�ɂ̓I�u�W�F�N�g�ԍ��A0�Ńq�b�g�Ȃ��A�P�Ńq�b�g���Ă���)
	int GetLineImpactFlag(int number);//line�z��̍ŏ����琔���Ă��Ԗڂ̃I�u�W�F�N�g�Փ˃t���O�擾����B(number�ɂ̓I�u�W�F�N�g�ԍ��A0�Ńq�b�g�Ȃ��A�P�Ńq�b�g���Ă���)

};