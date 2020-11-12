#include "graphPract.hpp"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

// function to add edge between two vertices
void Graph::addEdge(int v1, int v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->key == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


// function to add a vertex to the graph
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

// function to visualize the graph
void Graph::printGraph(){

    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->key<<" --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->key << " ";
        }
        cout<<endl;
    }

}

// function to go through all vertices and set them unvisited
void Graph::setAllVerticesUnvisited()
{
  int i;
  for(i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;

  }
}


// DFS
// TODO: Complete this function, so that it can be used in the isBridge function
void Graph::DFSPrint(vertex *n) 
{


}
void Graph::BFSPrint(int src) 
{  
    vertex*vStart;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->key == src)
        {
            vStart = vertices[i];
        }
    }
    vStart->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the source vertex
    q.push(vStart);

    vertex *n;
    //cout<<src<<endl;

    // standard BFS
    while(!q.empty()){
        
        n = q.front();
        cout<<n->key<<" ";
        q.pop();

        // go to all the adjacent vertices of n
        for( int x = 0; x < n->adj.size(); x++ )
        {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
            if(n->adj[x].v->visited == false){
                n->adj[x].v->visited = true;
                //cout<<n->adj[x].v->key<<endl;
                q.push(n->adj[x].v);
                n->adj[x].v->distance = n->distance + 1;
                

            }
            // if(n->adj[x].v->key == dest){
            //     cout<<"FOUND"<<endl;
            //     index = x;
            //     int d = n->adj[index].v->distance;
            //     return d;
            // }

        }

    }


    cout<<endl;

}


// function to remove an edge connecting vertices with keys key1 and key2
// TODO: Complete this function, so that it can be used in the isBridge function
void Graph::removeEdge(int key1, int key2)
{
  vertex *v1,*v2;
    int ind1;
    int ind2;
  // Finding the vertex pointers for the vertices with keys: key1 and key2
  for(int i = 0; i < vertices.size(); i++)
  {
      if(vertices[i]->key == key1)
      {
          v1 = vertices[i];
          ind1 = i;
      }

      if(vertices[i]->key == key2)
      {
          v2 = vertices[i];
          ind2 = i;
      }
  }

  // TODO: Modify the adjacency lists (remember that the graph is undirected)
  // You can use erase to remove an item from a vector
  // Ex: say you need to remove ith index item from a vector "myvector", you can use myvector.erase(myvector.begin()+i)


  for(int i = 0; i < v1->adj.size(); i++){
    if(v1->adj[i].v->key == v2->key){
        v1->adj.erase(v1->adj.begin()+i);
    }
  }

  for(int i = 0; i < v2->adj.size(); i++){
    if(v2->adj[i].v->key == v1->key){
       v2->adj.erase(v2->adj.begin()+i);
    }
  }

}


// Check if an edge connecting vertices with keys: key1 and key2 is a bridge of the graph, returns true if it is indeed a bridge otherwise false
// TODO SILVER: Follow the TODOs to complete the funciton below
//bool Graph::isBridge(int key1, int key2)
// {
//    int  var = 0;   // actual variable declaration.
//    int  *counter;        // pointer variable 

//     counter = &var;
//     vertex *n;


//   setAllVerticesUnvisited();

//   cout<< "Graph before removing the edge: " <<endl;
//   printGraph();

//   // num. of connected componenets in the graph before removing the edge
//   int initial_components = 0;
  

//   // TODO Step1: Get initial_components. Complete and use the DFTraversal function.
//     for(int i = 0; i < vertices.size() - 1; i++){
//         if(vertices[i]->visited == false){
//             DFTraversal(vertices[i]);
//             initial_components += 1;
//         }
//     }

   

//   cout<< "num. of connected components before removal: " << initial_components << endl;

//   // TODO Step 2: Remove the edge (key1,key2) from the graph, modify the adjacency list(s) in the removeEdge function.
//   removeEdge(key1, key2);

//   cout<< "Graph after removing the edge: " <<endl;
//   printGraph();

//   // Mark the vertices unvisited before doing the traversal again
//   setAllVerticesUnvisited();

//   // num. of connected componenets in the modified graph (i.e after removing the edge)
//   int components_after_removal = 0;

//   // TODO Step 3: Get components_after_removal (use DFTraversal again)
  
//   for(int i = 0; i < vertices.size(); i++){
//     if(vertices[i]->visited == false){
//         DFTraversal(vertices[i]);
//         components_after_removal += 1;
//     }
//   }
//   //components_after_removal = vertices.size();

//   cout<< "num. of connected components after removal: " <<components_after_removal << endl;

//   // Step4: Add the edge back to the graph
//   addEdge(key1, key2);

//   // TODO Step5: check if the no of connected components increases after removing the edge and return true
//   if(components_after_removal > initial_components)
//   return true;

//  return false;

// }