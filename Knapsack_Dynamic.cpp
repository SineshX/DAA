// 0/1 knapsack using dynamic programming

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int weight[] = {0, 2, 3, 4, 5};
    int value[] = {0, 5, 2, 9, 6};

    int items = 4, maxWeight = 6;

    //calc matrix
    int v[50][50];
    //in general size would be [ no_of_item+1 x maxWeight+1 ]
    //one raw n column for 0

    cout << "\nFilled Matrix : " << endl;
    for (int i = 0; i <= items; i++) //for row
    {                                // columnWeight = j
        for (int columnWeight = 0; columnWeight <= maxWeight; columnWeight++)
        { //current item(i) ka weight
            int currItemWeight = weight[i];
            // cout<<"current weight (wi) = "<<currItemWeight<< " , cell weight = "<<columnWeight;
            if (i == 0 || columnWeight == 0)
            {
                v[i][columnWeight] = 0;
            }
            else if (currItemWeight > columnWeight)
            { // greater than column ka weight
                v[i][columnWeight] = v[i - 1][columnWeight];
                // value of columnWeight just above
            }
            else if (currItemWeight <= columnWeight)
            { // max is built in fn
                v[i][columnWeight] = max(v[i - 1][columnWeight], (v[i - 1][columnWeight - currItemWeight] + value[i]));
            }
            //  cout<<"  filled Value   : " <<v[i][columnWeight]<< "\t"<<endl;
            cout << v[i][columnWeight] << "\t";
        }
        cout << endl;
    }
    cout << "total weight : " << maxWeight << endl;
    cout << "total value : " << v[items][maxWeight] << endl;

    return 0;
}