#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <list>


class StateMachine
{
public:
	StateMachine() = default;
	~StateMachine() = default;

	State initialState;
	State currentState;

	void process(InputManagerEvent & key);
	void addState(State * state);
	void showAllStates();
	std::list<State *> getStateList();


private: 
	std::list<State *> mStateMachine;
	void initialize();
};

#endif STATEMACHINE_H

