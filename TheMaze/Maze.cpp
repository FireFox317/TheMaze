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

	dir = UP;
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

	switch (dir) {
	case LEFT:
		// check up
		if (data[y + 1][x] == 1) {
			dir = UP;
			traverseMaze(x, y + 1);
		}
		
	case RIGHT:
		// check down
	case UP:
		// check right
	case DOWN:
		// check left

	}

	
}


