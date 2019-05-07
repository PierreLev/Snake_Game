#ifndef ACCUEIL_H
#define ACCUEIL_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class Accueil {
public:
	Accueil();
	~Accueil() = default;

	// Fonction d'affichage
	void drawing(Surface & surface);

private:
	PointReal mPosition;                // Position
	Color mColor;                       // Couleur
	//Image
	Image image{ "snake.png" };
	Image image1{ "snake.gif" };
	PointReal position3{ 20.0f, 20.0f };

	//Titre
	PointReal position1{ 400.0f, 300.0f };
	Font blerp{ "blerp.ttf" };
	TextStyle text{ blerp, 200, Color::red, true };

	//Appuyez sur une touche, instruction
	PointReal position2{ 400.0f, 500.0f };
	Font roboto{ "roboto-black.ttf" };
	TextStyle text1{ roboto, 20, Color::lightGrey, true };
	std::string options{
R"-(
-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
Choisissez parmi les options suivantes :
	(O)							Options
	(D)							Démarrer
	(Q)							Quitter
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };


};

#endif // !ACCUEIL_H
