#pragma once
#include "Dir.h"

sf::Color randomColor();

class Ant {
public:
	int x;
	int y;
	sf::Color color;
	int dir;

	Ant(){ }

	Ant(int _x, int _y) {
		x = _x;
		y = _y;
		dir = rand() % 4;
		color = randomColor();
	}

	Ant(int _x, int _y, sf::Color _color) {
		x = _x;
		y = _y;
		dir = rand() % 4;
		color = _color;
	}

	void move(sf::Image *img) {
		bool pixelColor = checkPixel(img);
		setPixel(img, pixelColor);

		//false = anything, true = white
		if (pixelColor == true)
			dir++;
		else
			dir--;

		if (dir > 3)
			dir = 0;
		
		if (dir < 0)
			dir = 3;

		switch (dir) {
		case Dir::down: y++; break;
		case Dir::left: x--; break;
		case Dir::right: x++; break;
		case Dir::up: y--; break;
		}
	}

private:
	void setPixel(sf::Image *img, bool colorType)
	{
		if (colorType == true)
			img->setPixel(x, y, color);
		else
			img->setPixel(x, y, sf::Color::White);
	}

	bool checkPixel(sf::Image *img) {
		if (img->getPixel(x, y) == sf::Color::White)
			return true;
		else
			return false;
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