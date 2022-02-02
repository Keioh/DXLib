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
			std::string data;//•¶Žš—ñˆêŽž•Û‘¶—p

			std::getline(file_in, data);

			return data;
		}
		else
		{
			file_in.close();
			return "no_data";
		}
	}
	else
	{
		return "no_data";
	}
}

void DiploidEngineFile::SetLine(const char* name, float data)
{
	if (file_out)
	{
		file_out << name << "=" << data << std::endl;
	}
}

void DiploidEngineFile::SetLine(const char* name, int data)
{
	if (file_out)
	{
		file_out << name << "=" << data << std::endl;
	}
}

void DiploidEngineFile::SetLine(const char* name, bool data)
{
	if (file_out)
	{
		if (data == true)
		{
			file_out << name << "=" << "true" << std::endl;
		}
		else
		{
			file_out << name << "=" << "false" << std::endl;
		}
	}
}

void DiploidEngineFile::Close()
{
	if (file_in)
	{
		file_in.close();
	}

	if (file_out)
	{
		file_out.close();
	}
}

void DiploidEngineFile::FileInClose()
{
	if (file_in)
	{
		file_in.close();
	}
}

void DiploidEngineFile::FileOutClose()
{
	if (file_out)
	{
		file_out.close();
	}
}

std::ifstream& DiploidEngineFile::GetFileInAdr()
{
	return file_in;
}

std::ofstream& DiploidEngineFile::GetFileOutAdr()
{
	return file_out;
}
