#pragma once
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
#include <sstream>
#include <limits>
#include "DxLib.h"


class DiploidEngineFile
{
private:
	std::ifstream file_in;//読み込み用
	std::ofstream file_out;//書き込み用


public:

	//ファイル読み込み時にファイルが無かった場合、自動的に作成されます。
	void ReadOpen(const char* path, unsigned int in_mode = std::ios::in);//1以上返ると成功(ファイルハンドルを返す)(modeはfstream参照)(新規ファイル作成時のファイルオープンモードはtrunc)
	void WriteOpen(const char* path, unsigned int out_mode = std::ios::out);

	std::string GetLine();//ファイルから1行だけ読み出す。(一行だけなのでfor文とかで連続して読み出す必要あり)(ファイル終端まで読み出した場合、自動で読み込み側のfstreamがcloseします。)
	void SetLine(const char* name, float data);//データ=数値という表記で出力されます。
	void SetLine(const char* name, int data);//データ=数値という表記で出力されます。
	void SetLine(const char* name, bool data);//データ=数値という表記で出力されます。

	void Close();//読み込み用と書き込み用のファイルストリームを閉じます。(ファイル操作を完了したらこの関数を使ってファイルを閉じてください)
	void FileInClose();//読み込み用のファイルストリームを閉じます。
	void FileOutClose();//書き込み用のファイルストリームを閉じます。

	std::ifstream& GetFileInAdr();
	std::ofstream& GetFileOutAdr();

};

//DiploidTranslate.cppに記述
class DiploidTranslate
{
private:

public:
	bool Find(std::string& string_data, std::string string_name);//string_dataには調べる文字列データ、string_nameには探したい文字列。文字列が見つかったらtrueを返す。
	bool Find(std::vector<std::string>& string_data, std::string string_name);//上記関数のvector配列対応版

	float FindDataFloat(std::string& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)
	int FindDataInt(std::string& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)
	bool FindDataBool(std::string& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)

	float FindDataFloat(std::vector<std::string>& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)
	int FindDataInt(std::vector<std::string>& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)
	bool FindDataBool(std::vector<std::string>& string_data, std::string string_name);//string_dataからstring_nameに対応する数値を取得します。(string_name=〇〇形式の○○部分を取得)

	void SplitString(std::string string_data, std::string& first, std::string& second);//「=」で繋いだstring_dataを｢=｣で分割し、firstとsecondで取得します。
	void SplitStringMulti(std::string string_data, std::string& first, std::string& second, std::string& three);//「=」で繋いだstring_dataを｢=｣で分割し、firstとsecondとthreeで取得します。

};