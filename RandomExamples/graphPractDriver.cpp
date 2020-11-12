#include <iostream>
#include <vector>
#include <queue>
#include "graphPract.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(6, 7);
    // g.addEdge(5, 6);
    // g.addEdge(0, 1); 
    // g.addEdge(0, 2); 
    // g.addEdge(1, 2); 
    // g.addEdge(2, 0); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 3); 

    // TODO Silver: Find the length of the shortest path between the source and destination vertex (complete the findShortestPath function)
    g.BFSPrint(0); // Expected: 2



    // else
    // {
    //   cout<< "source and destination are not connected" << endl;
    // }

    return 0;
}
