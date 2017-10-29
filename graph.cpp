#include<iostream>
#include<vector>
#include<queue>
#include "graph.h"
using namespace std;

int main()
{
	Graph G(7);
	G.addEdge(1,2);
	G.addEdge(2,5);
	G.addEdge(5,6);
	G.addEdge(5,7);
	G.addEdge(6,7);
	G.addEdge(1,3);
	G.addEdge(3,4);

	vector<int> v;
	v = G.shortestPath(1,7);
	printContainer(v.begin(),v.end()); 

}