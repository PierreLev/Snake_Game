#include "Transition.h"

Transition::Transition(InputManagerEvent mTransitionKey)
{
	setTransitionKey(mTransitionKey);
}

bool Transition::isTransiting(InputManagerEvent const & key) {
	return mTransitionKey == key;
}	

State* Transition::getNextState() {
	return mNextState;
}

void Transition::setNextState(State * state) {
	mNextState = state;
}

InputManagerEvent Transition::getTransitionKey() {
	return mTransitionKey;
}

void Transition::setTransitionKey(InputManagerEvent transitionKey) {
	mTransitionKey = transitionKey;
}

