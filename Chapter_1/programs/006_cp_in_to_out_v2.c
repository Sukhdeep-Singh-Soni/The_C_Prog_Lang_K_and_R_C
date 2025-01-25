
#include <stdio.h>

/* copy input to output : 2nd version*/

main() {
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }
}

/*There is only one reference to getchar(), now the code is more compact*/
