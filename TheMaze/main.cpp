#include "Maze.h"

#include <array>

int main() {
	std::array<std::array<int, 12>, 12> mazeData = 
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

	Maze maze(mazeData);

	Maze::Point startingPoint = maze.searchStartingPoint();

	//Maze::Point startingPoint(11,4);
	//maze.setPathDir(Maze::LEFT);

	maze.traverseMaze(startingPoint);

	return 0;
}

