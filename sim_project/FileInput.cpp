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