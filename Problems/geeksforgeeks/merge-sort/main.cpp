#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
void merge(int arr[], int l, int m, int r);
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
#ifdef LOCAL_TEST
    fstream f("input.txt");
#endif
    int arr[1000], n, T, i;
    cin >> T;
    while (T--) {
        cin >> n;
        for (i = 0; i<n; i++)
            cin >> arr[i];
        mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* The task is to complete merge() which is used
in below mergeSort() */
/*   l is for left index and r is right index of the
sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
if (l < r)   {
int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
} */
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    // Your code here
}