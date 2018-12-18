#pragma once
#include "vectorx.h"
#include <vector>

struct Cell {
	Vector2 position;
	Vector2 size;
};

class Grid
{
private:
	std::vector<Cell*> cells;

	int amountOfCellsInRow;
public:
	Grid(Vector2 size = Vector2(512,512));
	virtual ~Grid();
	
	std::vector<Cell*> GetCellVector() { return this->cells; };
};

