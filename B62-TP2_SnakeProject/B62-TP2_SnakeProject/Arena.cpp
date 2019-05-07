
#include "Log.h"
#include "LogManager.h"
#include "Arena.h"
#include "Demarrer.h"
#include <string>

//****CONSTRUCTEURS****

Arena::Arena(size_t width, size_t height)
	: Arena(width, height, 10, 10)
{
}

Arena::Arena(size_t width, size_t height, size_t cellWidth, size_t cellHeight)
	: Arena(width, height, cellWidth, cellHeight, 1)
{
}

Arena::Arena(size_t width, size_t height, size_t cellWidth, size_t cellHeight, size_t level)
	: mWidth{ width }, mHeight{ height }, mLevel{ level }
{
	mArena = this->newArena(cellWidth, cellHeight);
	Log::getInstance().writeLog((size_t)LogManager::trace, "Nouveau jeu");
}

Arena::Arena(SizeInt const & worldSize, size_t ballCount)
	: mSize(worldSize), mSnakeCell(ballCount)
{
}

//****FIN CONSTRUCTEURS****

//****METHODES****
	//---METHODES PUBLIC---

	
void Arena::setDirection(int direction, float elapsedTime){
	//if (this->isWaitFinished(elapsedTime)) {
		if (this->mSnakeCell.at(0).getDirection() == 0 && direction != 2) {
			this->mSnakeCell.at(0).setDirection(direction);
		}
		if (this->mSnakeCell.at(0).getDirection() == 1 && direction != 3) {
			this->mSnakeCell.at(0).setDirection(direction);
		}
		if (this->mSnakeCell.at(0).getDirection() == 2 && direction != 0) {
			this->mSnakeCell.at(0).setDirection(direction);
		}
		if (this->mSnakeCell.at(0).getDirection() == 3 && direction != 1) {
			this->mSnakeCell.at(0).setDirection(direction);
		}
		this->addWait(elapsedTime);
	//}
}

void Arena::voidArena()
{
	this->mArena = this->emptyArena();
}

void Arena::collisionEval()
{
	//X gauche droite de la t?te
	float boiteXSnakeG = mSnakeCell.at(0).getPosition().x() - mSnakeCell.at(0).getRadius();
	float boiteXSnakeD = mSnakeCell.at(0).getPosition().x() + mSnakeCell.at(0).getRadius();

	//Y haut bas de la t?te
	float boiteYSnakeH = mSnakeCell.at(0).getPosition().y() - mSnakeCell.at(0).getRadius();
	float boiteYSnakeB = mSnakeCell.at(0).getPosition().y() + mSnakeCell.at(0).getRadius();

	//Coordonn?es de la t?te

	//Boucle for avec tous les snakeCells
	for (int i = 2; i < mSnakeCell.size(); i++) {
		//X gauche droite
		float sG = mSnakeCell.at(i).getPosition().x() - mSnakeCell.at(i).getRadius();
		float sD = mSnakeCell.at(i).getPosition().x() + mSnakeCell.at(i).getRadius();

		//Y haut bas
		float sH = mSnakeCell.at(i).getPosition().y() - mSnakeCell.at(i).getRadius();
		float sB = mSnakeCell.at(i).getPosition().y() + mSnakeCell.at(i).getRadius();

		if (
			//coin droit haut snake
			((boiteXSnakeD > sG && boiteXSnakeD < sD) &&
			(boiteYSnakeH > sB && boiteYSnakeH < sH)) ||

			//coin gauche haut snake
				((boiteXSnakeG < sG && boiteXSnakeG > sD) &&
			(boiteYSnakeH > sB && boiteYSnakeH < sH)) ||

			//coin droite bas snake
					((boiteXSnakeD > sG && boiteXSnakeD < sD) &&
			(boiteYSnakeB > sH && boiteYSnakeH < sB)) ||

			//coin gauche bas snake
						((boiteXSnakeG > sG && boiteXSnakeG < sD) &&
			(boiteYSnakeB > sH && boiteYSnakeH < sB))
			)
		{
			Log::getInstance().writeLog((size_t)LogManager::debug, "Collision avec lui-meme");
			mSnakeCell.at(0).setIsDead();
		}


	}

}

	//---FIN METHODES PUBLIC---

	//---METHODES PRIVEE---

