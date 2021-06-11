#include<iostream>
#include<vector>
using namespace std;
//dont forget this, annoyed me for 1 fking hr ;

int main()
{   int size =10;
    vector<int> v1(size,0);
    //init all 10 values with 0
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    // vector<int> v[4];  // u can't


    vector<int> v2;
    int x2;
    // v.push_back(5);
    cout<<endl<<sizeof(v2); //12 why ??
    cout<<endl<<sizeof(x2); //4

    vector<int> v3 {1,2,3,6,7,8};
    cout<<endl<<v3[5]; //access successful :)

    int size_2 = 20 ;
    vector<int> v4(size_2); //x3 is size
    int value = 8;
    fill(v4.begin(),v4.end(),value);
    for(int i : v4) { cout<<i <<" "; }

    cout<<endl;
    
    vector<int> v5(2);
    v5[0] = 20;
    cout<<v5[0]<<endl;

    return 0;
}