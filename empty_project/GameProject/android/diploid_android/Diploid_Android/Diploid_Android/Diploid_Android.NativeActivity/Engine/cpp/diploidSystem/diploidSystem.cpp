#include "diploidSystem/diploidSystem.h"



void DiploidSystem::OnePushBOX_Impact(DiploidEngineImpact& impact, DiploidBox box)
{
	if (push_box_flag == false)
	{
		impact.PushBox(box);
		push_box_flag = true;
	}
}

void DiploidSystem::OneDeleteBOX_Impact(DiploidEngineImpact& impact, std::string name_tag)
{
	if ((delete_box_flag == false) && (push_box_flag == true))
	{
		impact.DestoryBox_Name_Tag(name_tag);
		delete_box_flag = true;
	}
}


void DiploidSystem::FlagReset_OnePushBOX()
{
	push_box_flag = false;
}

void DiploidSystem::FlagReset_OneDeleteBOX()
{
	delete_box_flag = false;
}


bool DiploidSystem::GetOnePushBOX_Flag()
{
	return push_box_flag;
}

bool DiploidSystem::GetOneDeleteBOX_Flag()
{
	return delete_box_flag;
}



void DiploidSystem::OnePushPOINT_Impact(DiploidEngineImpact& impact, DiploidPoint point)
{
	if (push_point_flag == false)
	{
		impact.PushPoint(point);
		push_point_flag = true;
	}
}

void DiploidSystem::OneDeletePOINT_Impact(DiploidEngineImpact& impact, std::string name_tag)
{
	if ((delete_point_flag == false) && (push_point_flag == true))
	{
		impact.DestoryPoint_Name_Tag(name_tag);
		delete_point_flag = true;
	}
}


void DiploidSystem::FlagReset_OnePushPOINT()
{
	push_point_flag = false;
}

void DiploidSystem::FlagReset_OneDeletePOINT()
{
	delete_point_flag = false;
}


bool DiploidSystem::GetOnePushPOINT_Flag()
{
	return push_point_flag;
}

bool DiploidSystem::GetOneDeletePOINT_Flag()
{
	return delete_box_flag;
}