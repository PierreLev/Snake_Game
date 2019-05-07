#include "TokenCell.h"

TokenCell::TokenCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, size_t tokenLevel)
	: Cell(x, y, CellState::food) , mLevel{tokenLevel}
{
}

//void TokenCell::draw()
//{
//}
//
//void TokenCell::set()
//{
//}
//
//void TokenCell::tic()
//{
//}
