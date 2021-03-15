#include<iostream>
#include<time.h>

using namespace std;
int main()
{
    int size,pre1=1,pre2=0;
    long int next_num = 0;
    for(int k =1; k<7 ; k++)
    {   
        
        size = 5*k;
       
        clock_t c_start = clock();
        for(int i=1;i<=size;i++)
        {   
            if(i==1){
                //cout<<0<<"\n";
            }
            else if(i==2){
               // cout<<1<<"\n";
            }
            else{   
            next_num = pre1+pre2;
            pre2 = pre1;
            pre1 = next_num;
            //cout<<next_num<<"\n";
            }

        }
        clock_t c_end = clock();
        double elapsed_time = ((c_end - c_start) /(double) CLOCKS_PER_SEC)*1000000000;
        cout<<"\n Size : "<< size << "  Time Taken : " << elapsed_time << " nano second \n\n";
    }

    return 0;
}