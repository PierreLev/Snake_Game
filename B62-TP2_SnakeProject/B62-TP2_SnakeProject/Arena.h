#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "SnakeCell.h"
#include "FoodCell.h"
#include "TokenCell.h"
#include "EmptyCell.h"
#include "Coordinates.h"
#include <bai>
#include "SnakeCell.h"
#include "WarpCell.h"

class Arena
{
public:
	using arenaChildren_t = std::vector<Cell*>;
	using Arena_t = std::vector<arenaChildren_t>;

	//Constructors Destructors
	Arena() = default;
	Arena(size_t width, size_t height);
	// Constructeur
	Arena(SizeInt const & worldSize, size_t ballCount = 10);
	Arena(size_t width, size_t height, size_t cellWidth, size_t cellHeight);
	Arena(size_t width, size_t height, size_t cellWidth, size_t cellHeight, size_t level);
	~Arena() = default;

	//void setDirection(int direction);
	void setSnake(SizeInt const & worldSize);
	void randomize();
	void randomizeWarp();
	void setWarp();
	void setFood();
	void addSnakeCell();
	void headToFood();


	void setDirection(int direction, float elapsedTime);

	//Init arena
	void voidArena();

	//Collision evaluations
	void collisionEval();

	//View function
	void drawChildren();

	//Children update functions
	void updateArena();

	//void tic(float elapsedTime);
/*
	void setArialFont(Font const & arialFont);*/
	// Mutateur aléatoire pour toutes les balles
	void tic(float elapsedTime);
	// Fonction d'affichage
	void draw(Surface & surface);

	/*void drawAccueil(Surface & surface);
	void drawDemarrer(Surface & surface);
	void drawInstructions(Surface & surface);
	void drawOptions(Surface & surface);
	void drawGameOver(Surface & surface);
	void drawQuit(Surface & surface);
	void drawPause(Surface & surface);*/

	// Mutateur du vecteur de gravité

	std::vector<SnakeCell> getSnake();
	std::vector<FoodCell> getFood();
	std::vector<WarpCell> getWarp();

	SizeInt getSize();
	
private:
	std::vector<SnakeCell> mSnakeCell;  // Ensemble de boule de snake
	std::vector<FoodCell> mFoodCell;    // Ensemble de balles
	std::vector<WarpCell> mWarpCell;           // Ensemble de warps
	SizeInt mSize;                      // Taille du monde
	Arena_t mArena;
	size_t mLevel;
	size_t mWidth;
	size_t mHeight;
	arenaChildren_t mChildren;
	float mWaitTime = 0.000001;
	float mWaitStarted = 0;

	bool istherefood = false;
	bool istherewarp = false;

	//Head serpent
	float mRadius{ 20.0f };                    // Rayon
	PointReal mPosition{ PointReal(200.0f,200.0f) };                // Position
	Color mColor{ Color::white };                       // Couleur


	//Setters Getters
		//getters
	Cell* getChildAt(size_t position);
	CellState::CellState_t getStateOfChild(size_t index);
	arenaChildren_t getChildrenAt(Coordinates coords);
	std::vector<CellState::CellState_t> getStateOfChildrenAt(Coordinates coords);
	std::vector<Coordinates> getCoordsChildren();
		//setters
	void setChildAt(Cell * cell, Coordinates coords);
		//Children update functions
		void addChild(Cell * cell);
		void addChildAtEnd(Cell * cell);
		void deleteChildAt(Coordinates coords);
		arenaChildren_t generateRandChildren(size_t nbChildren);
		Cell* getNewChild(CellState::CellState_t type);

	Arena_t newArena(size_t childrenWidth, size_t childrenHeigth);
	Arena::Arena_t emptyArena();
	bool isWaitFinished(float elapsedTime);
	void addWait(float elapsedTime);
};
#endif // !ARENA_H

