//Adjacency Matrix 

#include <iostream>

using namespace std;

class Graph
{
    int matrix[100][100];
    int size;

    void setup()
    {
        cout << "Please Enter no of vertices: ";
        cin >> size;
        cout<<"Please input 1 for yes 0 for no."<<endl;
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                int choice;
                cout<<"is there any edge from "
                    <<i<<" to "<<j<< " ?  :  ";
                cin >> choice;
                if (choice == 1 )
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
    }
    void printMatrix()
    {
        cout << "Here is the filled Matrix : \n    ";
        for (int i = 1; i <= size; i++)
            cout << i << " ";
        cout << "\n- - ";
        for (int i = 1; i <= size; i++)
            cout << "- ";
        cout << endl;

        for (int i = 1; i <= size; i++)
        {
            cout << i << " | ";
            for (int j = 1; j <= size; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
public:
    void init()
    {
        setup();
        printMatrix();
    }
};

int main()
{
    Graph g1;
    g1.init();
    return 0;
}

// OUTPUT  : 
/* 
Please Enter no of vertices: 4
Please input 1 for yes 0 for no.      
is there any edge from 1 to 1 ?  :  0
is there any edge from 1 to 2 ?  :  1
is there any edge from 1 to 3 ?  :  0
is there any edge from 1 to 4 ?  :  1
is there any edge from 2 to 1 ?  :  1
is there any edge from 2 to 2 ?  :  0
is there any edge from 2 to 3 ?  :  1
is there any edge from 2 to 4 ?  :  0
is there any edge from 3 to 1 ?  :  0
is there any edge from 3 to 2 ?  :  1
is there any edge from 3 to 3 ?  :  0
is there any edge from 3 to 4 ?  :  1
is there any edge from 4 to 1 ?  :  1
is there any edge from 4 to 2 ?  :  0
is there any edge from 4 to 3 ?  :  1
is there any edge from 4 to 4 ?  :  0
Here is the filled Matrix : 
    1 2 3 4 
- - - - - - 
1 | 0 1 0 1 
2 | 1 0 1 0 
3 | 0 1 0 1 
4 | 1 0 1 0 

*/