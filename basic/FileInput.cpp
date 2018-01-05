#include "FileInput.h"


void Filer::FileOpen_Config()
{
	if ((fp = fopen("config/config.txt", "r")) == NULL)
	{
		exit(2);
	}

	fscanf(fp, "BGM_Volume=%d\n", &sound_data.bgm_volume);//BGM����
	fscanf(fp, "SE_Volume=%d\n", &sound_data.se_volume);//SE����
	fscanf(fp, "BGM_Mute=%d\n", &sound_data.bgm_mute);//BGM�~���[�g
	fscanf(fp, "SE_Mute=%d\n", &sound_data.se_mute);//SE�~���[�g


	/*fscanf(fp, "%d", &F_B.host);	//�z�X�g�����邩�̃t���O(0�Ŏ󂯂鑤, 1�Ńz�X�g)
	fscanf(fp, "%d", &F_B.ips.d1);	//ip
	fscanf(fp, "%d", &F_B.ips.d2);
	fscanf(fp, "%d", &F_B.ips.d3);
	fscanf(fp, "%d", &F_B.ips.d4);
	fscanf(fp, "%d", &F_B.port);	//port
	fscanf(fp, "%d", &F_B.member);	//�l��
	*/
	fclose(fp);
}
