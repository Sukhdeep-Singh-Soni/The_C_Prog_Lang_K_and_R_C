/* Write a program to count the number of 1-bits in its integer argument */

#include <stdio.h>

int bitcount(int x);

#define FILENAME	((char*)"009_bitcount.c")

int main() {
    int number = 0xffff; /* integer 10 in hexadecimal form */
    printf("%s: Bitcount for %#x = %d\n", FILENAME, number, bitcount(number));

    return 0;
}

/* bitount: count 1 bits in x */
int bitcount(int x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01) /* integer 1 in octal form is 01 */
	    b++;
    return b;
}

