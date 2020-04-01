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
				buffer.SetAngle(count->GetAngle());//�p�x
				buffer.SetDestoryFlag(count->GetDestoryFlag());//�폜�t���O
				buffer.SetHitFlag(count->GetHitFlag());//�q�b�g�t���O
				buffer.SetLife(count->GetLife());//����
				buffer.SetMainCameraFlag(count->GetMainCameraFlag());//���C���J�����t���O
				buffer.SetMoveSpeed(count->GetMoveSpeed());//�ړ����x
				buffer.SetName(count->GetName());//���O
				buffer.SetObjectNumber(count->GetObjectNumber());//�I�u�W�F�N�g�ԍ�
				buffer.SetPosition(count->GetPosition());//�ʒu
				buffer.SetRotatePosition(count->GetRotatePosition());//��]���̒��S�_
				buffer.SetScale(count->GetScale().x, count->GetScale().y);//�X�P�[��
				buffer.SetTurnFlag(count->GetTurnFlag());//���]�t���O

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