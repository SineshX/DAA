// 0/1 knapsack using dynamic programming

#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int weight[]={0,2,3,4,5};
    int value[]= {0,5,2,9,6};

    int items = 4 ,maxWeight = 6 ; //5 , 100
	
    //calc matrix
    int v[50][50];
    
    cout<<endl<<"Filled Matrix : "<<endl;   
	for(int i = 0; i <=items; i++)
    {   // j = cell weight // column ki capacity
        for(int j= 0;j<=maxWeight;j++)
        {   //current item(i) ka weight
            int currWeight = weight[i] ;
            // cout<<"current weight (wi) = "<<currWeight<< " , cell weight = "<<j;
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
                v[i][j]=max(  v[i-1][j]  ,  (v[i-1][j-currWeight] + value[i])  );
            }
        //  cout<<"  filled Value   : " <<v[i][j]<< "\t"<<endl; 
         cout<<v[i][j]<< "\t"; 
        }
         cout<<endl; 
    }
	cout<<"total weight : "<<maxWeight<<endl;
	cout<<"total value : "<<v[items][maxWeight]<<endl;
    
   
    return 0;
}