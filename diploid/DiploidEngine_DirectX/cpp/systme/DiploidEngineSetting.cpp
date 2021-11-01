#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//�V�X�e���Z�[�u�t�@�C�����J��
	file.ReadOpen("data/system_config.txt");
	
	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data.push_back(file.GetLine());
	}

	file.Close();

	//����̐ݒ�
	system_data.language = translate.FindDataString(string_data, "language");

	//window�֘A
	system_data.window_x = translate.FindDataInt(string_data, "window_x");
	system_data.window_y = translate.FindDataInt(string_data, "window_y");
	system_data.refreshrate = translate.FindDataInt(string_data, "refreshrate");
	system_data.window_mode = translate.FindDataBool(string_data, "window_mode");
	system_data.vsync = translate.FindDataBool(string_data, "vsync");
	system_data.simulation_window_x = translate.FindDataInt(string_data, "simulation_window_x");
	system_data.simulation_window_y = translate.FindDataInt(string_data, "simulation_window_y");

	//�V���h�E�}�b�v�֘A
	system_data.shadow_map = translate.FindDataBool(string_data, "shadow_map");
	system_data.shadow_map_size_x = translate.FindDataInt(string_data, "shadow_map_size_x");
	system_data.shadow_map_size_y = translate.FindDataInt(string_data, "shadow_map_size_y");
	system_data.shadow_map_min_area_x = translate.FindDataFloat(string_data, "shadow_map_min_area_x");
	system_data.shadow_map_min_area_y = translate.FindDataFloat(string_data, "shadow_map_min_area_y");
	system_data.shadow_map_min_area_z = translate.FindDataFloat(string_data, "shadow_map_min_area_z");
	system_data.shadow_map_max_area_x = translate.FindDataFloat(string_data, "shadow_map_max_area_x");
	system_data.shadow_map_max_area_y = translate.FindDataFloat(string_data, "shadow_map_max_area_y");
	system_data.shadow_map_max_area_z = translate.FindDataFloat(string_data, "shadow_map_max_area_z");

	//game�ݒ�֘A
	system_data.string_draw_speed = translate.FindDataInt(string_data, "string_draw_speed");
	system_data.string_auto_speed = translate.FindDataInt(string_data, "string_auto_speed");
	system_data.string_background_alpha = translate.FindDataInt(string_data, "string_background_alpha");

	//window_x = 1280;
	//window_y = 720;
	window_bit = 32;
	//refresh_rate = 60;
	//window_mode = TRUE;
	window_name = "NovelGame(DiploidEngine2 NovelSystemVersion 0.7.61)";

	//�V�~�����[�V�����X�N���[���֘A(�W���ݒ�͌��̉�ʃT�C�Y��2)
	screen_handle = -1;
	//sim_window_x = window_x / 2;
	//sim_window_y = window_y / 2;	

	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
}

void DiploidEngineSetting::Init()
{
	DiploidEngineSetting::SetBegin();//DXLIB���������O�ɐݒ肷�鏈���B

	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	DiploidEngineSetting::SetEnd();//DXLIB����������ɐݒ肷�鏈���B
}

void DiploidEngineSetting::SetBegin()
{	
	SetWaitVSyncFlag(system_data.vsync);//���������M����҂���flag

	if (system_data.language == "japanese")
	{
		SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);//�����R�[�h�ύX
	}

	if (system_data.language == "english")
	{
		SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//�����R�[�h�ύX
	}

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//�t�H���g�̕`��̎d��
	SetFontThickness(1);//�t�H���g�̑�����ݒ�
	ChangeFont("���C���I");//�t�H���g�̎�ނ̐ݒ�
	SetFontSize(15);//�t�H���g�̑傫����ݒ�
	SetBackgroundColor(255, 255, 255);
	SetOutApplicationLogValidFlag(FALSE);//���O�o�͊֘A
	SetGraphMode(system_data.window_x, system_data.window_y, window_bit, system_data.refreshrate);//�𑜓x�ύX
	ChangeWindowMode(system_data.window_mode);//�E�B���h�E���[�h�ύX
	SetMainWindowText(window_name);//�A�v���P�[�V�����̖��O��ύX

	SetUseASyncLoadFlag(TRUE);//�񓯊��ǂݍ���
	SetUseDXArchiveFlag(TRUE);//DX�A�[�J�C�u�ǂݍ���
	SetAlwaysRunFlag(TRUE);//�E�B���h�E��A�N�e�B�u�ŏ��������s

	SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);//��ʕ�Ԃ̕ύX DX_FSSCALINGMODE_NEAREST DX_FSSCALINGMODE_BILINEAR
	SetDrawMode(DX_DRAWMODE_BILINEAR);//�摜�g�厞�̕�ԕύX DX_DRAWMODE_BILINEAR DX_DRAWMODE_NEAREST
	SetFullSceneAntiAliasingMode(4, 2);//�t���X�N���[��AA�ݒ�
	SetCreateDrawValidGraphMultiSample(4, 2);//AA�ݒ�

	SetEnableXAudioFlag(TRUE);//XAudio�t���O

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
}

void DiploidEngineSetting::SetEnd()
{
	//screen_handle = MakeScreen(window_x, window_y, FALSE);
	//SetDrawScreen(screen_handle);//����ʏ������I��

	SetDrawScreen(DX_SCREEN_BACK);//����ʏ������I��
	SetMouseDispFlag(TRUE);//�}�E�X�J�[�\���̕\��

	//3D�֘A
	SetCameraNearFar(100.0f, 10000.0f);
	SetupCamera_Perspective(1.054f);
	ChangeLightTypePoint(VGet(1100.851f, 300.4314f, 1500.125f), 2000.0f, 0.0f, 0.0005f, 0.0f);
}

void DiploidEngineSetting::End()
{
	DxLib_End();
}


void DiploidEngineSetting::Updata()
{
	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);

	if ((buffer_window_x != system_data.window_x) || (buffer_window_y != system_data.window_y))
	{
		SetGraphMode(system_data.window_x, system_data.window_y, window_bit, system_data.refreshrate);//�𑜓x�ύX

		//3D�֌W�̐ݒ�
		SetCameraNearFar(100.0f, 10000.0f);
		SetupCamera_Perspective(1.054f);
		ChangeLightTypePoint(VGet(1100.851f, 300.4314f, 1500.125f), 2000.0f, 0.0f, 0.0005f, 0.0f);

		reload = true;
	}
}


void DiploidEngineSetting::SetExit(int flag)
{
	exit = flag;
}

void DiploidEngineSetting::SetWindowSize(int new_window_x, int new_window_y)
{
	system_data.window_x = new_window_x;
	system_data.window_y = new_window_y;

	//GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
}

int DiploidEngineSetting::GetExit()
{
	return exit;
}

bool DiploidEngineSetting::GetReloadFlag()
{
	return reload;
}

void DiploidEngineSetting::SetReloadFlag(bool new_flag)
{
	reload = new_flag;
}

SystemData DiploidEngineSetting::GetSystemData()
{
	return system_data;
}