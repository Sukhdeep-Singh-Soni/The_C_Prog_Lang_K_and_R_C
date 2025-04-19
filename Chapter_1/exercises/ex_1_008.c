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

/* The integer variables n b , n t , a n d n I are used to count the number of blanks,
tabs, and newlines. respectively. Initially. these three variables are set equal
to 0.
Inside the body of the wh i I e loop. the occurrence of each blank. tab, and
newline from input is recorded. All lf stateme n ts are executed each time
through the loop. If the character received is anything but a blank. tab. or
newline, t hen no action is taken. I f it is one of these three, then the appropriate
counter is incremented. The program prints the results when the wh le loop
terminates ( g e t cha r returns EDF).
The if-e1se statement is not presented until page 21 K&R. With that
knowledge the solution could be:
#Include<std1o.h>
/*count blanks,tabs, and new lines */
main() {
int nb, nt, nl, c;
nb = 0; /* number of blanks */
nl = 0; /* number of tabs */
nt = 0; /* number of new lines */
wh i l e < C c
if
.
g e t c h., r (
< c .. .
+ + nb ;
else 1f (c
+ + n t;
else 1f (c
+ + n 1;
pr i n t f < " Xd X d
»
number
! •EDF >
. )
I \ t I)
• \ n, )
Xd \ n " , nb ,
nt,
n l >;*/
