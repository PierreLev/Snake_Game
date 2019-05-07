#include "Options.h"



Options::Options()
{
}

void Options::drawing(Surface & surface)
{
	// Dessine
	surface.clear(Color::black);
	surface.drawImage(image1, positionImage);
	surface.drawCenteredText(title, "Snake", positionTitle);
	surface.drawCenteredText(text, instructions, positionInstruct);
}


