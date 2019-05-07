#include "FoodCell.h"


FoodCell::FoodCell(){
}

FoodCell::FoodCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height)
	: Cell(x, y, state, width, height)
{
}

FoodCell::FoodCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y)
	: Cell(x, y, CellState::snake)
{
}



FoodCell::FoodCell(float radius, PointReal const & pos, Color const & color)
	: mRadius{ radius }, mPosition(pos), mColor(color)
{
}

void FoodCell::set(float radius, PointReal const & pos, Color const & color)
{
	mRadius = radius;
	mPosition = pos;
	mColor = color;
}

void FoodCell::randomize(SizeInt sizeWorld)
{
	float width{ float(sizeWorld.width()) }, height{ float(sizeWorld.height()) };


	mPosition.randomize(mRadius, width - mRadius, mRadius, height - mRadius);
	mColor.randomize(128, 255, true);
}


void FoodCell::drawing(Surface & surface) {
	surface.drawCircle(mPosition, mRadius, mColor);
}

PointReal FoodCell::getPosition()
{
	return mPosition;
}

void FoodCell::setPosition(PointReal newPos)
{
	mPosition = newPos;
}

// Implémentation des fonctions
float FoodCell::randomValue(float minVal, float maxVal)
{
	std::random_device randomDevice;
	std::default_random_engine randomEngine(randomDevice());
	return std::uniform_real_distribution<float>(minVal, maxVal)(randomEngine);
}

float FoodCell::getRadius()
{
	return mRadius;
}
