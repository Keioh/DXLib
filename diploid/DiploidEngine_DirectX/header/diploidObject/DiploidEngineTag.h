#pragma once
#include "DxLib.h"


#define DIPLOID_ENGINE_UI 0
#define DIPLOID_ENGINE_GAMEOBJECT 1
#define DIPLOID_ENGINE_MAP_HIT_OBJECT 2//�}�b�v�ƃL�����N�^�̃q�b�g���C���[
#define DIPLOID_ENGINE_PLAYER_ENEMY_HIT_OBJECT 3//PLAYER��ENEMY�̃q�b�g���C���[(��F�U������Ȃ�)

#define OBJECT_NUMBER_PLAYER_BODY 0//�{��(�U���q�b�g����Ɏg�p)
#define OBJECT_NUMBER_PLAYER_UP 1//��
#define OBJECT_NUMBER_PLAYER_LEFT 2//��
#define OBJECT_NUMBER_PLAYER_RIGHT 3//�E
#define OBJECT_NUMBER_PLAYER_DOWN 4//��
#define OBJECT_NUMBER_PLAYER_MAX OBJECT_NUMBER_PLAYER_DOWN + 1//PLAYER_DOWN�̐��l(�}�N���ǉ��łS�ȏ�ɂȂ�ꍇ�͂��̐��l�����������₷�B)


//���̂Ƃ���g��Ȃ�
class DiploidEngineTag
{
private:

public:

	//�^�O�o�^
	enum NAME
	{
		test
	};
};