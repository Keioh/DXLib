#pragma once
#include "Architecture/ArchitectureLaw.h"
#include <math.h>

namespace DiploidArchitectureLib
{
	//汎用関数
	class GenericFunction
	{
		//面積の計算
		double Area(double width, double length);//width * length(幅ｘ奥行き)

	};

	//法28条採光
	class Law28Light
	{
	private:


	public:
		//採光関係比率の計算(LightingCorrectionFactor関数の使用を推奨)
		double DaylightingRelationRate(double height, double distance);//純粋なdistance/heightの値を計算する。

		//採光補正係数の計算(令20条二項1号イロハまで実装)
		double LightingCorrectionFactor(double height, double distance, bool isRoad = false, int enforcementOrder = -1);//enforcementOrder=-1で純粋なdistance/heightの値を計算する。enforcementOrderには令２０条の該当する号もしくはArchitectureLaw内のOrderClassを用いる。isRoadは開口部が道に隣接しているかどうかのフラグ(falseで隣接していない)

		//採光有効面積の計算
		double EffectiveArea(double apertureArea, double lightingCorrectionFactor);//apertureAreaには開口部の面積。lightingCorrectionFactorには採光補正係数。

		//必要採光面積の計算(住宅のみの実装)
		double RequiredLightingArea(double floorSpace, int buildingType = BuildingType::Housing);//floorSpaceには床面積。buildingTypeには建築物の種類

		//必要面積に対して有効面積が足りているかの合否判定
		bool Judgment(double requiredLightingArea, double effectiveArea);//requiredLightingAreaには必要採光面積。effectiveAreaには採光有効面積。合格ならtrueが返る。
	};
}