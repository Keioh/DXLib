#pragma once

namespace DiploidArchitectureLib
{
	//�n��
	enum District
	{
		NoDistricet,//�n��w��Ȃ�
		TypeOneExclusiveDistrictForLow_riseResidentialBuildings,//�����w�Z����p�n��
		TypeTwoExclusiveDistrictForLow_riseResidentialBuildings,//�����w�Z����p�n��
		TypeOneExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//���풆���w�Z����p�n��
		TypeTwoExclusiveDistrictForMediumAndHigh_riseResidentialBuildings,//���풆���w�Z����p�n��
		TypeOneResidentialDistrict,//����Z���n��
		TypeTwoResidentialDistrict,//����Z���n��
		Semi_residentialDistrict,//���Z���n��
		RuralResidentialDistrict,//�c���Z���n��
		NeighborhoodCommercialDistrict,//�ߗ׏��ƒn��
		CommercialDistrict,//���ƒn��
		Semi_industrialDistricet,//���H�ƒn��
		IndustrialDistricet,//�H�ƒn��
		ExclusiveIndustrialDistricet//�H�Ɛ�p�n��
	};

	//���A��
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
		Housing//�Z��
	};

	//�{�s��
	class Order
	{
		//��20��(�L���ʐς̎Z����@)
		int No20(int district);//district�ɂ͒n����w��(enum District�Q��) �߂�l�͊Y�����鍆��Ԃ��B
	};
}