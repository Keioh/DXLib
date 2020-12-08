#include  "ver2.0/Graphics/DiploidSoftImage.h"

void  DiploidSoftImage::Load(const char* path)
{
	SetUseASyncLoadFlag(FALSE);

	soft_handle = LoadSoftImage(path);

	GetSoftImageSize(soft_handle, &graphics_size_x, &graphics_size_y);

	SetUseASyncLoadFlag(TRUE);
}

int DiploidSoftImage::GetGraphicsHandle()
{
	graphics_handle = CreateGraphFromSoftImage(soft_handle);

	return graphics_handle;
}

void DiploidSoftImage::CreatSoftImage(float x, float y)
{
	//�摜�T�C�Y���w��
	#pragma omp parallel for//���񏈗�
	for (int count_x = 0; count_x != graphics_size_x; count_x++)
	{
		#pragma omp parallel for//���񏈗�
		for (int count_y = 0; count_y != graphics_size_y; count_y++)
		{
			int r, g, b, a;
			DiploidBoxV2 box;

			GetPixelSoftImage(soft_handle, count_x, count_y, &r, &g, &b, &a);//�P�s�N�Z���̐F���擾

			box.Init(VGet(count_x * x, count_y * y, 0), VGet(x, y, 0), GetColor(r, g, b));//BOX��������
			box.SetFill(true);//�h��Ԃ�

			image_box.push_back(box);//BOX��ǉ�
		}
	}
}

void DiploidSoftImage::SetPixelSize(float x, float y)
{
	if (!image_box.empty())
	{
		#pragma omp parallel for//���񏈗�
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetSize(VGet(x, y, 0.0f));
		}
	}
}

void DiploidSoftImage::SetPosition(VECTOR pos)
{
	if (!image_box.empty())
	{
		#pragma omp parallel for//���񏈗�
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetPosition(pos);
		}
	}
}

void DiploidSoftImage::SetFill(bool fill)
{
	if (!image_box.empty())
	{
		#pragma omp parallel for//���񏈗�
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetFill(fill);
		}
	}
}

void DiploidSoftImage::Draw(bool debug)
{

}

void DiploidSoftImage::SoftwareDraw(bool debug)
{

	if (!image_box.empty())
	{
		#pragma omp parallel for//���񏈗�
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].Draw(true);
		}
	}	
	
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "Size X = %d", graphics_size_x);
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "Size Y = %d", graphics_size_y);
}