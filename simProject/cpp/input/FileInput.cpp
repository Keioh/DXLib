#include "FileInput.h"


void Filer::FileOpen_Config()//�ݒ�t�@�C���ǂݍ���
{
	//Filer::FileOpen_Window();//window�t�@�C���ǂݍ���

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

void Filer::FileOpen_Window()//Window�t�@�C���ǂݍ���
{
	if ((fp = fopen("config/window.txt", "r")) == NULL)
	{
		exit(1);
	}

	fscanf(fp, "WindowX=%d\n", &window_data.windowX);//�p��
	fscanf(fp, "WindowY=%d\n", &window_data.windowY);//�p��
	fscanf(fp, "WindowBit=%d\n", &window_data.windowBit);//�p��
	fscanf(fp, "FullScreen=%d\n", &window_data.fullscreen);//�p��

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

void Filer::FileOpen_Language()//����t�@�C���ǂݍ���
{
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

void Filer::FileOpen_Japanese()//���{��t�@�C���ǂݍ���
{
	if ((fp = fopen("language/jpn/TitleAndOption.txt", "r")) == NULL)
	{
		exit(1);
	}

	//���ʕ\�L
	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//�X�^�[�g(�^�C�g��)��ʕ\�L
	fgets(string_data.start_info_new_game, 128, fp);
	fgets(string_data.start_info_load, 128, fp);
	fgets(string_data.start_info_option, 128, fp);
	fgets(string_data.start_info_exit, 128, fp);

	//fscanf(fp, "%s\n", &string_data.ID_001);

	fclose(fp);	
	
	Filer::CharacterNameJPN();//�L�����N�^�[�̖��O��ǂݍ���
	Filer::CharacterDescriptionJPN();//�L�����N�^�[�̐�����ǂݍ���
	Filer::FactionInfomaitonBasicJPN();//��{�I�ȃt�@�N�V��������ǂݍ���
	Filer::HeadquartersInfomaitonBasicJPN();//��{�I�Ȗ{���n����ǂݍ���

	Filer::FactionTabInstructionsJPN();
	Filer::ConnectionModeInfomationJPN();
}

void Filer::FileOpen_English()//�p��t�@�C���ǂݍ���
{
	if ((fp = fopen("language/eng/TitleAndOption.txt", "r")) == NULL)
	{
		exit(1);
	}

	//���ʕ\�L
	fgets(string_data.bgm_volume, 128, fp);
	fgets(string_data.se_volume, 128, fp);

	//�X�^�[�g(�^�C�g��)��ʕ\�L
	fgets(string_data.start_info_new_game, 128, fp);
	fgets(string_data.start_info_load, 128, fp);
	fgets(string_data.start_info_option, 128, fp);
	fgets(string_data.start_info_exit, 128, fp);

	//fscanf(fp, "%s", &string_data.ID_001);

	fclose(fp);	

	Filer::CharacterNameENG();//�L�����N�^�[�̖��O��ǂݍ���
	Filer::CharacterDescriptionENG();//�L�����N�^�[�̐�����ǂݍ���
	Filer::FactionInfomaitonBasicENG();//��{�I�ȃt�@�N�V��������ǂݍ���
	Filer::HeadquartersInfomaitonBasicENG();//��{�I�Ȗ{���n����ǂݍ���

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

	//�^�C�g��
	fgets(faction_infomaiton_basic.main_title, 128, fp);

	//
	fgets(faction_infomaiton_basic.branch_point, 128, fp);
	fgets(faction_infomaiton_basic.laboratory, 128, fp);
	fgets(faction_infomaiton_basic.money, 128, fp);
	fgets(faction_infomaiton_basic.research, 128, fp);
	fgets(faction_infomaiton_basic.study, 128, fp);

	//�N���Ɋ֌W���邱��
	fgets(faction_infomaiton_basic.seasons, 128, fp);
	fgets(faction_infomaiton_basic.small_seasons, 128, fp);
	fgets(faction_infomaiton_basic.years, 128, fp);

	//�F�D�֌W�Ɋւ��邱��
	fgets(faction_infomaiton_basic.hostility, 128, fp);
	fgets(faction_infomaiton_basic.friendship, 128, fp);
	fgets(faction_infomaiton_basic.alliance, 128, fp);
	fgets(faction_infomaiton_basic.transaction, 128, fp);

	//����
	fgets(faction_infomaiton_basic.characteristic, 128, fp);

	//����u���b�N
	fgets(faction_infomaiton_basic.block, 128, fp);

	fclose(fp);
}

void Filer::FactionInfomaitonBasicENG()
{
	if ((fp = fopen("language/eng/basic/FactionInfoBasicENG.txt", "r")) == NULL)
	{
		exit(1);
	}

	//�^�C�g��
	fgets(faction_infomaiton_basic.main_title, 128, fp);

	//
	fgets(faction_infomaiton_basic.branch_point, 128, fp);
	fgets(faction_infomaiton_basic.laboratory, 128, fp);
	fgets(faction_infomaiton_basic.money, 128, fp);
	fgets(faction_infomaiton_basic.research, 128, fp);
	fgets(faction_infomaiton_basic.study, 128, fp);

	//�N���Ɋ֌W���邱��
	fgets(faction_infomaiton_basic.seasons, 128, fp);
	fgets(faction_infomaiton_basic.small_seasons, 128, fp);
	fgets(faction_infomaiton_basic.years, 128, fp);

	//�F�D�֌W�Ɋւ��邱��
	fgets(faction_infomaiton_basic.hostility, 128, fp);
	fgets(faction_infomaiton_basic.friendship, 128, fp);
	fgets(faction_infomaiton_basic.alliance, 128, fp);
	fgets(faction_infomaiton_basic.transaction, 128, fp);

	//����
	fgets(faction_infomaiton_basic.characteristic, 128, fp);
	
	//����u���b�N
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
