/* Write a program to add an s to item if the number of items are more than 1 */

#include <stdio.h>

#define FILENAME	((char*)"add_s.c")

int main() {
    int num_Items = 88;

    printf("%s: %d item%s in the list\n",FILENAME, num_Items, (num_Items == 1) ? "" : "s");

    return 0;
}
