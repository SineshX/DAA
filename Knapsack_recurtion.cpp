/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   13-05-2021
 ****************************************
 * Problem:   0/1 Knapsack using Dynamic Programming.
 ****************************************
 */

#include <iostream>
using namespace std;

int knapsack(int weight[],int value[],int maxWeight,int n)
{
    if(n==0||maxWeight==0)
    {
        return 0;
    }
    if(weight[n-1]<=maxWeight)
    {
        return max((value[n-1]+knapsack(weight,value,maxWeight-weight[n-1],n-1)),
                    knapsack(weight,value,maxWeight,n-1));
    }
    else{
        knapsack(weight,value,maxWeight,n-1);
    }

    // return 0;
}

int main()
{
    int value[]= {1,2,5,6};
    int weight[]= {2,3,4,5};
    int maxWeight=8;
    int n=sizeof(weight)/sizeof(weight[0]);
    cout << "answer is: "<<knapsack(weight,value,maxWeight,n)<<endl;
    return 0;
}

/***************OUTPUT*****************

answer is: 8   

*/