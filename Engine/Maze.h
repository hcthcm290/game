#pragma once
#include <vector>

class Maze
{
public:
	const int sizeOfMaze = 20;
	int** graph;
	bool* reached;

	// see if a vertex is in a graph and does have a way to go to another vertex //
	std::vector<int> inTracked;

public:
	Maze();
	bool allReached();
	bool doesHaveWay(int x);
	int Search(int x);
};
