#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string v1, string v2, int num){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = n;
        v->distance = 0;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
		
        cout<<vertices[i]->name<<":"<<endl;
		
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
		
        cout<<endl;
    }
}

void Graph::_grader_print_shortest_distance(string destination)
{
    for(unsigned int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == destination) {
            cout << vertices[i]->name << " (" << vertices[i]->distance << ")" << endl;
        }
    }
}

void Graph::_grader_setAllVerticesUnvisited()
{
  unsigned int i;
  for(i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;
      vertices[i]->distance = 0;
  }
}

vertex* searchVertex(string start, vector<vertex*> &vertices)
{
    vertex *vStart;
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == start)
            vStart = vertices[i];
    }
    return vStart;
}


void Graph::dijkstraTraverse(string start)
{
	// to be completed
	// must use searchVertex() for the source (see implementation above)

    vertex * vStart = new vertex;                           //created to assign the starting vertex to
    vStart = searchVertex(start, vertices);                 //assign starting
    vStart->visited = true;                                 //starting node is visited and 0 distance to
    vStart->distance = 0;
    
    int mindistance;                                        //mindistance and dist used to compare between vertex distances
    int dist;
    vertex*s;

    vector<vertex*> solved_List;                            //holds the list of shortest paths
    solved_List.push_back(vStart);                          //add starting node to end of the vector
    int c = vertices.size();                                //at most the while loop will need to go through the vertices size

        while(c > 0){
        mindistance = 10000000;
        vertex * n;
        n = NULL;
        n = solved_List.front();                            //establishes the start as the front

        for(int i = 0; i < solved_List.size(); i++){                    //goes through entire list

            for(int x = 0; x < solved_List[i]->adj.size(); x++){            //goes though each adjacent node at that point
                if(!solved_List[i]->adj[x].v->visited ){                            //if that adjacent node has not been visited          
                    dist = solved_List[i]->distance + solved_List[i]->adj[x].weight;        //dist is temporarily set to the TOTAL distance to that node
                
                if(dist < mindistance){                             //compares it to the other current mindistance
                    n = solved_List[i]->adj[x].v;                   //set vertex n temporarily to the vertext that is shorter
                    mindistance = dist;                             //reset mindistance
                    solved_List[i]->adj[x].v->pred = solved_List[i];        //set the predecessor vertex
                }
                }
            }
        }
        
        n->distance = mindistance;                          //set values for the n node
        n->visited = true;
        solved_List.push_back(n);                           //add to end of the vector
        c--;                                                //for while loop
    }
}