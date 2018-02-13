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
	const int UP = 0;
	const int RIGHT = 1;
	const int DOWN = 2;
	const int LEFT = 3;
	int dir;

	bool checkUp(int x, int y);
	bool checkRight(int x, int y);
	bool checkDown(int x, int y);
	bool checkLeft(int x, int y);

};

#endif