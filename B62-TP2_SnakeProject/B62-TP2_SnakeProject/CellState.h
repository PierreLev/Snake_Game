#ifndef CELLSTATE_H
#define CELLSTATE_H

class CellState
{
public:

	enum CellState_t { empty = 0, food, snake };

	CellState() = default;
	CellState(CellState_t state);
	~CellState() = default;

	CellState_t getState();
	void setState(CellState_t state);

private:
	CellState_t mState = empty;
};

#endif // !CELLSTATE_H