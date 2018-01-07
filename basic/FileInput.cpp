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

	fclose(fp);
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

	fclose(fp);
}
