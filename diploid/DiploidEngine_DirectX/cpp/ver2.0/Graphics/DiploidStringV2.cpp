#include "ver2.0/Graphics/DiploidStringV2.h"

void DiploidStringV2::LoadFile(const char* str)
{
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

void DiploidStringV2::Load(std::string str)
{	
	int line_count = 0;

	//file.ReadOpen(str);//�t�@�C���ǂݍ��݁B

	//while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data = str;//�f�[�^��ǂݍ��ށB
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
			wide_character.push_back(wide_string_data.substr(count,1));
			
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

		//line_count++;
	}

	//file.Close();//�t�@�C�������B
}

void DiploidStringV2::Init(float x, float y, int new_font_handle)
{

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

//�����̑傫���ɍ��킹�ĕ`�悷�鏈���������B
void DiploidStringV2::Draw(float frame_time)
{
	if (!character.empty())
	{
		for (int count = 0; count != character.at(0).size(); count++)
		{
			DrawString(0 + (20 * count), 0 + (20 * 0), character.at(0).at(count).c_str(), GetColor(200, 200, 200));
		}
	}
}