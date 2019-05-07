#include "SnakeCell.h"
#include "LogManager.h"
#include "Log.h"

SnakeCell::SnakeCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height) 
	: Cell(x, y, state, width, height) 
{
}
SnakeCell::SnakeCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y)
	: Cell(x, y, CellState::snake)
{
}

SnakeCell::SnakeCell(float radius, PointReal const & pos, Color const & color)
: mRadius{ radius }, mPosition(pos), mColor(color)
{
}
void SnakeCell::setSpeed(size_t s) {
	this->speed = s;
}

size_t SnakeCell::getSpeed() {
	return this->speed;
}

int SnakeCell::getDirection()
{
	return direction;
}

void SnakeCell::set(float radius, PointReal const & pos, Color const & color)
{
	mRadius = radius;
	mPosition = pos;
	mColor = color;
}


void SnakeCell::tic(float elaspedTime, SizeInt const & worldSize) {
	// Applique le vecteur de gravité
	if (direction == 0 && ((mPosition.x() + mRadius) < worldSize.width())) {
		mPosition.setX(mPosition.x() + speed);
	}
	else if (direction == 1 && ((mPosition.y() + mRadius) < worldSize.height())) {
		mPosition.setY(mPosition.y() + speed);
	}
	else if (direction == 2 && ((mPosition.x() - mRadius) >= 0))	{
		mPosition.setX(mPosition.x() - speed);
	}
	else if (direction == 3 && ((mPosition.y() - mRadius) >= 0) ){
		mPosition.setY(mPosition.y() - speed);
	}
	else {
		isdead = true;
		Log::getInstance().writeLog((size_t)LogManager::debug, "Collision avec un mur");
	}

}
void SnakeCell::drawing(Surface & surface) {
	surface.drawCircle(mPosition, mRadius, mColor);
}

void SnakeCell::setDirection(int newDirection)
{
	direction = newDirection;
}

PointReal SnakeCell::getPosition()
{
	return mPosition;
}

void SnakeCell::setPosition(PointReal newPos)
{
	mPosition = newPos;
}

float SnakeCell::getRadius()
{
	return mRadius;
}

Color SnakeCell::getColor()
{
	return mColor;
}

void SnakeCell::setIsDead()
{
	isdead = true;
}

bool SnakeCell::isDead()
{
	return this->isdead;
}

//void SnakeCell::draw()
//{
//}
//
//void SnakeCell::set()
//{
//}
//
//void SnakeCell::tic()
//{
//}
