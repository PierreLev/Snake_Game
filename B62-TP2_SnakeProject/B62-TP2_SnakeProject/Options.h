
#ifndef OPTIONS_H
#define OPTIONS_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class Options
{
public:
	Options();
	~Options() = default;;

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
	PointReal positionInstruct{ 400.0f, 300.0f };
	Font arial{ "arial.ttf" };
	TextStyle text{ arial, 20, Color::white, true };

	std::string instructions{
	R"-(
Options
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
Choisir le niveau de difficultés
	(F)							Facile
	(M)							Moyen (Taille des cellules 10px/10px)
	(D)							Difficile
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
Choisissez parmi les options suivantes :
	(A)							Accueil
	(I)					  		Instructions
	(Q)							Quitter
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };


};

#endif //!OPTIONS_H
