#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window(sf::VideoMode(300, 300), "Langton's Ant");

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == event.Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.display();
	}

	return 0;
}