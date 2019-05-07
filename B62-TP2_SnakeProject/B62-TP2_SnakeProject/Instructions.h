#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class Instructions {
public:
	Instructions();
	~Instructions() = default;

	// Fonction d'affichage
	void drawing(Surface & surface);

private:

	//Image
	PointReal positionImage{ 20.0f, 20.0f };
	Image image1{ "snake.png" };


	//Titre
	PointReal positionTitle{ 400.0f, 50.0f };
	Font blerp{ "blerp.ttf" };
	TextStyle title{ blerp, 100, Color::red, true };


	//Instructions
	PointReal positionInstruct{ 400.0f, 350.0f };
	Font arial{ "arial.ttf" };
	TextStyle text{ arial, 20, Color::white, true };
	std::string instructions{
R"-(
Instructions

But : Survivre le plus longtemps et devenir le plus long possible en
mangeant les pastilles.
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
Contrôles
	Flèches					Directions
	(T)							Téléportation
	(P)							Pause
	(Q)							Quitter
	(B)							Changer la couleur du background
	(S)							Changer la couleur du snake
	(N)							Changer la couleur des pastilles
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
Choisissez parmi les options suivantes :
	(O)							Options
	(Q)							Quitter
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };


};

#endif // !INSTRUCTIONS_H
