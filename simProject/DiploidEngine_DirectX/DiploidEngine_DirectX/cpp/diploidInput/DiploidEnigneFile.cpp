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

	//FileRead_close(file_handl);//ファイルを閉じる

	if (file_handl > 0)
	{
		return file_handl;
	}

	return 0;
}

int DiploidEngineFile::WriteINT(const char* path, const char* name, int data)
{
	output_file.open(path, std::ios::app);//追記モードでファイルを開く

	if (output_file)
	{
		output_file << name << '=' << data << std::endl;	
		
		output_file.close();

		return data;
	}

	output_file.close();

	return data;
}

float DiploidEngineFile::WriteFLOAT(const char* path, const char* name, float data)
{
	output_file.open(path, std::ios::app);//追記モードでファイルを開く

	if (output_file)
	{
		output_file << name << '=' << data << std::endl;

		output_file.close();

		return data;
	}

	output_file.close();

	return data;
}

void DiploidEngineFile::Read(int handl)
{
	FileRead_gets(strings, 256, handl);
}

void DiploidEngineFile::Close(int handl)
{
	FileRead_close(handl);
}