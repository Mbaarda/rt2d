#include "piece.h"



piece::piece() : Entity()
{
	this->addSprite("assets/black_piece.tga");

	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	this->radius = this->sprite()->width() / 2;
}


piece::~piece()
{
}

void piece::update(float deltaTime)
{
}