std::vector<Coordinates> Arena::getCoordsChildren()
{
	return std::vector<Coordinates>();
}

void Arena::addChild(Cell * cell)
{
	Coordinates coords = cell->getCoords();
	this->mArena[coords.getY()][coords.getX()] = cell;
}

Arena::Arena_t Arena::newArena(size_t childrenWidth, size_t childrenHeigth)
{
	Arena::Arena_t arena{ this->emptyArena() };

	// New snake
	SnakeCell snake = SnakeCell::SnakeCell(this->mWidth / 2, this->mHeight / 2);
	this->mChildren.push_back(&snake);
	this->addChild(&snake);

	Log::getInstance().writeLog((size_t)LogManager::trace, "Création du snake");

	// New food
	TokenCell token = TokenCell::TokenCell(this->mWidth / 3, this->mHeight / 3, this->mLevel);
	this->mChildren.push_back(&token);
	this->addChild(&token);

	return arena;
}

Arena::Arena_t Arena::emptyArena()
{
	Arena::Arena_t arena{};
	for (size_t y{ 0 }; y < this->mHeight; ++y) {
		Arena::arenaChildren_t line{};
		for (size_t x{ 0 }; x < this->mWidth; ++x) {
			line.push_back(new EmptyCell(CellState::empty));
		}
		arena.push_back(line);
	}
	return arena;
}
bool Arena::isWaitFinished(float elapsedTime) {
	if (this->mWaitStarted + this->mWaitTime >= elapsedTime) {
		return true;
	}else if (this->mWaitStarted + this->mWaitTime == this->mWaitTime) {
		return true;
	}
	return false;
}
void Arena::addWait(float elapsedTime) {
	this->mWaitStarted = elapsedTime;
}
	//---FIN METHODES PRIVEE---

//****FIN METHODES****

void Arena::tic(float elapsedTime) {
	for (int i = 0; i < this->mSnakeCell.size(); i++) {
		if (i != 0) {
			//Mouvement haut et bas
			if ((this->mSnakeCell.at(i - 1).getDirection() != this->mSnakeCell.at(i).getDirection()) &&
				(this->mSnakeCell.at(i - 1).getDirection() == 1 || this->mSnakeCell.at(i - 1).getDirection() == 3))
			{
				if (round(this->mSnakeCell.at(i - 1).getPosition().x()) == round(this->mSnakeCell.at(i).getPosition().x())) {
					this->mSnakeCell.at(i).setDirection(this->mSnakeCell.at(i - 1).getDirection());
				}
			}
			//Mouvement gauche et droite
			if ((this->mSnakeCell.at(i - 1).getDirection() != this->mSnakeCell.at(i).getDirection()) &&
				(this->mSnakeCell.at(i - 1).getDirection() == 0 || this->mSnakeCell.at(i - 1).getDirection() == 2))
			{
				if (round(this->mSnakeCell.at(i - 1).getPosition().y()) == round(this->mSnakeCell.at(i).getPosition().y())) {
					this->mSnakeCell.at(i).setDirection(this->mSnakeCell.at(i - 1).getDirection());
				}
			}
		}
	}
	std::for_each(this->mSnakeCell.begin(), this->mSnakeCell.end(), [this, elapsedTime](SnakeCell & snake) { snake.tic(elapsedTime, mSize); });

	if (istherefood == false) {
		setFood();
	}
	if (istherewarp == false) {
		setWarp();
	}
	headToFood();
	collisionEval();

}

void Arena::setSnake(SizeInt const & worldSize) {
	//std::for_each(this->mSnakeCell.begin(), this->mSnakeCell.end(), [&](SnakeCell & snake) { snake.init(); });
	int xTemp = mPosition.x();
	for (int i = 0; i < this->mSnakeCell.size(); i++) {
		if (i == 0) {
			this->mSnakeCell.at(i).set(mRadius, mPosition, Color::red);
		}
		else {
			this->mSnakeCell.at(i).set(mRadius, PointReal(xTemp - 2 * (mRadius + 1.0f), mPosition.y()), mColor);
			xTemp = xTemp - 2 * (mRadius + 1.0f);
		}
	}
}

void Arena::randomize()
{
	std::for_each(this->mFoodCell.begin(), this->mFoodCell.end(), [this](FoodCell & food) { food.randomize(mSize); });

}

