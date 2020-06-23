#include "data/res_data/enemy/move_pattern.h"

void MovePattern::PushBack(MoveData move_data)
{
	data.push_back(move_data);
}

void MovePattern::Reset()
{
	//itr = data.begin();
}

float MovePattern::Move()
{
	if (!data.empty())
	{
		//itr = data_ptr->begin();

		if (itr == data_ptr->end())
		{
			itr = data_ptr->begin();

			buffer_data.wait_time = 0.0f;
			buffer_data.move_time = 0.0f;
		}

		if (itr->wait_time >= buffer_data.wait_time)
		{
			buffer = 0.0f;

			++buffer_data.wait_time;

			return buffer;
		}
		else
		{
			if (itr->move_time >= buffer_data.move_time)
			{
				buffer = itr->speed;

				++buffer_data.move_time;

				return buffer;
			}
			else
			{
				if (itr != data_ptr->end())
				{
					++itr;

					buffer_data.wait_time = 0.0f;
					buffer_data.move_time = 0.0f;
				}
			}
		}
	}
	return 0.0f;
}

void MovePattern::Destory()
{
	if (!data.empty())
	{
		data.clear();
	}
}