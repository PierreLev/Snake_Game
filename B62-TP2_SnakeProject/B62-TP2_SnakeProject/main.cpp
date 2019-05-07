#include "Utils.h"
#include <conio.h>
#include "View.h"
#include "Model.h"
#include "Controller.h"
#include "Log.h"
#include "LogManager.h"

// Point d'entrée du programme
int WinMain()
{
	Log::getInstance().writeLog((size_t)LogManager::info, "Ouverture de l'application");

	// Taille de la scène
	SizeInt worldSize(800, 600);

	// BAI
	BasicApplicationInterface app(worldSize.width(), worldSize.height(), "Snake Game");

	// Monde
	Arena arena(worldSize, 5);
	arena.setSnake(worldSize);

	//StateMachine
	SnakeFSM sm = SnakeFSM();

	// Contrôleur
	Controller controller(arena, sm);
	app.registerLoop(controller, &Controller::tic);
	app.run();
}