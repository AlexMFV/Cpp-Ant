#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ant.h"
#include "Ants.h"
#include "Dir.h"

int main() {

	//Makes so that the rand() function randomizes with a time seed
	srand(time(0));

	int w_width = 800;
	int w_height = 800;

	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Langton's Ant");	

	//Change the pixels in the Image
	sf::Image pixelBuffer;
	pixelBuffer.create(w_width, w_height, sf::Color::White);

	//Texture that grabs the pixelBuffer
	sf::Texture texture;
	texture.loadFromImage(pixelBuffer);

	//Sprite that will be loaded with the ants positions by the Texture
	sf::Sprite sprite;
	sprite.setTexture(texture);

	//Create the Ants
	Ants ants(50, w_width, w_height);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == event.Closed)
				window.close();
		}

		window.clear();
		
		for (int i = 0; i < ants.size; i++)
			ants.ant_colony[i].move(&pixelBuffer);

		texture.update(pixelBuffer);
		sprite.setTexture(texture);

		window.draw(sprite);

		window.display();
	}

	return 0;
}