#include "FileInput.h"


void Filer::FileOpen_Config()//�ݒ�t�@�C���ǂݍ���
{
	Filer::FileOpen_Window();//window�t�@�C���ǂݍ���

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

	//�S�ē����t���O�������Ă�����
	if ((language_data.japanese_flag == 1 && language_data.english_flag == 1) ||
		(language_data.japanese_flag == 0 && language_data.english_flag == 0) ||
		(language_data.japanese_flag == -1 && language_data.english_flag == -1))
	{
		Filer::FileOpen_English();//�p��t�@�C����ǂݍ���
	}

	//����ݒ�t���O���ǂ��炩���I����������
	if (language_data.japanese_flag == 1)
	{
		Filer::FileOpen_Japanese();//���{��t�@�C����ǂݍ���
	}
	else if (language_data.english_flag == 1)
	{
		Filer::FileOpen_English();//�p��t�@�C����ǂݍ���
	}
}

void Filer::FileOpen_Window()//Window�t�@�C���ǂݍ���
{
	if ((fp = fopen("config/window.txt", "r")) == NULL)
	{
		exit(1);
	}

	fscanf(fp, "WindowX=%d\n", &window_data.windowX);//�p��
	fscanf(fp, "WindowY=%d\n", &window_data.windowY);//�p��
	fscanf(fp, "WindowBit=%d\n", &window_data.windowBit);//�p��

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

void Filer::FileOpen_Japanese()//���{��t�@�C���ǂݍ���
{
	if ((fp = fopen("language/jpn/data.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//fscanf(fp, "%s\n", &string_data.ID_001);


	fclose(fp);
}

void Filer::FileOpen_English()//�p��t�@�C���ǂݍ���
{
	if ((fp = fopen("language/eng/data.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//fscanf(fp, "%s", &string_data.ID_001);

	fclose(fp);
}