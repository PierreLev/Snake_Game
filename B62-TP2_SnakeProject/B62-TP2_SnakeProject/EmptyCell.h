#pragma once
#include "Cell.h"

class EmptyCell :
	public Cell
{
public:
	EmptyCell() = default;
	EmptyCell(CellState::CellState_t state);
	~EmptyCell() = default;


	//void draw() override;
	//void set() override;
	//void tic() override;


};

