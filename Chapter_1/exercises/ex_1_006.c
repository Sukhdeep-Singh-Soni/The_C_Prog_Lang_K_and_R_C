/*Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.*/

#include <stdio.h>

/* copy input to output : 2nd version*/

main() {
    int c;

    while(c = getchar() != EOF)
        printf("%d",c);
    printf("%d\n",c);
}

/*There is only one reference to getchar(), now the code is more compact*/

/* The expression
c
•
•·
g e t c ha r ( )
EDF
is equivalent to
c
•
C g e t c ha r ( )
1•
EDF )
(page 17 K&R) . The program reads characters from the standard input and
uses the expression above . While get c h ar has a charac ter to read it docs not
return the end of file and
get c ha r < >
1 •
EOF
is true. So I is assigned to c When t he program encounters the end of file,
the expression is false. Then 0 is assigned to c and the loop terminates. */
