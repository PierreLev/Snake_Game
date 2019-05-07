#include "StateMachine.h"
#include <iostream>
#include "LogManager.h"
#include "Log.h"
#include <string>

void StateMachine::initialize() {
	currentState = initialState;
}

void StateMachine::process(InputManagerEvent & key) {
	Transition * transition = currentState.isTransiting(key);

	std::string oldState = "";
	std::string newState = "";

	if (transition != nullptr) {
		oldState += currentState.getStateName();
		currentState = *transition->getNextState();
		newState += currentState.getStateName();
		
		if (oldState != newState) {
			Log::getInstance().writeLog((size_t)LogManager::trace, "Changement de State de " + oldState + " à " + newState);
		}
		//transition->action();
	}
	//currentState->action();
}

void StateMachine::addState(State * state) {
	mStateMachine.push_back(state);
}

void StateMachine::showAllStates() {
	for (State * state : mStateMachine) {
		std::cout << state->getStateName() << std::endl;
	}
}

std::list<State *> StateMachine::getStateList() {
	return mStateMachine;
}

