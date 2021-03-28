#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <time.h>
using namespace std;

int fibo(int n)
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


int main()
{
    int size;
    //1
    //#include <chrono>

    auto clock_start = std::chrono::high_resolution_clock::now();
    //fn
    auto clock_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(clock_end - clock_start).count();
    cout << "Time Taken  : " << elapsed_time_ms << " ms\n\n";

//2
// #include <time.h>

    clock_t Start, End;

    Start = clock();
    //fn
    End = clock();

    cout << "\n"
         << "Size : " << size
         << "\t Time Taken  : " << 1000000 * (End - Start / (double)CLOCKS_PER_SEC)
         << "   microsec\n\n";

//3
// #include <sys/time.h>
// #include <time.h>

    double tStart, tEnd;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    tStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
    //fn
    gettimeofday(&tv, NULL);
    tEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
    cout << "\n"
         << "Size : " << size
         << "\t Time Taken  : " << tEnd - tStart
         << "   microsec\n\n";

    return 0;
}
