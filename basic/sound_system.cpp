#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//������
{
	sound_volume = 255;
}

void SoundSystem::LoadSound(char* path)//����ǂݍ���
{
	sound_handl = LoadSoundMem(path);
}

void SoundSystem::Play(float volume_scale, int PlayType)//�����Đ�����B(volume_scale��1.0f~0.0f�Őݒ�B0.0f�Ń{�����[��0)
{
	ChangeVolumeSoundMem(sound_volume * volume_scale, sound_handl);//���ʂ�ݒ�B

	if (CheckSoundMem(sound_handl) == 0)//�Đ�����Ă��Ȃ��Ȃ�
	{
		PlaySoundMem(sound_handl, PlayType, TRUE);//�Đ�����B
	}
}

void SoundSystem::Stop()//�����~����B
{
	if (CheckSoundMem(sound_handl) == 1)//�Đ����Ȃ�
	{
		StopSoundMem(sound_handl);//�����~�߂�B
	}
}

void SoundSystem::SoundDelete()//�ǂݍ��񂾉����폜
{
	DeleteSoundMem(sound_handl);//�폜
}