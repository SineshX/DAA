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
#include<iostream>
#include<algorithm>
using namespace std;

class myItem
{	
	public:
	int value,weight;
	float ratio;  
	
	void findratio()
	{	//value by weight
		ratio = (float)value/weight;
	}
	
}; 

//function to sort obj by ratio to use sort :)
// sort(obj,obj + 5,sortbyratio); 
bool sortbyratio(myItem const & A, myItem const & B) 
{
    return (A.ratio > B.ratio);
}

int main(void)
{	
	
    int items,maxWeight,count; //5 , 100
	
	cout<<"Please Enter No of Items  : ";
	cin>>items;
	myItem obj[items]; //for unsorted value,weight,ratio

	cout<<"Enter Space separated Values  : ";
	for (int i = 0; i < items; i++)
	{
		cin>>obj[i].value;
	}
	cout<<"Enter Space separated Weights : ";
	for (int i = 0; i < items; i++)
	{
		cin>>obj[i].weight;
	}

	cout<<"Enter Maximum size(Weight) of Sack : ";
	cin>>maxWeight;

    for (int i = 0; i < items; i++)
    {	//calculationg ratio
	    obj[i].findratio();
    }

	cout<<"Displaying Unsorted Data  :"<<endl ; 
	cout<<"Value | Weight | Ratio"<<endl;
	for (int i = 0; i < items; i++)
	{
		cout<<obj[i].value<<"       "<<obj[i].weight<<"        "<<obj[i].ratio<<endl;
	}
    
	sort(obj,obj + items,sortbyratio); //sorting objects :)
    
	cout<<"Displaying Sorted Data  : (Decending by ratio)"<<endl ; 
	cout<<"Value | Weight | Ratio"<<endl;
	for (int i = 0; i < items; i++)
	{
		cout<<obj[i].value<<"       "<<obj[i].weight<<"        "<<obj[i].ratio<<endl;
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
Please Enter No of Items  : 3
Enter Space separated Values  : 60 100 120 
Enter Space separated Weights : 10 20 30
Enter Maximum size(Weight) of Sack : 50
Displaying Unsorted Data  :
Value | Weight | Ratio
60       10        6
100       20        5
120       30        4
Displaying Sorted Data  : (Decending by ratio)
Value | Weight | Ratio
60       10        6
100       20        5
120       30        4
total weight taken : 50
total value : 240
********************************/
