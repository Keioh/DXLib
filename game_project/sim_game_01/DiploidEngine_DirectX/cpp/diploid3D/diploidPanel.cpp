#include "diploid3D/diploidPanel.h"

DiploidPanel::DiploidPanel()
{
	//���_���W
	vertex[0].pos = VGet(-1, 1, 0);//����
	vertex[1].pos = VGet(1, 1, 0);//�E��
	vertex[2].pos = VGet(-1 , -1,0);//����
	vertex[3].pos = VGet(-1, -1,0);//����
	vertex[4].pos = VGet(1, 1, 0);//�E��
	vertex[5].pos = VGet(1, -1, 0);//�E��

	//�@��
	vertex[0].norm = VGet(0, 0, -1);//����
	vertex[1].norm = VGet(0, 0, -1);//����
	vertex[2].norm = VGet(0, 0, -1);//����
	vertex[3].norm = VGet(0, 0, -1);//����
	vertex[4].norm = VGet(0, 0, -1);//����
	vertex[5].norm = VGet(0, 0, -1);//����

	//�g�U��
	vertex[0].dif = GetColorU8(255, 255, 255, 255);//����
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);

	//���ˌ�
	vertex[0].spc = GetColorU8(255, 255, 255, 255);//����
	vertex[1].spc = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(255, 255, 255, 255);
	vertex[4].spc = GetColorU8(255, 255, 255, 255);
	vertex[5].spc = GetColorU8(255, 255, 255, 255);

	//�摜���W
	vertex[0].u = 0.0f;//����
	vertex[0].v = 0.0f;
	vertex[1].u = 1.0f;//�E��
	vertex[1].v = 0.0f;
	vertex[2].u = 0.0f;//����
	vertex[2].v = 1.0f;
	vertex[3].u = 0.0f;//����
	vertex[3].v = 1.0f;
	vertex[4].u = 1.0f;//�E��
	vertex[4].v = 0.0f;
	vertex[5].u = 1.0f;//�E��
	vertex[5].v = 1.0f;

	//�T�u�摜���W
	vertex[0].su = 0.0f;//����
	vertex[0].sv = 0.0f;
	vertex[1].su = 0.0f;//�E��
	vertex[1].sv = 0.0f;
	vertex[2].su = 0.0f;//����
	vertex[2].sv = 0.0f;
	vertex[3].su = 0.0f;//����
	vertex[3].sv = 0.0f;
	vertex[4].su = 0.0f;//�E��
	vertex[4].sv = 0.0f;
	vertex[5].su = 0.0f;//�E��
	vertex[5].sv = 0.0f;
}

void DiploidPanel::Load(const char* path)
{
	object.image.Load(path);
}

void DiploidPanel::Init(VECTOR size)
{
	//���_���W
	vertex[0].pos = VGet(-1 * size.x, 1 * size.y, 0 + size.z);//����
	vertex[1].pos = VGet(1 * size.x, 1 * size.y, 0 + size.z);//�E��
	vertex[2].pos = VGet(-1 * size.x, -1 * size.y, 0 + size.z);//����
	vertex[3].pos = VGet(-1 * size.x, -1 * size.y, 0 + size.z);//����
	vertex[4].pos = VGet(1 * size.x, 1 * size.y, 0 + size.z);//�E��
	vertex[5].pos = VGet(1 * size.x, -1 * size.y, 0 + size.z);//�E��

	//�@��
	vertex[0].norm = VGet(0, 0, -1);//����
	vertex[1].norm = VGet(0, 0, -1);//����
	vertex[2].norm = VGet(0, 0, -1);//����
	vertex[3].norm = VGet(0, 0, -1);//����
	vertex[4].norm = VGet(0, 0, -1);//����
	vertex[5].norm = VGet(0, 0, -1);//����

	//�g�U��
	vertex[0].dif = GetColorU8(255, 255, 255, 255);//����
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);

	//���ˌ�
	vertex[0].spc = GetColorU8(255, 255, 255, 255);//����
	vertex[1].spc = GetColorU8(255, 255, 255, 255);
	vertex[2].spc = GetColorU8(255, 255, 255, 255);
	vertex[3].spc = GetColorU8(255, 255, 255, 255);
	vertex[4].spc = GetColorU8(255, 255, 255, 255);
	vertex[5].spc = GetColorU8(255, 255, 255, 255);

	//�摜���W
	vertex[0].u = 0.0f;//����
	vertex[0].v = 0.0f;
	vertex[1].u = 1.0f;//�E��
	vertex[1].v = 0.0f;
	vertex[2].u = 0.0f;//����
	vertex[2].v = 1.0f;
	vertex[3].u = 0.0f;//����
	vertex[3].v = 1.0f;
	vertex[4].u = 1.0f;//�E��
	vertex[4].v = 0.0f;
	vertex[5].u = 1.0f;//�E��
	vertex[5].v = 1.0f;

	//�T�u�摜���W
	vertex[0].su = 0.0f;//����
	vertex[0].sv = 0.0f;
	vertex[1].su = 0.0f;//�E��
	vertex[1].sv = 0.0f;
	vertex[2].su = 0.0f;//����
	vertex[2].sv = 0.0f;
	vertex[3].su = 0.0f;//����
	vertex[3].sv = 0.0f;
	vertex[4].su = 0.0f;//�E��
	vertex[4].sv = 0.0f;
	vertex[5].su = 0.0f;//�E��
	vertex[5].sv = 0.0f;
}

void DiploidPanel::Updata()
{
}

void DiploidPanel::Draw(bool draw)
{	
	SetCameraPositionAndTarget_UpVecY(VGet(1280 / 2, 720 / 2, -1000.0f), VGet(1280 / 2, 720 / 2, 0.1f));

	DrawPolygon3D(vertex, 2, object.image.handl, TRUE);

	//�O�p�`�̏���ۑ�
	triangle_one[0] = vertex[0].pos;
	triangle_one[1] = vertex[1].pos;
	triangle_one[2] = vertex[2].pos;

	triangle_two[0] = vertex[3].pos;
	triangle_two[1] = vertex[4].pos;
	triangle_two[2] = vertex[5].pos;

}

void DiploidPanel::Translate(VECTOR trans)
{
	translate = MGetTranslate(trans);

	for (int count = 0; count <= 5; ++count)
	{	
		translate_position[count] = VTransform(vertex[count].pos, translate);

		vertex[count].pos = translate_position[count];
	}
}

void DiploidPanel::Scale(VECTOR scale)
{
	DiploidPanel::scale = MGetScale(scale);

	for (int count = 0; count <= 5; ++count)
	{
		scale_position[count] = VTransform(vertex[count].pos, DiploidPanel::scale);

		vertex[count].pos = scale_position[count];
	}
}

void DiploidPanel::RotateX(float rotate)
{
	rotate_x = MGetRotX(rotate);

	for (int count = 0; count <= 5; ++count)
	{
		rotate_x_position[count] = VTransform(vertex[count].pos, rotate_x);

		vertex[count].pos = rotate_x_position[count];
	}
}

void DiploidPanel::RotateY(float rotate)
{
	rotate_y = MGetRotY(rotate);

	for (int count = 0; count <= 5; ++count)
	{
		rotate_y_position[count] = VTransform(vertex[count].pos, rotate_y);

		vertex[count].pos = rotate_y_position[count];
	}
}

void DiploidPanel::RotateZ(float rotate)
{
	rotate_z = MGetRotZ(rotate);

	for (int count = 0; count <= 5; ++count)
	{
		rotate_z_position[count] = VTransform(vertex[count].pos, rotate_z);

		vertex[count].pos = rotate_z_position[count];
	}
}