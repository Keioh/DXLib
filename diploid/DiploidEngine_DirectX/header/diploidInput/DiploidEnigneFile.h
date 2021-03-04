#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include "DxLib.h"

class DiploidEngineFile
{
private:
	std::fstream file_in;//読み込み用
	std::ofstream file_out;//書き込み用

public:

	//ファイル読み込み時にファイルが無かった場合、自動的に作成されます。
	void Load(const char* path, unsigned int in_mode = std::ios::in, unsigned int out_mode = std::ios::trunc);//1以上返ると成功(ファイルハンドルを返す)(modeはfstream参照)(新規ファイル作成時のファイルオープンモードはtrunc)

	std::string GetLine();//ファイルから1行だけ読み出す。(一行だけなのでfor文とかで連続して読み出す必要あり)(ファイル終端まで読み出した場合、自動で読み込み側のfstreamがcloseします。)
	void SetLine(std::string name, float data);//データ=数値という表記で出力されます。

	void Close();//読み込み用と書き込み用のファイルストリームを閉じます。(ファイル操作を完了したらこの関数を使ってファイルを閉じてください)
	void FileInClose();//読み込み用のファイルストリームを閉じます。
	void FileOutClose();//書き込み用のファイルストリームを閉じます。
};