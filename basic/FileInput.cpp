#include "FileInput.h"


void Filer::FileOpen_Config()
{
	if ((fp = fopen("pack/user/config.txt", "r")) == NULL)
	{
		exit(2);
	}

	/*fscanf(fp, "%d", &F_B.host);	//ホストをするかのフラグ(0で受ける側, 1でホスト)
	fscanf(fp, "%d", &F_B.ips.d1);	//ip
	fscanf(fp, "%d", &F_B.ips.d2);
	fscanf(fp, "%d", &F_B.ips.d3);
	fscanf(fp, "%d", &F_B.ips.d4);
	fscanf(fp, "%d", &F_B.port);	//port
	fscanf(fp, "%d", &F_B.member);	//人数
	*/
	fclose(fp);
}
