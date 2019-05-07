#include "View.h"
#include "Accueil.h"
#include "Instructions.h"
#include "Options.h"
#include "GameOver.h"
#include "Quit.h"
#include "Pause.h"
#include "Demarrer.h"
#include "Log.h"
#include "LogManager.h"

void View::move() {

}

float View::getPositionX()
{
	return positionX;
}

float View::getPositionY()
{
	return positionY;
}

void View::drawState(Surface & surface, std::string state, std::vector<SnakeCell> snake, std::vector<FoodCell> foods, std::vector<WarpCell> warps)
{

	surface.clear();
	if (state == "welcome") {
		this->drawAccueil(surface);
	}else if (state == "options") {
		this->drawOptions(surface);
	}else if (state == "instructions") {
		this->drawInstructions(surface);
	}else if (state == "start") {
		this->drawDemarrer(surface);
	}else if (state == "onGame") {
		this->drawArena(surface, snake, foods, warps);
	}else if (state == "gameOver") {
		this->drawGameOver(surface);
	}else if (state == "pause") {
		this->drawPause(surface);
	}else if (state == "quit") {
		this->drawQuit(surface);
	}else if (state == "exit") {
		Log::getInstance().writeLog((size_t)LogManager::trace, "Sorti du jeu sécuritaire");
		Log::getInstance().writeLog((size_t)LogManager::info, "---------------------------");
		exit(0);
	}
}

void View::drawAccueil(Surface & surface) {
	Accueil accueil;
	accueil.drawing(surface);
}

void View::drawInstructions(Surface & surface) {

	Instructions instructions;
	instructions.drawing(surface);
}

void View::drawOptions(Surface & surface) {

	Options options;
	options.drawing(surface);
}

void View::drawGameOver(Surface & surface)
{
	GameOver gameover;
	gameover.drawing(surface);
}

void View::drawQuit(Surface & surface)
{
	Quit quit;
	quit.drawing(surface);
}

void View::drawPause(Surface & surface)
{
	Pause pause;
	pause.drawing(surface);
}

void View::drawArena(Surface & surface, std::vector<SnakeCell> snakes, std::vector<FoodCell> foods, std::vector<WarpCell> warps ) {
	surface.clear(Color::black);
	Color gravColorFill(0, 0, 48);
	Color gravColorOutline(0, 0, 128);

	std::for_each(snakes.begin(), snakes.end(), [&surface](SnakeCell & snake) { snake.drawing(surface); });
	std::for_each(foods.begin(), foods.end(), [&surface](FoodCell & food) { food.drawing(surface); });
	std::for_each(warps.begin(), warps.end(), [&surface](WarpCell & warp) { warp.drawing(surface); });

}



void View::drawDemarrer(Surface & surface) {
	Demarrer demarrer;
	demarrer.drawing(surface);
}

