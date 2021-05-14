// 0/1 knapsack using dynamic programming

#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int weights[]={0,2,3,4,5};
    int values[]={0,1,2,5,6};

    int items = 4 ,maxWeight = 8 ; //5 , 100
	/*
	cout<<"Please Enter No of Items  : ";
	cin>>items;

    values[0]=0;
	cout<<"Enter Space separated Values  : ";
	for (int i = 1; i <=items; i++)
	{
		cin>>values[i];
    }

    weights[0]=0;
	cout<<"Enter Space separated Weights : ";
	for (int i = 1; i <=items; i++)
	{
		cin>>weights[i];
	}

	cout<<"Enter Maximum size(Weight) of Sack : ";
	cin>>maxWeight;
    */
    //calc matrix
    int v[50][50];
    //beaceuse of 0th row n column
    
    //print empty 
    for (int i = 0; i <=items; i++)
        {
            for (int j = 0; j < maxWeight; j++)
            {
                cout<<v[i][j]<<"\t";
            }
            cout<<endl;
        }

    cout<<endl;   
	for(int i = 0; i <=items; i++)
    {   // j = current weight // column ki capacity
        for(int j= 0;j<=maxWeight;j++)
        {   
            int currWeight = weights[i] ;
            cout<<"current weight (wi) = "<<currWeight<< " , cell weight = "<<j;
            //current item(i) ka weight 
            if(i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if(currWeight > j)
            { // greater than column(j) ka weight 
                v[i][j]=v[i-1][j]; 
              // value of just above
            }
            else if(currWeight <= j)
            {   // max is built in fn
                v[i][j]=max(  v[i-1][j]  ,  (v[i-1][j-currWeight] + values[i])  );
               printf("\n max(  %d  ,  (%d + %d)  )\n",v[i-1][j],v[i-1][j-currWeight],values[i]);
            }
         cout<<"  filled  : " <<v[i][j]<< "\t"<<endl; 
        }
         cout<<endl; 
    }
	cout<<"total weight : "<<maxWeight<<endl;
	cout<<"total value : "<<v[items][maxWeight]<<endl;
    
    
    
   
    return 0;
}