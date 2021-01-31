#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include "DxLib.h"

class DiploidEngineFile
{
private:
	std::ifstream file_in;//入力
	std::string strings;
	char buffer[512];

public:
	std::vector<std::string> str_data;
	std::vector<char> data;

	//バグ
	void Load(const char* path, unsigned int mode = std::ios::in, size_t char_size = 2);//1以上返ると成功(ファイルハンドルを返す)(modeはfstream参照)

	void Close();//ファイルを閉じる(ファイル操作を完了したら必ずこの関数を使ってファイルを閉じてください)

};