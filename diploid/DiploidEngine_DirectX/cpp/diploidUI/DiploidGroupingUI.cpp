#include "diploidUI/DiploidGroupingUI.h"


void DiploidGroupingUI::Update()
{
	if (!selectedUI_list.empty())
	{		
		int count_number = 0;

		for (int count = 0; count != selectedUI_list.size(); count++)
		{
			if ((selectedUI_list[count].GetClick() == true) && (selectedUI_list[count].GetHit() == true))
			{
				select_count[count] = count_number;

				count_number++;
			}

			if (selectedUI_list[count].GetSelectedUI() == 1)
			{
				selectedUI_list[count].SetSelectedUI(1);
			}
			else
			{
				for (int count_two = 0; count_two != selectedUI_list.size(); count_two++)
				{
					if (select_count[count_two] != count_number)
					{
						selectedUI_list[count_two].SetSelectedUI(-1);

					}
				}
			}

			selectedUI_list[count].Updata();
		}

		count_number = 0;
	}
}

void DiploidGroupingUI::Draw(bool draw)
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


void DiploidGroupingUI::Push(DiploidSelectedUIV2 data)
{
	selectedUI_list.push_back(data);
	select_count.push_back(0);
}

std::vector<DiploidSelectedUIV2>& DiploidGroupingUI::VectorPointer()
{
	return selectedUI_list;
}