#include "Controller.h"
#include <bai>                              // Inclusion complète de la librairie bai
#include "SnakeFSM.h"
#include "Log.h"
#include "LogManager.h"

using namespace std;
using namespace bai;



Controller::Controller(Arena & mArena)
	: mArena{ mArena }
{
}
Controller::Controller(Arena & mArena, SnakeFSM & snakeSM)
	: mArena{ mArena } , mStateMachine{ snakeSM }
{
}

// Pas de simulation
bool Controller::tic(float elapsedTime, InputManager & reader, Surface & surface) {

	//À séparer
	// Lecture des entrées
	//int direction;
	//bool quit{ reader.isKeyPressed(InputManager::Key::Q) };

	auto key = this->getSMKey(reader);

	this->mStateMachine.process(key);

	auto state = this->mStateMachine.currentState.getStateName();



	//if (reader.isKeyPressed(InputManager::Key::Left)) { mArena.setDirection(2); }							            // bouge à gauche
	//if (reader.isKeyPressed(InputManager::Key::Up)) { mArena.setDirection(3); }							            // bouge vers le haut
	//if (reader.isKeyPressed(InputManager::Key::Right)) { mArena.setDirection(0); }							            // bouge vers la droite
	//if (reader.isKeyPressed(InputManager::Key::Down)) { mArena.setDirection(1); }							            // bouge vers le bas
	
	if (state == "onGame") {
		std::string message = ""; 
		if (key == InputManagerEvent::nothing) {
			message = "Tic du jeu";
		} else if (key == InputManagerEvent::left) { 
			mArena.setDirection(2, elapsedTime); 
			message = "Nouvelle direction: left";
		} else if (key == InputManagerEvent::up) { 
			mArena.setDirection(3, elapsedTime);
			message = "Nouvelle direction: up";
		} else if (key == InputManagerEvent::right) { 
			mArena.setDirection(0, elapsedTime);
			message = "Nouvelle direction: right";
		} else if (key == InputManagerEvent::down) { 
			mArena.setDirection(1, elapsedTime);
			message = "Nouvelle direction: down";
		}

		if (message != "" || message != "Tic du jeu") {
			Log::getInstance().writeLog((size_t)LogManager::trace, message);
		} else {
			Log::getInstance().writeLog((size_t)LogManager::error, "Ce n'est pas normale, direction erronée");
		}
		this->mArena.tic(elapsedTime);
	}

	auto snake = this->mArena.getSnake();
	this->mView->drawState(surface, state, snake, this->mArena.getFood(), this->mArena.getWarp());
	if (snake.at(0).isDead() || (state == "welcome" && ! snake.at(0).isDead())) {
		auto smKey = InputManagerEvent::Dead;
		this->mStateMachine.process(smKey);
		this->mArena = this->newArena();
	}

	return true;
}



Arena Controller::newArena() {
	Arena arena(this->mArena.getSize() , 5);
	arena.setSnake(this->mArena.getSize() );
	return arena;
}
InputManagerEvent Controller::getSMKey(InputManager & reader) {
	bool onGame{ false };
	if (this->mStateMachine.currentState.getStateName() == "OnGame") { onGame = true; }
	InputManagerEvent smKey;
	if (reader.isKeyPressed(InputManager::Key::Left)) { smKey = InputManagerEvent::left; }						            // bouge à gauche
	else if (reader.isKeyPressed(InputManager::Key::Up)) { smKey = InputManagerEvent::up; }							            // bouge vers le haut
	else if (reader.isKeyPressed(InputManager::Key::Right)) { smKey = InputManagerEvent::right; }						            // bouge vers la droite
	else if (reader.isKeyPressed(InputManager::Key::Down)) { smKey = InputManagerEvent::down; }						            // bouge vers le bas
	else if (reader.isKeyPressed(InputManager::Key::W)) { 
		smKey = InputManagerEvent::w;
		if (onGame) { smKey = InputManagerEvent::up; }
	}						           
	else if (reader.isKeyPressed(InputManager::Key::A)) { 
		smKey = InputManagerEvent::a;
		if(onGame) { smKey = InputManagerEvent::left; }
	}
	else if (reader.isKeyPressed(InputManager::Key::S)) {
		smKey = InputManagerEvent::s;
		if (onGame) { smKey = InputManagerEvent::down; }
	}
	else if (reader.isKeyPressed(InputManager::Key::D)) { 
		smKey = InputManagerEvent::d;
		if (onGame) { smKey = InputManagerEvent::right; }
	}
	else if (reader.isKeyPressed(InputManager::Key::E)) { smKey = InputManagerEvent::e; 
	}						            
	else if (reader.isKeyPressed(InputManager::Key::I)) { smKey = InputManagerEvent::i; }
	else if (reader.isKeyPressed(InputManager::Key::O)) { smKey = InputManagerEvent::o;	}						          
	else if (reader.isKeyPressed(InputManager::Key::Q)) { smKey = InputManagerEvent::q; }							      
	else if (reader.isKeyPressed(InputManager::Key::R)) { smKey = InputManagerEvent::r; }						          
	else if (reader.isKeyPressed(InputManager::Key::Y)) { smKey = InputManagerEvent::y; }							        
	else if (reader.isKeyPressed(InputManager::Key::Escape)) { smKey = InputManagerEvent::esc; }						        
	else if (reader.isKeyPressed(InputManager::Key::Space)) { smKey = InputManagerEvent::space; }
	else if (reader.isKeyPressed(InputManager::Key::Enter)) { smKey = InputManagerEvent::enter; }
	else { smKey = InputManagerEvent::nothing; }

	return smKey;
}




	