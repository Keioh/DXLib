#include "diploidUI/diploidUI.h"

DiploidUI::DiploidUI()
{

}

DiploidUI::~DiploidUI()
{

}

//ワンクリックボタン
void DiploidUI::OneClickButton_Load()
{

}

void DiploidUI::OneClickButton_Init(VECTOR position, VECTOR size, std::string name_tag, int layer_number)
{
	box.Init(position, size);
	box.name_tag = name_tag;
	box.layer_number = layer_number;
}

void DiploidUI::OneClickButton_Push(DiploidEngineImpact& impact)
{
	impact.PushBox(box);
}

bool DiploidUI::OneClickButton_Update(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	box.color = GetColor(150, 150, 150);

	if (impact.GetBoxImpactFlag_Sreach_Name_Tag(box.name_tag) == true)
	{
		box.color = GetColor(180, 180, 180);

		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			box.color = GetColor(200, 200, 200);

			return true;
		}
	}

	return false;
}

void DiploidUI::OneClickButton_Draw()
{
	box.fill = TRUE;
	box.Draw();
}