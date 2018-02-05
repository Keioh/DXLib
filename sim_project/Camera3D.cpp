#include "Camera3D.h"

void Camera3D::Set(VECTOR pos)
{
	//Œ»İ‚ÌˆÊ’u‚ğ•Û‘¶
	xF = pos.x;
	yF = pos.y;
	zF = pos.z;

	SetCameraPositionAndTarget_UpVecY(pos, VGet(0.0f, 1.0f, 0.0f));

}