/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// draw grid
	
	gridwidth = 512;
	gridheight = 512;
	cellwidth = 51;
	cellheight = 51;	

	piece* blackpiece = new piece();
	blackPieces.push_back(blackpiece);
	this->addChild(blackpiece);

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	grid = new MyEntity();
	mousePos =  Vector2(Input().getMouseX(), Input().getMouseY());

	//myentity->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);


	/*int matrix[10][10] = {	
							0,1,0,1,0,1,0,1,0,1,
							1,0,1,0,1,0,1,0,1,0,
							0,1,0,1,0,1,0,1,0,1,
							1,0,1,0,1,0,1,0,1,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,2,0,2,0,2,0,2,0,2,
							2,0,2,0,2,0,2,0,2,0,
							0,2,0,2,0,2,0,2,0,2,
							2,0,2,0,2,0,2,0,2,0,			
	}*/
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(blackPieces[0]);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete blackPieces[0];
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	//if (mousex > left )
		
	//Check mouse position
	mousePos = Vector2(Input().getMouseX(), Input().getMouseY());


	//std::vector<Sprite*> spritebatch = grid->spritebatch();
	int counter = 0;
	for (int x = 0; x < gridwidth; x++) {
		for (int y = 0; y < gridheight; y++) {
			//Point2 pos = spritebatch[counter]->spriteposition;
			/*
			int halfwidth = cellwidth / 2;
			int halfheight = cellheight / 2;
			int left = pos.x - halfwidth;
			int right = pos.x + halfwidth;
			int top = pos.y - halfheight;
			int bottom = pos.y + halfheight;
			*/
			
		}
	}

	if (input()->getMouseDown(0)) {
		//if(blackturn)
		for (int i = 0; i <= blackPieces.size(); i++) {
			Vector2 dv = Vector2(mousePos.x, mousePos.y, blackPieces[i]->position.x,blackPieces[i]->position.y)
			if (true) {

			}
		}
	}
}
