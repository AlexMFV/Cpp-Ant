#pragma once

sf::Color randomColor();

class Ant {
public:
	int x;
	int y;
	sf::Color color;

	Ant(){ }

	Ant(int _x, int _y) {
		x = _x;
		y = _y;
		color = randomColor();
	}

	Ant(int _x, int _y, sf::Color _color) {
		x = _x;
		y = _y;
		color = _color;
	}

	void move(sf::Image img, int x, int y) {
		bool pixelColor = checkPixel(img, x, y);

		//false = anything, true = white
		//if()
	}

private:
	bool checkPixel(sf::Image img, int x, int y) {
		if (img.getPixel(x, y) == sf::Color::White)
			return true;
		else
			return false;
	}

	void processRotation() {

	}
};

//Sets a random color for the ant
sf::Color randomColor() {
	sf::Color col;
	col.r = rand() % 256;
	col.g = rand() % 256;
	col.b = rand() % 256;
	return col;
}