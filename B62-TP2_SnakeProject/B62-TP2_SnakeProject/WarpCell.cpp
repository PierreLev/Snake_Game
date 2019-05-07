#include "WarpCell.h"



WarpCell::WarpCell()
{
}


WarpCell::WarpCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height)
	: Cell(x, y, state, width, height)
{
}

WarpCell::WarpCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y)
	: Cell(x, y, CellState::snake)
{
}

WarpCell::WarpCell(float radius, PointReal const & pos, Color const & color)
	: mRadius{ radius }, mPosition(pos), mColor(color)
{
}

void WarpCell::set(float radius, PointReal const & pos, Color const & color)
{
	mRadius = radius;
	mPosition = pos;
	mColor = color;
}

void WarpCell::randomize(SizeInt sizeWorld)
{
	float width{ float(sizeWorld.width()) }, height{ float(sizeWorld.height()) };


	mPosition.randomize(mRadius, width - mRadius, mRadius, height - mRadius);
	mColor.randomize(128, 255, true);
}


void WarpCell::drawing(Surface & surface) {
	//surface.drawCircle(mPosition, mRadius, mColor);
	surface.drawRectangle(mPosition, SizeInt(10, 10), 0, mColor);
}

PointReal WarpCell::getPosition()
{
	return mPosition;
}

void WarpCell::setPosition(PointReal newPos)
{
	mPosition = newPos;
}

// Implémentation des fonctions
float WarpCell::randomValue(float minVal, float maxVal)
{
	std::random_device randomDevice;
	std::default_random_engine randomEngine(randomDevice());
	return std::uniform_real_distribution<float>(minVal, maxVal)(randomEngine);
}

float WarpCell::getRadius()
{
	return mRadius;
}

