#pragma once
#include <fstream>
#include "DxLib.h"


class DiploidEngineFile
{
private:
	std::ifstream input_file;//入力
	std::ofstream output_file;//出力

public:
	int file_handl;//ファイルハンドル

	int Craete(const char* path);//ファイルを作る。同じ場所と名前でこの関数を使用すると白紙で元ファイルが上書きされます(1が返ると成功)
	int Load(const char* path);//1以上返ると成功(ファイルハンドルを返す)
	int WriteINT(const char* path, const char* name, int data);//ファイルの末尾に書き込みたい数値が返る
	float WriteFLOAT(const char* path, const char* name, float data);//ファイルの末尾に書き込みたい数値が返る
};