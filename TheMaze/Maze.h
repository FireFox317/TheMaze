#ifndef MAZE_H
#define MAZE_H

#include <array>

class Maze
{
public:
	Maze();
	~Maze();

	void printMaze();
	bool traverseMaze(int x, int y);

private:
	std::array<std::array<int, 12>, 12> data;
	int cols, rows;

};

#endif