void Arena::randomizeWarp()
{
	std::for_each(mWarpCell.begin(), mWarpCell.end(), [this](WarpCell & warp) { warp.randomize(mSize); });
}


void Arena::setWarp() {
	WarpCell warp;
	mWarpCell.push_back(warp);
	randomizeWarp();
	istherewarp = true;
}

void Arena::setFood() {
	FoodCell food;
	this->mFoodCell.push_back(food);
	randomize();
	istherefood = true;
}

void Arena::addSnakeCell() {
	SnakeCell lastSnake = this->mSnakeCell.at(this->mSnakeCell.size() - 1);
	PointReal posi = lastSnake.getPosition();
	float radius = lastSnake.getRadius();
	int direction = lastSnake.getDirection();
	Color color = lastSnake.getColor();
	

	Log::getInstance().writeLog((size_t)LogManager::trace, "Snake grandit");


	if (direction == 0) {
		float x = posi.x() - 2 * (radius + 1.0f);
		posi.setX(x);
	}
	else if (direction == 1) {
		float y = posi.y() - 2 * (radius + 1.0f);
		posi.setY(y);
	}
	else if (direction == 2) {
		float x = posi.x() + 2 * (radius + 1.0f);
		posi.setX(x);
	}
	else if (direction == 3) {
		float y = posi.y() + 2 * (radius + 1.0f);
		posi.setY(y);
	}

	SnakeCell newSnake(radius, posi, color);

	this->mSnakeCell.push_back(newSnake);


}

void Arena::headToFood() {
	//X gauche droite
	float boiteXSnakeG = this->mSnakeCell.at(0).getPosition().x() - this->mSnakeCell.at(0).getRadius();
	float boiteXSnakeD = this->mSnakeCell.at(0).getPosition().x() + this->mSnakeCell.at(0).getRadius();
	float boiteXFoodG = this->mFoodCell.at(0).getPosition().x() - this->mFoodCell.at(0).getRadius();
	float boiteXFoodD = this->mFoodCell.at(0).getPosition().x() + this->mFoodCell.at(0).getRadius();

	//Y haut bas
	float boiteYSnakeH = this->mSnakeCell.at(0).getPosition().y() - this->mSnakeCell.at(0).getRadius();
	float boiteYSnakeB = this->mSnakeCell.at(0).getPosition().y() + this->mSnakeCell.at(0).getRadius();
	float boiteYFoodH = this->mFoodCell.at(0).getPosition().y() - this->mFoodCell.at(0).getRadius();
	float boiteYFoodB = this->mFoodCell.at(0).getPosition().y() + this->mFoodCell.at(0).getRadius();

	if (((boiteXFoodG <= boiteXSnakeD) && (boiteYFoodB >= boiteYSnakeH)) &&
		((boiteXFoodD >= boiteXSnakeG) && (boiteYFoodB <= boiteYSnakeB)))
	{
		Log::getInstance().writeLog((size_t)LogManager::debug, "Collision avec bouffe");
		Log::getInstance().writeLog((size_t)LogManager::info, "Snake mange bouffe");
		this->mFoodCell.erase(this->mFoodCell.begin());
		istherefood = false;
		addSnakeCell();
	}
}


void Arena::draw(Surface & surface) {
	surface.clear(Color::black);
	Color gravColorFill(0, 0, 48);
	Color gravColorOutline(0, 0, 128);

	std::for_each(this->mSnakeCell.begin(), this->mSnakeCell.end(), [&surface](SnakeCell & snake) { snake.drawing(surface); });
	std::for_each(this->mFoodCell.begin(), this->mFoodCell.end(), [&surface](FoodCell & food) { food.drawing(surface); });
	std::for_each(this->mWarpCell.begin(), this->mWarpCell.end(), [&surface](WarpCell & warp) { warp.drawing(surface); });

}

std::vector<SnakeCell> Arena::getSnake()
{
	return this->mSnakeCell;
}

std::vector<FoodCell> Arena::getFood()
{
	return this->mFoodCell;
	;
}

std::vector<WarpCell> Arena::getWarp()
{
	return this->mWarpCell;
}

SizeInt Arena::getSize()
{
	return this->mSize;
}
