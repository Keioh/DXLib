#pragma once
#include <fstream>
#include "DxLib.h"


class DiploidEngineFile
{
private:
	std::ifstream input_file;//入力
	std::ofstream output_file;//出力

	int file_handl;//ファイルハンドル

public:


	int Craete(const char* path);//ファイルを作る。同じ場所と名前でこの関数を使用すると白紙で元ファイルが上書きされます(1が返ると成功)
	int Load(const char* path);//1以上返ると成功(ファイルハンドルを返す)
	int Write(const char* path);//1以上返ると成功
};