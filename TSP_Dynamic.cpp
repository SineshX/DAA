//travelling salesman problem using dynamic programming 

#include <iostream>
using namespace std;

int arr[10][10], completed[10], n, cost = 0;
void init();
void mincost(int city);
int least(int c);

int main()
{
    init();
    cout<<"\n\nThe Path is:\n";

    mincost(0); 
    cout<<"\n\nMinimum cost is "<<cost<<endl;

    return 0;
}//end of main function

void init()
{
    int i, j;
    cout << "Enter the number of Cities  : ";
    cin >> n;
    cout << "\nEnter the Cost of travelling \n";

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Elements of Row " << i+1 << " : ";
        for (j = 0; j < n; j++)
            cin >> arr[i][j];
        completed[i] = 0;
    }

    cout << "\n\nThe cost Matrix is:";
    for (i = 0; i < n; i++)
    {
        cout << endl;
        for (j = 0; j < n; j++)
            cout << "\t" << arr[i][j];
    }
}
void mincost(int city)
{
    int i, ncity;
    completed[city] = 1;
    cout << city + 1 << "--->";
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += arr[city][ncity];
        return;
    }
    mincost(ncity);
}
int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if ((arr[c][i] != 0) && (completed[i] == 0))
            if (arr[c][i] + arr[i][c] < min)
            {
                min = arr[i][0] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}
/*********OUTPUT*********************


Enter the number of Cities  : 4

Enter the Cost of travelling 

Enter Elements of Row 1 : 3 4 0 2

Enter Elements of Row 2 : 2 0 4 3

Enter Elements of Row 3 : 1 2 3 4

Enter Elements of Row 4 : 2 5 7 3


The cost Matrix is:
        3       4       0       2
        2       0       4       3
        1       2       3       4
        2       5       7       3

The Path is:
1--->4--->2--->3--->1

Minimum cost is 12                       
*/