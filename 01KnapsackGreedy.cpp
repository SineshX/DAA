/*
 ****************************************
 * Name   :   Sinesh Kumar
 * Roll No:   1917286
 * Date   :   20-04-2021
 ****************************************
 * Problem:  Write a program to impliment 0/1 Knapsack using Greedy Strategy.
 ****************************************
 *	Consider there is one thief, who want to take the most valueable items
 *	but he can carry maximum 10 kg.
 *	He can't take fraction of one item , Thus, he may take a item (1) or not (0)
 ****************************************
 */

#include<iostream>
#include<algorithm>
// #include<vector>
using namespace std;

class myItem
{	
	public:
	int value,weight;
	float ratio; //value by weight 
	myItem()
	{
		value = 0;
		weight = 1;
		ratio = 0;
	}
	void load(int w , int v)
	{	//just don't pass 0 as weight:_:
		value = v;
		weight = w;
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
	//using hardcoded data
    int items = 5,maxWeight = 100;
    int i_value[items] = {2,9,5,7,6};
    int i_weight[items] = {10,36,25,50,24};
	myItem obj[items]; //for unsorted ratio  

    for (int i = 0; i < items; i++)
    {
	    obj[i].load(i_weight[i],i_value[i]);
    }

	cout<<"displaying Unsorted data  :"<<endl ; 
	cout<<"ratio | weight | value"<<endl;
	for (int i = 0; i < items; i++)
	{
		cout<<obj[i].ratio<<"       "<<obj[i].weight<<"       "<<obj[i].value<<endl;
	}
    
	sort(obj,obj + items,sortbyratio); //sorting objects :)
    
	cout<<"displaying sorted data  :"<<endl ; 
	cout<<"ratio | weight | value"<<endl;
	for (int i = 0; i < items; i++)
	{
		cout<<obj[i].ratio<<"       "<<obj[i].weight<<"       "<<obj[i].value<<endl;
	}
	
	// since obj list is sorted 

	int  total_weight=0,total_value = 0;
	for(int i = 0;i<items;i++)
    {
        if(obj[i].weight + total_weight > maxWeight)
        {  
            continue;
        }
        else
        {
            total_weight += obj[i].weight;
			total_value  += obj[i].value;
        }
    }
	cout<<"total weight : "<<total_weight<<endl;
	cout<<"total value : "<<total_value<<endl;
    return 0;
}
/**********OUTPUT***********
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
total weight : 95
total value : 22
*/