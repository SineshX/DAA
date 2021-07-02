//pass array and length to get ur array sorted :) 

#include <stdio.h>

/***************************************************************
 * Sorting Algorithms *
 ****************************************************************/

void bubbleSort(int array[], int length);
void insertionSort(int array[], int length);
void selectionSort(int array[], int length);
void quickSort(int array[], int left, int right);
void mergeSort(int array[], int left, int right);


void setArray(int array[], int arrayReference[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = arrayReference[i];
    }
}
//bubble sort 
void bubbleSort(int array[], int length) {
    int i, j, cache;
    int n = length - 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (array[j] > array[j + 1]) {
                cache = array[j];
                array[j] = array[j + 1];
                array[j + 1] = cache;
            }
        }
    }
}
//indertion sort
void insertionSort(int array[], int length) {
    int i, j, cache;
    for (i = length; i > 0; i--) {
        for (j = 1; j < i; j++) {
            if (array[j] < array[j - 1]) {
                cache = array[j];
                array[j] = array[j - 1];
                array[j - 1] = cache;
            }
        }
    }
}

// selection sort
void selectionSort(int array[], int length) {
    int i, j, curMinIndex, cache;
    int n = length - 1;
    for (i = 0; i < n; i++) {
        curMinIndex = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[curMinIndex]) {
                curMinIndex = j;
            }
        }
        if (curMinIndex != i) {
            cache = array[curMinIndex];
            array[curMinIndex] = array[i];
            array[i] = cache;
        }
    }
}

// Quick Sort
void quickSort(int array[], int left, int right) {
    int i;
    int lengthLow = 0;
    int lengthHigh = 0;
    int cacheLow[right - left];
    int cacheHigh[right - left];
    for (i = left; i < right; i++) {
        if (array[i] > array[right]) {
            cacheHigh[lengthHigh++] = array[i];
        } else {
            cacheLow[lengthLow++] = array[i];
        }
    }

    for (i = 0; i < lengthLow; i++) {
        array[i + left] = cacheLow[i];
    }

    array[lengthLow + left] = array[right];
    for (i = 0; i < lengthHigh; i++) {
        array[i + lengthLow + 1 + left] = cacheHigh[i];
    }
    if (lengthLow > 1) {
        quickSort(array, left, (left + lengthLow - 1));
    }

    if (lengthHigh > 1) {
        quickSort(array, (left + lengthLow + 1), right);
    }
}

// Merge Sort
void mergeSort(int array[], int left, int right) {
    if (right > left) {
        int middle = (right + left) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, (middle + 1), right);

        int i, j, k;
        int n1 = middle - left + 1;
        int n2 =  right - middle;

        int L[n1], R[n2];
        for (i = 0; i < n1; i++) {
            L[i] = array[left + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = array[middle + 1 + j];
        }

        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k++] = L[i++];
            } else {
                array[k++] = R[j++];
            }
        }

        while (i < n1) {
            array[k++] = L[i++];
        }

        while (j < n2) {
            array[k++] = R[j++];
        }
    }
} //endt