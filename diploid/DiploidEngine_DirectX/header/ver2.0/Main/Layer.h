#pragma  once
#include "DxLib.h"
#include <list>
#include "ver2.0/Graphics/DiploidImageV2.h"

using namespace std;

//2D��ԏ��Z����\�����邽�߂̃N���X�ł��B
class DiploidLayerV2
{
private:
	list<DiploidImageV2> image_list;//�摜���X�g�̖{��
	list<DiploidImageV2>::iterator image_list_itr;//�摜���X�g�ւ̃C�e���[�^

	DiploidImageV2 buffer;

protected:

public:
	void Update();//���s���̏��������s���܂��B
	void Draw(bool draw = true);

	list<DiploidImageV2>::iterator GetImageListIterator();//image_list�ւ̃C�e���[�^���擾���܂��B
	list<DiploidImageV2>* GetImageListPointer();//image_list�ւ̃|�C���^���擾���܂��B
};