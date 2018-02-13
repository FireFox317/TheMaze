#include <array>
#include <iostream>

std::array<std::array<int, 12>, 12> maze =
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

int main() {

	printMaze();



	return 0;
}

void printMaze() {
	for (auto row : maze) {
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
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}