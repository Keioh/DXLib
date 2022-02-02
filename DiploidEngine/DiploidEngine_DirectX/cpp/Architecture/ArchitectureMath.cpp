#include "Architecture/ArchitectureMath.h"

double ArchitectureMath::DaylightingRelationRate(double height, double distance)
{
	double ans;

	return ans = ((distance / height) * 6.0f) - 1.4f;
}