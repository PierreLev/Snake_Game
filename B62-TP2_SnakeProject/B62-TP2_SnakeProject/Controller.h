#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model.h"
#include "View.h"
#include "Arena.h"
#include "SnakeFSM.h"

class Controller
{
public:
	Controller() = default;
	~Controller() = default;
	// Constructeur
	Controller(Arena & mArena);
	Controller(Arena & mArena, SnakeFSM & snakeSM);


	View * mView;
	Arena & mArena;
	SnakeFSM mStateMachine;
	bool tic(float elapsedTime, InputManager & reader, Surface & surface);

	Arena newArena();

	InputManagerEvent getSMKey(InputManager & key);


};
#endif
