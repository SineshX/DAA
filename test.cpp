#include <iostream>
#include <vector>
using namespace std;
// testing two variable inside for loop one independent(count here)
int main()
{
    int i, count = 4;
    for (i = 0, count = 0; i < 10; i++)
    {   
        cout<<" i  = "<<i;
        cout<<"   count  = "<<count++<<endl;
        // cout<<" i  = "<<i<<endl;

    }
    
    return 0;
}