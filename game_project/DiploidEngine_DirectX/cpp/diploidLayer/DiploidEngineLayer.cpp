#include "diploidLayer\DiploidEngineLayer.h"

void DiploidEngineLayer::GetSize()
{
	top_size = image_top_vector.size();
	mid_size = image_mid_vector.size();
	bot_size = image_bot_vector.size();

	top_byte = top_size * sizeof(DiploidImage);
	mid_byte = mid_size * sizeof(DiploidImage);
	bot_byte = bot_size * sizeof(DiploidImage);
}


void DiploidEngineLayer::PushTopGraphics(DiploidImage image)
{
	image_top_vector.push_back(image);
}

void DiploidEngineLayer::PushMidGraphics(DiploidImage image)
{
	image_mid_vector.push_back(image);
}

void DiploidEngineLayer::PushBotGraphics(DiploidImage image)
{
	image_bot_vector.push_back(image);
}


void DiploidEngineLayer::Updata()
{
	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			image->Updata();
		}
	}

	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			image->Updata();
		}
	}	
	
	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			image->Updata();
		}
	}
}

void DiploidEngineLayer::Draw(bool debug, bool draw)
{
	GetSize();//各配列の大きさを取得

	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			image->Draw(draw);
		}
	}

	//デバッグ情報
	if (debug == true)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "top layer vector size : %.6f MB   objects : %d", top_byte / 1000000, top_size);
		DrawFormatString(0, 120, GetColor(255, 255, 255), "mid layer vector size : %.6f MB   objects : %d", mid_byte / 1000000, mid_size);
		DrawFormatString(0, 140, GetColor(255, 255, 255), "bot layer vector size : %.6f MB   objects ; %d", bot_byte / 1000000, bot_size);
		DrawFormatString(0, 160, GetColor(255, 255, 255), "all layer vector size : %.6f MB   all object ; %d", (top_byte + mid_byte + bot_byte) / 1000000, top_size + mid_size + bot_size);
	}
}


void DiploidEngineLayer::Destory()
{
	DestoryTop();//top配列から要素を削除
	DestoryMid();//mid配列から要素を削除
	DestoryBot();//bot配列から要素を削除
}

void DiploidEngineLayer::DestoryTop()
{
	if (!image_top_vector.empty())
	{
		for (auto image = image_top_vector.begin(); image != image_top_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_top_vector.erase(image);
				image = image_top_vector.begin();
			}
		}
	}
}

void DiploidEngineLayer::DestoryMid()
{
	if (!image_mid_vector.empty())
	{
		for (auto image = image_mid_vector.begin(); image != image_mid_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_mid_vector.erase(image);
				image = image_mid_vector.begin();
			}
		}
	}
}

void DiploidEngineLayer::DestoryBot()
{
	if (!image_bot_vector.empty())
	{
		for (auto image = image_bot_vector.begin(); image != image_bot_vector.end(); ++image)
		{
			if (image->destory == true)
			{
				image_bot_vector.erase(image);
				image = image_bot_vector.begin();
			}
		}
	}
}


void DiploidEngineLayer::SetTOPAnimationPosition(int number, VECTOR move_speed)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineLayer::SetTOPAnimationPositionX(int number, float move_speed)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_speed.x = move_speed;
			}
		}
	}
}

void DiploidEngineLayer::SetTOPAnimationPositionY(int number, float move_speed)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_speed.y = move_speed;
			}
		}
	}
}


void DiploidEngineLayer::SetTOPPositionYAdd(int number, float move_speed)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_speed.y += move_speed;
			}
		}
	}
}

void DiploidEngineLayer::SetTOPPosition(int number, VECTOR position)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->position = position;
			}
		}
	}
}


void DiploidEngineLayer::SetMIDAnimationPosition(int number, VECTOR move_speed)
{
	if (!image_mid_vector.empty())
	{
		for (auto mid = image_mid_vector.begin(); mid != image_mid_vector.end(); ++mid)
		{
			if (mid->number == number)
			{
				mid->move_speed = move_speed;
			}
		}
	}
}

void DiploidEngineLayer::SetBOTAnimationPosition(int number, VECTOR move_speed)
{
	if (!image_bot_vector.empty())
	{
		for (auto bot = image_bot_vector.begin(); bot != image_bot_vector.end(); ++bot)
		{
			if (bot->number == number)
			{
				bot->move_speed = move_speed;
			}
		}
	}
}


void DiploidEngineLayer::SetTOPAnimationAngle(int number, float angle)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_angle = angle;
			}
		}
	}
}

