#include "diploidUI/DiploidSwitchingGroupUI.h"


void DiploidSwitchingGroupUI::Update()
{
	if (!selectedUI_list.empty())
	{	
		for (int count = 0; count != selectedUI_list.size(); count++)
		{
			//カーソルがヒットかつクリックかつUIが選択状態なら
			if ((selectedUI_list[count].GetHit() == true) && (selectedUI_list[count].GetClick() == true) && (selectedUI_list[count].GetSelectedUI() == 1))
			{
				for (int count_two = 0; count_two != selectedUI_list.size(); count_two++)
				{
					//カーソルがヒットかつクリックかつUIが選択状態以外のUIオブジェクトを非選択状態(-1)にする
					if (count_two != count)
					{
						selectedUI_list[count_two].SetSelectedUI(-1);
					}
				}
			}

			selectedUI_list[count].Updata();
		}
	}
}

void DiploidSwitchingGroupUI::Draw(bool draw)
{
	if (draw == true)
	{
		if (!selectedUI_list.empty())
		{
			for (int count = 0; count != selectedUI_list.size(); count++)
			{
				selectedUI_list[count].Draw(true,true);
			}
		}
	}
}

std::string DiploidSwitchingGroupUI::GetName()
{
	if (!selectedUI_list.empty())
	{
		for (int count = 0; count != selectedUI_list.size(); count++)
		{
			if (selectedUI_list[count].GetSelectedUI() == 1)
			{
				return selectedUI_list[count].GetName();
			}
		}
	}
}

DiploidSelectedUIV2 DiploidSwitchingGroupUI::GetObjectInfo()
{
	if (!selectedUI_list.empty())
	{
		for (int count = 0; count != selectedUI_list.size(); count++)
		{
			if (selectedUI_list[count].GetSelectedUI() == 1)
			{
				return selectedUI_list[count];
			}
		}
	}
}


void DiploidSwitchingGroupUI::Push(DiploidSelectedUIV2 data, std::string name)//nameは被らないように
{
	data.SetName(name);

	selectedUI_list.push_back(data);
}

std::vector<DiploidSelectedUIV2>& DiploidSwitchingGroupUI::VectorPointer()
{
	return selectedUI_list;
}