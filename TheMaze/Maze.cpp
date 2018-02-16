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

void Maze::setSolveDir(int direction) {
	dir = direction;
}

Maze::Point Maze::searchStartingPoint() {
	// Since we need the index of the 2d array we cannot use a range based loop, 
	// which is used in the printMaze function. Instead a normal for loop is used
	Point p;
	for (size_t i = 0; i < data.size(); i++) {
		for (size_t j = 0; j < data.size(); j++) {
			if (data[i][j] == 2) { // A 2 is represented as the starting point
				p.x = j;
				p.y = i;
			}
		}
	}

	// When the starting point is on the top of the maze, the starting direction is DOWN
	// since that is the only way it can go, the same goes for the rest of the edges of the maze.
	// When the starting point is not on one of the edges of the maze, but in the maze itself the 
	// direction is 'randomly' set to UP.
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
	setSolveDir(direction);

	return p;
}

bool Maze::traverseMaze(Point currentPoint) {
	// Save the path of the solver
	data[currentPoint.y][currentPoint.x] = 3;

	printMaze();

	if (checkFinish(currentPoint)) {
		std::cout << "Finish found!" << "\n";
		return true;
	}

	// Calculate the point to the right and to the front of the current point 
	// and use that to determine if there is a wall or not
	Point rightPoint = Maze::rightPoint(currentPoint);
	Point frontPoint = Maze::frontPoint(currentPoint);

	if (!checkWall(rightPoint)) {
		// Change the direction to the right and go the next point by calling the function again
		changeDir(RIGHT);
		return traverseMaze(rightPoint);
	}
	else if(!checkWall(frontPoint)){
		// When going forward the direction shouldnt change
		return traverseMaze(frontPoint);
	}
	else {
		// Change the direction to the left and go the next point by calling the function again
		changeDir(LEFT);
		return traverseMaze(currentPoint);
	}
	return false;

}

bool Maze::checkWall(Point p0) {
	// If the point is outside the maze return true, such that the solver doesnt go there
	if (p0.x < 0 || p0.x > cols - 1 || p0.y < 0 || p0.y > rows - 1) {
		return true;
	}
	// Check if there is a wall
	return data[p0.y][p0.x] == 0;
}

// Calculates the point to the right of the point passed into this function
// This obviously depends on the current direction of the solver
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

// Calculates the point to the front of the point passed into this function
// This obviously depends on the current direction of the solver
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

// The finished is reached when the solver is on one of the edges of the map
// and the direction is pointing outwards, i.e. when the solver is on the top row
// and the direction is pointing up the finished is reached.
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

// Changes the direction to the right or the left.
// The direction the solver wants to change to is passed into the function.
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








