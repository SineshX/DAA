
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

void KnapSack(myItem obj[],int items,int maxWeight);

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
   KnapSack(obj,items,maxWeight);

   return 0;
}//end of main function 

void KnapSack(myItem obj[],int items,int maxWeight)
{
    
	sort(obj,obj + items,sortbyratio); //sorting objects :)
    
	cout<<"Displaying Sorted Data  : (Decending by ratio)"<<endl ; 
	cout<<"Value | Weight | Ratio"<<endl;
	for (int i = 0; i < items; i++)
	{
		cout<<obj[i].value<<"       "<<obj[i].weight<<"        "<<obj[i].ratio<<endl;
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
}
/**********OUTPUT***********
Please Enter No of Items  : 5
Enter Space separated Values  : 4 5 8 9 10
Enter Space separated Weights : 1 2 4 5 3 
Enter Maximum size(Weight) of Sack : 10
Displaying Unsorted Data  :
Value | Weight | Ratio
4       1        4
5       2        2.5
8       4        2
9       5        1.8
10       3        3.33333
Displaying Sorted Data  : (Decending by ratio)
Value | Weight | Ratio
4       1        4
10       3        3.33333
5       2        2.5
8       4        2
9       5        1.8
total weight : 10
total value : 27
*/