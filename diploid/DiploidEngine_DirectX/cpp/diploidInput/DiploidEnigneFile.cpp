#include "diploidInput\DiploidEnigneFile.h"


void DiploidEngineFile::ReadOpen(const char* path, unsigned int in_mode)
{
	file_in.open(path, in_mode);

	if (!file_in)
	{
		file_out.open(path);
		file_out.close();

		file_in.open(path, in_mode);
	}
}

void DiploidEngineFile::WriteOpen(const char* path, unsigned int out_mode)
{
	file_out.open(path, out_mode);
}

std::string DiploidEngineFile::GetLine()
{
	if (file_in)
	{
		if (!file_in.eof())
		{
			std::string data;

			std::getline(file_in, data);

			return data;
		}
		else
		{
			file_in.close();
			return "end_file";
		}
	}
	return "end_file";
}

void DiploidEngineFile::SetLine(std::string name, float data)
{
	file_out << name << "=" << data << std::endl;
}

void DiploidEngineFile::Close()
{
	file_in.close();
	file_out.close();
}

void DiploidEngineFile::FileInClose()
{
	file_in.close();
}

void DiploidEngineFile::FileOutClose()
{
	file_out.close();
}