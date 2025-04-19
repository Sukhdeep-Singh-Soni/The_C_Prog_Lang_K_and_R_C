/* Write a program to write a pseuo random number generator and seed function to
 * initialize the starting for random number generator */

#include <stdio.h>

#define FILENAME	((char*)"005_pseudo_random_num_gen.c")

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main() {
    unsigned int seed_val = 45;
    srand(seed_val);
    printf("%s: Random Number Generated = %d\n",FILENAME, rand());
    return 0;
}

/* rand: return pseudo-random number integer on 0..32767 */
int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}
