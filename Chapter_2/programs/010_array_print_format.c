/* this loop prints n
elements of an array, 10 per line, with each column separated by one blank, and with each line
(including the last) terminated by a newline. */

#include <stdio.h>

int main() {
    int arr[] = {12, 34, 56, 78, 90, 87, 567, 34, 12, 45, 65, 87, 12, 67, 8789, 34, 12, 34, 5, 23, 44,
                 76, 87, 13, 14, 10, 91, 84, 82 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        printf("%6d%c",arr[i], (i%10==9 || i==n-1)? '\n' : ' ');
    return 0;
}
