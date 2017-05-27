#include <iostream>
#include "DxLib.h"
#include "System.h"
#include "Main_Game.h"


Main_Game::Main_Game()
{
}

void Main_Game::Main_Load()
{
	back_screen = LoadGraph("pack/ui/start_screen.png");
	main_sound.Load();
	main_dice.Load();
}

void Main_Game::Main_Init()
{
	main_filer.FileOpen_Config();
	main_net.init();
	main_dice.init();
}

void Main_Game::Main_Game_Loop()
{
	Main_Init();
	Main_Load();

	main_net.NetListen(main_filer.F_B.host, main_filer.F_B);//�l�b�g���[�N�ڑ��ҋ@�ύX����
	main_net.NetWork_wait(main_filer.F_B.host, main_filer.F_B);//�l�b�g���[�N�ڑ��܂��͑ҋ@����


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		DrawGraph(0, 0, back_screen, TRUE);//�w�i�\��


		dice_role = main_dice.Dice_role_oneDhundred(50, 50);//1d100�̃_�C�X���[���{�^��
		dice_role_custom = main_dice.Dice_role_custom(50, 100);
		main_dice.Critical_Fumble_Screen();//�N���t�@������


		//�l�b�g���[�N����
		if (main_filer.F_B.host == 1)//�z�X�g�̎��̏���
		{
			if (CheckHitKey(KEY_INPUT_0) == 1)//���y��~
			{
				sound_number = main_sound.stop;
			}
			else if (CheckHitKey(KEY_INPUT_1) == 1)//���y�Đ��@�ҋ@
			{
				sound_number = main_sound.wait;
			}
			else if (CheckHitKey(KEY_INPUT_2) == 1)//���y�Đ��@�Â��Ȑ퓬
			{
				sound_number = main_sound.quiet_battle;
			}
			else if (CheckHitKey(KEY_INPUT_3) == 1)//���y�Đ��@�������퓬
			{
				sound_number = main_sound.intense_battle;
			}
			else if (CheckHitKey(KEY_INPUT_4) == 1)//���y�Đ��@����
			{
				sound_number = main_sound.normal_time_in_game;
			}
			else if (CheckHitKey(KEY_INPUT_5) == 1)//���y�Đ��@�_�i����
			{
				sound_number = main_sound.deity;
			}
			else if (CheckHitKey(KEY_INPUT_6) == 1)//���y�Đ��@����
			{
				sound_number = main_sound.reasoning;
			}
			else if (CheckHitKey(KEY_INPUT_7) == 1)//���y�Đ��@���|
			{
				sound_number = main_sound.fear;
			}
			else if (CheckHitKey(KEY_INPUT_8) == 1)//���y�Đ��@�N���C�}�b�N�X
			{
				sound_number = main_sound.climax;
			}

			main_net.NetSend(&dice_role, main_filer.F_B);//1d100�{�^���������ꂽ�猋�ʂ𑗐M
			main_net.NetSend(&main_dice.start, main_filer.F_B);//start�𑗐M
			main_net.NetSend(&main_dice.end, main_filer.F_B);//end�𑗐M
			main_net.NetSend(&dice_role_custom, main_filer.F_B);//�J�X�^���_�C�X�{�^���������ꂽ�猋�ʂ𑗐M
			main_net.NetSend(&main_dice.graph_drawing_flag, main_filer.F_B);//�{�^���������ꂽ��I���ɂ���f�[�^�𑗐M

			switch (sound_number)//�T�E���h�ԍ��𑗐M
			{
			case 0:	main_net.NetSend(&main_sound.stop, main_filer.F_B); break;

			case 1:	main_net.NetSend(&main_sound.wait, main_filer.F_B); break;

			case 2: main_net.NetSend(&main_sound.quiet_battle, main_filer.F_B); break;

			case 3: main_net.NetSend(&main_sound.intense_battle, main_filer.F_B); break;

			case 4: main_net.NetSend(&main_sound.normal_time_in_game, main_filer.F_B); break;

			case 5: main_net.NetSend(&main_sound.deity, main_filer.F_B); break;

			case 6: main_net.NetSend(&main_sound.reasoning, main_filer.F_B); break;

			case 7: main_net.NetSend(&main_sound.fear, main_filer.F_B); break;

			case 8: main_net.NetSend(&main_sound.climax, main_filer.F_B); break;
					
			default:
				break;
			}

			main_sound.Play(sound_number);//���y�Đ�

			main_net.NetConnectionData(20,300);//�ڑ���Ԃ��m�F

			//DrawFormatString(0, 0, GetColor(0, 0, 0), "click = %d", main_dice.oneD100_click);
			
		}
		else if (main_filer.F_B.host == 0)//�z�X�g�łȂ��Ƃ��̏���
		{
			main_net.NetRead(&main_dice.oneDhundred);//1d100�̃_�C�X���[���̌��ʂ���M����oneDhundred����B
			main_net.NetRead(&main_dice.start);//start����M����oneDhundred����B
			main_net.NetRead(&main_dice.end);//end����M����oneDhundred����B
			main_net.NetRead(&main_dice.customDcustom);//1d100�̃_�C�X���[���̌��ʂ���M����oneDhundred����B
			main_net.NetRead(&main_dice.graph_drawing_flag);//�N���t�@���摜�\���̃t���O����M����graph_drawing_flag����B

			main_net.NetRead(&sound_name);//��M����sound_name�ɑ��

			main_sound.Play(sound_name);//sound_name��Play�ɑ�����ĉ��y���Đ�


			/*DrawFormatString(0, 0, GetColor(0, 0, 0), "1d100 = %d", main_dice.oneDhundred);
			DrawFormatString(0, 20, GetColor(0, 0, 0), "graph_drawing_flag = %d", main_dice.graph_drawing_flag);
			DrawFormatString(0, 40, GetColor(0, 0, 0), "sound_name = %d", main_dice.oneDhundred);*/

		}


		/*DrawFormatString(0, 600, GetColor(0, 0, 0), "HOST = %d", main_filer.F_B.host);
		DrawFormatString(0, 620, GetColor(0, 0, 0), "IP_01 = %d", main_filer.F_B.ips.d1);
		DrawFormatString(0, 640, GetColor(0, 0, 0), "IP_02 = %d", main_filer.F_B.ips.d2);
		DrawFormatString(0, 660, GetColor(0, 0, 0), "IP_03 = %d", main_filer.F_B.ips.d3);
		DrawFormatString(150, 640, GetColor(0, 0, 0), "IP_04 = %d", main_filer.F_B.ips.d4);
		DrawFormatString(150, 660, GetColor(0, 0, 0), "PORT = %d", main_filer.F_B.port);*/
	}
}