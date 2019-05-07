#ifndef VIEW_H
#define VIEW_H
#include <vector>
#include "Point.h"
#include "SnakeCell.h"
#include "FoodCell.h"
#include "WarpCell.h"
#include <bai>                              // Inclusion complète de la librairie bai
#include <string>
extern float global_posiX;
extern float global_posiY;

class View
{
public:
	View() = default;
	~View() = default;

	void move();
	float getPositionX();
	float getPositionY();

	void drawState(Surface & surface, std::string state, std::vector<SnakeCell> snake, std::vector<FoodCell> foods, std::vector<WarpCell> warps);

	void drawAccueil(Surface & surface);
	void drawInstructions(Surface & surface);
	void drawOptions(Surface & surface);
	void drawGameOver(Surface & surface);
	void drawQuit(Surface & surface);
	void drawPause(Surface & surface);
	void drawArena(Surface & surface, std::vector<SnakeCell> snake, std::vector<FoodCell> foods, std::vector<WarpCell> warps);

	void drawDemarrer(Surface & surface);
	
private :
	float positionX{ 200 };
	float positionY{ 200 };

};

#endif // !VIEW_H