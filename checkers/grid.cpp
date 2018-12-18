#include "grid.h"



Grid::Grid(Vector2 size)
{
	amountOfCellsInRow = 10;

	for (int x = 0; x < size.x; x += size.x / amountOfCellsInRow) {
		for (int y = 0; y < size.y; y += size.y / amountOfCellsInRow) {
			Cell* cell = new Cell();
			cell->position = Vector2(x, y);
			cell->size = Vector2(size.x / amountOfCellsInRow, size.y / amountOfCellsInRow);

			this->cells.push_back(cell);
		}
	}
}


Grid::~Grid()
{
}
