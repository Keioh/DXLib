#include "diploidUI/DiploidGroupingUI.h"


void DiploidGroupingUI::Update()
{
	if (!selectedUI_list.empty())
	{	
		for (int count = 0; count != selectedUI_list.size(); count++)
		{
			//�J�[�\�����q�b�g���N���b�N����UI���I����ԂȂ�
			if ((selectedUI_list[count].GetHit() == true) && (selectedUI_list[count].GetClick() == true) && (selectedUI_list[count].GetSelectedUI() == 1))
			{
				for (int count_two = 0; count_two != selectedUI_list.size(); count_two++)
				{
					//�J�[�\�����q�b�g���N���b�N����UI���I����ԈȊO��UI�I�u�W�F�N�g���I�����(-1)�ɂ���
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