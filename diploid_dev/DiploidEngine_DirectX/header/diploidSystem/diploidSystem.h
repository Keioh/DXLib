#pragma once
#include "DxLib.h"
#include "diploidImpact/DiploidEngineImpact.h"

class DiploidSystem
{
private:
	bool push_flag = false;
	bool delete_flag = false;

	bool push_box_flag = false;
	bool delete_box_flag = false;

	bool push_point_flag = false;
	bool delete_point_flag = false;

public:

	//BOX
	void OnePushBOX_Impact(DiploidEngineImpact& impact, DiploidBox box);//���[�v����񂾂��v�b�V������B
	void OneDeleteBOX_Impact(DiploidEngineImpact& impact, std::string name_tag);//���[�v����񂾂��폜����B

	void FlagReset_OnePushBOX();//���ǂݍ��݃t���O�����Z�b�g����B
	void FlagReset_OneDeleteBOX();//���ǂݍ��݃t���O�����Z�b�g����B

	bool GetOnePushBOX_Flag();//OnePushBOX_Impact�̌��݂̃t���O���擾����B
	bool GetOneDeleteBOX_Flag();//OneDeleteBOX_Impact�̌��݂̃t���O���擾����B

	//POINT
	void OnePushPOINT_Impact(DiploidEngineImpact& impact, DiploidPoint point);//���[�v����񂾂��v�b�V������B
	void OneDeletePOINT_Impact(DiploidEngineImpact& impact, std::string name_tag);//���[�v����񂾂��폜����B

	void FlagReset_OnePushPOINT();//���ǂݍ��݃t���O�����Z�b�g����B
	void FlagReset_OneDeletePOINT();//���ǂݍ��݃t���O�����Z�b�g����B

	bool GetOnePushPOINT_Flag();//OnePushBOX_Impact�̌��݂̃t���O���擾����B
	bool GetOneDeletePOINT_Flag();//OneDeleteBOX_Impact�̌��݂̃t���O���擾����B

};