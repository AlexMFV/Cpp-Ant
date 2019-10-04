#pragma once

class Ants {
public:
	Ant *ant_colony;

	Ants(int size, int width, int height) {
		ant_colony = new Ant[size];

		for (int i = 0; i < size; i++)
			ant_colony[i] = Ant(rand() % width, rand() % height, randomColor());
	}
};