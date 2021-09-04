#include "ver2.0/Objects/GameScene.h"

void GameScene::OnceLoad()
{
	jp.OnceLoad();
}

void GameScene::Load()
{
	jp.Create();

	string_back_wall.Load("texter/novel/basic/string_back_wall.png");
	data_back_wall.Load("texter/novel/basic/data_ui.png");
	data_test.Load("texter/novel/date/test.png");
	place_test.Load("texter/novel/place/test.png");

	novel_scene.Load("texter/novel/abandoned_road.png", "abandoned_road");
	novel_scene.Load("texter/novel/00.png", "1");
	novel_scene.Load("texter/novel/02.png", "2");

	end_anime.Load("texter/novel/icon/64_64/0.png");
	end_anime.Load("texter/novel/icon/64_64/1.png");
	end_anime.Load("texter/novel/icon/64_64/2.png");
	end_anime.Load("texter/novel/icon/64_64/3.png");


	auto_button.Load();
	skip_button.Load();
	option_button.Load();
	load_button.Load();
	save_button.Load();
	quick_load_button.Load();
	quick_save_button.Load();

	prologue.Load();
}

void GameScene::Init(DiploidEngineSetting& setting)
{
	prologue.Init(setting, VGet(0, 0, 0));

	system_data = setting.GetSystemData();

	jp.StringInit(setting);
	jp.NameInit(setting);
	jp.SetSpeed(system_data.string_draw_speed);

	auto_button.Init(VGet(setting.GetSystemData().window_x - 64, setting.GetSystemData().window_y - 16, 0));
	auto_button.SetSpeed(60);
	skip_button.Init(VGet(setting.GetSystemData().window_x - (64 * 2), setting.GetSystemData().window_y - 16, 0));
	option_button.Init(VGet(setting.GetSystemData().window_x - (64 * 3), setting.GetSystemData().window_y - 16, 0));
	load_button.Init(VGet(setting.GetSystemData().window_x - (64 * 4), setting.GetSystemData().window_y - 16, 0));
	save_button.Init(VGet(setting.GetSystemData().window_x - (64 * 5), setting.GetSystemData().window_y - 16, 0));
	quick_load_button.Init(VGet(setting.GetSystemData().window_x - (64 * 6), setting.GetSystemData().window_y - 16, 0));
	quick_save_button.Init(VGet(setting.GetSystemData().window_x - (64 * 7), setting.GetSystemData().window_y - 16, 0));

	novel_scene.Init(setting, VGet(0, 0, 0));

	string_back_wall.Init(VGet(0, 0, 0));
	string_back_wall.SetScale(setting.GetSystemData().window_x / string_back_wall.GetSize().x, setting.GetSystemData().window_y / string_back_wall.GetSize().y);

	data_back_wall.Init(VGet(0, 0, 0));
	data_test.Init(VGet(0, 0, 0));
	place_test.Init(VGet(0, 0, 0));

	box.Init(VGet(0, 0, 0), VGet(setting.GetSystemData().window_x, setting.GetSystemData().window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	end_anime.Init(VGet(setting.GetSystemData().window_x - 50, setting.GetSystemData().window_y - 64, 0), 4, 0.5f, 0.5f);
}

void GameScene::Updata(DiploidEngineInput& input, DiploidEngineScreen& screen)
{
	//�`�摬�x��ݒ肵�Ȃ����B
	if (jp.string[click].GetDrawSpeed() != (system_data.string_draw_speed * 50))
	{
		jp.string[click].SetSpeed(system_data.string_draw_speed * 50);
		jp.name[click].SetSpeed(system_data.string_draw_speed * 50);
	}

	//�I�[�g���x��ݒ肵�Ȃ����B
	if (auto_button.GetAutoSpeed() != (system_data.string_auto_speed * 0.8f))
	{
		auto_button.SetSpeed(system_data.string_auto_speed * 0.8f);
	}

	//������̔w�i�摜�̓��ߓx��ݒ肵�Ȃ����B
	if (string_back_wall.GetAplha() != system_data.string_background_alpha)
	{
		string_back_wall.SetAlpha(system_data.string_background_alpha);
	}

	//��������Ō�܂œǂݐ؂������ɂł�Ñ��A�j���[�V����
	end_anime.SetAnimationSpeed(250 * screen.GetFrameTime());

	//�I�v�V�����@�\�̍X�V
	option_button.Update(input);

	//���[�h�@�\�̍X�V
	load_button.Update(input);

	//�Z�[�u�@�\�̍X�V
	save_button.Update(input);

	//�N�C�b�N���[�h�@�\�̍X�V
	quick_load_button.Update(input);

	//�N�C�b�N�Z�[�u�@�\�̍X�V
	quick_save_button.Update(input);

	//�t�F�[�h�A�E�g�������Ă�����
	if (box_draw_flag == 1)
	{
		//�v�����[�O�̕\��̕\�����I�����Ă�����
		if (prologue.GetFinish() == true)
		{
			//�I�[�g�@�\�̍X�V
			auto_button.Update(input, jp.string[click].GetEnd(), screen.GetFrameTime());

			//�X�L�b�v�@�\�̍X�V
			skip_button.Update(input, screen.GetFrameTime());


			//�I�[�g�@�\�̐i��flag��true��������
			if (auto_button.GetNextFlag() == true)
			{
				if ((jp.size() - 1) != click)
				{
					jp.string[click].SetCompleteFlag(true);//���Ǎς�flag�𗧂Ă�
					click++;//���̕�
				}
			}

			//���Ǎς�flag��������
			if (jp.string[click].GetCompleteFlag() == true)
			{
				//�X�L�b�v�@�\��flag��0��������(�I����ԂȂ�)
				if (skip_button.GetNextFlag() == 0)
				{
					jp.string[click].AllIn();//�Ō�̕����܂ŕ\��
					novel_scene.AlphaMax();//�w�i�����S�\��			
				}
				else if (skip_button.GetNextFlag() == 1)//�X�L�b�v�@�\��flag��1��������
				{
					if ((jp.size() - 1) != click)
					{
						//jp.string[click].SetCompleteFlag(true);//���Ǎς�flag�𗧂Ă�
						click++;//���̕�
					}
				}
			}

			//�X�L�b�v�{�^���ɃJ�[�\�����N���b�N����A���I����ԂȂ�
			if (skip_button.GetClick() == true)
			{
				if (skip_button.GetSelected() == 1)
				{
					auto_button.SetSelected(-1);//�I�[�g�{�^���̑I����Ԃ�����
				}
			}

			//�I�[�g�{�^���ɃJ�[�\�����N���b�N����A���I����ԂȂ�
			if (auto_button.GetClick() == true)
			{
				if (auto_button.GetSelected() == 1)
				{
					skip_button.SetSelected(-1);//�X�L�b�v�{�^���̑I����Ԃ�����
				}
			}

			//�I�v�V�����{�^���ɃJ�[�\�������킳���Ă��ăN���b�N���ꂽ�Ȃ�
			if ((option_button.GetHit() == true) && (option_button.GetClick() == true))
			{
				option_button.SetSelected(1);//�I�v�V�����{�^���̑I����Ԃ��ێ�
				box_draw_flag = 2;//�t�F�[�h�A�E�g�t���O�𗧂Ă�
			}

			//���[�h�{�^���ɃJ�[�\�������킳���Ă��ăN���b�N���ꂽ�Ȃ�
			if ((load_button.GetHit() == true) && (load_button.GetClick() == true))
			{
				is_save_or_load = GAME_LOAD;//���[�h��ʂ֍s���t���O�𗧂Ă�
				load_button.SetSelected(1);//�I�v�V�����{�^���̑I����Ԃ��ێ�
				box_draw_flag = 2;//�t�F�[�h�A�E�g�t���O�𗧂Ă�
			}

			//�Z�[�u�{�^���ɃJ�[�\�������킳���Ă��ăN���b�N���ꂽ�Ȃ�
			if ((save_button.GetHit() == true) && (save_button.GetClick() == true))
			{
				is_save_or_load = GAME_SAVE;//�Z�[�u��ʂ֍s���t���O�𗧂Ă�
				save_button.SetSelected(1);//�I�v�V�����{�^���̑I����Ԃ��ێ�
				box_draw_flag = 2;//�t�F�[�h�A�E�g�t���O�𗧂Ă�
			}


			//�S�Ă�UI����J�[�\��������Ă���Ƃ�
			if ((auto_button.GetHit() == false) && (skip_button.GetHit() == false) && (option_button.GetHit() == false)
				&& (load_button.GetHit() == false) && (save_button.GetHit() == false) && (quick_load_button.GetHit() == false) && (quick_save_button.GetHit() == false))
			{
				//���N���b�N�����Ƃ�
				if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
				{
					//�X�L�b�v���I���Ȃ�I�t�ɂ���B
					if (skip_button.GetSelected() == 1)
					{
						skip_button.SetSelected(-1);
					}
					else//�X�L�b�v���I�t�Ȃ�
					{
						if (jp.string[click].GetEnd() == 0)//�Ō�܂ŕ\������Ă��Ȃ�������
						{
							jp.string[click].AllIn();//�Ō�̕����܂ŕ\��
							novel_scene.AlphaMax();//�w�i�����S�\��
						}
						else
						{
							if ((jp.size() - 1) != click)
							{
								jp.string[click].SetCompleteFlag(true);//���Ǎς�flag�𗧂Ă�
								click++;//���̕���\��
							}
						}
					}
				}
			}

		}
	}

	if (prologue.GetFinish() == false)
	{
		//�v�����[�O�\��̍X�V
		prologue.Updata(screen);

		if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
		{
			prologue.NextAnimation();
		}
	}

	//��ʂ̐؂�ւ�
	novel_scene.SetDrawName(jp.string[click].GetSceneName());

	novel_scene.Update(screen);//��ʐ؂�ւ��̃A�b�v�f�[�g

	//�V�[�����n�܂�����
	if (box_draw_flag == 0)//�t�F�[�h�A�E�g�n��
	{
		alpha -= alpha_speed * screen.GetFrameTime();//���ߒl��ύX

		if (alpha <= 0)//���ߒl�t���[����
		{
			alpha = 0;
			box_draw_flag = 1;//�t�F�[�h�A�E�g����
		}
	}

	if (box_draw_flag == 2)//�t�F�[�h�C���n��
	{
		alpha += alpha_speed * screen.GetFrameTime();//���ߒl��ύX

		if (alpha > 255)//���ߒl�t���[����
		{
			alpha = 255;
			box_draw_flag = 3;//�t�F�[�h�C������
		}
	}
}

void GameScene::Draw(DiploidEngineScreen& screen)
{
	//data_back_wall.Draw();
	//data_test.Draw();
	//place_test.Draw();

	//screen_graphics.Draw(0.1f);

			//�w�i�̕`��
	novel_scene.Draw();

	//�t�F�[�h�A�E�g������������(���v�����[�O�̕\�肪�������Ă�����)
	if (box_draw_flag == 1)
	{
		if (prologue.GetFinish() == true)
		{
			//�����\���̔w�i�̕`��
			string_back_wall.Draw();

			//������(�L�����̖��O)�̕`��
			jp.name[click].Draw(screen.GetFrameTime());

			//������(��b��)�̕`��
			jp.string[click].Draw(screen.GetFrameTime());

			//�����Ō�܂ŕ`�悳��Ă�����
			if (jp.string[click].GetEnd() == 1)
			{
				end_anime.StackDraw();//�����A�C�R���̃A�j����`��
			}
			else
			{
				end_anime.Reset();//�����A�C�R���̃A�j�����ŏ�����ɐݒ�
			}

			//�I�[�g�{�^���̕`��
			auto_button.Draw(screen.GetFrameTime());

			//�X�L�b�v�{�^���̕`��
			skip_button.Draw(screen.GetFrameTime());

			//�I�v�V�����{�^���̕`��
			option_button.Draw(screen.GetFrameTime());

			//���[�h�{�^���̕`��
			load_button.Draw(screen.GetFrameTime());

			//�Z�[�u�{�^���̕`��
			save_button.Draw(screen.GetFrameTime());

			//�N�C�b�N���[�h�{�^���̕`��
			quick_load_button.Draw(screen.GetFrameTime());

			//�N�C�b�N�Z�[�u�{�^���̕`��
			quick_save_button.Draw(screen.GetFrameTime());
		}
	}

	if (prologue.GetFinish() == false)
	{
			//�v�����[�O�̕\�����������Ă��Ȃ��Ȃ�
			prologue.Draw();//�\��	
	}



	//�t�F�[�h�A�E�g�pBOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


	//DrawFormatString(0, 0, GetColor(255, 255, 255), "language = %s", system_data.language.c_str());
}

void GameScene::Reset()
{
	//�e�{�^���̃p�����[�^�[�Ə�Ԃ����Z�b�g����
	auto_button.Reset();
	skip_button.Reset();
	option_button.Reset();
	load_button.Reset();
	save_button.Reset();
	quick_load_button.Reset();
	quick_save_button.Reset();

	//���[�h���Z�[�u���̃t���O�����Z�b�g
	is_save_or_load = GAME_LOAD;

	//������f�[�^���ŏ�����ɂ���
	click = 0;
	jp.Reset();

	//�v�����[�O�̃O���t�B�b�N�����Z�b�g
	prologue.Reset();
}


void GameScene::SetInGameFlag(bool new_flag)
{
	in_game = new_flag;
}

bool GameScene::GetInGameFlag()
{
	return in_game;
}


void GameScene::SetOptionButtonFlag(int new_flag)
{
	option_button.SetSelected(new_flag);
}

bool GameScene::GetOptionButtonFlag()
{
	if ((option_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		option_button.SetSelected(-1);//�I����Ԃ�����
		return true;
	}
	else
	{
		return false;
	}
}


void GameScene::SetLoadButtonFlag(int new_flag)
{
	load_button.SetSelected(new_flag);
}

bool GameScene::GetLoadButtonFlag()
{
	if ((load_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		load_button.SetSelected(-1);//�I����Ԃ�����
		return true;
	}
	else
	{
		return false;
	}
}


void GameScene::SetSaveButtonFlag(int new_flag)
{
	save_button.SetSelected(new_flag);
}

bool GameScene::GetSaveButtonFlag()
{
	if ((save_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//�t�F�[�h�A�E�g��flag�𗧂Ă�
		save_button.SetSelected(-1);//�I����Ԃ�����
		return true;
	}
	else
	{
		return false;
	}
}


void GameScene::SetSystemData(SystemData data)
{
	system_data = data;
}


int GameScene::GetSelectedScene()
{
	return is_save_or_load;
}