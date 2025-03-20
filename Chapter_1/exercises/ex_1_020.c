/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
   of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
   Should n be a variable or a symbolic parameter? */

#include <stdio.h>
#define TAB_STOP	4

main() {
    int c;			/* current input character */
    int i;			/* keep track of character count */
    int Num_Spaces_To_TabStop;  /* store the number of spaces to put instead of tab which align to defined tab stop column value */
    
    i = 0;
    while((c = getchar()) != EOF) {
	++i;

	/* When a new line appears reset the starting point for tabstop */
	if (c == '\n') 
	    i = 0;

	/* When a tab detects; calaulate spaces to put */
	if (c == '\t') {
	    i -= 1;    /* decrement i to remove the tab index and add the number of spaces to i to align with the tab stop columns */
	    Num_Spaces_To_TabStop = (TAB_STOP - (i % TAB_STOP)); /* formula to calculate proper number of blanks to space to the
								    next tab stop e.g (4 - (5 % 4)) = 1 spaces to put */	    
	    i = i + Num_Spaces_To_TabStop; /* increment to number of spaces need to put, to align with the tab stop columns */
	    
	    /* put proper number blanks to space to the next tab stop */
	    while (Num_Spaces_To_TabStop--)
	        putchar(' ');
	} else
	      putchar(c);
    }
}

/* Tab Stop column n should be a macro as to readily change the tab stop column size
 * based on our requirements */
