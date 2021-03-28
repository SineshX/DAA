//Write a recursive program for Merge Sort. Compute its time complexity.
//Use a random function to generate random numbers.
//Use time function to compute time. 
//Draw graphs between size of input and execution time .

#include <iostream>
#include <sys/time.h>
#include <time.h>

using namespace std;

void randInput(int[], int);
void dispArray(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

//Merge Sort
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

        mergeSort(arr, 0, size - 1);

        gettimeofday(&tv, NULL);
        tEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);

        cout << "\n"
             << "Size : " << size 
             << "\t Time Taken  : " << tEnd - tStart 
             << "   microsec";
    }

    return 0;
}

//Merge
void merge(int a[], int low, int mid, int high)
{

    int i, k, j, b[100000];
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
            // input in b[k] = a[i] // simple 
            //those are for increament only
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {

        b[k++] = a[i++];
    }
    while (j < high)
    {
        b[k++] = a[j++];
    }
    for (i = low; i < k; i++)
    {
        a[i] = b[i];
    }
}

//MergeSort

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
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
Size : 10000     Time Taken  : 0.0158041   microsec
Size : 20000     Time Taken  : 0.0271871   microsec
Size : 30000     Time Taken  : 0.0331912   microsec
Size : 40000     Time Taken  : 0.0411189   microsec
Size : 50000     Time Taken  : 0.066813   microsec
Size : 60000     Time Taken  : 0.0796101   microsec
Size : 70000     Time Taken  : 0.0826919   microsec
Size : 80000     Time Taken  : 0.107901   microsec
Size : 90000     Time Taken  : 0.11983   microsec
Size : 100000    Time Taken  : 0.127641   microsec

*/