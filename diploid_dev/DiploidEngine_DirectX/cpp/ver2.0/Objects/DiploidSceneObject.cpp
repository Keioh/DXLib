#include "ver2.0/Objects/DiploidSceneObject.h"

void DiploidSceneObject::AddObject(DiploidImageV2 object)
{
	imageV2_map[object.GetName()] = object;
}

void DiploidSceneObject::AddObject(DiploidAnimation object, std::string name)
{
	anime_map[name] = object;
}