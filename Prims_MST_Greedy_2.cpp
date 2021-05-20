#include <iostream>
#include <vector>

#include "AdjacencyMatrix.h"
/*
it has a Graph class with some functions :
init(int size)
addEdge(v,w,weight) ,
(optional) 1 for undirected(,,,1)
weight(v,w)
nodeCount()
edgeCount()
getValue(v)
setValue(v,value)
removeEdge(v,w)
hasEdge(v,w)
neighbours(v)
display()

*/

using namespace std;

#define INFINITY 999
#define VISITED 0


int minVertex(Graph G, int D[])
{
    int v = 0; // Initialize v to any unvisited vertex;
    for (int i = 1; i < G.nodeCount(); i++)
    {
        if (G.getValue(i) != VISITED)
        {
            v = i;
            break;
        }
    }

    for (int i = 0; i < G.nodeCount(); i++) // Now find smallest value
    {
        if ((G.getValue(i) != VISITED) && (D[i] < D[v]))
            v = i;
    }
    return v;
}

//
// Compute shortest distances to the MCST, store them in D.
// V[i] will hold the index for the vertex that is i's parent in the MCST
//s is source vertex
void Prim(Graph G, int s, int D[], int V[])
{
    for (int i = 0; i < G.nodeCount(); i++) // Initialize
        D[i] = INFINITY;
    D[s] = 0;
    for (int i = 0; i < G.nodeCount(); i++)
    {                            // Process the vertices
        int v = minVertex(G, D); // Find next-closest vertex
        G.setValue(v, VISITED);
        if (D[v] == INFINITY)
            return; // Unreachable
        if (v != s)
        {   cout<<endl;// to be deleted
            // AddEdgetoMST(V[v], v);
        }

        vector<int> nList = G.neighbors(v);

        for (int j = 0; j < nList.size(); j++)
        {
            int w = nList.at(j);
            if (D[w] > G.weight(v, w))
            {
                D[w] = G.weight(v, w);
                V[w] = v;
            }
        }
    }
}

/***********************/
int main()
{ //prims algorithm is a greedy algorithm to find minimum spanning (mst)tree
    Graph g;
    g.init(6);
    g.addEdge(1,2,8,1);
    g.addEdge(2,3,8,1);
    g.addEdge(3,4,12,1);
    g.addEdge(4,5,2,1);
    g.addEdge(5,6,4,1);
    g.addEdge(1,6,2,1);
    g.display();
    // cout<<g.nodeCount();
    int s = 1;//source vertex
    int D[6] ;
    int V[6];//parent array
    // Prim(g,s,D,V);
    return 0;
}
