#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate()//�Q�[���N�����Ɉ�x�����t�@�C������鏈���B
{

}

void DiploidEngineApp::Load()//�Q�[���N������1�񂾂����[�h����f�[�^(����摜��Z�[�u�f�[�^��}�b�v�f�[�^�Ȃ�)
{	

}

void DiploidEngineApp::Init()//�Q�[���N�����Ɉ�񂾂��������������������L�q�B
{
	player_main.Init(VGet(GetWindowSize().x / 2, 600, 0.0f), 5.0f, GetColor(255, 100, 100), TRUE);//�v���C���[�{��
	player_grays.Init(VGet(GetWindowSize().x / 2, 600, 0.0f), 30.0f, GetColor(100, 100, 255));//�v���C���[�̃O���C�Y��
}

void DiploidEngineApp::Updata()//�A�j���[�V�����ȂǘA�����čs�����������B(��ɐ��l����)
{
	input.Update();


	if (input.GetKey(KEY_INPUT_LSHIFT) == true)//���V�t�g�L�[����������
	{
		slow = 0.5f;//�v���C���[�̑�����0.5�{��		
	}
	else
	{
		slow = 1.0f;//�v���C���[�̑����𓙔{��
	}				

	if (input.GetReleaseKey(KEY_INPUT_LCONTROL) == true)//�R���g���[���L�[����������
	{
		if (grays_count > 50)//�O���C�Y�J�E���^�[��50�ȏ゠������
		{
			grays_count -= 50;//�O���C�Y�J�E���^�[��50���炷

			for (auto& count : grays_bullet_list)
			{
				if (count.GetHitFlag() == true)//�O���C�Y��ɓ����Ă�����
				{


					//�O���C�Y�p�e�ۂ𔽎�
					count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
					count.SetDestoryFlag(true);//�폜�t���O���I���ɂ���B

					//�v���C���[�e�ۂ��쐬
					player_bullet_list.push_back(player_bullet);//�e�ۂ����X�g�ɒǉ�
					player_bullet_list.back().Init(VGet(count.GetPosition().x, count.GetPosition().y, 0.0f), count.GetRadius(), GetColor(255, 255, 255), TRUE);//�e�ۂ����˂����ʒu��ݒ�
					player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//�e�ۂ̑��x�ƕ�����ݒ�B
				}
			}
		}
	}

	if (input.GetKey(KEY_INPUT_LCONTROL) == true)
	{
		ctr_count++;
		if (ctr_count > 70)ctr_count = 70;
		if ((ctr_count > 50) && (grays_count > 300))//�R���g���[���L�[��20���[�v�ȏォ�O���C�Y�J�E���^�[��250�ȏ�Ȃ�
		{
			grays_count -= 250;//�O���C�Y�J�E���^�[��250���炷

			for (auto& count : grays_bullet_list)
			{
				if (count.GetHitFlag() == true)//�O���C�Y��ɓ����Ă�����
				{
					count.SetMoveSpeed(VGet(0.0f, 0.0f, 0.0f));
					count.SetDestoryFlag(true);//�O���C�Y�p�e�ۂ̍폜�t���O�𗧂Ă�B

					//�v���C���[�̒e�ۂ��쐬
					player_bullet_list.push_back(player_bullet);//�e�ۂ����X�g�ɒǉ�
					player_bullet_list.back().Init(VGet(player_main.GetPosition().x, player_main.GetPosition().y - player_grays.GetRadius(), 0.0f), 10.0f, GetColor(255, 255, 255), TRUE);//�e�ۂ����˂����ʒu��ݒ�
					player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//�e�ۂ̑��x�ƕ�����ݒ�B	
					
				}
				else
				{
					count.SetMoveSpeed(VGet(-(count.GetPosition().x - player_main.GetPosition().x) / ctr_count, -(count.GetPosition().y - player_main.GetPosition().y) / ctr_count, 0.0f));
				}
			}
		}
	}
	else
	{		
		ctr_count = 30;
	}


	if ((input.GetKey(KEY_INPUT_D) == true) || (input.GetKey(KEY_INPUT_RIGHT) == true))//D�L�[����������
	{
		if (player_main.GetPosition().x < GetWindowSize().x - player_main.GetRadius())//��ʊO�ɍs���Ȃ��悤��
		{
			//�v���C���[�{�̂̈ړ�
			player_main.SetMoveSpeed(VGet(8.0f * slow, 0.0f, 0.0f));
			player_main.MoveUpdata();

			//�v���C���[�O���C�Y��̈ړ�
			player_grays.SetMoveSpeed(VGet(8.0f * slow, 0.0f, 0.0f));
			player_grays.MoveUpdata();

		}
	}

	if ((input.GetKey(KEY_INPUT_A) == true) || (input.GetKey(KEY_INPUT_LEFT) == true))//A�L�[����������
	{
		if (player_main.GetPosition().x > player_main.GetRadius())//��ʊO�ɍs���Ȃ��悤��
		{
			//�v���C���[�{�̂̈ړ�
			player_main.SetMoveSpeed(VGet(-8.0f * slow, 0.0f, 0.0f));
			player_main.MoveUpdata();

			//�v���C���[�O���C�Y��̈ړ�
			player_grays.SetMoveSpeed(VGet(-8.0f * slow, 0.0f, 0.0f));
			player_grays.MoveUpdata();

		}
	}

	if ((input.GetKey(KEY_INPUT_W) == true) || (input.GetKey(KEY_INPUT_UP) == true))//W�L�[����������
	{
		if (player_main.GetPosition().y > player_main.GetRadius())//��ʊO�ɍs���Ȃ��悤��
		{
			//�v���C���[�{�̂̈ړ�
			player_main.SetMoveSpeed(VGet(0.0f, -8.0f * slow, 0.0f));
			player_main.MoveUpdata();

			//�v���C���[�O���C�Y��̈ړ�
			player_grays.SetMoveSpeed(VGet(0.0f, -8.0f * slow, 0.0f));
			player_grays.MoveUpdata();
		}
	}

	if ((input.GetKey(KEY_INPUT_S) == true) || (input.GetKey(KEY_INPUT_DOWN) == true))//S�L�[����������
	{
		if (player_main.GetPosition().y < GetWindowSize().y - player_main.GetRadius())//��ʊO�ɍs���Ȃ��悤��
		{
			//�v���C���[�{�̂̈ړ�
			player_main.SetMoveSpeed(VGet(0.0f, 8.0f * slow, 0.0f));
			player_main.MoveUpdata();

			//�v���C���[�O���C�Y��̈ړ�
			player_grays.SetMoveSpeed(VGet(0.0f, 8.0f * slow, 0.0f));
			player_grays.MoveUpdata();
		}
	}


	if (input.GetKey(KEY_INPUT_SPACE) == true)//SPACE�L�[����������
	{
		is_count += 1;
		if (is_count > 0 - (grays_count * 0.2))//�O���C�Y�J�E���^�[�����܂��Ă�������ł��o�����x���A�b�v
		{
			//�v���C���[�̒e�ۂ��쐬
			player_bullet_list.push_back(player_bullet);//�e�ۂ����X�g�ɒǉ�
			player_bullet_list.back().Init(VGet(player_main.GetPosition().x, player_main.GetPosition().y - player_grays.GetRadius(), 0.0f), 10.0f, GetColor(255, 255, 255), TRUE);//�e�ۂ����˂����ʒu��ݒ�
			player_bullet_list.back().SetMoveSpeed(VGet((-GetRand(4) + GetRand(4)), -(GetRand(5) + 10), 0));//�e�ۂ̑��x�ƕ�����ݒ�B
			is_count = 0;
		}
	}

	//�v���C���[�e�ۂ̍X�V
	for (auto& count : player_bullet_list)
	{
		count.MoveUpdata();//�v���C���[�̒e�ۈړ��̍X�V

		//�v���C���[�e�ۂ̉�ʒ[�̔���
		if (count.GetPosition().x < count.GetRadius())
		{		
			//�v���C���[�̒e�ۂ𔽎�
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//�폜�t���O���I���ɂ���B

			//�O���C�Y�p�e�ۂ��쐬
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//���x��0.3�{�Ɍ���
		}

		if (count.GetPosition().y < count.GetRadius())
		{			
			//�v���C���[�̒e�ۂ𔽎�
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//�폜�t���O���I���ɂ���B

			//�O���C�Y�p�e�ۂ��쐬
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//���x��0.3�{�Ɍ���
		}

		if (count.GetPosition().x > GetWindowSize().x - count.GetRadius())
		{	
			//�v���C���[�̒e�ۂ𔽎�
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//�폜�t���O���I���ɂ���B

			//�O���C�Y�p�e�ۂ��쐬
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//���x��0.3�{�Ɍ���
		}

		if (count.GetPosition().y > GetWindowSize().y - count.GetRadius())
		{		
			//�v���C���[�̒e�ۂ𔽎�
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));	
			count.SetDestoryFlag(true);//�폜�t���O���I���ɂ���B

			//�O���C�Y�p�e�ۂ��쐬
			grays_bullet_list.push_back(grays_bullet);
			grays_bullet_list.back().Init(count.GetPosition(), count.GetRadius(), GetColor(255, 50, 50), TRUE);
			grays_bullet_list.back().SetMoveSpeed(VGet(count.GetMoveSpeed().x * 0.3, count.GetMoveSpeed().y * 0.3, 0.0f));//���x��0.3�{�Ɍ���
		}
	}

	//�O���C�Y�p�e�ۂ̍X�V
	for (auto& count : grays_bullet_list)
	{
		count.MoveUpdata();//�O���C�Y�p�e�ۈړ��̍X�V

		//�O���C�Y�p�e�ۂ̉�ʒ[�̔���
		if (count.GetPosition().x < 0)
		{
			//�O���C�Y�p�e�ۂ𔽎�
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().y < 0)
		{
			//�O���C�Y�p�e�ۂ𔽎�
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().x > GetWindowSize().x)
		{
			//�O���C�Y�p�e�ۂ𔽎�
			count.SetMoveSpeed(VGet(-count.GetMoveSpeed().x, count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

		if (count.GetPosition().y > GetWindowSize().y)
		{
			//�O���C�Y�p�e�ۂ𔽎�
			count.SetMoveSpeed(VGet(count.GetMoveSpeed().x, -count.GetMoveSpeed().y, 0.0f));
			count.AddLife(1.0f);
		}

	}

	//�O���C�Y��Ƃ̓����蔻��
	for (auto& count : grays_bullet_list)
	{
		collision.CircleAndCircleCollisionUpdata(&player_grays, &count);//�O���C�Y��Ƃ̓����蔻��

		if (count.GetHitFlag() == true)
		{
			grays_is_count += 1;

			if (grays_is_count > 20)
			{
				grays_count += 1;//�O���C�Y���Ă�����O���C�Y�̃J�E���^�[���グ��
				grays_is_count = 0;
			}
		}
	}
}

void DiploidEngineApp::Draw()//���ʂ�`�ʂ��鏈��
{
	//�O���C�Y�p�e�ےe�ۂ̕`��
	for (auto& count : grays_bullet_list)
	{
		count.Draw();//�O���C�Y�p�e�ۂ̕`��
	}

	//�v���C���[�e�ۂ̕`��
	for (auto& count : player_bullet_list)
	{
		count.Draw();//�v���C���[�e�ۂ̕`��
	}

	player_main.Draw();//�v���C���[�̕`��
	player_grays.Draw();//�v���C���[�̃O���C�Y��̕`��

	//�O���C�Y������
	for (auto& count : grays_bullet_list)
	{
		if (count.GetHitFlag() == true)
		{
			DrawString(player_main.GetPosition().x, player_main.GetPosition().y, "Grays!!", GetColor(255, 255, 255));//�O���C�Y�������o��.

		}
	}

	DrawFormatString(0, 20, GetColor(255, 255, 255), "Grays Count %d NOW!!", grays_count);//�O���C�Y�J�E���^�[�̕`��
}

void DiploidEngineApp::Destory()//���[�v���ɍ폜�������I�u�W�F�N�g������ꍇ�͂����ō폜�����������B
{
	//�v���C���[�e�ۂ̍폜����
	if (!player_bullet_list.empty())
	{
		for (auto count = player_bullet_list.begin(); count != player_bullet_list.end();)
		{
			if (count->GetDestoryFlag() == true)//�f�X�g���C�t���O��true�Ȃ�e�ۂ��폜
			{
				count = player_bullet_list.erase(count);
				continue;
			}
			++count;
		}
	}

	//�O���C�Y�p�e�ۂ̍폜����
	if (!grays_bullet_list.empty())
	{
		for (auto count = grays_bullet_list.begin(); count != grays_bullet_list.end();)
		{
			if (count->GetDestoryFlag() == true)
			{
				count = grays_bullet_list.erase(count);
				continue;
			}

			if (count->GetLife() >= 10.0f)//������1.0f�ȏ�Ȃ�e�ۂ��폜
			{
				count = grays_bullet_list.erase(count);
				continue;
			}
			++count;
		}
	}
}

void DiploidEngineApp::End()//engine�I���O�����B
{

}