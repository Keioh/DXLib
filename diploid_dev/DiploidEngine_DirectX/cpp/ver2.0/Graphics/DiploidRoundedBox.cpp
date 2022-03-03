#include "ver2.0/Graphics/DiploidRoundedBox.h"

void DiploidRoundedBox::Init(VECTOR position, VECTOR size, unsigned int color, float roundness)
{
	_position = position;
	_size = size;
	_roundness = roundness;
	_color = color;

	box[0].Init(VGet(_position.x, _position.y + _roundness, _position.z),VGet(_roundness, _size.y - (_roundness * 2), _size.z), _color);
	box[1].Init(VGet(_position.x + _roundness, _position.y, _position.z), VGet(_size.x - (_roundness * 2), _roundness, _size.z), _color);
	box[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), VGet(_roundness + 1, _size.y - (_roundness * 2), _size.z), _color);
	box[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), VGet(_size.x - (_roundness * 2), _roundness + 1, _size.z), _color);
	box[4].Init(VGet(_position.x + _roundness - 1, _position.y + _roundness - 1, _position.z), VGet(_size.x - (_roundness * 2) + 2, _size.y - (_roundness * 2) + 2, _size.z), _color);

	circle[0].Init(VGet(_position.x + _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[1].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);
	circle[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);

	for (int count = 0; count != 5; count++)
	{
		box[count].SetFill(true);
	}

	return_size = VGet(_size.x + (_roundness * 2), _size.y + (_roundness * 2), _size.z);
}

void DiploidRoundedBox::Update()
{

}

void DiploidRoundedBox::Draw(bool debug, bool draw)
{	
	for (int count = 0; count != 4; count++)
	{
		circle[count].Draw(draw);
	}

	for (int count = 0; count != 5; count++)
	{
		box[count].Draw(draw);
	}
}


void DiploidRoundedBox::SetSize(VECTOR new_size)
{
	_size = new_size;

	box[0].Init(VGet(_position.x, _position.y + _roundness, _position.z), VGet(_roundness, _size.y - (_roundness * 2), _size.z), _color);
	box[1].Init(VGet(_position.x + _roundness, _position.y, _position.z), VGet(_size.x - (_roundness * 2), _roundness, _size.z), _color);
	box[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), VGet(_roundness + 1, _size.y - (_roundness * 2), _size.z), _color);
	box[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), VGet(_size.x - (_roundness * 2), _roundness + 1, _size.z), _color);
	box[4].Init(VGet(_position.x + _roundness - 1, _position.y + _roundness - 1, _position.z), VGet(_size.x - (_roundness * 2) + 2, _size.y - (_roundness * 2) + 2, _size.z), _color);

	circle[0].Init(VGet(_position.x + _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[1].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);
	circle[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);

	for (int count = 0; count != 5; count++)
	{
		box[count].SetFill(true);
	}


	return_size = VGet(_size.x + (_roundness * 2), _size.y + (_roundness * 2), _size.z);
}

void DiploidRoundedBox::SetRoundness(float new_roundness)
{
	_roundness = new_roundness;

	box[0].Init(VGet(_position.x, _position.y + _roundness, _position.z), VGet(_roundness, _size.y - (_roundness * 2), _size.z), _color);
	box[1].Init(VGet(_position.x + _roundness, _position.y, _position.z), VGet(_size.x - (_roundness * 2), _roundness, _size.z), _color);
	box[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), VGet(_roundness + 1, _size.y - (_roundness * 2), _size.z), _color);
	box[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), VGet(_size.x - (_roundness * 2), _roundness + 1, _size.z), _color);
	box[4].Init(VGet(_position.x + _roundness - 1, _position.y + _roundness - 1, _position.z), VGet(_size.x - (_roundness * 2) + 2, _size.y - (_roundness * 2) + 2, _size.z), _color);

	circle[0].Init(VGet(_position.x + _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[1].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);
	circle[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);

	for (int count = 0; count != 5; count++)
	{
		box[count].SetFill(true);
	}

	return_size = VGet(_size.x + (_roundness * 2), _size.y + (_roundness * 2), _size.z);
}

void DiploidRoundedBox::SetColor(unsigned int new_color)
{
	_color = new_color;

	box[0].Init(VGet(_position.x, _position.y + _roundness, _position.z), VGet(_roundness, _size.y - (_roundness * 2), _size.z), _color);
	box[1].Init(VGet(_position.x + _roundness, _position.y, _position.z), VGet(_size.x - (_roundness * 2), _roundness, _size.z), _color);
	box[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), VGet(_roundness + 1, _size.y - (_roundness * 2), _size.z), _color);
	box[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), VGet(_size.x - (_roundness * 2), _roundness + 1, _size.z), _color);
	box[4].Init(VGet(_position.x + _roundness - 1, _position.y + _roundness - 1, _position.z), VGet(_size.x - (_roundness * 2) + 2, _size.y - (_roundness * 2) + 2, _size.z), _color);

	circle[0].Init(VGet(_position.x + _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[1].Init(VGet(_position.x + _size.x - _roundness, _position.y + _roundness, _position.z), _roundness, _color, true);
	circle[2].Init(VGet(_position.x + _size.x - _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);
	circle[3].Init(VGet(_position.x + _roundness, _position.y + _size.y - _roundness, _position.z), _roundness, _color, true);

	for (int count = 0; count != 5; count++)
	{
		box[count].SetFill(true);
	}

	return_size = VGet(_size.x + (_roundness * 2), _size.y + (_roundness * 2), _size.z);
}


VECTOR DiploidRoundedBox::GetSize()
{
	return return_size = VGet(_size.x + (_roundness * 2), _size.y + (_roundness * 2), _size.z);
}