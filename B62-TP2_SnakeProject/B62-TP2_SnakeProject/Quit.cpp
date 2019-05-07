#include "Quit.h"



Quit::Quit()
{
}

void Quit::drawing(Surface & surface)
{
	surface.clear(Color::black);
	surface.drawImage(image1, positionImage);
	surface.drawCenteredText(title, "Snake", positionTitle);
	surface.drawCenteredText(text, instructions, positionInstruct);
}


