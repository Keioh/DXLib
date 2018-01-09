#include "FileInput.h"


void Filer::FileOpen_Config()
{
	if ((fp = fopen("config/config.txt", "r")) == NULL)
	{
		exit(1);
	}

	fscanf(fp, "BGM_Volume=%d\n", &sound_data.bgm_volume);//BGM音量
	fscanf(fp, "SE_Volume=%d\n", &sound_data.se_volume);//SE音量
	fscanf(fp, "BGM_Mute=%d\n", &sound_data.bgm_mute);//BGMミュート
	fscanf(fp, "SE_Mute=%d\n", &sound_data.se_mute);//SEミュート
	fscanf(fp, "Japanese=%d\n", &language_data.japanese_flag);//日本語
	fscanf(fp, "English=%d\n", &language_data.english_flag);//英語

	fclose(fp);

	//全て同じフラグが立っていたら
	if ((language_data.japanese_flag == 1 && language_data.english_flag == 1) ||
		(language_data.japanese_flag == 0 && language_data.english_flag == 0) ||
		(language_data.japanese_flag == -1 && language_data.english_flag == -1))
	{
		Filer::FileOpen_English();//英語ファイルを読み込む
	}

	//言語設定フラグがどちらかがオンだったら
	if (language_data.japanese_flag == 1)
	{
		Filer::FileOpen_Japanese();//日本語ファイルを読み込む
	}
	else if (language_data.english_flag == 1)
	{
		Filer::FileOpen_English();//英語ファイルを読み込む
	}
}

void Filer::FileWrite_Config()//設定ファイル書き込み
{
	if ((fp = fopen("config/config.txt", "w")) == NULL)
	{
		exit(1);
	}

	fprintf(fp, "BGM_Volume=%d\n", sound_data.bgm_volume);//BGM音量
	fprintf(fp, "SE_Volume=%d\n", sound_data.se_volume);//SE音量
	fprintf(fp, "BGM_Mute=%d\n", sound_data.bgm_mute);//BGMミュート
	fprintf(fp, "SE_Mute=%d\n", sound_data.se_mute);//SEミュート
	fprintf(fp, "Japanese=%d\n", language_data.japanese_flag);//日本語
	fprintf(fp, "English=%d\n", language_data.english_flag);//英語

	fclose(fp);
}

void Filer::FileOpen_Japanese()//日本語ファイル読み込み
{
	if ((fp = fopen("language/jpn/test.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(string_data.ID_000, 128, fp);
	fgets(string_data.ID_001, 128, fp);

	//fscanf(fp, "%s\n", &string_data.ID_001);


	fclose(fp);
}

void Filer::FileOpen_English()//英語ファイル読み込み
{
	if ((fp = fopen("language/eng/test.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(string_data.ID_000, 128, fp);
	fgets(string_data.ID_001, 128, fp);

	//fscanf(fp, "%s", &string_data.ID_001);

	fclose(fp);
}