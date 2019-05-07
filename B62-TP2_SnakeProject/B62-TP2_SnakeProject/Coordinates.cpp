#include "coordinates.h"

//****CONSTRUCTEURS****

Coordinates::Coordinates(coordinate_t x, coordinate_t y)
	: Coordinates::Coordinates(x,y,true)
{
}

Coordinates::Coordinates(bool valid)
	: Coordinates::Coordinates(0, 0, valid)
{
}

Coordinates::Coordinates(coordinate_t x, coordinate_t y, bool valid)
	: mX {x}, mY{y}, mValid{valid}
{
}

//****FIN CONSTRUCTEURS****

//****METHODES****
	//---METHODES PUBLIC---

Coordinates::coordinate_t Coordinates::getX()
{
	return this->mX;
}

Coordinates::coordinate_t Coordinates::getY()
{
	return this->mY;
}

bool Coordinates::isValid()
{
	return this->mValid;
}

void Coordinates::setX(coordinate_t x)
{
	this->mX = x;
}

void Coordinates::setY(coordinate_t y)
{
	this->mY = y;
}

void Coordinates::setCoords(coordinate_t x, coordinate_t y)
{
	this->setX(x); this->setY(y);
}

void Coordinates::setValid(bool valid)
{
	this->mValid = valid;
}

	//---FIN METHODES PUBLIC---	

	//---METHODES PRIVEE---

	//---FIN METHODES PRIVEE---

//****FIN METHODES****
