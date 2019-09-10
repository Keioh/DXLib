#include "diploidUI/diploidUI.h"

DiploidUI::DiploidUI()
{

}

DiploidUI::~DiploidUI()
{

}

//ワンクリックボタン
void DiploidUI::OneClickButtonBOX_Load()
{

}

void DiploidUI::OneClickButtonBOX_Init(VECTOR position, VECTOR size, std::string name_tag, int layer_number)
{
	box.Init(position, size);
	box.name_tag = name_tag;
	box.layer_number = layer_number;
}

void DiploidUI::OneClickButtonBOX_Push(DiploidEngineImpact& impact)
{
	impact.PushBox(box);
}

bool DiploidUI::OneClickButtonBOX_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	box.color = GetColor(150, 150, 150);

	if (impact.GetBoxImpactFlag_Sreach_Name_Tag(box.name_tag) == true)
	{
		box.color = GetColor(180, 180, 180);

		if (input.GetPressMouse(mouse_input_button_type) == true)
		{
			box.color = GetColor(200, 200, 200);

			return true;
		}
	}

	return false;
}

void DiploidUI::OneClickButtonBOX_Draw()
{
	box.fill = TRUE;
	box.Draw();
}


//ワンクリックボタン(押してすぐに元に戻るボタン)
void DiploidUI::OneClickButtonCIRCLE_Init(VECTOR position, float radius, std::string name_tag, int layer_number)
{
	circle.Init(position, radius);
	circle.name_tag = name_tag;
	circle.layer_number = layer_number;
}

void DiploidUI::OneClickButtonCIRCLE_Push(DiploidEngineImpact& impact)
{
	impact.PushCircle(circle);
}

void DiploidUI::OneClickButtonCIRCLE_Load()
{
}

bool DiploidUI::OneClickButtonCIRCLE_Update(int mouse_input_button_type, DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	input.Update();
	circle.color = GetColor(150, 150, 150);

	if (impact.GetCircleImpactFlag_Sreach_Name_Tag(circle.name_tag) == true)
	{
		circle.color = GetColor(180, 180, 180);

		if (input.GetPressMouse(mouse_input_button_type) == true)
		{
			circle.color = GetColor(200, 200, 200);

			return true;
		}
	}

	return false;
}

void DiploidUI::OneClickButtonCIRCLE_Draw()
{
	circle.fill = TRUE;
	circle.Draw();
}