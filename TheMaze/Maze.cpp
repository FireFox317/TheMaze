#include "Maze.h"

#include <iostream>

Maze::Maze()
{
	rows = cols = 12;

	data =
	{ {
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,0,1,1,1,1,1,1,0 },
	{ 1,1,0,1,0,1,0,0,0,0,1,0 },
	{ 0,0,0,1,0,1,1,1,1,0,1,0 },
	{ 0,1,1,1,1,0,0,0,1,0,1,2 },
	{ 0,0,0,0,1,0,1,0,1,0,1,0 },
	{ 0,1,1,0,1,0,1,0,1,0,1,0 },
	{ 0,0,1,0,1,0,1,0,1,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,0,1,0 },
	{ 0,0,0,0,0,0,1,0,0,0,1,0 },
	{ 0,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 }
	} };
}


Maze::~Maze()
{
}

void Maze::printMaze() {
	for (auto row : data) {
		for (int element : row) {
			if (element == 0) {
				std::cout << "#";
			}
			else if (element == 1) {
				std::cout << ".";
			}
			else if (element == 2) {
				std::cout << "x";
			}
			else if (element == 3) {
				std::cout << "X";
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool Maze::traverseMaze(int x, int y) {
	data[y][x] = 3;

	printMaze();

	if (x > 0 && data[y][x - 1] == 1 && traverseMaze(x - 1, y)) {
		return true;
	}

	if (x < cols && data[y][x + 1] == 1 && traverseMaze(x + 1, y)) {
		return true;
	}

	if (y > 0 && data[y - 1][x] == 1 && traverseMaze(x, y - 1)) {
		return true;
	}

	if (y < rows && data[y + 1][x] == 1 && traverseMaze(x, y + 1)) {
		return true;
	}

	return false;

	
}
