/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   20-04-2021
 ****************************************
 * Problem:  Find All Hamiltonian Cycle 
 ****************************************
 *	visit all nodes exactly once and come back to origin
 * find all possible cycles
 ****************************************
 */

#include <iostream>
#include <vector>
using namespace std;

int graph[5][5] = {{0, 1, 0, 1, 0},
                   {1, 0, 1, 1, 1},
                   {0, 1, 0, 0, 1},
                   {1, 1, 0, 0, 0},
                   {0, 1, 1, 0, 0}};

int n = sizeof(graph) / sizeof(graph[0]);
// 100/20 , coz 25*4 = 100 and 5*4 = 20 // size of int = 4

vector<int> x(n, 0); // init all with 0
// for storing cycle node values :p not index

void hamiltonian(int k);
void nextVertex(int k);
//defined after main function

int main()
{
    for (int i : x)
    {
        cout << i << " ";
    }
    int source = 1; //1 is source vertex
    x.at(0) = source;
    cout << x.at(0);

    //k = 1 , is index of x vector (stores cycle nodes)
    // intitially x[k] = 0 // coz initilized
    hamiltonian(1);
    return 0;
} //end of main fun

void hamiltonian(int k)
{
    do
    {
        nextVertex(k);

        break;

    } while (true);
}

void nextVertex(int k)
{   
    do
    {
        x[k] = (x[k] + 1) % (n + 1); // n = 5
        //1 2 3 4 5 0 -- again 1 2 3 4 5 0 --etc
        if (x[k] == 0)
        {
            return;
        } //if found zero

        //first run me x[1] = 1

        //now checking if edge exist
        if (graph[x[k - 1] - 1][x[k] - 1] != 0) //extra -1 coz graph is frim 0
        {   //since edge exist ___
            int j;
            for (j = 0; j <= k; j++)        
            {  //  checking for duplicate entry in x vector till filled ( k-1 index tak)
                if (x[j] == x[k])
                {
                    break;
                }
            }//end of loop
            if (j == k)

        }

        break; //to be removed
    } while (true);
}

