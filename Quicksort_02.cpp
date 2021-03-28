// Write a recursive program for Quick sort. Compute its time complexity.
//Use a random function to generate random numbers.
//Use time function to compute time.
//Draw graphs between size of input and execution time .

#include <iostream>
#include <sys/time.h>
#include <time.h>

using namespace std;

void randInput(int[], int);
void dispArray(int[], int);
int partition(int[], int, int);
void quickSort(int[], int, int);

inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Quick Sort
int main()
{

    double tStart, tEnd;
    struct timeval tv;

    int arr[100000], i;

    for (i = 1; i < 11; i++)
    {
        int size = 10000 * i;
        randInput(arr, size);

        gettimeofday(&tv, NULL);
        tStart = tv.tv_sec + (tv.tv_usec / 1000000.0);

        quickSort(arr, 0, size - 1);

        gettimeofday(&tv, NULL);
        tEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);

        cout << "\n"
             << "Size : " << size
             << "\t Time Taken  : " << tEnd - tStart
             << "   microsec";
    }

    return 0;
} // end of main function 

//Partion Function
int partition(int a[], int l, int r)
{
    int i, j, temp;
    int p;

    p = a[l];
    i = l;
    j = r + 1;

    do
    {
        do
        {
            i++;
        } while (a[i] < p);
        do
        {
            j--;
        } while (a[j] > p);

        swap(&a[i], &a[j]);
    } while (i < j);

    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);

    return j;
}
//QuickSort
void quickSort(int a[], int l, int r)
{
    int s;
    if (l < r)
    {
        s = partition(a, l, r);
        quickSort(a, l, s - 1);
        quickSort(a, s + 1, r);
    }
}

void randInput(int X[], int n)
{

    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        X[i] = rand() % 10000;
    }
}

void dispArray(int X[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << X[i];
    }
}

/*

OUTPUT : 
Size : 10000     Time Taken  : 0.00101995   microsec
Size : 20000     Time Taken  : 0.00199389   microsec
Size : 30000     Time Taken  : 0.0030129   microsec
Size : 40000     Time Taken  : 0.00302601   microsec
Size : 50000     Time Taken  : 0.00500011   microsec
Size : 60000     Time Taken  : 0.00599504   microsec
Size : 70000     Time Taken  : 0.0059979   microsec
Size : 80000     Time Taken  : 0.00700021   microsec
Size : 90000     Time Taken  : 0.00799894   microsec
Size : 100000    Time Taken  : 0.00900006   microsec

*/  
