#include "diploidInput\DiploidEnigneFile.h"



bool DiploidTranslate::Find(std::string& string_data, std::string string_name)
{
	if (string_data.find(string_name) != -1)
	{
		return true;
	}

	return false;
}

bool DiploidTranslate::Find(std::vector<std::string>& string_data, std::string string_name)
{
	for (auto count = string_data.begin(); count != string_data.end(); ++count)
	{
		if (count->find(string_name) != -1)
		{
			return true;
		}		
	}

	return false;
}