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
	std::cout << dir << '\n';
	

	if (x == 0 && y == 2) {
		return true;
	}

	if (dir == UP) {
		checkRight(x,y);
		checkLeft(x,y);
		checkUp(x,y);
	}
	else if (dir == LEFT) {
		checkUp(x, y);
		checkDown(x, y);
		checkLeft(x, y);
	}
	else if (dir == RIGHT) {
		checkDown(x, y);
		checkUp(x, y);
		checkRight(x, y);
	}
	else if (dir == DOWN) {
		checkLeft(x, y);
		checkRight(x, y);
		checkDown(x, y);
	}

	return false;

	
}

bool Maze::checkUp(int x, int y)
{
	if (y < rows && data[y + 1][x] == 1) {
		dir = UP;
		if (traverseMaze(x, y + 1)) {
			return true;
		}
	}
}

bool Maze::checkRight(int x, int y)
{
	if (x < cols && data[y][x + 1] == 1) {
		dir = RIGHT;
		if (traverseMaze(x + 1, y)) {
			return true;
		}
	}
}

bool Maze::checkDown(int x, int y)
{
	if (y > 0 && data[y - 1][x] == 1) {
		dir = DOWN;
		if (traverseMaze(x, y - 1)) {
			return true;
		}
	}
}

bool Maze::checkLeft(int x, int y)
{
	if (x > 0 && data[y][x - 1] == 1) {
		dir = LEFT;
		if (traverseMaze(x - 1, y)) {
			return true;
		}
	}
}

