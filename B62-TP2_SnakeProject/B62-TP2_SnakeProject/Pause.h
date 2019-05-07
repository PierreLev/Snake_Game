
#ifndef PAUSE_H
#define PAUSE_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class Pause {
public:
	Pause();
	~Pause() = default;

	// Fonction d'affichage
	void drawing(Surface & surface);

private:

	//Image
	PointReal positionImage{ 40.0f, 20.0f };
	Image image1{ "pause.png" };


	//Titre
	PointReal positionTitle{ 400.0f, 100.0f };
	Font blerp{ "blerp.ttf" };
	TextStyle title{ blerp, 100, Color::red, true };


	//Instructions
	PointReal positionInstruct{ 400.0f, 350.0f };
	Font arial{ "arial.ttf" };
	TextStyle text{ arial, 25, Color::white, true };
	std::string instructions{
	R"-(
Pause

-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
	(R)							Reprendre le jeu
	(A)							Accueil
	(Q)							Quitter
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };



};

#endif // !PAUSE_H
