#include "SnakeFSM.h"

SnakeFSM::SnakeFSM()
{
	initializeFSM();
}


SnakeFSM::~SnakeFSM()
{
}

void SnakeFSM::initializeFSM() {
	initializeStateFSM();
	initiliazeStateTransitions();
	this->initialState = *this->welcome;
	this->currentState = *this->welcome;
}

void SnakeFSM::initializeStateFSM() {
	addState(welcome);
	addState(options);
	addState(start);
	addState(instructions);
	addState(pause);
	addState(onGame);
	addState(quit);
	addState(ext);
	addState(gameOver);
}

void SnakeFSM::initiliazeStateTransitions() {

	for (unsigned int state = 0; state < getStateList().size(); state++) {
		switch (state) {
		case 0:
			welcome->addTransition(qWelcome);
			qWelcome->setNextState(quit);
			welcome->addTransition(oWelcome);
			oWelcome->setNextState(options);
			welcome->addTransition(sWelcome);
			sWelcome->setNextState(start);
			break;
		case 1:
			options->addTransition(escapeOpt);
			escapeOpt->setNextState(welcome);
			options->addTransition(iOpt);
			iOpt->setNextState(instructions);
			break;
		case 2:
			start->addTransition(enterStart);
			enterStart->setNextState(onGame);
			break;
		case 3:
			instructions->addTransition(escapeInst);
			escapeInst->setNextState(options);
			instructions->addTransition(qInst);
			qInst->setNextState(quit);
			break;
		case 4:
			pause->addTransition(ePause);
			ePause->setNextState(welcome);
			pause->addTransition(qPause);
			qPause->setNextState(quit);
			pause->addTransition(enterPause);
			enterPause->setNextState(onGame);
			pause->addTransition(rPause);
			rPause->setNextState(onGame);
			pause->addTransition(aPause);
			aPause->setNextState(welcome);
			break;
		case 5:
			onGame->addTransition(escapeGame);
			escapeGame->setNextState(pause);
			onGame->addTransition(w);
			w->setNextState(onGame);
			onGame->addTransition(a);
			a->setNextState(onGame);
			onGame->addTransition(s);
			s->setNextState(onGame);
			onGame->addTransition(d);
			d->setNextState(onGame);
			onGame->addTransition(up);
			up->setNextState(onGame);
			onGame->addTransition(dwn);
			dwn->setNextState(onGame);
			onGame->addTransition(lft);
			lft->setNextState(onGame);
			onGame->addTransition(rgt);
			rgt->setNextState(onGame);
			onGame->addTransition(space);
			space->setNextState(onGame);
			onGame->addTransition(dead);
			dead->setNextState(gameOver);
			break;
		case 6:
			quit->addTransition(yExit);
			yExit->setNextState(ext);
			quit->addTransition(escapeExit);
			escapeExit->setNextState(welcome);
			break;
		case 8:
			gameOver->addTransition(enterGameOver);
			enterGameOver->setNextState(welcome);
			gameOver->addTransition(qGameOver);
			qGameOver->setNextState(quit);
			gameOver->addTransition(aGameOver);
			aGameOver->setNextState(welcome);
			break;
		case 9:
			npt->addTransition(enterNpt);
			enterNpt->setNextState(welcome);
			npt->addTransition(escapeNpt);
			escapeNpt->setNextState(welcome);
			break;
		}
	}
}




