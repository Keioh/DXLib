#include "Architecture/ArchitectureMath.h"

//面積の計算
double DiploidArchitectureLib::GenericFunction::Area(double width, double length)//width * length(幅ｘ奥行き)
{
	double ans = 0.0;

	//面積の計算
	ans = width * length;

	return ans;
}


//採光関係比率(LightingCorrectionFactor関数の使用を推奨)
double DiploidArchitectureLib::Law28Light::DaylightingRelationRate(double height, double distance)//純粋なdistance/heightの値を計算する。
{
	double ans = 0.0;

	//採光関係比率
	ans = (distance / height);

	return ans;
}

//採光補正係数
double DiploidArchitectureLib::Law28Light::LightingCorrectionFactor(double height, double distance, bool isRoad, int enforcementOrder)//enforcementOrder=-1で純粋なdistance/heightの値を計算する。enforcementOrderには令２０条の該当する号もしくはArchitectureLaw内のOrderClassを用いる。isRoadは開口部が道に隣接しているかどうかのフラグ(falseで隣接していない)
{
	double ans = 0.0;

	//採光関係比率
	if (enforcementOrder == -1)
	{
		ans = (distance / height);
	}

	//令20条二項1号
	if (enforcementOrder == Number::One)
	{
		//採光補正係数
		ans = ((distance / height) * 6.0) - 1.4;

		//開口部が道に面する場合
		if (isRoad == true)
		{
			//イ
			if (ans < 1.0)
			{
				ans = 1.0;
			}
		}
		else if (isRoad == false)//開口部が道に面しない場合
		{
			//ロ
			if ((height >= 7.0) && (ans < 1.0))
			{
				ans = 1.0;
			}

			//ハ
			if ((height < 7.0) && (ans < 0.0))
			{
				ans = 0.0;
			}
		}
	}

	//採光補正係数が3.0を超えるとき、3.0を限度とする。
	if (ans > 3.0)
	{
		ans = 3.0;
	}

	return ans;
}

//採光有効面積の計算
double DiploidArchitectureLib::Law28Light::EffectiveArea(double apertureArea, double lightingCorrectionFactor)//apertureAreaには開口部の面積。lightingCorrectionFactorには採光補正係数。
{
	double ans = 0.0;

	//有効面積の計算
	ans = apertureArea * lightingCorrectionFactor;

	return ans;
}

//必要採光面積の計算
double DiploidArchitectureLib::Law28Light::RequiredLightingArea(double floorSpace, int buildingType)//floorSpaceには床面積。buildingTypeには建築物の種類
{
	double ans = 0.0;

	//住宅の場合
	if (buildingType == BuildingType::Housing)
	{
		ans = floorSpace * (1 / 7);
	}

	return ans;
}

//必要面積に対して有効面積が足りているかの合否判定
bool DiploidArchitectureLib::Law28Light::Judgment(double requiredLightingArea, double effectiveArea)//requiredLightingAreaには必要採光面積。effectiveAreaには採光有効面積。合格ならtrueが返る。
{
	bool judg = false;

	//有効面積が必要面積以上かの判定
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