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
	if (delete_box_flag == false)
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