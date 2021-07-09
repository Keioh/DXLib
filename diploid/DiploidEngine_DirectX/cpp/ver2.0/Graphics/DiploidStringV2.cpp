#include "ver2.0/Graphics/DiploidStringV2.h"

int DiploidStringV2::CreateFontData(int Size, int Thick, int FontType, char* FontName)
{
	font_handle = CreateFontToHandle(FontName, Size, Thick, FontType);

	return font_handle;
}

int DiploidStringV2::GetHandle()
{
	return font_handle;
}


void DiploidStringV2::LoadFile(const char* str)
{
	Clear();

	int line_count = 0;

	file.ReadOpen(str);//�t�@�C���ǂݍ��݁B

	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data = file.GetLine();//�f�[�^��ǂݍ��ށB
		//wide_character.push_back(std::vector<wstring>());//���char��ǉ�
		character.push_back(std::vector<string>());//���char��ǉ�

		//string��wstring�ɕϊ�
		int BufferSize = MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, (wchar_t*)NULL, 0);

		wchar_t* cpUCS2 = new wchar_t[BufferSize];

		MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, cpUCS2, BufferSize);

		std::wstring wide_string_data(cpUCS2, cpUCS2 + BufferSize - 1);

		delete[] cpUCS2;// �o�b�t�@�̔j��


		for (int count = 0; count != wide_string_data.size(); ++count)
		{
			wide_character.push_back(wide_string_data.substr(count, 1));

			//wstring����string�ւ̕ϊ�
			int wBufferSize = WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, (char*)NULL, 0, NULL, NULL);

			// �o�b�t�@�̎擾
			CHAR* cpMultiByte = new CHAR[wBufferSize];

			// wstring �� SJIS
			WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, cpMultiByte, wBufferSize, NULL, NULL);

			// string�̐���
			std::string non_wide_string_data(cpMultiByte, cpMultiByte + wBufferSize - 1);

			// �o�b�t�@�̔j��
			delete[] cpMultiByte;

			//string�ϊ���̈ꕶ���f�[�^���v�b�V��
			character.at(line_count).push_back(non_wide_string_data);
		}

		wide_character.clear();

		//character.push_back(std::vector<string>());//���char��ǉ�

		line_count++;
	}

	file.Close();//�t�@�C�������B
}

void DiploidStringV2::Create(std::string str)
{
	Clear();

	int line_count = 0;

	string_data = str;//�f�[�^��ǂݍ��ށB
	character.push_back(std::vector<string>());//���char��ǉ�

	//string��wstring�ɕϊ�
	int BufferSize = MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, (wchar_t*)NULL, 0);

	wchar_t* cpUCS2 = new wchar_t[BufferSize];

	MultiByteToWideChar(CP_ACP, 0, string_data.c_str(), -1, cpUCS2, BufferSize);

	std::wstring wide_string_data(cpUCS2, cpUCS2 + BufferSize - 1);

	delete[] cpUCS2;// �o�b�t�@�̔j��


	for (int count = 0; count != wide_string_data.size(); ++count)
	{
		wide_character.push_back(wide_string_data.substr(count, 1));

		//wstring����string�ւ̕ϊ�
		int wBufferSize = WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, (char*)NULL, 0, NULL, NULL);

		// �o�b�t�@�̎擾
		CHAR* cpMultiByte = new CHAR[wBufferSize];

		// wstring �� SJIS
		WideCharToMultiByte(CP_OEMCP, 0, wide_character.at(count).c_str(), -1, cpMultiByte, wBufferSize, NULL, NULL);

		// string�̐���
		std::string non_wide_string_data(cpMultiByte, cpMultiByte + wBufferSize - 1);

		// �o�b�t�@�̔j��
		delete[] cpMultiByte;

		//string�ϊ���̈ꕶ���f�[�^���v�b�V��
		character.at(0).push_back(non_wide_string_data);
	}

	wide_character.clear();
}

void DiploidStringV2::ChangeFont(int handle)
{
	font_handle = handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);
}

void DiploidStringV2::Init(float x, float y, int new_font_handle)
{
	master_position = VGet(x, y, 0);

	font_handle = new_font_handle;

	GetFontStateToHandle(&font_name, &size, &thick, font_handle);
}

void DiploidStringV2::Init(float x, float y)
{
	master_position = VGet(x, y, 0);
}

void DiploidStringV2::DrawFile(int line, float frame_time)
{
	if (!character.empty())
	{
		for (int count = 0; count != character.at(line).size(); count++)
		{
			DrawString(0 + (20 * count), 0 + (20 * 0), character.at(line).at(count).c_str(), GetColor(200, 200, 200));
		}
	}
}

void DiploidStringV2::Draw(float frame_time)
{
	int width = 0;

	if (!character.empty())
	{
		for (int count = 0; count != character.at(0).size(); count++)
		{
			width = GetDrawStringWidthToHandle(character.at(0).at(0).c_str(), strlen(character.at(0).at(count).c_str()), font_handle) + width;

			DrawStringToHandle(master_position.x + width, master_position.y, character.at(0).at(count).c_str(), GetColor(200, 200, 200), font_handle);

		}
	}

	//DrawFormatString(0, 60, GetColor(0, 0, 0), "%d", GetDrawStringWidthToHandle(character.at(0).at(0).c_str(), strlen(character.at(0).at(0).c_str()), font_handle));
}

void DiploidStringV2::Clear()
{
	character.clear();
	wide_character.clear();
	string_data.clear();
}