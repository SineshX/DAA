//binary search
#include<iostream>
#include<time.h>
#include<math.h>
// #include<chrono>


using namespace std;
long int myRandom(unsigned long int n)
{   
    // int num;
    // num = (rand() % (upper-lower +1)) + lower;
    return rand()%n;
}

int mybubble(unsigned long int a[], unsigned long int n) //Bubble Sort
{   //improved bubbble sort
    int c = 0; //for swap
    //sorting using bubble sort :)
    for (int s = 0; s < n - 1; s++)
    {
        for (int i = 0; i < n-(s+1); i++) // or n-1 simply
        {
            if (a[i] > a[i + 1])
            {   
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
    }
    return 0;
}

int myBinary(unsigned long int a[],int lb,unsigned long int n, long int searched_num )
    {  
        if (lb <= n) 
        {
            int mid = (lb + n)/2;
            if (a[mid] == searched_num)
            return mid ;
            if (a[mid] > searched_num)
            return myBinary(a, lb, mid-1, searched_num);
            if (a[mid] < searched_num)
            return myBinary(a, mid+1, n, searched_num);
        }
        return -1;
    }
int main()
{  
    int n ,index;//size

    srand(time(0)); 
    // taking input


    for(int k=1;k<6;k++)
    {
        // cout<<"\nPlease enter size of array : ";
        // cin>>size;
        n = pow(10,k);

        unsigned long int a[n];

        srand(time(0));
        for(unsigned long int i=0;i<n;i++)
        {
            a[i]=myRandom(n);
        }

        // cout<<"\nHere is your list of numbers : ";
        // for(int i=0;i<n;i++)
        // {
        //     cout<<a[i]<<"\t";
        // }

        // cout<<"\nWhich number you wanna search ? : ";
        // scanf("%d",&s);
        // cout<<"\nseached number : "<<searched_num<<"\n";
        long int searched_num = myRandom(n);
        cout<<"\n to be searched : "<<searched_num;
        mybubble(a,n);
        //clock start 

        const clock_t clock_start = clock(); 
        index = myBinary(a,0,n,searched_num);

        //clock end 
        const clock_t clock_end = clock();
        
        double elapsed_time = ((clock_end-clock_start)/(double) CLOCKS_PER_SEC)*1000000; 
        cout<<"\nSize : "<<n<<",\tTime Taken  : "<<elapsed_time<< " micro second  ";
        cout<< index ; 

    }   
    return 0;
}

