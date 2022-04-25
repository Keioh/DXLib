#include "Architecture/ArchitectureLaw.h"

int DiploidArchitectureLib::Order::No20(int district)//districtÇ…ÇÕínàÊÇéwíË(enum DistrictéQè∆)
{
	//ìÒçÄ
	if ((district == TypeOneExclusiveDistrictForLow_riseResidentialBuildings) ||
		(district == TypeTwoExclusiveDistrictForLow_riseResidentialBuildings) ||
		(district == TypeOneExclusiveDistrictForMediumAndHigh_riseResidentialBuildings) ||
		(district == TypeTwoExclusiveDistrictForMediumAndHigh_riseResidentialBuildings) ||
		(district == TypeOneResidentialDistrict) ||
		(district == TypeTwoResidentialDistrict) ||
		(district == Semi_residentialDistrict) ||
		(district == RuralResidentialDistrict))
	{
		return Number::One;
	}

	if ((district == Semi_industrialDistricet) ||
		(district == IndustrialDistricet) ||
		(district == ExclusiveIndustrialDistricet))
	{
		return Number::Two;
	}

	if ((district == NeighborhoodCommercialDistrict) ||
		(district == CommercialDistrict) ||
		(district == NoDistricet))
	{
		return Number::Three;
	}

	return -1;
}