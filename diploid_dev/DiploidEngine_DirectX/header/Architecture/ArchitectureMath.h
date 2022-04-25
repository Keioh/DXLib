#pragma once
#include "Architecture/ArchitectureLaw.h"
#include <math.h>

namespace DiploidArchitectureLib
{
	//�ėp�֐�
	class GenericFunction
	{
		//�ʐς̌v�Z
		double Area(double width, double length);//width * length(�������s��)

	};

	//�@28���̌�
	class Law28Light
	{
	private:


	public:
		//�̌��֌W�䗦�̌v�Z(LightingCorrectionFactor�֐��̎g�p�𐄏�)
		double DaylightingRelationRate(double height, double distance);//������distance/height�̒l���v�Z����B

		//�̌��␳�W���̌v�Z(��20���1���C���n�܂Ŏ���)
		double LightingCorrectionFactor(double height, double distance, bool isRoad = false, int enforcementOrder = -1);//enforcementOrder=-1�ŏ�����distance/height�̒l���v�Z����BenforcementOrder�ɂ͗߂Q�O���̊Y�����鍆��������ArchitectureLaw����OrderClass��p����BisRoad�͊J���������ɗאڂ��Ă��邩�ǂ����̃t���O(false�ŗאڂ��Ă��Ȃ�)

		//�̌��L���ʐς̌v�Z
		double EffectiveArea(double apertureArea, double lightingCorrectionFactor);//apertureArea�ɂ͊J�����̖ʐρBlightingCorrectionFactor�ɂ͍̌��␳�W���B

		//�K�v�̌��ʐς̌v�Z(�Z��݂̂̎���)
		double RequiredLightingArea(double floorSpace, int buildingType = BuildingType::Housing);//floorSpace�ɂ͏��ʐρBbuildingType�ɂ͌��z���̎��

		//�K�v�ʐςɑ΂��ėL���ʐς�����Ă��邩�̍��۔���
		bool Judgment(double requiredLightingArea, double effectiveArea);//requiredLightingArea�ɂ͕K�v�̌��ʐρBeffectiveArea�ɂ͍̌��L���ʐρB���i�Ȃ�true���Ԃ�B
	};
}