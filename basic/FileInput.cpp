#include "FileInput.h"


void Filer::FileOpen_Config()
{
	if ((fp = fopen("config/config.txt", "r")) == NULL)
	{
		exit(1);
	}

	fscanf(fp, "BGM_Volume=%d\n", &sound_data.bgm_volume);//BGM����
	fscanf(fp, "SE_Volume=%d\n", &sound_data.se_volume);//SE����
	fscanf(fp, "BGM_Mute=%d\n", &sound_data.bgm_mute);//BGM�~���[�g
	fscanf(fp, "SE_Mute=%d\n", &sound_data.se_mute);//SE�~���[�g
	fscanf(fp, "Japanese=%d\n", &language_data.japanese_flag);//���{��
	fscanf(fp, "English=%d\n", &language_data.english_flag);//�p��

	fclose(fp);
}

void Filer::FileWrite_Config()//�ݒ�t�@�C����������
{
	if ((fp = fopen("config/config.txt", "w")) == NULL)
	{
		exit(1);
	}

	fprintf(fp, "BGM_Volume=%d\n", sound_data.bgm_volume);//BGM����
	fprintf(fp, "SE_Volume=%d\n", sound_data.se_volume);//SE����
	fprintf(fp, "BGM_Mute=%d\n", sound_data.bgm_mute);//BGM�~���[�g
	fprintf(fp, "SE_Mute=%d\n", sound_data.se_mute);//SE�~���[�g
	fprintf(fp, "Japanese=%d\n", language_data.japanese_flag);//���{��
	fprintf(fp, "English=%d\n", language_data.english_flag);//�p��

	fclose(fp);
}
