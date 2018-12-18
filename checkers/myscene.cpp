/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "grid.h"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	grid = new Grid();
	currentPiece = nullptr;

	myentity = new MyEntity();
	this->addChild(myentity);

	for (int i = blackPieces.size(); i <= 20 - 1; i++) {
		piece* blackpiece = new piece(0);
		blackPieces.push_back(blackpiece);
		this->addChild(blackpiece);
		std::cout << "someString" <<  std::endl;
	}

	for (int i = whitePieces.size(); i <= 20 - 1; i++) {
		piece* whitepiece = new piece(1);
		whitePieces.push_back(whitepiece);
		this->addChild(whitepiece);
	}
	
	mousePos =  Vector2(input()->getMouseX(), input()->getMouseY());


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
	this->removeChild(whitePieces[0]);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete blackPieces[0];
	delete whitePieces[0];
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
		
	//Check mouse position
	mousePos = Vector2(input()->getMouseX(), input()->getMouseY());

	if (input()->getMouse(0)) {
		//if(blackturn)
		for (int i = 0; i <= blackPieces.size()-1; i++) {
			Vector2 calculatedMinus = Vector2(mousePos.x - blackPieces[i]->position.x, mousePos.y - blackPieces[i]->position.y);
			float distance = sqrt((calculatedMinus.x * calculatedMinus.x) + (calculatedMinus.y * calculatedMinus.y));

			if (distance < blackPieces[i]->getRadius()) {
				blackPieces[i]->position = mousePos;
				currentPiece = blackPieces[i];
			}
		}
	}
	else if (input()->getMouseUp(0)) {
		Cell* currentCell = nullptr;

		for (int i = 0; i < this->grid->GetCellVector().size(); i++) {
			bool inRange = false;

			if (this->mousePos.x > this->grid->GetCellVector()[i]->position.x && this->mousePos.y > this->grid->GetCellVector()[i]->position.y) {
				if (this->mousePos.x < this->grid->GetCellVector()[i]->position.x + this->grid->GetCellVector()[i]->size.x
					&& this->mousePos.y < this->grid->GetCellVector()[i]->position.y + this->grid->GetCellVector()[i]->size.y) {
					inRange = true;
				}
			}

			if (inRange) {
				currentCell = this->grid->GetCellVector()[i];
			}
		}

		if (currentCell) {
			currentPiece->position = Vector2(currentCell->position.x + (currentCell->size.x / 2), currentCell->position.y + (currentCell->size.y / 2));
		}
	}
	
	if (input()->getMouse(0)) {
		//if(blackturn)
		for (int i = 0; i <= whitePieces.size() - 1; i++) {
			Vector2 calculatedMinus = Vector2(mousePos.x - whitePieces[i]->position.x, mousePos.y - whitePieces[i]->position.y);
			float distance = sqrt((calculatedMinus.x * calculatedMinus.x) + (calculatedMinus.y * calculatedMinus.y));

			if (distance < whitePieces[i]->getRadius()) {
				whitePieces[i]->position = mousePos;
				currentPiece = whitePieces[i];
			}
		}
	}
	else if (input()->getMouseUp(0)) {
		Cell* currentCell = nullptr;

		for (int i = 0; i < this->grid->GetCellVector().size(); i++) {
			bool inRange = false;

			if (this->mousePos.x > this->grid->GetCellVector()[i]->position.x && this->mousePos.y > this->grid->GetCellVector()[i]->position.y) {
				if (this->mousePos.x < this->grid->GetCellVector()[i]->position.x + this->grid->GetCellVector()[i]->size.x
					&& this->mousePos.y < this->grid->GetCellVector()[i]->position.y + this->grid->GetCellVector()[i]->size.y) {
					inRange = true;
				}
			}

			if (inRange) {
				currentCell = this->grid->GetCellVector()[i];
			}
		}

		if (currentCell) {
			currentPiece->position = Vector2(currentCell->position.x + (currentCell->size.x / 2), currentCell->position.y + (currentCell->size.y / 2));
		}
	}
}
