#include <iostream>
#include <vector>
#include <stack>
#include "graph.h"

using namespace std;

int Graph::insertVertex(int k) {
	Vertex* newVertex = new Vertex;
	newVertex->key = k;
	vertices.push_back(newVertex);
	return 0;
}

int Graph::insertEdge(int start, int end) {
	adjVertex* newEdge = new adjVertex;
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == start) { // find start @ index 'i'
			for (int j=0; j<vertices.size(); j++) {
				if (vertices[j]->key == end) { // find end @ index 'j'
					newEdge->v = vertices[j];
					vertices[i]->adjList.push_back(*newEdge);
					return 0;
				}
			}
			cout << "End node not found :(\n";
			return -1;
		}
	}
	cout << "Start node not found :(\n";
	return -1;
	//newEdge->v = ??; // Vertex reference containing the 'end' value;
}

Vertex* Graph::search(int k) {
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == k) {
			//cout << "Found it!\n";
			return vertices[i];
		}
	}
	cout << "Didn't find the key :(\n";
	return NULL;
}


void DFTraversal(Vertex *n, int index, vector<Vertex*> vertices, bool &test) 
{


    for(int x = 0; x < n->adjList.size(); x++ )
    {
        if(n->adjList[x].v->visited == false){
                n->adjList[x].v->visited = true;
                // cout<<n->adjList[x].v->key<<" ";
                // cout<<vertices
                if(n->adjList[x].v->key == vertices[index]->key){
                    // cout<<"FOUND"<<endl;
                    test = true;

                }


                DFTraversal(n->adjList[x].v, index, vertices, test);

            }

    }
 

}






bool Graph::FindCycles(int k) {
	//implement this
                // you might need to use search function
	// you can create one more helper function but don't edit above code
    Vertex* Vert = search(k);
    int index;
    bool test = false;


    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == Vert->key){
        index = i;
        
    }
    }

    DFTraversal(Vert, index, vertices, test);
    if(test == true){
        return true;
    }






    // for(int x = 0; x < Vert->adjList.size(); x++ )
    // {
    //     if(Vert->adjList[x].v->visited == false){
    //             Vert->adjList[x].v->visited = true;
    //             // cout<<n->adjList[x].v->key<<" ";
    //             // cout<<vertices
    //             if(Vert->adjList[x].v->key == k){
    //                 return true;
    //             }


    //             Vert = Vert->adjList[x].v;

    //         }

    // }
 
    
    
    return false;
		
}