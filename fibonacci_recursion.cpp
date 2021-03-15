#include<iostream>
#include<time.h>
// #include<stdlib.h>
// #include<math.h>
using namespace std;

long int fibo(long int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibo(n-1)+fibo(n-2);
    }

}

int main(void)
{
    int size;
    //cout<<"please input size of fibonacci series  : ";
    //cin>>size;
    // cout<<"\n fibonacci series  : ";
    for(int k =1; k<7 ; k++)
    {   
         //size = pow(10,k);
        size = 5*k;
        // cout<<"\n fibonacci series  : ";   
        clock_t c_start = clock();
        // for(int i=0;i<size;i++)
        // {
        //     cout<<fibo(i)<<" , ";
        // }
        fibo(size);
        clock_t c_end = clock();
        double elapsed_time = ((c_end - c_start) /(double) CLOCKS_PER_SEC)*1000000;
        cout<<"\n Size : "<< size << "  Time Taken : " << elapsed_time << " micro second \n\n";
    }
    

    return 0;

}