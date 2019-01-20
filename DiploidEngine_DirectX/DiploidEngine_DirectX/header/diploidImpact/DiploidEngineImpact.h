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

	//Updata()���g���ď���������ꍇ�͈ȉ��̊֐����g�p���Ȃ��B
	void ImpactCirclePoint();//�~�Ɠ_�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������){�v�o�O�m�F}
	void ImpactCircleCircle();//�~�Ɖ~�̓����蔻�菈��
	void ImpactBoxPoint();//�l�p�Ɠ_�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������)
	void ImpactBoxBox();//�l�p�Ǝl�p�̓����蔻�菈��(��ʊO�̔���͍s��Ȃ���������������)
	void ImpactBoxCircle();//�l�p�Ɖ~�̓����蔻�菈��
	void ImpactCircleLine();//�~�Ɛ����̓����蔻�菈��
	void ImpactPointLine();//�_�Ɛ����̓����蔻�菈��
	void ImpactLineLine();//�����Ɛ����̓����蔻�菈��
	void ImpactLineBox();//�����Ɣ��̓����蔻�菈��

	void Draw(bool wire = true, bool debug = false);//�`��

	void SetBoxAnimation(int number, VECTOR move_speed = { 0,0,0 }, VECTOR move_size = { 0,0,0 });//box�z�񂩂�����box�������ăA�j���[�V�����l��ύX����B(�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetCircleAnimation(int number, VECTOR move_speed = { 0,0,0 }, float move_size = 0.0f);//circle�z�񂩂�����circle�������ăA�j���[�V�����l��ύX����B(�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)
	void SetPointAnimation(int number, VECTOR move_speed = { 0,0,0 });//point�z�񂩂�����point�������ăA�j���[�V�����l��ύX����B(�z��ɒǉ�������ɐ��l��ύX�������ꍇ�Ɏg�p)

	int GetEndBoxNumber();//box�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndCircleNumber();//circle�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndPointNumber();//point�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetEndLineNumber();//line�z��̌��݂̈�ԍŌ�̐����擾�B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)

	int GetMaxBoxNumber();//box�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Abox�ȊO�̃I�u�W�F�N�g�Ɣ�r���Ĉ�ԑ傫������Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxPointNumber();//point�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Apoint�ȊO�̃I�u�W�F�N�g�Ɣ�r���Ĉ�ԑ傫������Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxCircleNumber();//circle�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Acircle�ȊO�̃I�u�W�F�N�g�Ɣ�r���Ĉ�ԑ傫������Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)
	int GetMaxLineNumber();//line�z�����ɁA��ԑ傫���l��Ԃ��B�܂�Aline�ȊO�̃I�u�W�F�N�g�Ɣ�r���Ĉ�ԑ傫������Ԃ��B(�z��ɂȂɂ��Ȃ����-1��Ԃ��B)

	int GetMaxArrayNumber();//box.point.circle.line�z������ꂼ���ׂĈ�ԑ傫���v�f����Ԃ��B
};