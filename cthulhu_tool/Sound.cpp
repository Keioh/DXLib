#include "Sound.h"

Sound::Sound()
{	
	stop_sound_dont_use = 0;//�Ȃ����������ł��Ȃ�
	stop_sound_dont_use_1 = 0;//�Ȃ����������ł��Ȃ�
	//stop_sound_dont_use_2 = 0;//�Ȃ����������ł��Ȃ�

	stop				= 0;//�Đ��X�g�b�v
	wait				= 1;//�ҋ@
	quiet_battle		= 2;//�Â��Ȑ퓬
	intense_battle		= 3;//�������퓬
	normal_time_in_game = 4;//����
	deity				= 5;//�_�i����
	reasoning			= 6;//����
	fear				= 7;//���|
	climax				= 8;//�N���C�}�b�N�X
}

void Sound::Load()
{
	sound[1] = LoadSoundMem("pack/sound/�ҋ@.mp3");
	sound[2] = LoadSoundMem("pack/sound/�Â��Ȑ퓬.mp3");
	sound[3] = LoadSoundMem("pack/sound/�������퓬.mp3");
	sound[4] = LoadSoundMem("pack/sound/����.mp3");
	sound[5] = LoadSoundMem("pack/sound/�_�i����.mp3");
	sound[6] = LoadSoundMem("pack/sound/����.mp3");
	sound[7] = LoadSoundMem("pack/sound/���|.mp3");
	sound[8] = LoadSoundMem("pack/sound/�N���C�}�b�N�X.mp3");

}

void Sound::Play(int sound_number)//�T�E���h�Đ��֐�(�Đ��������T�E���h�̔ԍ�)	0�͂Ȃɂ��Đ����Ȃ��B
{
	switch (sound_number)
	{
	case 0:	//���ׂĂ̍Đ����~����
			StopSoundMem(sound[1]);
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 1:	//�ҋ@
		ChangeVolumeSoundMem(180, sound[1]);//�{�����[���ύX

		if(CheckSoundMem(sound[1]) == 0)PlaySoundMem(sound[1], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[2]);//sound[1]�ȊO���Đ���~����
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 2:	//�Â��Ȑ퓬	
		ChangeVolumeSoundMem(180, sound[2]);//�{�����[���ύX

		if (CheckSoundMem(sound[2]) == 0)PlaySoundMem(sound[2], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[2]�ȊO���Đ���~����
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 3://�������퓬
		ChangeVolumeSoundMem(180, sound[3]);//�{�����[���ύX

		if (CheckSoundMem(sound[3]) == 0)PlaySoundMem(sound[3], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[3]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 4://����
			ChangeVolumeSoundMem(180, sound[4]);//�{�����[���ύX

		if (CheckSoundMem(sound[4]) == 0)PlaySoundMem(sound[4], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[4]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 5://�_�i����
			ChangeVolumeSoundMem(255, sound[5]);//�{�����[���ύX

		if (CheckSoundMem(sound[5]) == 0)PlaySoundMem(sound[5], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[5]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 6://����
			ChangeVolumeSoundMem(180, sound[6]);//�{�����[���ύX

		if (CheckSoundMem(sound[6]) == 0)PlaySoundMem(sound[6], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[6]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[7]);
			StopSoundMem(sound[8]);

			break;

	case 7://���|
			ChangeVolumeSoundMem(190, sound[7]);//�{�����[���ύX
	
		if (CheckSoundMem(sound[7]) == 0)PlaySoundMem(sound[7], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[7]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[8]);

			break;

	case 8://�N���C�}�b�N�X
			ChangeVolumeSoundMem(190, sound[7]);//�{�����[���ύX

		if (CheckSoundMem(sound[8]) == 0)PlaySoundMem(sound[8], DX_PLAYTYPE_LOOP);//�Đ�����Ă��Ȃ���΍Đ�����
			StopSoundMem(sound[1]);//sound[8]�ȊO���Đ���~����
			StopSoundMem(sound[2]);
			StopSoundMem(sound[3]);
			StopSoundMem(sound[4]);
			StopSoundMem(sound[5]);
			StopSoundMem(sound[6]);
			StopSoundMem(sound[7]);

			break;

	default:
		break;
	}
}