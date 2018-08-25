#include "diploidInput\DiploidEnigneFile.h"


int DiploidEngineFile::Craete(const char* path)
{
	output_file.open(path);

	if (!output_file)
	{
		return 0;
	}

	output_file.close();

	return 1;
}

int DiploidEngineFile::Load(const char* path)
{
	file_handl = FileRead_open(path, TRUE);//ファイルを読み込む

	FileRead_close(file_handl);//ファイルを閉じる

	if (file_handl > 0)
	{
		return file_handl;
	}

	return 0;
}

int DiploidEngineFile::Write(const char* path)
{
	return 0;
}