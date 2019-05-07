#ifndef DEMARRER_H
#define DEMARRER_H

#include "Cell.h"
#include <vector>
#include <bai>
#include <Point.h>

using namespace bai;

class Demarrer {
public:
	Demarrer();
	~Demarrer() = default;

	// Fonction d'affichage
	void drawing(Surface & surface);

private:
	PointReal mPosition;                // Position
	Color mColor;                       // Couleur
	//Image
	Image image{ "snake2.png" };
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
Appuyer sur Enter lorsque vous êtes prêt à jouer...
-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-'-
)-" };


};

#endif // !DEMARRER_H
