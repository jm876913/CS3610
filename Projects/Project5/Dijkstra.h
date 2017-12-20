#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include "graphType.h"
using namespace std;
//# define INF 0x3f3f3f3f

//typedef pair<int, int> Ipair;

class weightedGraphType: public graphType{
	public:
		int vertex;

		//list< pair<int, int> > *adj;

		//void addEdge(int u, int v, int w);
		void createGraph();
		void ShortestPath(int vertex);
		void PrintShortestDist(int vertex);

		weightedGraphType(int size = 0);
		~weightedGraphType();

	protected:
		double **weights;
		double *smallestWeight;
};