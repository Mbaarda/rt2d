/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{

	this->addSprite("assets/background.tga");
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	
}
