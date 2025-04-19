/* Write a program to search x in v[n] using binary search algorithm */

#include <stdio.h>

#define FILENAME	((char*)"012_binsearch.c")

int binsearch(int v[], int n, int x);

int main() {
    int arr[] = {12, 18, 24, 26, 31, 39, 40, 41, 45, 54, 67, 87, 120, 153};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 153;

    printf("%s: Binary Search Result = %d\n", FILENAME, binsearch(arr, n, element));
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int v[], int n, int x) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
	if (x > v[mid])
	    low = mid + 1;
	else if (x < v[mid])
	    high = mid - 1;
	else /* x == v[mid] */
	    return mid;
    }
    return -1;
}

