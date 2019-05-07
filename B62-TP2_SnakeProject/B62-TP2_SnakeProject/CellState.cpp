#include "CellState.h"


//****CONSTRUCTEURS****
CellState::CellState(CellState_t state)
	: mState{ state }
{
}
//****FIN CONSTRUCTEURS****

//****METHODES****
	//---METHODES PUBLIC---

CellState::CellState_t CellState::getState()
{
	return this->mState;
}

void CellState::setState(CellState_t state)
{
	this->mState = state;
}

	//---FIN METHODES PUBLIC---

	//---METHODES PRIVEE---

	//---FIN METHODES PRIVEE---

//****FIN METHODES****


