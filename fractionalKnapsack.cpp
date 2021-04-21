/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   20-04-2021
 ****************************************
 * Problem:  Write a program to implement fractional Knapsack using the Greedy approach.
 ****************************************
 *	Consider there is one thief, who want to take the most valueable items
 *	but he can carry maximum 100 kg.
 *	He can take fraction of one item.
 ****************************************
 */
#include <iostream>
#include <algorithm>
using namespace std;

class myItem
{
public:
    int value, weight;
    float ratio; //value by weight

    void load(int w, int v)
    {
        value = v;
        weight = w;
        ratio = (float)value / weight;
    }
    void display()
    {
        cout << ratio << "       " << weight << "       " << value << endl;
    }
};

//function to sort obj by ratio to use sort :)
// sort(obj,obj + 5,sortbyratio);
bool sortbyratio(myItem const &A, myItem const &B)
{
    return (A.ratio > B.ratio);
}

int main(void)
{
    //using hardcoded data
    int items = 5, maxWeight = 100;
    int i_value[items] = {2, 9, 5, 7, 6};
    int i_weight[items] = {10, 36, 25, 50, 24};
    myItem obj[items]; //for unsorted ratio

    for (int i = 0; i < items; i++)
    {
        obj[i].load(i_weight[i], i_value[i]);
    }

    cout << "displaying Unsorted data  :" << endl;
    cout << "ratio | weight | value" << endl;
    for (int i = 0; i < items; i++)
    {
        obj[i].display();
    }

    sort(obj, obj + items, sortbyratio); //sorting objects :)

    cout << "displaying sorted data  :" << endl;
    cout << "ratio | weight | value" << endl;
    for (int i = 0; i < items; i++)
    {
        obj[i].display();
    }

    // since obj list is sorted

    float total_weight = 0, total_value = 0;
    for ( int i = 0; i < items; i++)
    {
        if (obj[i].weight + total_weight > maxWeight)
        {
            int remaning_weight = maxWeight - total_weight;
            total_weight += remaning_weight;
            total_value += (obj[i].ratio) * (remaning_weight);
            break;
        }
        else
        {
            total_weight += obj[i].weight;
            total_value += obj[i].value;
        }
    }
    cout << "total weight taken : " << total_weight << endl;
    cout << "total value : " << total_value << endl;
    return 0;
}

/************OUTPUT*************
displaying Unsorted data  :
ratio | weight | value
0.2       10       2
0.25       36       9
0.2       25       5
0.14       50       7
0.25       24       6
displaying sorted data  :
ratio | weight | value
0.25       36       9
0.25       24       6
0.2       10       2
0.2       25       5
0.14       50       7
total weight taken : 100
total value : 22.7

********************************/
