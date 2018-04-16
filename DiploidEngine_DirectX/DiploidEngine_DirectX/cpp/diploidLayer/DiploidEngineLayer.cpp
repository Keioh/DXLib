#include "diploidLayer\DiploidEngineLayer.h"

//全てのレイヤーを更新
void DiploidEngineLayer::UpdataLayerObject()
{
	//bot
	for (int n = 0; n != layer_bot_object_simple.size(); n++)//抽象
	{
		layer_bot_object_simple[n].Update();
	}

	for (int n = 0; n != layer_bot_object_circle.size(); n++)//円
	{
		layer_bot_object_circle[n].Update();
	}

	//mid
	for (int n = 0; n != layer_mid_object_simple.size(); n++)//抽象
	{
		layer_mid_object_simple[n].Update();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Update();
	}

	//top
	for (int n = 0; n != layer_top_object_simple.size(); n++)//抽象
	{
		layer_top_object_simple[n].Update();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)//円
	{
		layer_top_object_circle[n].Update();
	}
}

//全てのレイヤーを描写
void DiploidEngineLayer::DrawLayerObject()
{
	//bot
	for (int n = 0; n != layer_bot_object_simple.size(); n++)//抽象
	{
		layer_bot_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_bot_object_circle.size(); n++)//円
	{
		layer_bot_object_circle[n].Draw();
	}

	//mid
	for (int n = 0; n != layer_mid_object_simple.size(); n++)//抽象
	{
		layer_mid_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)//円
	{
		layer_mid_object_circle[n].Draw();
	}

	//top
	for (int n = 0; n != layer_top_object_simple.size(); n++)//抽象
	{
		layer_top_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)//円
	{
		layer_top_object_circle[n].Draw();
	}
}


//抽象プッシュ
void DiploidEngineLayer::PushBackTopObject_simple(DiploidEngineObject object)
{
	layer_top_object_simple.push_back(object);//レイヤーにオブジェクトを追加
}

void DiploidEngineLayer::PushBackMidObject_simple(DiploidEngineObject object)
{
	layer_mid_object_simple.push_back(object);//レイヤーにオブジェクトを追加
}

void DiploidEngineLayer::PushBackBotObject_simple(DiploidEngineObject object)
{
	layer_bot_object_simple.push_back(object);//レイヤーにオブジェクトを追加
}


//円プッシュ
void DiploidEngineLayer::PushBackTopObject_circle(DiploidCircle object)
{
	layer_top_object_circle.push_back(object);//レイヤーにオブジェクトを追加
}

void DiploidEngineLayer::PushBackMidObject_circle(DiploidCircle object)
{
	layer_mid_object_circle.push_back(object);//レイヤーにオブジェクトを追加
}

void DiploidEngineLayer::PushBackBotObject_circle(DiploidCircle object)
{
	layer_bot_object_circle.push_back(object);//レイヤーにオブジェクトを追加
}

//円ポップ
void DiploidEngineLayer::PopBackTopObject_circle(int object_number)
{
	layer_top_object_circle.erase(layer_top_object_circle.begin() + (object_number));//レイヤーからオブジェクトを削除
}

void DiploidEngineLayer::PopBackMidObject_circle(int object_number)
{
	layer_mid_object_circle.erase(layer_mid_object_circle.begin() + (object_number));//レイヤーからオブジェクトを削除
}

void DiploidEngineLayer::PopBackBotObject_circle(int object_number)
{
	layer_bot_object_circle.erase(layer_bot_object_circle.begin() + (object_number));//レイヤーからオブジェクトを削除
}

//抽象アプデ
void DiploidEngineLayer::UpdateLayerObject_simple()
{
	for (int n = 0; n != layer_bot_object_simple.size(); n++)
	{
		layer_bot_object_simple[n].Update();
	}

	for (int n = 0; n != layer_mid_object_simple.size(); n++)
	{
		layer_mid_object_simple[n].Update();
	}

	for (int n = 0; n != layer_top_object_simple.size(); n++)
	{
		layer_top_object_simple[n].Update();
	}
}

//抽象描写
void DiploidEngineLayer::DrawLayerObject_simple()
{
	for (int n = 0; n != layer_bot_object_simple.size(); n++)
	{
		layer_bot_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_simple.size(); n++)
	{
		layer_mid_object_simple[n].Draw();
	}

	for (int n = 0; n != layer_top_object_simple.size(); n++)
	{
		layer_top_object_simple[n].Draw();
	}
}

//円アプデ
void DiploidEngineLayer::UpdateLayerObject_circle()
{
	for (int n = 0; n != layer_bot_object_circle.size(); n++)
	{
		layer_bot_object_circle[n].Update();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Update();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)
	{
		layer_top_object_circle[n].Update();
	}
}

//円描写
void DiploidEngineLayer::DrawLayerObject_circle()
{
	for (int n = 0; n != layer_bot_object_circle.size(); n++)
	{
		layer_bot_object_circle[n].Draw();
	}

	for (int n = 0; n != layer_mid_object_circle.size(); n++)
	{
		layer_mid_object_circle[n].Draw();
	}

	for (int n = 0; n != layer_top_object_circle.size(); n++)
	{
		layer_top_object_circle[n].Draw();
	}
}