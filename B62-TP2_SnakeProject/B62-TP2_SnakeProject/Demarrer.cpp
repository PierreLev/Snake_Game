#include "Demarrer.h"



Demarrer::Demarrer()
{
}

void Demarrer::drawing(Surface & surface)
{
	// Dessine
	surface.clear(Color::black);
	surface.drawImage(image, position3);
	surface.drawCenteredText(text, "Snake", position1);
	surface.drawCenteredText(text1, options, position2);

}
