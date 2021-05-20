/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   20-05-2021
 ****************************************
 * Implementation of chained matrix multiplication using Dynamic Programming. 
 ****************************************
 */

#include <iostream>
#include <climits>
#define N (32)
using namespace std;

int s[N][N];
void print(int i, int j);
void matrixChainMult(int *p, int n);

int main()
{
    int n;
    cout << "\nPlease enter the number of matrix: ";
    cin >> n;
    int p[n + 1];
    cout << "Please enter the chain(" << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    matrixChainMult(p, n);

    return 0;
}//end of main function

void matrixChainMult(int *p, int n)
{
    int m[n + 1][n + 1], j, q;

    for (int i = 0; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    print(1, n);
    cout<<"\nMinimum cost of multiplication  is = "<<m[1][n]<<endl;
}

void print(int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print(i, s[i][j]);
        print(s[i][j] + 1, j);
        cout << ")";
    }
}

/*************OUTPUT**************

Please enter the number of matrix: 4
Please enter the chain(5): 5 4 6 2 7
((A1(A2A3))A4)
Minimum cost of multiplication  is = 158

*/