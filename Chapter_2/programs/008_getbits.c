/* consider the function getbits(x,p,n) that returns the (right adjusted) n -bit field of x
 * that begins at position p . We assume that bit position 0 is at the right end and that n
 * and p are sensible positive values. For example, getbits(x,4,3) returns the three bits in
 * positions 4, 3 and 2, right-adjusted. */

#include <stdio.h>

#define FILENAME	((char*)"008_getbits.c")

unsigned getbits(int x, int p, int n);

int main() {
    printf("%s: Getting 3 bits from position 4 in number 10 = %d\n", FILENAME, getbits(10,4,3));
    printf("%s: Getting 3 bits from position 3 in number 10 = %d\n", FILENAME, getbits(10,3,3));
    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(int x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
