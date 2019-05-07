#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Cell.h"
class Model
{
public:
	Model() = default;
	~Model() = default;
	
	void createUniverse();
	std::vector<std::vector<Cell>> universe;

	void initiateVector();

private:

};
#endif
