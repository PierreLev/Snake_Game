#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class GameOver {
public:
	GameOver();
	~GameOver() = default;

	// Fonction d'affichage
	void drawing(Surface & surface);

private:

	//Image
	PointReal positionImage{ 0.0f, 10.0f };
	Image image1{ "gameover.png" };


	//Titre
	PointReal positionTitle{ 400.0f, 100.0f };
	Font blerp{ "blerp.ttf" };
	TextStyle title{ blerp, 100, Color::red, true };


	//Instructions
	PointReal positionInstruct{ 400.0f, 400.0f };
	Font arial{ "arial.ttf" };
	TextStyle text{ arial, 25, Color::white, true };
	std::string instructions{
	R"-(
Game Over

-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
	(A)							Retour à l'accueil
	(Q)							Quitter
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };



};

#endif // !GAMEOVER_H
