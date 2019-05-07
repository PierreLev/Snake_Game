#ifndef Cell_H
#define Cell_H

#include "Coordinates.h"
#include "CellState.h"
#include "Point.h"
#include "Surface.h"
#include "BasicApplicationInterface.h"
#include "Resources.h"
#include <Surface.h>
#include <BasicApplicationInterface.h>
#include <Resources.h>


class Cell
{
public:
	Cell() = default;
	Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height);
	Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state);
	Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y);
	Cell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, size_t width, size_t height);
	Cell(CellState::CellState_t state);
	~Cell() = default;

	CellState getState();
	Coordinates getCoords();
	size_t getWidth();
	size_t getHeight();

	void setState(CellState::CellState_t state);
	void setCoords(Coordinates::coordinate_t x, Coordinates::coordinate_t y);

	//virtual void draw() = 0;
	//virtual void set() = 0;
	//virtual void tic() = 0;

protected:
	CellState mState;
	Coordinates mCoords;
	size_t mIndex;
	
	static size_t WIDTH;
	static size_t HEIGHT;
	static size_t INDEX;

	static void setWidth(size_t width);
	static void setHeight(size_t height);
};

#endif // !CELL_H