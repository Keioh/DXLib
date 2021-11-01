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


float DiploidTranslate::FindDataFloat(std::string& string_data, std::string string_name)
{
	if (string_data.find(string_name) != -1)
	{
		std::stringstream ss;
		float buffer = 0.0f;

		ss << string_data;

		ss.ignore(string_data.size(), '=');

		ss >> buffer;

		return buffer;
	}

	return 0;
}

int DiploidTranslate::FindDataInt(std::string& string_data, std::string string_name)
{
	if (string_data.find(string_name) != -1)
	{
		std::stringstream ss;
		int buffer = 0;

		ss << string_data;

		ss.ignore(string_data.size(), '=');

		ss >> buffer;

		return buffer;
	}

	return 0;
}

bool DiploidTranslate::FindDataBool(std::string& string_data, std::string string_name)
{
	if (string_data.find(string_name) != -1)
	{
		std::stringstream ss;
		bool buffer = false;

		ss << string_data;

		ss.ignore(string_data.size(), '=');

		if (string_data.find("true") != -1)
		{
			buffer = true;
		}
		else if(string_data.find("false") != -1)
		{
			buffer = false;
		}

		return buffer;
	}

	return false;
}

std::string DiploidTranslate::FindDataString(std::string& string_data, std::string string_name)
{
	if (string_data.find(string_name) != -1)
	{
		std::stringstream ss;
		std::string buffer;

		ss << string_data;

		ss.ignore(string_data.size(), '=');	

		ss >> buffer;

		return buffer;
	}

	return "no_data";
}


float DiploidTranslate::FindDataFloat(std::vector<std::string>& string_data, std::string string_name)
{
	for (auto count = string_data.begin(); count != string_data.end(); ++count)
	{
		if (count->find(string_name) != -1)
		{
			std::stringstream ss;
			float buffer = 0.0f;

			ss << *count;

			ss.ignore(count->size(), '=');

			ss >> buffer;

			return buffer;
		}
	}
	return 0.0f;
}

int DiploidTranslate::FindDataInt(std::vector<std::string>& string_data, std::string string_name)
{
	for (auto count = string_data.begin(); count != string_data.end(); ++count)
	{
		if (count->find(string_name) != -1)
		{
			std::stringstream ss;
			int buffer = 0;

			ss << *count;

			ss.ignore(count->size(), '=');

			ss >> buffer;

			return buffer;
		}
	}

	return 0;
}

bool DiploidTranslate::FindDataBool(std::vector<std::string>& string_data, std::string string_name)
{
	for (auto count = string_data.begin(); count != string_data.end(); ++count)
	{
		if (count->find(string_name) != -1)
		{
			std::stringstream ss;
			bool buffer = false;

			ss << *count;

			ss.ignore(count->size(), '=');

			if (count->find("true") != -1)
			{
				buffer = true;
			}
			else if (count->find("false") != -1)
			{
				buffer = false;
			}

			return buffer;
		}
	}

	return false;
}

std::string DiploidTranslate::FindDataString(std::vector<std::string>& string_data, std::string string_name)
{
	for (auto count = string_data.begin(); count != string_data.end(); ++count)
	{
		if (count->find(string_name) != -1)
		{
			std::stringstream ss;
			std::string buffer;

			ss << *count;

			ss.ignore(count->size(), '=');

			ss >> buffer;

			return buffer;
		}
	}

	return "no_data";
}


void DiploidTranslate::SplitString(std::string string_data, std::string& first, std::string& second)
{
	std::stringstream ss;
	std::string one, two;

	//first‚Ì•¶Žš—ñ‚ÌŽæ“¾
	int count = 0;

	while ((ProcessMessage() == 0) && (string_data[count] != '='))
	{
		one += string_data[count];

		count++;
	}

	first = one;


	//second‚Ì•¶Žš—ñ‚ÌŽæ“¾
	ss << string_data;

	ss.ignore(2048, '=');

	ss >> second;
}

void DiploidTranslate::SplitString(std::string string_data, int& first, std::string& second)
{
	std::stringstream ss, ss_b;
	std::string two;
	//int one = 0;

	//first‚Ì•¶Žš—ñ‚ÌŽæ“¾
	int count = 0;

	while ((ProcessMessage() == 0) && (string_data[count] != '='))
	{
		//one += string_data[count];

		ss_b << string_data[count];

		count++;
	}

	ss_b >> first;


	//second‚Ì•¶Žš—ñ‚ÌŽæ“¾
	ss << string_data;

	ss.ignore(2048, '=');

	ss >> second;
}

void DiploidTranslate::SplitStringMulti(std::string string_data, std::string& first, std::string& second, std::string& three)
{

}