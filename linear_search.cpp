//searching an element in array
#include<iostream>
#include<time.h>
#include<math.h>
// #include<chrono>


using namespace std;

long int myRandom(long long int size)
{   
    // int num;
    // num = (rand() % (upper-lower +1)) + lower;
    return rand()%size;
}

int main()
{   
    int flag=0;  
    long long int size;
    for(int k=1;k<7;k++)
    {
        // cout<<"\nPlease enter size of array : ";
        // cin>>size;
        size = pow(10,k);

        long long int a[size];

        srand(time(0));
        for(long long int i=0;i<size;i++)
        {
            a[i]=myRandom(size);
        }

        // cout<<"\nHere is your list of numbers : ";
        // for(int i=0;i<size;i++)
        // {
        //     cout<<a[i]<<"\t";
        // }

        // cout<<"\nWhich number you wanna search ? : ";
        // scanf("%d",&s);
        long long int searched_num = myRandom(size);
        // cout<<"\nseached number : "<<searched_num<<"\n";
        //clock start 

        const clock_t clock_start = clock(); 
        for(long long int i=0;i<size;i++)
        {
            if(searched_num==a[i])
            {  
                flag++;
            } 
        }
        //clock end 
        const clock_t clock_end = clock();
        /*
        if(flag == 0) //rem to apply ==
        {
            cout<<"Number not found :_: \n";
        }
        else
        {
            cout<<" Number Found "<<flag<< " times \n";
        }
        */
        
        long double elapsed_time = ((clock_end-clock_start)/(long double) CLOCKS_PER_SEC)*1000000; 
        cout<<"\nSize : "<<size<<",\tTime Taken  : "<<elapsed_time<< " micro second";

    }   
    
    return 0;
}