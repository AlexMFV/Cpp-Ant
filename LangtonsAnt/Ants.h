#pragma once

class Ants {
public:
	Ant* ant_colony;
	int size;

	Ants(int _size, int width, int height) {
		size = _size;
		ant_colony = new Ant[_size];

		for (int i = 0; i < size; i++)
			ant_colony[i] = Ant(rand() % width, rand() % height, randomColor());
	}
};