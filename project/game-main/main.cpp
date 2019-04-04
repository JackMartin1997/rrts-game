#include <iostream>
#include <Window.h>
#include <Square.h>
#include <Texture.h>

int main(int argc, char *argv[])
{
	rrts::Graphics::Window window(1280, 720);
	rrts::Graphics::Square square;
	rrts::Graphics::Texture texture;

	texture.loadFromFile("text.png");

	square.setTexture(&texture);

	window.WhileRunning([&](){
		window.pollEvents();
		window.clear();

		window.draw(square);

		window.swapBuffer();
	});

	return 0;
}