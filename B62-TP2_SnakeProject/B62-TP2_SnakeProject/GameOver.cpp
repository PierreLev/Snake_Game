#include "GameOver.h"



GameOver::GameOver()
{
}

void GameOver::drawing(Surface & surface)
{
	surface.clear(Color::black);
	surface.drawImage(image1, positionImage);
	surface.drawCenteredText(title, "Snake", positionTitle);
	surface.drawCenteredText(text, instructions, positionInstruct);
}

