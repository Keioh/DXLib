#pragma once

namespace DiploidArchitectureLib
{
	//地域
	enum District
	{
		NoDistricet,//地域指定なし
		TypeOneExclusiveDistrictForLow_riseResidentialBuildings,//第一種低層住居専用地域
		TypeTwoExclusiveDistrictForLow_riseResidentialBuildings,//第二種低層住居専用地域
		TypeOneExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//第一種中高層住居専用地域
		TypeTwoExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//第二種中高層住居専用地域
		TypeOneResidentialDistrict,//第一種住居地域
		TypeTwoResidentialDistrict,//第二種住居地域
		Semi_residentialDistrict,//準住居地域
		RuralResidentialDistrict,//田園住居地域
		NeighborhoodCommercialDistrict,//近隣商業地域
		CommercialDistrict,//商業地域
		Semi_industrialDistricet,//準工業地域
		IndustrialDistricet,//工業地域
		ExclusiveIndustrialDistricet//工業専用地域
	};

	//項、号
	enum Number
	{
		One = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven
	};

	enum BuildingType
	{
		Housing//住宅
	};

	//施行令
	class Order
	{
		//第20条(有効面積の算定方法)
		int No20(int district);//districtには地域を指定(enum District参照) 戻り値は該当する号を返す。
	};
}