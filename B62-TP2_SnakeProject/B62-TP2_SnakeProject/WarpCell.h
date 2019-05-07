#ifndef WARPCELL_H
#define WARPCELL_H

#include "Cell.h"
#include <bai>
#include <Point.h>
#include <random>

using namespace bai;

class WarpCell :
	public Cell
{
public:
	WarpCell();
	// Constructeur
	WarpCell(float radius, PointReal const & pos, Color const & color);
	//SnakeCell(float radius = 5.0f, PointReal const & pos = PointReal(), Color const & color = Color::white);
	WarpCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height);
	WarpCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y);
	~WarpCell() = default;

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

