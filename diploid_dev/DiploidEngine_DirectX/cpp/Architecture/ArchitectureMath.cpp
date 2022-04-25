#include "Architecture/ArchitectureMath.h"

//�ʐς̌v�Z
double DiploidArchitectureLib::GenericFunction::Area(double width, double length)//width * length(�������s��)
{
	double ans = 0.0;

	//�ʐς̌v�Z
	ans = width * length;

	return ans;
}


//�̌��֌W�䗦(LightingCorrectionFactor�֐��̎g�p�𐄏�)
double DiploidArchitectureLib::Law28Light::DaylightingRelationRate(double height, double distance)//������distance/height�̒l���v�Z����B
{
	double ans = 0.0;

	//�̌��֌W�䗦
	ans = (distance / height);

	return ans;
}

//�̌��␳�W��
double DiploidArchitectureLib::Law28Light::LightingCorrectionFactor(double height, double distance, bool isRoad, int enforcementOrder)//enforcementOrder=-1�ŏ�����distance/height�̒l���v�Z����BenforcementOrder�ɂ͗߂Q�O���̊Y�����鍆��������ArchitectureLaw����OrderClass��p����BisRoad�͊J���������ɗאڂ��Ă��邩�ǂ����̃t���O(false�ŗאڂ��Ă��Ȃ�)
{
	double ans = 0.0;

	//�̌��֌W�䗦
	if (enforcementOrder == -1)
	{
		ans = (distance / height);
	}

	//��20���1��
	if (enforcementOrder == Number::One)
	{
		//�̌��␳�W��
		ans = ((distance / height) * 6.0) - 1.4;

		//�J���������ɖʂ���ꍇ
		if (isRoad == true)
		{
			//�C
			if (ans < 1.0)
			{
				ans = 1.0;
			}
		}
		else if (isRoad == false)//�J���������ɖʂ��Ȃ��ꍇ
		{
			//��
			if ((height >= 7.0) && (ans < 1.0))
			{
				ans = 1.0;
			}

			//�n
			if ((height < 7.0) && (ans < 0.0))
			{
				ans = 0.0;
			}
		}
	}

	//�̌��␳�W����3.0�𒴂���Ƃ��A3.0�����x�Ƃ���B
	if (ans > 3.0)
	{
		ans = 3.0;
	}

	return ans;
}

//�̌��L���ʐς̌v�Z
double DiploidArchitectureLib::Law28Light::EffectiveArea(double apertureArea, double lightingCorrectionFactor)//apertureArea�ɂ͊J�����̖ʐρBlightingCorrectionFactor�ɂ͍̌��␳�W���B
{
	double ans = 0.0;

	//�L���ʐς̌v�Z
	ans = apertureArea * lightingCorrectionFactor;

	return ans;
}

//�K�v�̌��ʐς̌v�Z
double DiploidArchitectureLib::Law28Light::RequiredLightingArea(double floorSpace, int buildingType)//floorSpace�ɂ͏��ʐρBbuildingType�ɂ͌��z���̎��
{
	double ans = 0.0;

	//�Z��̏ꍇ
	if (buildingType == BuildingType::Housing)
	{
		ans = floorSpace * (1 / 7);
	}

	return ans;
}

//�K�v�ʐςɑ΂��ėL���ʐς�����Ă��邩�̍��۔���
bool DiploidArchitectureLib::Law28Light::Judgment(double requiredLightingArea, double effectiveArea)//requiredLightingArea�ɂ͕K�v�̌��ʐρBeffectiveArea�ɂ͍̌��L���ʐρB���i�Ȃ�true���Ԃ�B
{
	bool judg = false;

	//�L���ʐς��K�v�ʐψȏォ�̔���
	if (requiredLightingArea >= effectiveArea)
	{
		judg = true;
	}
	else
	{
		judg = false;
	}

	return judg;
}