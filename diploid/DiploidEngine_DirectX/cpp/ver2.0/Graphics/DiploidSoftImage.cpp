#include  "ver2.0/Graphics/DiploidSoftImage.h"

void  DiploidSoftImage::Load(const char* path)
{
	SetUseASyncLoadFlag(FALSE);

	soft_handle = LoadARGB8ColorSoftImage(path);

	GetSoftImageSize(soft_handle, &graphics_size_x, &graphics_size_y);

	SetUseASyncLoadFlag(TRUE);
}

int DiploidSoftImage::GetGraphicsHandle()
{
	//graphics_handle = CreateGraphFromSoftImage(soft_handle);

	return graphics_handle;
}

void DiploidSoftImage::CreatSoftImage(float x, float y)
{
	//�s�N�Z���̐F���
	int r, g, b, a;

	//�摜����f�[�^���擾
	for (int count_x = 0; count_x != graphics_size_x; count_x++)
	{
		for (int count_y = 0; count_y != graphics_size_y; count_y++)
		{

			GetPixelSoftImage(soft_handle, count_x, count_y, &r, &g, &b, &a);//�P�s�N�Z���̐F���擾

			//�ʒu���̎擾
			data_buffer.pos.x = count_x * x;
			data_buffer.pos.y = count_y * y;
			data_buffer.pos.z = 0.0f;


			//�F���̎擾
			data_buffer.r = r;
			data_buffer.g = g;
			data_buffer.b = b;
			data_buffer.a = a;

			//�f�[�^��push
			data.push_back(data_buffer);
		}
	}

	if (!data.empty())
	{
		//�I�u�W�F�N�g�̍쐬�B
		for (int count = 0; count != data.size(); count++)
		{
			box.Init(data[count].pos, VGet(x, y, 0.0f), GetColor(data[count].r, data[count].g, data[count].b));
			box.SetFill(true);

			image_box.push_back(box);
		}

		//for (int count = 0; count != data.size(); count++)
		{
			//DeleteSoftImage(data[count].soft_handle);//�\�t�g�摜�̃n���h�����폜
		}
	}
}

void DiploidSoftImage::CreatGraphicsImage(int x, int y)
{
	//�摜����f�[�^���擾
	for (int count_x = 0; count_x != graphics_size_x; count_x++)
	{
		for (int count_y = 0; count_y != graphics_size_y; count_y++)
		{

			GetPixelSoftImage(soft_handle, count_x, count_y, &r, &g, &b, &a);//�P�s�N�Z���̐F���擾

			//�F���̎擾
			data_buffer.r = r;
			data_buffer.g = g;
			data_buffer.b = b;
			data_buffer.a = a;


			//�ʒu���̎擾
			data_buffer.pos.x = count_x * x;
			data_buffer.pos.y = count_y * y;
			data_buffer.pos.z = 0.0f;

			//�傫�����̎擾
			data_buffer.size.x = x;
			data_buffer.size.y = y;
			data_buffer.size.z = 0.0f;


			//�f�[�^��push
			data.push_back(data_buffer);
		}
	}
	
	if (!data.empty())
	{
		//�O���t�B�b�N�n���h���̍쐬�B
		for (int count = 0; count != data.size(); count++)
		{
			data[count].soft_handle = MakeARGB8ColorSoftImage(x, y);//����̃\�t�g�摜�̍쐬

			FillSoftImage(data[count].soft_handle, data[count].r, data[count].g, data[count].b, data[count].a);//�\�t�g�摜�̐F��h��Ԃ�

			SetUseASyncLoadFlag(FALSE);
			data[count].image_handle = CreateGraphFromSoftImage(data[count].soft_handle);//�\�t�g�摜����C���[�W�n���h�����쐬
			SetUseASyncLoadFlag(TRUE);

			DeleteSoftImage(data[count].soft_handle);//�\�t�g�摜�̃n���h�����폜
		}
	}
}

void DiploidSoftImage::SetSoftPixelSize(float x, float y)
{
	if (!image_box.empty())
	{
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetSize(VGet(x, y, 0));
		}
	}
}

void DiploidSoftImage::SetSoftPosition(VECTOR pos)
{
	if (!image_box.empty())
	{
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetMoveSpeed(pos);
			image_box[count].MoveUpdate();

		}
	}
}

void DiploidSoftImage::SetSoftFill(bool fill)
{
	if (!image_box.empty())
	{
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetFill(fill);
		}
	}
}

void DiploidSoftImage::SetSoftThickness(float thickness)
{
	if (!image_box.empty())
	{
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].SetThickness(thickness);
		}
	}
}


void DiploidSoftImage::SetGraphicsScale(float x, float y)
{
	scale_x = x;
	scale_y = y;
}


void DiploidSoftImage::Draw(bool debug)
{

}

void DiploidSoftImage::SoftwareDraw(bool debug)
{
	if (!image_box.empty())
	{
		for (int count = 0; count != image_box.size(); count++)
		{
			image_box[count].Draw(true);
		}
	}
}

void DiploidSoftImage::GraphicsDraw(bool debug)
{
	if (!data.empty())
	{
		#pragma omp parallel for
		for (int count = 0; count != data.size(); count++)
		{
			DrawRotaGraph3(data[count].pos.x, data[count].pos.y, 
				0,0,
				scale_x, scale_y,
				angle,
				data[count].image_handle,
				TRUE,
				FALSE);
		}
	}

	if (debug == true)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "x = %d", graphics_size_x);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "y = %d", graphics_size_y);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "size = %d", data.size());
	}
}

void DiploidSoftImage::SoftImageDelet()
{
	if (!data.empty())
	{
		for (int count = 0; count != data.size(); count++)
		{
			DeleteSoftImage(data[count].soft_handle);
		}
	}
}