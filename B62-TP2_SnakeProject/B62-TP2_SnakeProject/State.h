#ifndef STATE_H
#define STATE_H
#include "Transition.h"
#include <list>
#include <string>


class State
{
public:

	State() = default;;
	State(std::string stateName);
	~State() = default;;

	Transition * isTransiting(InputManagerEvent & key);
	void addTransition(Transition * transition);
	std::string getStateName();
	void setStateName(std::string name);
	void showAllTransitions();
	std::list<Transition *> getTransitionList();

private:
	std::string mStateName;
	std::list<Transition *> mTransition;

};
#endif STATE_H
