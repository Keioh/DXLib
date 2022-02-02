#pragma once
#include "DxLib.h"
#include <list>
#include <string>
#include <vector>
#include "ver2.0/Objects/DiploidSelectedUIV2.h"
#include "ver2.0/Objects/DiploidSlider.h"


class DiploidSwitchingGroupUI
{
private:
	std::vector<DiploidSelectedUIV2> selectedUI_list;

public:

	void Update();
	void Draw(bool draw = true);

	void Push(DiploidSelectedUIV2 data, std::string name);//name�ɂ̓{�^���̖��O����́B(��:�����I�u�W�F�N�g���ł͓������O�����݂��Ȃ��悤��)

	std::string GetName();//���ݗL���ɂȂ��Ă���{�^���̖��O���擾���܂��B
	DiploidSelectedUIV2 GetObjectInfo();//���ݗL���ɂȂ��Ă���{�^���̏����擾���܂��B

	std::vector<DiploidSelectedUIV2>& VectorPointer();

};