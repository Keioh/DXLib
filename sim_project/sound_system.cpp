#include "sound_system.h"

SoundSystem::SoundSystem()
{
	SoundSystem::init();
}

void SoundSystem::init()//������
{
	sound_r = 5.0f;
	one_shot_flag = false;
	sound_volume = 255;
}

void SoundSystem::LoadSound(char* path, int data_flag)//����ǂݍ���
{
	SetCreate3DSoundFlag(data_flag);
	sound_handl = LoadSoundMem(path);
}

void SoundSystem::LoadSoundCopy(int copy_handl)//���������g���ꍇ�͂�����̊֐����g�����ƁB
{
	sound_copy_handl = DuplicateSoundMem(copy_handl);
}

void SoundSystem::Play(float volume, int PlayType, bool copy_type)//�����Đ�����B
{
	ChangeVolumeSoundMem(volume, sound_handl);//���ʂ�ݒ�B
	ChangeVolumeSoundMem(volume, sound_copy_handl);//���ʂ�ݒ�B

	if (copy_type == false)
	{
		if (CheckSoundMem(sound_handl) == 0)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//�Đ�����B
		}
	}
	else if (copy_type == true)//�n���h���������̏ꍇ
	{
		if (CheckSoundMem(sound_copy_handl) == 0)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//�Đ�����B
		}
	}
}

void SoundSystem::Play3D(VECTOR pos, float volume, int PlayType, bool wire, bool copy_type)//�����Đ�����B(3D��)
{
	Set3DSoundListenerPosAndFrontPos_UpVecY(pos, VGet(0.0f, 1.0f, 0.0f));//���X�i�[��ݒ�
	Set3DRadiusSoundMem(sound_r, sound_handl);//�������鋗����ݒ�
	ChangeVolumeSoundMem(volume, sound_handl);//���ʂ�ݒ�B
	ChangeVolumeSoundMem(volume, sound_copy_handl);//���ʂ�ݒ�B

	if (wire == true)
	{
		DrawSphere3D(pos, 1.0f, 64, GetColor(150, 150, 150), GetColor(150, 150, 150), TRUE);
	}

	if (copy_type == false)
	{
		if (CheckSoundMem(sound_handl) == 0)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//�Đ�����B
		}
	}
	else if (copy_type == true)//�n���h���������̏ꍇ
	{
		if (CheckSoundMem(sound_copy_handl) == 0)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//�Đ�����B
		}
	}
}

void SoundSystem::OneShotPlay(float volume, int PlayType, bool copy_type)//��񂾂��Đ��������Ƃ��͂�����
{
	ChangeVolumeSoundMem(volume, sound_handl);//���ʂ�ݒ�B
	ChangeVolumeSoundMem(volume, sound_copy_handl);//���ʂ�ݒ�B

	if (copy_type == false)
	{
		if ((CheckSoundMem(sound_handl) == 0) && one_shot_flag == false)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//�Đ�����B
			one_shot_flag = true;
		}
	}
	else if (copy_type == true)
	{
		if ((CheckSoundMem(sound_copy_handl) == 0) && one_shot_flag == false)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//�Đ�����B
			one_shot_flag = true;
		}
	}
}

void SoundSystem::OneShotPlay3D(VECTOR pos, float volume, int PlayType, bool wire, bool copy_type)//��񂾂��Đ��������Ƃ��͂�����(3D��)
{	
	Set3DSoundListenerPosAndFrontPos_UpVecY(pos, VGet(0.0f, 1.0f, 0.0f));//���X�i�[��ݒ�
	Set3DRadiusSoundMem(sound_r, sound_handl);//�������鋗����ݒ�
	ChangeVolumeSoundMem(volume, sound_handl);//���ʂ�ݒ�B
	ChangeVolumeSoundMem(volume, sound_copy_handl);//���ʂ�ݒ�B

	if (wire == true)
	{
		DrawSphere3D(pos, 1.0f, 64, GetColor(150, 150, 150), GetColor(150, 150, 150), TRUE);
	}

	if (copy_type == false)
	{
		if ((CheckSoundMem(sound_handl) == 0) && one_shot_flag == false)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_handl, PlayType, TRUE);//�Đ�����B
			one_shot_flag = true;
		}
	}
	else if (copy_type == true)
	{
		if ((CheckSoundMem(sound_copy_handl) == 0) && one_shot_flag == false)//�Đ�����Ă��Ȃ��Ȃ�
		{
			PlaySoundMem(sound_copy_handl, PlayType, TRUE);//�Đ�����B
			one_shot_flag = true;
		}
	}
}

void SoundSystem::OneShotReset()//��񂾂��Đ������ꍇ�͂��̊֐��ŕK��������
{
	if (one_shot_flag = true)
	{
		one_shot_flag = false;
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