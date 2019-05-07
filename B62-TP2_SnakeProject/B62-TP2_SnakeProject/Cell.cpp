#include "Cell.h"


size_t Cell::WIDTH{ 10 };
size_t Cell::HEIGHT{ 10 };
size_t Cell::INDEX{ 0 };

//****CONSTRUCTEURS****
Cell::Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height)
	: mCoords{ Coordinates(x,y) }, mState{ CellState(state) } , mIndex{ Cell::INDEX }
{
	Cell::INDEX++;
	if (width != Cell::WIDTH) {
		Cell::setWidth(width);
	}
	if (height != Cell::HEIGHT) {
		Cell::setHeight(height);
	}
}

Cell::Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state)
: Cell(x,y,state,1,1)
{
}

Cell::Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y)
	: Cell(x,y, CellState::empty)
{
}

Cell::Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, size_t width, size_t height)
	: Cell(x,y, CellState::empty,width,height)
{
}

Cell::Cell(CellState::CellState_t state)
: Cell( 0 , 0 , state )
{
}

//****FIN CONSTRUCTEURS****

//****METHODES****
	//---METHODES PUBLIC---

CellState Cell::getState()
{
	return this->mState;
}

Coordinates Cell::getCoords()
{
	return this->mCoords;
}

size_t Cell::getWidth()
{
	return Cell::WIDTH;
}

size_t Cell::getHeight()
{
	return Cell::HEIGHT;
}

void Cell::setState(CellState::CellState_t state)
{
	this->mState.setState(state);
}

void Cell::setCoords(Coordinates::coordinate_t x, Coordinates::coordinate_t y)
{
	this->mCoords.setCoords(x, y);
}
	//---FIN METHODES PUBLIC---

	//---METHODES PRIVEE---

void Cell::setWidth(size_t width)
{
	Cell::WIDTH = width;
}
void Cell::setHeight(size_t height)
{
	Cell::HEIGHT = height;
}
	//---FIN METHODES PRIVEE---

//****FIN METHODES****
