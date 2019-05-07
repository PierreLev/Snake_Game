#ifndef FOODCELL_H
#define FOODCELL_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>
#include <random>

using namespace bai;

class FoodCell :
	public Cell
{
public:
	FoodCell();
	// Constructeur
	FoodCell(float radius, PointReal const & pos, Color const & color);
	//SnakeCell(float radius = 5.0f, PointReal const & pos = PointReal(), Color const & color = Color::white);
	FoodCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height);
	FoodCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y);
	~FoodCell() = default;

	// Mutateur global
	void set(float radius, PointReal const & pos, Color const & color);
	// Mutateur aléatoire
	void randomize(SizeInt sizeWorld);



	// Fonction d'affichage
	void drawing(Surface & surface);
	PointReal getPosition();
	void setPosition(PointReal newPos);

	// Fonction utilitaire
	float randomValue(float minVal, float maxVal);

	float getRadius();




private:
	//SnakeCell(float radius = 5.0f, PointReal const & pos = PointReal(), Color const & color = Color::white);
	float mRadius{ 10.0f };                    // Rayon
	PointReal mPosition;                // Position
	Color mColor{ Color::yellow };                       // Couleur

};

#endif // !FOODCELL_H

