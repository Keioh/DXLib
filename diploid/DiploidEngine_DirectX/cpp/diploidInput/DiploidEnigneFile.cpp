#include "diploidInput\DiploidEnigneFile.h"


void DiploidEngineFile::Load(const char* path, unsigned int mode, size_t char_size)
{
	file_in.open(path, mode);

	while (!file_in.eof())
	{
		std::getline(file_in, strings);

		//str_data.push_back(strings);

		
		for (int i = 0; i != (512 / char_size); i++)
		{
			buffer[i] = *strings.substr(i * char_size, char_size).c_str();
		}

		data.push_back(*buffer);
		
	}


	file_in.close();
}


void DiploidEngineFile::Close()
{
	file_in.close();
}
