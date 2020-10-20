#include "DxLib.h"


template<typename new_object_date>
class DiploidCreator
{
private:
	bool created_flag = false;

	new_object_date* pointer;

public:
	~DiploidCreator()
	{
		delete[] pointer;
	}

	new_object_date* Create()
	{
		pointer = new new_object_date;

		created_flag = true;

		return pointer;
	}

	void ReCreate()
	{
		created_flag = false;
	}

	void Destory()
	{
		delete[] pointer;
	}
};