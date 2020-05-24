#include "data/sim_data/military_ui.h"

void MilitaryUI::Load()
{
	//UI”wŒi
	image.Load("texter/sim_texter/military_ui_1.png");


	//‰¤
	king_image.Load("texter/sim_texter/king.png");
	king.Load(king_image.GetGraphicsHandl());

	//ŒöŽÝ
	duke_image.Load("texter/sim_texter/duke.png");
	duke[0].Load(duke_image.GetGraphicsHandl());
	duke[1].Load(duke_image.GetGraphicsHandl());

	//ŒòŽÝ
	marquess_one_image.Load("texter/sim_texter/Marquess.png");
	marquess_one.Load(marquess_one_image.GetGraphicsHandl());
	marquess_two.Load(marquess_one_image.GetGraphicsHandl());

	//ŽqŽÝ
	viscount_one_image.Load("texter/sim_texter/Viscount.png");
	viscount_one.Load(viscount_one_image.GetGraphicsHandl());
	viscount_two.Load(viscount_one_image.GetGraphicsHandl());

	//’jŽÝ
	baron_one_image.Load("texter/sim_texter/Baron.png");
	baron_one.Load(baron_one_image.GetGraphicsHandl());
	baron_two.Load(baron_one_image.GetGraphicsHandl());

}

void MilitaryUI::Init(VECTOR pos, float scale)
{
	//UIŠÖ˜A
	image.Init(pos,false);
	image.SetScale(scale, scale);

	box.Init(pos, VGet(1024, 1024, 0), GetColor(200, 200, 200), scale);


	//‰¤
	king.Init(VGet(pos.x + 32, pos.y + 128, 0.0f), VGet(1024, 256, 0), 0.24f);

	//ŒöŽÝ‚»‚Ì‚P
	duke[0].Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 2), 0.0f), VGet(1024, 128, 0), 0.235f);

	//ŒöŽÝ‚»‚Ì2
	duke[1].Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 3), 0.0f), VGet(1024, 128, 0), 0.235f);


	//ŒòŽÝ‚»‚Ì‚P
	marquess_one.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 4), 0.0f), VGet(1024, 128, 0), 0.235f);

	//ŒòŽÝ‚»‚Ì2
	marquess_two.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 5), 0.0f), VGet(1024, 128, 0), 0.235f);


	//ŽqŽÝ‚»‚Ì‚P
	viscount_one.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 6), 0.0f), VGet(1024, 128, 0), 0.235f);

	//ŽqŽÝ‚»‚Ì2
	viscount_two.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 7), 0.0f), VGet(1024, 128, 0), 0.235f);


	//’jŽÝ‚»‚Ì‚P
	baron_one.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 8), 0.0f), VGet(1024, 128, 0), 0.235f);

	//’jŽÝ‚»‚Ì2
	baron_two.Init(VGet(pos.x + 32, pos.y + 128 + ((128 * 0.24f) * 9), 0.0f), VGet(1024, 128, 0), 0.235f);

}

void MilitaryUI::Updata(DiploidEngineInput* input)
{
	if (collision.BoxAndMouseCollisionUpdate(&box, input->GetMousePosition().x, input->GetMousePosition().y) == true)
	{
		box.SetColor(GetColor(255, 0, 0));
		hit = true;

		king.Updata(input);

		duke[0].Updata(input);
		duke[1].Updata(input);

		marquess_one.Updata(input);
		marquess_two.Updata(input);

		viscount_one.Updata(input);
		viscount_two.Updata(input);

		baron_one.Updata(input);
		baron_two.Updata(input);

	}
	else
	{
		box.SetColor(GetColor(0, 0, 255));
		hit = false;
	}
}

void MilitaryUI::Draw(bool draw, bool debug)
{
	image.Draw(draw);

	king.Draw(draw, debug);

	duke[0].Draw(draw, debug);
	duke[1].Draw(draw, debug);

	marquess_one.Draw(draw, debug);
	marquess_two.Draw(draw, debug);

	viscount_one.Draw(draw, debug);
	viscount_two.Draw(draw, debug);

	baron_one.Draw(draw, debug);
	baron_two.Draw(draw, debug);

	if (debug == true)
	{
		box.Draw(draw);
	}
}


bool MilitaryUI::GetHit()
{
	return hit;
}