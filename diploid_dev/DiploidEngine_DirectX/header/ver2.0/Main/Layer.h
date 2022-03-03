#pragma  once
#include "DxLib.h"
#include <list>
#include "ver2.0/Graphics/DiploidImageV2.h"

using namespace std;

//2D空間上でZ軸を表現するためのクラスです。
class DiploidLayerV2
{
private:
	list<DiploidImageV2> image_list;//画像リストの本体
	list<DiploidImageV2>::iterator image_list_itr;//画像リストへのイテレータ

	DiploidImageV2 buffer;

protected:

public:
	void Update();//奥行きの処理を実行します。
	void Draw(bool draw = true);

	list<DiploidImageV2>::iterator GetImageListIterator();//image_listへのイテレータを取得します。
	list<DiploidImageV2>* GetImageListPointer();//image_listへのポインタを取得します。
};