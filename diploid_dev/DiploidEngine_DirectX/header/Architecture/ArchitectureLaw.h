#pragma once

namespace DiploidArchitectureLib
{
	//nζ
	enum District
	{
		NoDistricet,//nζwθΘ΅
		TypeOneExclusiveDistrictForLow_riseResidentialBuildings,//ζκναwZκpnζ
		TypeTwoExclusiveDistrictForLow_riseResidentialBuildings,//ζρναwZκpnζ
		TypeOneExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//ζκνwZκpnζ
		TypeTwoExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//ζρνwZκpnζ
		TypeOneResidentialDistrict,//ζκνZnζ
		TypeTwoResidentialDistrict,//ζρνZnζ
		Semi_residentialDistrict,//Znζ
		RuralResidentialDistrict,//cZnζ
		NeighborhoodCommercialDistrict,//ίΧ€Ζnζ
		CommercialDistrict,//€Ζnζ
		Semi_industrialDistricet,//HΖnζ
		IndustrialDistricet,//HΖnζ
		ExclusiveIndustrialDistricet//HΖκpnζ
	};

	//A
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
		Housing//Zξ
	};

	//{sί
	class Order
	{
		//ζ20π(LψΚΟΜZθϋ@)
		int No20(int district);//districtΙΝnζπwθ(enum DistrictQΖ) ίθlΝY·ιπΤ·B
	};
}