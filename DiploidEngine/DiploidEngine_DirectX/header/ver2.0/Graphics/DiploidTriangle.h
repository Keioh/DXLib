#pragma once
#include <string>
#include <list>
#include <math.h>
#include "DxLib.h"

using namespace std;

//�O�p�`�̒��_�f�[�^
struct TRIANGLE
{
	VECTOR point_one;//���_���̂P
	VECTOR point_two;//���_���̂Q
	VECTOR point_three;//���_���̂R
};

//2D�̉~�Ɋւ���N���X(�X�^���h�A���[���ȃN���X�Ƃ��Ď���)
class DiploidTriangle
{
private:
	string name;//�I�u�W�F�N�g�̖��O(��Ɍ�������Ƃ��Ɏg�p)
	int layer_number;//���C���[�̔ԍ�(��ɓ����蔻�莞�ɂǂ̑w�ɋ���̂����ʂ���̂Ɏg�p)
	int object_number;//�I�u�W�F�N�g�̔ԍ�

	TRIANGLE triangle_position;//�I�u�W�F�N�g�̈ʒu
	VECTOR position;//�I�u�W�F�N�g�̈ʒu
	VECTOR move_speed;//�I�u�W�F�N�g�̈ړ��X�s�[�h
	float move_angle;//�I�u�W�F�N�g�̈ړ�����
	float radius;//�~�̔��a(�����ASize)
	VECTOR center_pos;

	list<VECTOR> hit_points_list;//�������Ă���ꏊ�̈ʒu�B
	list<VECTOR>* hit_points_list_pointer;//hit_points_list�ւ̃|�C���^�[(�C�e���[�^�ł͂Ȃ�)
	list<VECTOR>::iterator hit_points_list_iterator = hit_points_list.begin();//hit_points_list�̃C�e���[�^

	unsigned int object_color;//�F
	bool object_fill;//�h��Ԃ�
	float object_thickness;//����
	float object_life;//����

	bool destory_flag = false;//�폜�t���O(true�̏ꍇ�A�폜�Ώۂ�)
	bool hit_flag = false;//�������Ă��邩�̃t���O
	bool main_camera = false;//���C���J�����̒ǂ��I�u�W�F�N�g���̃t���O

protected:

public:

	void Init(TRIANGLE pos, unsigned int color, float rotation = 0, bool fill = FALSE, float thickness = 1.0f);
	void MoveUpdate();//�ݒ肵���ړ����x�𔽉f���܂��B
	void Draw(bool draw = true, bool aa = true);//�~��`�悵�܂��B(draw��false�����邱�Ƃŕ`�悵�Ȃ�)

	void SetColor(unsigned int new_color);//�V�����F��ݒ肵�܂��B
	void SetPosition(TRIANGLE new_pos);//�V�����ʒu��ݒ肵�܂��B
	void SetRadius(float new_radius);//�V�������a��ݒ肵�܂��B
	void SetFill(bool new_fill);//�V���ɓh��Ԃ���ݒ肵�܂��B
	void SetThickness(float new_thickness);//�V���ɐ��̑�����ݒ肵�܂��B

	void SetName(string new_name);//�V���ɃI�u�W�F�N�g�̖��O��ݒ肵�܂��B
	void SetObjectNumber(int new_number);//�V�����I�u�W�F�N�g�ԍ���ݒ肵�܂��B
	void SetHitFlag(bool new_hit_flag);//�V�����q�b�g�t���O��ݒ肵�܂��B
	void SetMoveSpeed(VECTOR new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(3���w���)
	void SetMoveSpeed(float angle, float new_move_speed);//�V�����ړ����鑬�x��ݒ肵�܂��B(���W�A���p�w���)
	void SetLife(float new_life);//�V����������ݒ肵�܂��B
	void SetDestoryFlag(bool new_flag);//�V�����폜�t���O��ݒ肵�܂��B
	void SetMainCameraFlag(bool new_flag);//�V�������C���J�����t���O��ݒ肵�܂��B(Camera�֐��ȊO����̎g�p�͍T����)

	void AddLife(float add_val);//�����J�E���g�𑫂��܂��B
	void SubLife(float sub_val);//�����J�E���g�������܂��B
	
	TRIANGLE GetPosition();//���݂̈ʒu���擾���܂��B
	float GetRadius();//���݂̔��a���擾���܂��B
	float GetThickness();//���݂̐��̑������擾���܂��B
	unsigned int GetColor();//���݂̐F���擾���܂��B
	bool GetFill();//���݂̓h��Ԃ��̐ݒ���擾���܂��B
	VECTOR GetCenterPosition();//���݂̏d�S�𓾂܂��B

	string GetName();//���݂̃I�u�W�F�N�g�̖��O���擾���܂��B
	int GetObjectNumber();//���݂̃I�u�W�F�N�g�̔ԍ����擾���܂��B
	bool GetHitFlag();//���݂̃I�u�W�F�N�g�̃q�b�g�t���O���擾���܂��B
	VECTOR GetMoveSpeed();//���݂̃I�u�W�F�N�g�̈ړ����x���擾���܂��B
	float GetMoveAngle();//���݂̃I�u�W�F�N�g�̈ړ����Ă�����p���擾���܂��B(���W�A��)
	float GetLife();//���݂̃I�u�W�F�N�g�̎������擾���܂��B
	bool GetDestoryFlag();//���݂̍폜�t���O���擾���܂��B(true�ō폜�ΏۃI��)	
	bool GetMainCameraFlag();//���݂̃I�u�W�F�N�g�����C���J�����̑ΏۂɂȂ��Ă��邩�̃t���O���擾���܂��B

	size_t GetHitPointsVolume();//���݂̓������Ă���ꏊ�̑������擾���܂��B
	VECTOR GetHitPosition();//���݂̓������Ă���ꏊ�̈ʒu���擾���܂��B
	list<VECTOR>::iterator GetHitPointsListIterator(list<VECTOR>::iterator* pointer_to_iterator);//hit_points_list�̃C�e���[�^���擾���܂��B(�g�p�񐄏�:�C�e���[�^�w���)
	list<VECTOR>::iterator GetHitPointsListIterator();//�v���؁Fhit_points_list�̃C�e���[�^���擾���܂��B(�g�p�����F���S�ŁBlist<>::begin()�������l)
	list<VECTOR>* GetHitPointsListPointer();//hit_points_list�ւ̃|�C���^���擾���܂��B
};