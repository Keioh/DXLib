#include "data/game_data/main_castle.h"

MyCastle::MyCastle()
{

}

void MyCastle::Load()
{
	//JSON�t�@�C���ǂݍ���
	json.file.LoadJSON("json/base_data/castle/my_castle.json");
	
	//JSON�l�̑��
	population = json.file.GetJSON()["population"];
	defense = json.file.GetJSON()["defense"];
	money = json.file.GetJSON()["money"];
	size = json.file.GetJSON()["size"];
}

void MyCastle::Inti(VECTOR position, float radius)
{
	//���_�I���̉~
	ui.OneClickButtonCIRCLE_Init(position, radius + size, "my_castle");
	
	//���_�̔w�i�F
	back_color_circle_object.circle.Init(position, radius + size);
	back_color_circle_object.circle.name_tag = "my_castle_back_color";
	back_color_circle_object.circle.fill = TRUE;
	back_color_circle_object.circle.color = GetColor(200, 200, 200);

	//���_�̖h��
	defense_circle_object.circle.Init(position, radius + size);
	defense_circle_object.circle.color = GetColor(0, 0, 0);
	defense_circle_object.circle.name_tag = "my_castle_defense_wall";
	defense_circle_object.circle.thickness = defense;//JSON�l�����B
	defense_circle_object.circle.center_position_draw_flag = false;
}

void MyCastle::Push(DiploidEngineImpact& impact)
{
	ui.OneClickButtonCIRCLE_Push(impact);//ui�I�u�W�F�N�g�̃v�b�V��
}

void MyCastle::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	if (ui.OneClickButtonCIRCLE_Update(MOUSE_INPUT_RIGHT,impact, input) == true)//���_���E�N���b�N������
	{
		//������������
	}

	back_color_circle_object.circle.Update();//���_�w�i�F�̃A�b�v�f�[�g
	defense_circle_object.circle.Update();//���_�h�ǂ̃A�b�v�f�[�g
}

void MyCastle::Draw(bool wire, bool debug)
{
	back_color_circle_object.circle.Draw();//���_�w�i�F��`��
	defense_circle_object.circle.Draw();//���_�h�ǂ�`��

	//�f�o�b�O�����
	if (debug == true)
	{	
		DrawFormatString(0, 0, GetColor(0, 0, 0), "population = %d", population);
		DrawFormatString(0, 20, GetColor(0, 0, 0), "defense = %d", defense);
		DrawFormatString(0, 40, GetColor(0, 0, 0), "money = %d", money);
		DrawFormatString(0, 60, GetColor(0, 0, 0), "size = %d", size);
		
		ui.OneClickButtonCIRCLE_Draw();
	}
}