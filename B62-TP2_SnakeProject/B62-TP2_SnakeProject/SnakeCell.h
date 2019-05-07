#ifndef SNAKEcell_H
#define SNAKEcell_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class SnakeCell :
	public Cell
{
public:
	SnakeCell() = default;
	// Constructeur
	SnakeCell(float radius, PointReal const & pos, Color const & color);
	//SnakeCell(float radius = 5.0f, PointReal const & pos = PointReal(), Color const & color = Color::white);
	SnakeCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y, CellState::CellState_t state, size_t width, size_t height);
	SnakeCell(Coordinates::coordinate_t x, Coordinates::coordinate_t y);
	~SnakeCell() = default;

	void setSpeed(size_t s);
	size_t getSpeed();
	//std::string getDirection();
	int getDirection();

	// Mutateur global
	void set(float radius, PointReal const & pos, Color const & color);
	void init();
	// Fonction calculant un pas de simulation
	void tic(float elaspedTime, SizeInt const & worldSize);
	// Fonction d'affichage
	void drawing(Surface & surface);
	void setDirection(int direction);
	PointReal getPosition();
	void setPosition(PointReal newPos);
	float getRadius();
	Color getColor();
	void setIsDead();
	bool isDead();


	//mouvements
	//eatTablet
	//isAlive

	//void draw() override;
	//void set() override;
	//void tic() override;

private:
	//SnakeCell(float radius = 5.0f, PointReal const & pos = PointReal(), Color const & color = Color::white);
	float mRadius;                    // Rayon
	PointReal mPosition;                // Position
	Color mColor;                       // Couleur
	float speed{ 0.3 };
	bool isdead{ false };
	//std::string directionString;
	int direction;
	Coordinates mHead;
	Coordinates mTail;
	std::vector <Coordinates> mBody;
};

#endif // !SNAKEcell_H

