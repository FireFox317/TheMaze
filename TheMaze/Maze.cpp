#include "Maze.h"

#include <iostream>

Maze::Maze(std::array<std::array<int, 12>, 12> _data) : data(_data)
{
}

Maze::~Maze()
{
}

void Maze::printMaze() {
	for (auto row : data) {
		for (auto element : row) {
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
	std::cout << std::endl;
}

void Maze::setPathDir(int direction) {
	dir = direction;
}

Maze::Point Maze::searchStartingPoint() {
	// since we need the index we cannot use a range based loop, 
	// which is used in the printMaze function
	Point p;
	for (size_t i = 0; i < data.size(); i++) {
		for (size_t j = 0; j < data.size(); j++) {
			if (data[i][j] == 2) {
				p.x = j;
				p.y = i;
			}
		}
	}
	int direction;
	if (p.x == 0) {
		direction = RIGHT;
	}
	else if (p.x == cols - 1) {
		direction = LEFT;
	}
	else if (p.y == 0) {
		direction = DOWN;
	}
	else if (p.y == rows - 1) {
		direction = UP;
	}
	else {
		direction = UP;
	}
	setPathDir(direction);

	return p;
}

bool Maze::traverseMaze(Point p0) {
	data[p0.y][p0.x] = 3;

	printMaze();

	if (checkFinish(p0)) {
		std::cout << "Finish found!" << "\n";
		return true;
	}

	Point rightPoint = Maze::rightPoint(p0);
	Point frontPoint = Maze::frontPoint(p0);

	if (!checkWall(rightPoint)) {
		changeDir(RIGHT);
		return traverseMaze(rightPoint);
	}
	else if(!checkWall(frontPoint)){
		return traverseMaze(frontPoint);
	}
	else {
		changeDir(LEFT);
		return traverseMaze(p0);
	}

}

bool Maze::checkWall(Point p0) {
	if (p0.x < 0 || p0.x > cols - 1 || p0.y < 0 || p0.y > rows - 1) {
		return true;
	}
	return data[p0.y][p0.x] == 0;
}

Maze::Point Maze::rightPoint(Point p0) {
	Point p1;
	if (dir == UP) {
		p1.x = p0.x + 1;
		p1.y = p0.y;
	}
	else if (dir == RIGHT) {
		p1.x = p0.x;
		p1.y = p0.y + 1;
	}
	else if (dir == DOWN) {
		p1.x = p0.x - 1;
		p1.y = p0.y;
	}
	else if (dir == LEFT) {
		p1.x = p0.x;
		p1.y = p0.y - 1;
	}
	else {
		p1.x = p0.x;
		p1.y = p0.y;
	}
	return p1;
}

Maze::Point Maze::frontPoint(Point p0) {
	Point p1;
	if (dir == UP) {
		p1.x = p0.x;
		p1.y = p0.y - 1;
	}
	else if (dir == RIGHT) {
		p1.x = p0.x + 1;
		p1.y = p0.y;
	}
	else if (dir == DOWN) {
		p1.x = p0.x;
		p1.y = p0.y + 1;
	}
	else if (dir == LEFT) {
		p1.x = p0.x - 1;
		p1.y = p0.y;
	}
	else {
		p1.x = p0.x;
		p1.y = p0.y;
	}
	return p1;
}

bool Maze::checkFinish(Point p0) {
	if (p0.x == 0 && dir == LEFT) {
		return true;
	}
	else if (p0.x == cols - 1 && dir == RIGHT) {
		return true;
	}
	else if (p0.y == 0 && dir == UP) {
		return true;
	}
	else if (p0.y == rows - 1 && dir == DOWN) {
		return true;
	}

	return false;
}

void Maze::changeDir(int targetdir){
	if (targetdir == RIGHT) {
		if (dir == LEFT) {
			dir = UP;
		}
		else {
			dir = dir + 1;
		}
	}
	else if (targetdir == LEFT) {
		if (dir == UP) {
			dir = LEFT;
		}
		else {
			dir = dir - 1;
		}
	}
}








