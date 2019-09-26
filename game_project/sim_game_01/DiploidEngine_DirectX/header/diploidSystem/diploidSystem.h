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

public:

	void OnePushBegin();
	void OnePushBOX_Impact(DiploidEngineImpact& impact, DiploidBox box);//���[�v����񂾂��v�b�V������B
	void OneDeleteBOX_Impact(DiploidEngineImpact& impact, std::string name_tag);//���[�v����񂾂��폜����B

	void FlagReset_OnePushBOX();//���ǂݍ��݃t���O�����Z�b�g����B
	void FlagReset_OneDeleteBOX();//���ǂݍ��݃t���O�����Z�b�g����B

	bool GetOnePushBOX_Flag();//OnePushBOX_Impact�̌��݂̃t���O���擾����B
	bool GetOneDeleteBOX_Flag();//OneDeleteBOX_Impact�̌��݂̃t���O���擾����B

};