#pragma once
#include "DxLib.h"
#include <vector>
#include <string>

//�ύX�񐄏��}�N��
//���C���[�ԍ�(0�`4)
#define DIPLOID_LAYER_00 0//�R�}���hUI�̓����蔻��
#define DIPLOID_LAYER_01 1//�}�b�v�`�b�v�ƃv���C���[�̓����蔻��
#define DIPLOID_LAYER_02 2//�G�ƃv���C���[�̓����蔻��
#define DIPLOID_LAYER_03 3
#define DIPLOID_LAYER_04 4
#define DIPLOID_LAYER_05 5
#define DIPLOID_LAYER_06 6
#define DIPLOID_LAYER_07 7
#define DIPLOID_LAYER_08 8


//���}�N��(�_�C�X�v���O�����Ŏg�p)
#define OBJECT_NUMBER_POINT 0//�|�C���g
#define OBJECT_NUMBER_PLUS_BUTTON 1//�v���X�{�^��
#define OBJECT_NUMBER_MINUS_BUTTON 2//�}�C�i�X�{�^��
#define OBJECT_NUMBER_CUSTOM_NUMBER_BUTTON 3//�J�X�^���i���o�[�{�^��
#define OBJECT_NUMBER_CLEAR_BUTTON 4//�N���A�{�^��

//���t�֘A
//�G��
const int NEXT_DAY = 1;
const int NEXT_SEASON = 1;
const int SPRING_SEASON = 1;
const int RAINY_SEASON = 2;
const int SUMMER_SEASON = 3;
const int WINTER_SEASON = 4;

//��(��)
const int NEXT_MONTH = 1;
const int TANTOU_NO_TUKI = 1;
const int KOUTOU_NO_TUKI = 2;
const int NOUTOU_NO_TUKI = 3;

//��(��)
const int TANSEI_NO_TUKI = 4;
const int KOUSEI_NO_TUKI = 5;
const int NOUSEI_NO_TUKI = 6;

//��(��)
const int TANSEKI_NO_TUKI = 7;
const int KOUSEKI_NO_TUKI = 8;
const int NOUSEKI_NO_TUKI = 9;

//��(��)
const int TANHAKU_NO_TUKI = 10;
const int KOUPAKU_NO_TUKI = 11;
const int NOUHAKU_NO_TUKI = 12;


//��v�R�}���h�֘A
const int NO_COMMAND		  = 0;//�R�}���h�I��Ȃ�
const int CAMP_COMMAND		  = 1;//��c�R�}���h
const int INFORMATION_COMMAND = 2;//���R�}���h
const int MOVE_COMMAND		  = 3;//�ړ��R�}���h
const int PRODUCTION_COMMAND  = 4;//����R�}���h
const int RESEARCH_COMMAND	  = 5;//�����R�}���h
const int EXPLORE_COMMAND	  = 6;//�T���R�}���h


//�v���[���[�̌����Ă������
const int PLAYER_DIRECTION_UP = 0;//��
const int PLAYER_DIRECTION_DOWN = 1;//��
const int PLAYER_DIRECTION_LEFT = 2;//��
const int PLAYER_DIRECTION_RIGHT = 3;//�E
const int PLAYER_DIRECTION_LEFT_UP = 4;//����
const int PLAYER_DIRECTION_RIGHT_UP = 5;//�E��
const int PLAYER_DIRECTION_RIGHT_DOWN = 6;//�E��
const int PLAYER_DIRECTION_LEFT_DOWN = 7;//����

//�v���[���[�̈ړ����
const int PLAYER_WAIT = 0;//�ҋ@
const int PLAYER_WALK = 1;//���
const int PLAYER_RUN = 2;//����

//�X�e�[�^�X�ُ�֘A
const int STATUS_INJURY_LV1 = 0;//����LV1
const int STATUS_INJURY_LV2 = 1;//����LV2
const int STATUS_INJURY_LV3 = 2;//����LV3
const int STATUS_INJURY_LV4 = 3;//����LV4
const int STATUS_INJURY_LV5 = 4;//����LV5


//�^�O���\����
struct Tag
{
	int object_number;//�I�u�W�F�N�g�ԍ�
	int layer_number;//���C���[�ԍ�
	std::string name_tag;//�I�u�W�F�N�g��
};

//Push�֐��ȊO������
class DiploidEngineTag
{
private:
	std::vector<Tag> tag_vector;

public:
	DiploidEngineTag();
	~DiploidEngineTag() {};


	int GetNumber(int target);//tag_vector�̑O����target�Ԗڂ�object_number��Ԃ��܂��B
	std::string GetObjectName(int target);//tag_vector�̑O����target�Ԗڂ�object_name��Ԃ��܂��B

	int GetNumber_tag_vector(int object_number);//object_number�Ŏw�肵���z�񂪑O���牽�ԖڂȂ̂���Ԃ��܂��B
	int GetNameTag_tag_vector(std::string object_name);//object_name�Ŏw�肵���z�񂪑O���牽�ԖڂȂ̂���Ԃ��܂��B

	void SortOnObjectNumber();//object_number���ɏ����ɕ��בւ��܂��B

	//�ȉ��g�p�p�x�������Ȃ�ł��낤�֐�
	Tag GetTag_target(int target);//tag_vector�̑O����target�Ԗڂ�tag��Ԃ��܂��B
	Tag GetTag_object_number(int object_number);//object_number�Ŏw�肵���z�������o������tag��Ԃ��܂��B
	Tag GetTag_name_tag(std::string object_name);//object_name�Ŏw�肵���z�������o������tag��Ԃ��܂��B

	int FindOnTagVector(Tag tag);//tag_vector����tag������o���O���牽�ԖڂȂ̂���Ԃ��܂��B

	void Push(Tag tag);//�^�O��o�^���܂��B

	void Destory_target(int target);//tag_vector�̑O����target�Ԗڂ�Tag��폜���܂��B
	void Destory_object_number(int object_number);//tag_vector�̒�����object_number������o���폜���܂��B
	void Destory_name_tag(std::string object_name);//tag_vector�̒�����object_name������o���폜���܂��B

};