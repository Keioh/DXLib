#pragma once
#include <list>
#include <memory>
#include <unordered_map>
#include "DxLib.h"
#include "diploidApp\DiploidEngineMain.h"
#include "diploidObject\DiploidEngineObject.h"
#include "system\DiploidEngineMath.h"
#include "diploidUI/diploidUI.h"
#include "diploidSystem/diploidSystem.h"
#include "system/define.h"

#include "ver2.0/Graphics/DiploidCircleV2.h"
#include "ver2.0/Main/Collision.h"
#include "ver2.0/Main/Camera.h"
#include "ver2.0/Graphics/DiploidImageV2.h"
#include "ver2.0/Graphics/DiploidBoxV2.h"
#include "ver2.0/Graphics/DiploidSoftImage.h"
#include "ver2.0/Graphics/DiploidScreenGraphics.h"
#include "ver2.0/Graphics/DiploidStrings.h"
#include "diploidObject\DiploidCreator.h"

#include "diploidStandalone\standalone.h"


#include "ver2.0/Objects/LogoScene.h"
#include "ver2.0/Objects/TitleScene.h"
#include "ver2.0/Objects/GameScene.h"
#include "ver2.0/Objects/OptionScene.h"
#include "ver2.0/Objects/FileScene.h"

using namespace std;

class DiploidEngineApp : public DiploidEngineMain
{
private:
	LogoScene logo_scene;
	TitleScene title_scene;
	GameScene game_scene;
	OptionScene option_scene;
	FileScene file_scene;

public:
	void FileCreate(DiploidEngineApp* app);
	void OnceLoad(DiploidEngineApp* app);//��񂾂�����ǂݍ���
	void Load(DiploidEngineApp* app);//��񂾂��摜��ǂݍ���(�𑜓x��ύX�����ۂɂ��Ă΂�܂��B)
	void OnceInit(DiploidEngineApp* app);//��񂾂�����������
	void Init(DiploidEngineApp* app);//��񂾂��摜��������(�𑜓x��ύX�����ۂɂ��Ă΂�܂��B�ēǂݍ��ݎ��ɒl��ύX�������Ȃ��ꍇ��Updata()�֐��ŏ��������邱�ƁB)
	void Updata(DiploidEngineApp* app);//���[�v����(fps�ˑ�)
	void Draw(DiploidEngineApp* app);//�`��
	void Destory(DiploidEngineApp* app);//ver1.0�̋@�\�ł̃I�u�W�F�N�g�폜
	void End(DiploidEngineApp* app);//�Q�[���I�����̏���
};