#include<stdio.h>
#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;


int main() {
	
	Graph g;
	g.insertVertex(10);
	g.insertVertex(12);
	g.insertVertex(13);
	g.insertEdge(10, 12);
	g.insertEdge(10, 13);
	g.insertEdge(13, 10);
	
	if(g.FindCycles(10))
		cout<< "Cycle exists\n";
	else
		cout<<"Cycle doesn't exists\n";
	

	return 0;
}