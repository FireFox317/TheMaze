#ifndef MAZE_H
#define MAZE_H

#include <array>

class Maze
{
public:
	Maze();
	~Maze();

	void printMaze();

private:
	std::array<std::array<int, 12>, 12> data;


};

#endif