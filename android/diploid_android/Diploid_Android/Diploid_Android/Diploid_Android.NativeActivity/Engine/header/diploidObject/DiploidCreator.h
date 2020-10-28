#include "DxLib.h"


template<typename new_object_date>
class DiploidCreator
{
private:
	int create_time = 0;
	int destroy_time = 0;

	new_object_date* pointer = nullptr;

public:
	~DiploidCreator()
	{
		if (pointer != nullptr)
		{
			delete pointer;
		}

		pointer = nullptr;
		create_time = 0;
		destroy_time = 0;
	}

	new_object_date* Create(int time = 0)
	{
		if (pointer == nullptr)
		{
			create_time++;

			if (create_time > time)
			{
				pointer = new new_object_date;

				return pointer;
			}
			else
			{
				return pointer;
			}
		}
		else
		{
			create_time = 0;
			return pointer;
		}
	}

	new_object_date* Get()
	{
		if (pointer != nullptr)
		{
			return  pointer;
		}
		else
		{
			return  nullptr;
		}
	}

	void Destroy(int time = 0)
	{
		if (pointer != nullptr)
		{
			destroy_time++;

			if (destroy_time > time)
			{
				delete pointer;
				pointer = nullptr;
				create_time = 0;
				destroy_time = 0;
			}
		}
	}
};