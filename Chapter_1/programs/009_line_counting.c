
#include <stdio.h>

/* count line in input */

main() {
    int c, nl;

    while((c = getchar()) != EOF)
        if(c == '\n')
            ++nl;
    printf("%d\n",nl);
}
