#include "Maze.h"
#include <random>
#include <ctime>
using namespace std;
Maze::Maze()
{
	// make new graph matrix //
	srand(time(NULL));
	graph = new int* [sizeOfMaze * sizeOfMaze];
	for (int i = 0; i < sizeOfMaze * sizeOfMaze; i++)
	{
		graph[i] = new int[4];
	}

	for (int i = 0; i < sizeOfMaze * sizeOfMaze; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			graph[i][j] = 1;
		}
	}

	// make a array to see if a vertex is in a grarh or not //
	reached = new bool[sizeOfMaze * sizeOfMaze];
	for (int i = 0; i < sizeOfMaze * sizeOfMaze; i++)
	{
		reached[i] = false;
	}

	// include vertex 0 to graph //
	inTracked.push_back(0);
	reached[0] = true;

	while (allReached() == false)
	{
		int locationInTrack = rand() % (inTracked.size());
		int vertex = inTracked[locationInTrack];

		if (vertex == 0)
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					int way = rand() % 2 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else
					{
						nextVerx += sizeOfMaze;
					}
				} while (reached[nextVerx]);
				graph[vertex][graph[0][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if (vertex == sizeOfMaze * sizeOfMaze - 1)
		{
			reached[sizeOfMaze * sizeOfMaze - 1] = true;
		}
		else if (vertex == sizeOfMaze - 1)
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 2 + 0;
					if (way == 0)
					{
						nextVerx -= 1;
					}
					else
					{
						nextVerx += sizeOfMaze;
					}
				} while (reached[nextVerx]);
				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if (vertex == sizeOfMaze * (sizeOfMaze - 1))
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 2 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else
					{
						nextVerx -= sizeOfMaze;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if (vertex < sizeOfMaze)
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 3 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else if (way == 1)
					{
						nextVerx += sizeOfMaze;
					}
					else
					{
						nextVerx -= 1;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if (vertex > sizeOfMaze * (sizeOfMaze - 1))
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 3 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else if (way == 1)
					{
						nextVerx -= sizeOfMaze;
					}
					else
					{
						nextVerx -= 1;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if (vertex % sizeOfMaze == 0)
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 3 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else if (way == 1)
					{
						nextVerx += sizeOfMaze;
					}
					else
					{
						nextVerx -= sizeOfMaze;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else if ((vertex + 1) % sizeOfMaze == 0)
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 3 + 0;
					if (way == 0)
					{
						nextVerx -= sizeOfMaze;
					}
					else if (way == 1)
					{
						nextVerx += sizeOfMaze;
					}
					else
					{
						nextVerx -= 1;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
		else
		{
			if (doesHaveWay(vertex))
			{
				int nextVerx = vertex;
				do
				{
					nextVerx = vertex;
					int way = rand() % 4 + 0;
					if (way == 0)
					{
						nextVerx += 1;
					}
					else if (way == 1)
					{
						nextVerx += sizeOfMaze;
					}
					else if (way == 2)
					{
						nextVerx -= 1;
					}
					else
					{
						nextVerx -= sizeOfMaze;
					}
				} while (reached[nextVerx]);

				graph[vertex][graph[vertex][0]] = nextVerx;
				graph[vertex][0] += 1;
				reached[nextVerx] = true;
				inTracked.push_back(nextVerx);
			}
			else
			{
				inTracked.erase(inTracked.begin() + locationInTrack);
			}
		}
	}

}

bool Maze::allReached()
{
	int count = 0;
	for (int i = 0; i < sizeOfMaze * sizeOfMaze; i++)
	{
		if (reached[i])
		{
			count += 1;
		}
	}

	if (count == sizeOfMaze * sizeOfMaze)
	{
		return true;
	}

	return false;
}

bool Maze::doesHaveWay(int x)
{
	if (x == 0)
	{
		if (reached[x + 1] && reached[x + sizeOfMaze])
			return false;
		return true;
	}
	else if (x == sizeOfMaze - 1)
	{
		if (reached[x - 1] && reached[x + sizeOfMaze])
			return false;
		return true;
	}
	else if (x == sizeOfMaze * (sizeOfMaze - 1))
	{
		if (reached[x + 1] && reached[x - sizeOfMaze])
			return false;
		return true;
	}
	else if (x < sizeOfMaze)
	{
		if (reached[x + 1] && reached[x - 1] && reached[x + sizeOfMaze])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (x > sizeOfMaze * (sizeOfMaze - 1))
	{
		if (reached[x + 1] && reached[x - 1] && reached[x - sizeOfMaze])
			return false;
		return true;
	}
	else if (x % sizeOfMaze == 0)
	{
		if (reached[x + 1] && reached[x + sizeOfMaze] && reached[x - sizeOfMaze])
			return false;
		return true;
	}
	else if ((x + 1) % sizeOfMaze == 0)
	{
		if (reached[x - 1] && reached[x + sizeOfMaze] && reached[x - sizeOfMaze])
			return false;
		return true;
	}
	else
	{
		if (reached[x - 1] && reached[x + 1] && reached[x + sizeOfMaze] && reached[x - sizeOfMaze])
			return false;
		return true;
	}
}

int Maze::Search(int x)
{
	return 0;
}
