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
	Filer::HeadquartersInfomaitonBasicJPN();//基本的な本拠地情報を読み込む

	Filer::FactionTabInstructionsJPN();
	Filer::ConnectionModeInfomationJPN();
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
	Filer::HeadquartersInfomaitonBasicENG();//基本的な本拠地情報を読み込む

	Filer::FactionTabInstructionsENG();
	Filer::ConnectionModeInfomationENG();
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
	if ((fp = fopen("language/jpn/basic/FactionInfoBasicJPN.txt.txt", "r")) == NULL)
	{
		exit(1);
	}

	//タイトル
	fgets(faction_infomaiton_basic.main_title, 128, fp);

	//
	fgets(faction_infomaiton_basic.branch_point, 128, fp);
	fgets(faction_infomaiton_basic.laboratory, 128, fp);
	fgets(faction_infomaiton_basic.money, 128, fp);
	fgets(faction_infomaiton_basic.research, 128, fp);
	fgets(faction_infomaiton_basic.study, 128, fp);

	//年号に関係すること
	fgets(faction_infomaiton_basic.seasons, 128, fp);
	fgets(faction_infomaiton_basic.small_seasons, 128, fp);
	fgets(faction_infomaiton_basic.years, 128, fp);

	//友好関係に関すること
	fgets(faction_infomaiton_basic.hostility, 128, fp);
	fgets(faction_infomaiton_basic.friendship, 128, fp);
	fgets(faction_infomaiton_basic.alliance, 128, fp);
	fgets(faction_infomaiton_basic.transaction, 128, fp);

	//特性
	fgets(faction_infomaiton_basic.characteristic, 128, fp);

	//取引ブロック
	fgets(faction_infomaiton_basic.block, 128, fp);

	fclose(fp);
}

void Filer::FactionInfomaitonBasicENG()
{
	if ((fp = fopen("language/eng/basic/FactionInfoBasicENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	//タイトル
	fgets(faction_infomaiton_basic.main_title, 128, fp);

	//
	fgets(faction_infomaiton_basic.branch_point, 128, fp);
	fgets(faction_infomaiton_basic.laboratory, 128, fp);
	fgets(faction_infomaiton_basic.money, 128, fp);
	fgets(faction_infomaiton_basic.research, 128, fp);
	fgets(faction_infomaiton_basic.study, 128, fp);

	//年号に関係すること
	fgets(faction_infomaiton_basic.seasons, 128, fp);
	fgets(faction_infomaiton_basic.small_seasons, 128, fp);
	fgets(faction_infomaiton_basic.years, 128, fp);

	//友好関係に関すること
	fgets(faction_infomaiton_basic.hostility, 128, fp);
	fgets(faction_infomaiton_basic.friendship, 128, fp);
	fgets(faction_infomaiton_basic.alliance, 128, fp);
	fgets(faction_infomaiton_basic.transaction, 128, fp);

	//特性
	fgets(faction_infomaiton_basic.characteristic, 128, fp);
	
	//取引ブロック
	fgets(faction_infomaiton_basic.block, 128, fp);

	fclose(fp);
}

void Filer::HeadquartersInfomaitonBasicJPN()
{
	if ((fp = fopen("language/jpn/basic/HeadquartersInfomationBasicJPN.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(headquarters_infomation_basic.main_title, 128, fp);


	fclose(fp);
}

void Filer::HeadquartersInfomaitonBasicENG()
{
	if ((fp = fopen("language/eng/basic/HeadquartersInfomationBasicENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(headquarters_infomation_basic.main_title, 128, fp);


	fclose(fp);
}

void Filer::FactionTabInstructionsJPN()
{
	if ((fp = fopen("language/jpn/basic/FactionTabInstructionsJPN.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(faction_tab_instructions.branch_point, 64, fp);
	fgets(faction_tab_instructions.laboratory, 64, fp);
	fgets(faction_tab_instructions.money, 64, fp);
	fgets(faction_tab_instructions.research, 64, fp);
	fgets(faction_tab_instructions.study, 64, fp);
	fgets(faction_tab_instructions.characteristic, 64, fp);
	fgets(faction_tab_instructions.block, 64, fp);
	fgets(faction_tab_instructions.seasons, 64, fp);
	fgets(faction_tab_instructions.small_seasons, 64, fp);
	fgets(faction_tab_instructions.years, 64, fp);
	fgets(faction_tab_instructions.hostility, 64, fp);
	fgets(faction_tab_instructions.friendship, 64, fp);
	fgets(faction_tab_instructions.alliance, 64, fp);
	fgets(faction_tab_instructions.transaction, 64, fp);


	fclose(fp);
}

void Filer::FactionTabInstructionsENG()
{
	if ((fp = fopen("language/eng/basic/FactionTabInstructionsENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(faction_tab_instructions.branch_point, 64, fp);
	fgets(faction_tab_instructions.laboratory, 64, fp);
	fgets(faction_tab_instructions.money, 64, fp);
	fgets(faction_tab_instructions.research, 64, fp);
	fgets(faction_tab_instructions.study, 64, fp);
	fgets(faction_tab_instructions.characteristic, 64, fp);
	fgets(faction_tab_instructions.block, 64, fp);
	fgets(faction_tab_instructions.seasons, 64, fp);
	fgets(faction_tab_instructions.small_seasons, 64, fp);
	fgets(faction_tab_instructions.years, 64, fp);
	fgets(faction_tab_instructions.hostility, 64, fp);
	fgets(faction_tab_instructions.friendship, 64, fp);
	fgets(faction_tab_instructions.alliance, 64, fp);
	fgets(faction_tab_instructions.transaction, 64, fp);


	fclose(fp);
}

void Filer::ConnectionModeInfomationJPN()
{
	if ((fp = fopen("language/jpn/basic/ConnectionModeInfomationJPN.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(connection_mode_infomation.main_title, 64, fp);

	fclose(fp);
}

void Filer::ConnectionModeInfomationENG()
{
	if ((fp = fopen("language/eng/basic/ConnectionModeInfomationENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	fgets(connection_mode_infomation.main_title, 64, fp);

	fclose(fp);
}
