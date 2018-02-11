#include "FileInput.h"


void Filer::FileOpen_Config()//設定ファイル読み込み
{
	//Filer::FileOpen_Window();//windowファイル読み込み

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
}

void Filer::FileOpen_Window()//Windowファイル読み込み
{
	if ((fp = fopen("config/window.txt", "r")) == NULL)
	{
		exit(1);
	}

	fscanf(fp, "WindowX=%d\n", &window_data.windowX);//英語
	fscanf(fp, "WindowY=%d\n", &window_data.windowY);//英語
	fscanf(fp, "WindowBit=%d\n", &window_data.windowBit);//英語
	fscanf(fp, "FullScreen=%d\n", &window_data.fullscreen);//英語

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
	fprintf(fp, "Japanese=%d\n", language_data.japanese_flag);//日本語
	fprintf(fp, "English=%d\n", language_data.english_flag);//英語

	fclose(fp);
}

void Filer::FileOpen_Language()//言語ファイル読み込み
{
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

void Filer::FileOpen_Japanese()//日本語ファイル読み込み
{
	if ((fp = fopen("language/jpn/TitleAndOption.txt", "r")) == NULL)
	{
		exit(1);
	}

	//音量表記
	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//スタート(タイトル)画面表記
	fgets(string_data.start_info_new_game, 128, fp);
	fgets(string_data.start_info_load, 128, fp);
	fgets(string_data.start_info_option, 128, fp);
	fgets(string_data.start_info_exit, 128, fp);

	//fscanf(fp, "%s\n", &string_data.ID_001);

	fclose(fp);	
	
	Filer::CharacterNameJPN();//キャラクターの名前を読み込む
	Filer::CharacterDescriptionJPN();//キャラクターの説明を読み込む
	Filer::FactionInfomaitonBasicJPN();//基本的なファクション情報を読み込む
}

void Filer::FileOpen_English()//英語ファイル読み込み
{
	if ((fp = fopen("language/eng/TitleAndOption.txt", "r")) == NULL)
	{
		exit(1);
	}

	//音量表記
	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//スタート(タイトル)画面表記
	fgets(string_data.start_info_new_game, 128, fp);
	fgets(string_data.start_info_load, 128, fp);
	fgets(string_data.start_info_option, 128, fp);
	fgets(string_data.start_info_exit, 128, fp);

	//fscanf(fp, "%s", &string_data.ID_001);

	fclose(fp);	

	Filer::CharacterNameENG();//キャラクターの名前を読み込む
	Filer::CharacterDescriptionENG();//キャラクターの説明を読み込む
	Filer::FactionInfomaitonBasicENG();//基本的なファクション情報を読み込む
}


void Filer::CharacterNameJPN()
{
	if ((fp = fopen("language/jpn/character_name_jpn.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(character_name.charcter_name_0, 128, fp);
	fgets(character_name.charcter_name_1, 128, fp);
	fgets(character_name.charcter_name_2, 128, fp);
	fgets(character_name.charcter_name_3, 128, fp);


	fclose(fp);
}

void Filer::CharacterNameENG()
{
	if ((fp = fopen("language/eng/character_name_eng.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(character_name.charcter_name_0, 128, fp);
	fgets(character_name.charcter_name_1, 128, fp);
	fgets(character_name.charcter_name_2, 128, fp);
	fgets(character_name.charcter_name_3, 128, fp);

	fclose(fp);
}

void Filer::CharacterDescriptionJPN()
{
	if ((fp = fopen("language/jpn/character1/CharacterDescriptionJPN.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(character_description.charcter_0, 256, fp);
	fgets(character_description.charcter_1, 256, fp);
	fgets(character_description.charcter_2, 256, fp);
	fgets(character_description.charcter_3, 256, fp);

	fclose(fp);
}

void Filer::CharacterDescriptionENG()
{
	if ((fp = fopen("language/eng/character1/CharacterDescriptionENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(character_description.charcter_0, 256, fp);
	fgets(character_description.charcter_1, 256, fp);
	fgets(character_description.charcter_2, 256, fp);
	fgets(character_description.charcter_3, 256, fp);

	fclose(fp);
}

void Filer::FactionInfomaitonBasicJPN()
{
	if ((fp = fopen("language/jpn/basic/FactionInfoBbasicJPN.txt.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(faction_infomaiton_basic.main_title, 128, fp);
	fgets(faction_infomaiton_basic.charcter_1, 128, fp);
	fgets(faction_infomaiton_basic.charcter_2, 128, fp);
	fgets(faction_infomaiton_basic.charcter_3, 128, fp);

	fclose(fp);
}

void Filer::FactionInfomaitonBasicENG()
{
	if ((fp = fopen("language/eng/basic/FactionInfoBbasicENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(faction_infomaiton_basic.main_title, 128, fp);
	fgets(faction_infomaiton_basic.charcter_1, 128, fp);
	fgets(faction_infomaiton_basic.charcter_2, 128, fp);
	fgets(faction_infomaiton_basic.charcter_3, 128, fp);

	fclose(fp);
}