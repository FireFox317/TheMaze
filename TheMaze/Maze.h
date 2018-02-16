#ifndef MAZE_H
#define MAZE_H

#include <array>

// This class always expects a 12 by 12 array with the following data structure:
// 0 = wall; 1 = path; 2 = startingpoint.
class Maze
{
public:

	// A struct Point is used to store the x and y value of a section of the maze
	struct Point {
		int x;
		int y;
		Point() {}
		Point(int _x, int _y) : x(_x), y(_y) {}
	};

	// These constants are used to define the direction in which the solver can move
	static const int UP = 0;
	static const int RIGHT = 1;
	static const int DOWN = 2;
	static const int LEFT = 3;

	// When the object is made the user should pass in the 12 by 12 array containing the maze data
	Maze(std::array<std::array<int, 12>, 12> _data);
	~Maze();

	void printMaze();

	// This function solves the maze and the user should pass in the starting point as an argument
	bool traverseMaze(Point p0);

	// Sets the direction in which the solver starts to solve
	void setSolveDir(int direction);

	// Returns the starting point of the maze, represented by a 2 in the 12 by 12 array.
	Point searchStartingPoint();

private:
	std::array<std::array<int, 12>, 12> data;
	const int cols = 12;
	const int rows = 12;

	// Direction used by the solver to use the right-hand rule
	int dir;

	// Functions used to solve the maze
	bool checkWall(Point p0);
	Point rightPoint(Point p0);
	Point frontPoint(Point p0);
	bool checkFinish(Point p0);
	void changeDir(int targetdir);
};

#endif