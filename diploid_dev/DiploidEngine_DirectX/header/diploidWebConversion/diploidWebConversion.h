#pragma once
#include "DxLib.h"
#include <string>
#include "diploidInput/DiploidEnigneFile.h"

#include "ver2.0/Graphics/DiploidBoxV2.h"

//DiploidEngineのオブジェクトからJavaScript/CSS/HTMLを生成します。
class DiploidWebConversion
{
private:
	std::string buffer;
	DiploidEngineFile file;

public:
	 
	std::string toWebCode(DiploidBoxV2 object, int red, int green, int blue);

};