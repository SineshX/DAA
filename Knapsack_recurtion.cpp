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
    if(weight[n-1] <= maxWeight)
    {   //last item ka weight <= maxWeight
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
    int value[]= {19,13,9};
    int weight[]= {13,8,16};
    // int value[]= {70,80,90,200};
    // int weight[]= {20,30,40,70};

    int maxWeight=13;
    int n = sizeof(weight)/sizeof(weight[0]);
    int totalValue = knapsack(weight,value,maxWeight,n);
    cout << "Total Value of sack is :  "<<totalValue<<endl;
    return 0;
}

/***************OUTPUT*****************

Total Value of sack is :  8  

*/