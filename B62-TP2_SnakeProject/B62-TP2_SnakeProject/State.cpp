#include "State.h"
#include <iostream>

State::State(std::string stateName)
{
	setStateName(stateName);
}

Transition* State::isTransiting(InputManagerEvent & key) {
	for (Transition * transition : mTransition) {
		if (transition->isTransiting(key)) {
			return transition;
		}
	}
	return nullptr;
}

void State::addTransition(Transition * transition) {
	mTransition.push_back(transition);
}

std::string State::getStateName() {
	return mStateName;
}

void State::setStateName(std::string name) {
	mStateName = name;
}

void State::showAllTransitions(){
	for (Transition * transition : mTransition) {
		std::cout << (int)transition->getTransitionKey() << std::endl;
	}
}

std::list<Transition *> State::getTransitionList() {
	return mTransition;
}



