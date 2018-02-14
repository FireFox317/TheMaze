#ifndef MAZE_H
#define MAZE_H

#include <array>

class Maze
{
public:

	struct Point {
		int x;
		int y;
		Point() {}
		Point(int _x, int _y) : x(_x), y(_y) {}
	};

	static const int UP = 0;
	static const int RIGHT = 1;
	static const int DOWN = 2;
	static const int LEFT = 3;

	Maze(std::array<std::array<int, 12>, 12> _data);
	~Maze();

	void printMaze();
	bool traverseMaze(Point p0);
	void setPathDir(int direction);

	Point searchStartingPoint();

private:
	std::array<std::array<int, 12>, 12> data;
	const int cols = 12;
	const int rows = 12;

	int dir;

	bool checkWall(Point p0);
	Point rightPoint(Point p0);
	Point frontPoint(Point p0);
	bool checkFinish(Point p0);
	void changeDir(int targetdir);


};

#endif