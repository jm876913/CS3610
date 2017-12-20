#include "Dijkstra.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*void weightedGraphType::addEdge(int u, int v, int w){
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}*/
void weightedGraphType::createGraph(int vertex){
	vector <list<Edge> > adjList;
	int edgecounter = 0;

	for(int i = 0; i < )
}

void weightedGraphType::ShortestPath(int vertex){
	bool *weightFound;

	weightFound = new bool[gSize];

	for (int j = 0; j < gSize; j++)
		weightFound[j] = false;

	weightFound[vertex] = true;

	smallestWeight[vertex] = 0;

	for (int i = 0; i < gSize - 1; i++)
	{
		double minWeight = DBL_MAX;
		int v;

		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (smallestWeight[j] < minWeight)
				{
					v = j;
					minWeight = smallestWeight[v];
				}
		weightFound[v] = true;

		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
					smallestWeight[j] = minWeight + weights[v][j];
	} //end for
} //end shortestPath



weightedGraphType::weightedGraphType(int size) :graphType(size){
	weights = new double* [size];

	for(int i = 0; i < size; i++)
		weights[i] = new double[size];

	smallestWeight = new double[size];
}

weightedGraphType::~weightedGraphType(){
	for(int i = 0; i<gSize; i++)
		delete [] weights[i];

	delete[] weights;
	delete smallestWeight;
}