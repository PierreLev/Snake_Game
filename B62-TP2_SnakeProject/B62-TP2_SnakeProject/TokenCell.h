#ifndef TOKENcell_H
#define TOKENcell_H

#include "Cell.h"
class TokenCell :
	public Cell
{
public:
	TokenCell() = default;
	TokenCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, size_t tokenLevel);
	~TokenCell() = default;

//	void draw() override;
//	void set() override;
//	void tic() override;
	
private:
	size_t mLevel;
};

#endif // !TOKENcell_H



