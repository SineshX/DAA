/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   25-04-2021
 ****************************************
 * Problem:  Code & analyse Minimum Spanning Tree(MST) using Prim's Algotithm 
 ****************************************
 * Given graph G1 is weighted and undirected 
 ***************************************
 */

#include <iostream>
using namespace std;

void print(int parent[], int g[5][5])
{
    int totalWeight = 0;
    cout << "Edge \t\t Weight\n";
    for (int i = 1; i < 5; i++)
    {
        cout << i << " - " << parent[i] << " \t\t " << g[i][parent[i]] << endl;
        totalWeight += g[i][parent[i]];
    }
    cout << "\nTotal weight = " << totalWeight << endl;
}

int minimum(int key[], bool mstSet[])
{
    int min = 1000, minIndex;
    //min is INFINITY initially

    for (int i = 0; i < 5; i++)
    {
        if (mstSet[i] == false && key[i] < min)
            min = key[i], minIndex = i;
    }
    return minIndex;
} // end of minimum function

void primMST(int g[5][5])
{
    int parent[5];  //store msTree index
    int key[5];     //store minEdge
    bool mstSet[5]; //check included vertex

    for (int i = 0; i < 5; i++)
    { //all key = INFINITY and all mstSet marked unvisited
        key[i] = 1000;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1; //

    for (int i = 0; i < 5 - 1; i++)
    { //for each element in mstSet
        int u = minimum(key, mstSet);
        //u is picked vertex ka index ,
        mstSet[u] = true;
        //find adjacent vertex and update value
        for (int v = 0; v < 5; v++)
        {
            if (g[u][v] && mstSet[v] == false && g[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    print(parent, g);
} // end of primMST function

int main()
{
    int G1[5][5] = {{0, 9, 5, 2, 0},
                    {9, 0, 0, 6, 5},
                    {5, 0, 0, 4, 5},
                    {2, 6, 4, 0, 4},
                    {0, 5, 5, 4, 0}};

    primMST(G1);

    return 0;
}

/***********OUTPUT***********
Edge             Weight
1 - 4            5     
2 - 3            4     
3 - 0            2     
4 - 3            4     

Total weight = 15  
*/