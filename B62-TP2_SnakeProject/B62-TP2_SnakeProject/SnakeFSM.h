#ifndef SNAKEFSM_H
#define SNAKEFSM_H

#include "StateMachine.h";

class SnakeFSM : public StateMachine
{
public:
	SnakeFSM();
	~SnakeFSM();
	
private:
	//Fonctions pour initialiser le StateMachine 
	void initializeFSM();
	void initializeStateFSM();
	void initiliazeStateTransitions();

	//States
	State * welcome = new State("welcome");
	State * options = new State("options");
	State * instructions = new State("instructions");
	State * start = new State("start");
	State * onGame = new State("onGame");
	State * gameOver = new State("gameOver");
	State * pause = new State("pause");
	State * quit = new State("quit");
	State * ext = new State("exit");
	State * npt = new State("input");

	/*****************TRANSITIONS*******************/

	//Transition Welcome
	Transition * qWelcome = new Transition(InputManagerEvent::q);
	Transition * oWelcome = new Transition(InputManagerEvent::o);
	Transition * sWelcome = new Transition(InputManagerEvent::d);

	//Transition Options
	Transition * escapeOpt = new Transition(InputManagerEvent::a);
	Transition * iOpt = new Transition(InputManagerEvent::i);

	//Transition Start
	Transition * enterStart = new Transition(InputManagerEvent::enter);

	//Transition Instructions
	Transition * escapeInst = new Transition(InputManagerEvent::o);
	Transition * qInst = new Transition(InputManagerEvent::q);

	//Transition Pause
	Transition * ePause = new Transition(InputManagerEvent::e);
	Transition * qPause = new Transition(InputManagerEvent::q);
	Transition * rPause = new Transition(InputManagerEvent::r);
	Transition * aPause = new Transition(InputManagerEvent::a);
	Transition * enterPause = new Transition(InputManagerEvent::enter);

	//Transition OnGame
	Transition * escapeGame = new Transition(InputManagerEvent::esc);
	Transition * up = new Transition(InputManagerEvent::up);
	Transition * dwn = new Transition(InputManagerEvent::down);
	Transition * lft = new Transition(InputManagerEvent::left);
	Transition * rgt = new Transition(InputManagerEvent::right);
	Transition * space = new Transition(InputManagerEvent::space);
	Transition * w = new Transition(InputManagerEvent::w);
	Transition * a = new Transition(InputManagerEvent::a);
	Transition * s = new Transition(InputManagerEvent::s);
	Transition * d = new Transition(InputManagerEvent::d);
	Transition * dead = new Transition(InputManagerEvent::Dead);

	//Transition Exit
	Transition * escapeExit = new Transition(InputManagerEvent::a);
	Transition * yExit = new Transition(InputManagerEvent::o);

	//Transition GameOver
	Transition * enterGameOver = new Transition(InputManagerEvent::enter);
	Transition * qGameOver = new Transition(InputManagerEvent::q);
	Transition * aGameOver = new Transition(InputManagerEvent::a);

	//Transition input
	Transition * enterNpt = new Transition(InputManagerEvent::enter);
	Transition * escapeNpt = new Transition(InputManagerEvent::esc);
};

#endif SNAKEFSM_H

