#include "Maze.h"

#include <array>
#include <iostream>

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

	std::cout << "The Maze Solver!" << "\n\n"
		<< "Press enter to solve the maze...";
	std::cin.get();

	Maze::Point startingPoint = maze.searchStartingPoint();

	// Manually setting the startingPoint and searching direction
	// is done using the following code:

	// Maze::Point startingPoint(11,4);
	// maze.setSolveDir(Maze::LEFT);

	maze.traverseMaze(startingPoint);

	return 0;
}

