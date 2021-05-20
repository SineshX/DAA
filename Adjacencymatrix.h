#include<iostream>
#include<vector>
using namespace std;

#define VISITED 0

//its alway better to know : directed/undirected graph
//for now ignore

class Graph
{
private:
    int n; // size of matrix is equal to no of vertices ??
    int **matrix; // a double pointer 
    vector<int> nodeValues;// store values of node
    //if needed like node1 = A or 65 etc.. -- for adv usage
    int numEdge; // edge Count 
    

public:
    void init(int n)// may be later convert to constructor
    { // Initialize the graph with n vertices
        this->n = n; 

        matrix = new int *[n]; //yes its vertical XD
        //created raw (array) to store pointer ie : int*[n] --that star*
         
        // allocating each cell an int array // each cell will contain address of that array
        // took 1 hr tranning from Abdul Bari's videos XD
        for (int k = 0; k < n; ++k)
        {
            matrix[k] = new int[n];
            nodeValues.push_back(k+1); // giving node values 1 2 3 ... for now 
            // yes, at 0 index we have 1 , a/c to user  
            //initialize raw 1..and so on with 0)
            for(int l=0;l<n;l++)
            {
                matrix[k][l]=0;
            }
        }

        nodeValues.resize(n); 
        numEdge = 0;
    }// done

    // Adds a new edge from node v to node w
    // Returns the new edge (most imp function)
    void addEdge(int v, int w, int weight,int flag = 0) // addWeight
    {
        if (weight == 0)
            return; // Can't store weight of 0
        // user ka 1 apna 0 
        if (matrix[v-1][w-1] == 0)// means node exist// TODO : coz i'll init with zero
            numEdge++;        
        matrix[v-1][w-1] = weight;

        //for undirected
        if(flag == 1) //flag 1 for undirected
        {
            if (matrix[w-1][v-1] == 0)
                numEdge++;
            matrix[w-1][v-1] = weight;
        }

    }//done

    // Get the weight value for an edge
    int weight(int v, int w) { return matrix[v-1][w-1]; }

    // Return the number of vertices
    int nodeCount() { return nodeValues.size(); }

    // Return the current number of edges
    int edgeCount() { return numEdge; }

    // Get the value of node with index v
    int getValue(int v) { return nodeValues.at(v-1); }

    // Set the value of node with index v
    void setValue(int v, int val) { nodeValues.at(v-1) = val; }
    // technically no logic , see init function

    
    // Removes the edge from the graph.
    void removeEdge(int v, int w)
    {
        if (matrix[v-1][w-1] != 0)
        {
            matrix[v-1][w-1] = 0;// setweight 0
            numEdge--;
        }
    }

    // Returns true iff the graph has the edge
    bool hasEdge(int v, int w) { return matrix[v-1][w-1] != 0; } // non zero ko true , else false

    // Returns an array [vector] containing the indicies of the neighbors of v
    vector<int> neighbors(int v)
    {
        vector<int> temp;// will store index of neighbour
        
        for (int i = 0; i < n; i++)
            if (matrix[v-1][i] != 0)
                temp.push_back(i+1);
                //column no.
                
        return temp;// vector conat
    }

    //print
    void display()
    {   
        cout << "Here is the filled Matrix : \n";
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    //Constructor
    Graph () { }

    //Copy Constructor 
    Graph (const Graph &obj)
	{for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /*code avi krne ka mood nahi hai*/ 
            }
        }
	}

    //
    

    //Distructor
    ~Graph()//  copied form stackOverflow
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
            //delete innner array of integer 
        }
        delete[] matrix;
        //delete pointer holding array of pointers
    }
};
/*
int main()
{
    Graph g;
    g.init(4);
    g.addEdge(1,2,10);
    g.addEdge(1,3,30);
    g.addEdge(2,4,40);
    g.addEdge(3,4,50);
    cout<<g.totalEdge()<<endl;

    //
    g.display();
    //
    vector<int> nList = g.neighbors(1);

    return 0;
}
*/