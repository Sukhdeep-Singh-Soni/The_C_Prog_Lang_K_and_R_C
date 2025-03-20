/*Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.*/

#include <stdio.h>

/* copy input to output : 2nd version*/

main() {
    int c;

    while(c = getchar() != EOF) {
        printf("%d",c);
    }
    printf("%d\n",c);
}

/*There is only one reference to getchar(), now the code is more compact*/
