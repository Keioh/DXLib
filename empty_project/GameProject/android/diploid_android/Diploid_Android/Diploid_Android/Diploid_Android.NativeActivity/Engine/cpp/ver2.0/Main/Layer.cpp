#include "ver2.0/Main/Layer.h"


void DiploidLayerV2::Update()
{
	if (!image_list.empty())
	{
		for (auto count = image_list.begin(); count != image_list.end(); ++count)
		{
			auto next_count = ++count;

			if (count->GetPosition().y < next_count->GetPosition().y)
			{
				buffer.SetAngle(count->GetAngle());//角度
				buffer.SetDestoryFlag(count->GetDestoryFlag());//削除フラグ
				buffer.SetHitFlag(count->GetHitFlag());//ヒットフラグ
				buffer.SetLife(count->GetLife());//寿命
				buffer.SetMainCameraFlag(count->GetMainCameraFlag());//メインカメラフラグ
				buffer.SetMoveSpeed(count->GetMoveSpeed());//移動速度
				buffer.SetName(count->GetName());//名前
				buffer.SetObjectNumber(count->GetObjectNumber());//オブジェクト番号
				buffer.SetPosition(count->GetPosition());//位置
				buffer.SetRotatePosition(count->GetRotatePosition());//回転軸の中心点
				buffer.SetScale(count->GetScale().x, count->GetScale().y);//スケール
				buffer.SetTurnFlag(count->GetTurnFlag());//反転フラグ

				count = image_list.insert(next_count, buffer);
				count = image_list.erase(--count);
			}
		}
	}
}

void DiploidLayerV2::Draw(bool draw)
{
	if (!image_list.empty())
	{
		for (auto& count : image_list)
		{
			count.Draw(draw);
		}
	}
}


list<DiploidImageV2>::iterator DiploidLayerV2::GetImageListIterator()
{
	return image_list_itr = image_list.begin();
}

list<DiploidImageV2>* DiploidLayerV2::GetImageListPointer()
{
	return &image_list;
}