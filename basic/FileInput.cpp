#include "FileInput.h"


void Filer::FileOpen_Config()
{
	if ((fp = fopen("pack/user/config.txt", "r")) == NULL)
	{
		exit(2);
	}

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
