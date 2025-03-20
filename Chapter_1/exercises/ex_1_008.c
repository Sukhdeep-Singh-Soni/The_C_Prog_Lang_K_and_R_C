/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

main() {
    int c, nl, nb, nt;

    nl = nb = nt = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n')
            ++nl;
	if(c == '\t')
            ++nt;
	if(c == ' ')
	    ++nb;
    }
    printf("blanks    - %d\ntabs      - %d\nnewlines  - %d\n",nb,nt,nl);
}