void DiploidEngineLayer::SetMIDAnimationAngle(int number, float angle)
{
	if (!image_mid_vector.empty())
	{
		for (auto mid = image_mid_vector.begin(); mid != image_mid_vector.end(); ++mid)
		{
			if (mid->number == number)
			{
				mid->move_angle = angle;
			}
		}
	}
}

void DiploidEngineLayer::SetBOTAnimationAngle(int number, float angle)
{
	if (!image_bot_vector.empty())
	{
		for (auto bot = image_bot_vector.begin(); bot != image_bot_vector.end(); ++bot)
		{
			if (bot->number == number)
			{
				bot->move_angle = angle;
			}
		}
	}
}


void DiploidEngineLayer::SetTOPAnimationSize(int number, VECTOR size)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->move_size = size;
			}
		}
	}
}

void DiploidEngineLayer::SetMIDAnimationSize(int number, VECTOR size)
{
	if (!image_mid_vector.empty())
	{
		for (auto mid = image_mid_vector.begin(); mid != image_mid_vector.end(); ++mid)
		{
			if (mid->number == number)
			{
				mid->move_size = size;
			}
		}
	}
}

void DiploidEngineLayer::SetBOTAnimationSize(int number, VECTOR size)
{
	if (!image_bot_vector.empty())
	{
		for (auto bot = image_bot_vector.begin(); bot != image_bot_vector.end(); ++bot)
		{
			if (bot->number == number)
			{
				bot->move_size = size;
			}
		}
	}
}


void DiploidEngineLayer::SetTOPAnimationScale(int number, float scale)
{
	if (!image_top_vector.empty())
	{
		for (auto top = image_top_vector.begin(); top != image_top_vector.end(); ++top)
		{
			if (top->number == number)
			{
				top->scale = scale;
			}
		}
	}
}

void DiploidEngineLayer::SetMIDAnimationScale(int number, float scale)
{
	if (!image_mid_vector.empty())
	{
		for (auto mid = image_mid_vector.begin(); mid != image_mid_vector.end(); ++mid)
		{
			if (mid->number == number)
			{
				mid->scale = scale;
			}
		}
	}
}

void DiploidEngineLayer::SetBOTAnimationScale(int number, float scale)
{
	if (!image_bot_vector.empty())
	{
		for (auto bot = image_bot_vector.begin(); bot != image_bot_vector.end(); ++bot)
		{
			if (bot->number == number)
			{
				bot->scale = scale;
			}
		}
	}
}


int DiploidEngineLayer::GetTOPNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_top_vector.begin() + target;

	if (!image_top_vector.empty())
	{
		return itr->number;
	}
}

int DiploidEngineLayer::GetMIDNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_mid_vector.begin() + target;

	if (!image_mid_vector.empty())
	{
		return itr->number;
	}
}

int DiploidEngineLayer::GetBOTNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_bot_vector.begin() + target;

	if (!image_bot_vector.empty())
	{
		return itr->number;
	}
}


void DiploidEngineLayer::SetTOPNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_top_vector.begin() + target_number;//topイテレータ

	itr->number = set_number;//新しい値を代入
}

void DiploidEngineLayer::SetMIDNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_mid_vector.begin() + target_number;//midイテレータ

	itr->number = set_number;//新しい値を代入
}

void DiploidEngineLayer::SetBOTNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_bot_vector.begin() + target_number;//botイテレータ

	itr->number = set_number;//新しい値を代入
}


int DiploidEngineLayer::GetTOPLayerNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_top_vector.begin() + target;

	if (!image_top_vector.empty())
	{
		return itr->layer_number;
	}
}

int DiploidEngineLayer::GetMIDLayerNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_mid_vector.begin() + target;

	if (!image_mid_vector.empty())
	{
		return itr->layer_number;
	}
}

int DiploidEngineLayer::GetBOTLayerNumber(int target)
{
	std::vector<DiploidImage>::iterator itr = image_bot_vector.begin() + target;

	if (!image_bot_vector.empty())
	{
		return itr->layer_number;
	}
}


void DiploidEngineLayer::SetTOPLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_top_vector.begin() + target_number;//topイテレータ

	itr->layer_number = set_number;//新しい値を代入
}

void DiploidEngineLayer::SetMIDLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_mid_vector.begin() + target_number;//topイテレータ

	itr->layer_number = set_number;//新しい値を代入
}

void DiploidEngineLayer::SetBOTLayerNumber(int target_number, int set_number)
{
	std::vector<DiploidImage>::iterator itr = image_bot_vector.begin() + target_number;//topイテレータ

	itr->layer_number = set_number;//新しい値を代入
}