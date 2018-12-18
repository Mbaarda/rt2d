#include "piece.h"



piece::piece(int side) : Entity()
{
	if (side == 0) {
		this->addSprite("assets/black_piece.tga");
		
	}
	else  {
		this->addSprite("assets/white_piece.tga");
	}
	this->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);

	this->radius = 32;
}


piece::~piece()
{
}

void piece::update(float deltaTime)
{
}
