#include "diploidLayer\DiploidEngineLayer.h"

//全てのレイヤーを更新
void DiploidEngineLayer::UpdataLayerObject()
{
}

//全てのレイヤーを描写
void DiploidEngineLayer::DrawLayerObject()
{
}


//抽象プッシュ
void DiploidEngineLayer::PushBackTopObject_simple(DiploidEngineObject object)
{
}

void DiploidEngineLayer::PushBackMidObject_simple(DiploidEngineObject object)
{
}

void DiploidEngineLayer::PushBackBotObject_simple(DiploidEngineObject object)
{
}


//円プッシュ
void DiploidEngineLayer::PushBackTopObject_circle(DiploidCircle object)
{
}

void DiploidEngineLayer::PushBackMidObject_circle(DiploidCircle object)
{
}

void DiploidEngineLayer::PushBackBotObject_circle(DiploidCircle object)
{
}

//円ポップ
void DiploidEngineLayer::PopBackTopObject_circle(int object_number)
{
}

void DiploidEngineLayer::PopBackMidObject_circle(int object_number)
{
}

void DiploidEngineLayer::PopBackBotObject_circle(int object_number)
{
}

//抽象アプデ
void DiploidEngineLayer::UpdateLayerObject_simple()
{

}

//抽象描写
void DiploidEngineLayer::DrawLayerObject_simple()
{

}

//円アプデ
void DiploidEngineLayer::UpdateLayerObject_circle()
{

}

//円描写
void DiploidEngineLayer::DrawLayerObject_circle()
{

}