#ifndef TRANSITION_H
#define TRANSITION_H

#include "Event.h"
class State;


class Transition
{
public:
	Transition(InputManagerEvent mTransitionKey);
	~Transition() = default;

	bool isTransiting(InputManagerEvent const & key);
	State* getNextState();
	void setTransitionKey(InputManagerEvent transitionKey);
	InputManagerEvent getTransitionKey();
	void setNextState(State * state);
	
private:
	State * mNextState;
	InputManagerEvent mTransitionKey;
};

#endif TRANSITION_H