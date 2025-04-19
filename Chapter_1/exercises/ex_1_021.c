/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
   number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab .
   When either a tab or a single blank would suffice to reach a tab stop, which should be given
   preference? */

#include <stdio.h>
#define TAB_STOP	4

main() {
    int c;			/* current input character */
    int i;			/* keep track of character count */
    int Num_Spaces_To_TabStop;  /* store the number of spaces to put instead of tab which align to defined tab stop column value */
    int spaces;			/* count the number of continuous space */
    int prev_char;
    int Num_Tabs_Required, Num_Spaces_Required;
    int j;			/* keep track of starting position of continuous blanks */
    int tab_Spaces;
    int tab_Count;
    int left_Spaces;

    i = 0;
    j = 0;
    spaces = 0;
    tab_Spaces = 0;
    tab_Count = 0;
    left_Spaces = 0;
    prev_char = '\0';
    while((c = getchar()) != EOF) {
	++i;
        
	if (c == ' ') {
	    spaces++;
            if (j == 0)
                j = i - 1;
	}
	/* When a new line appears reset the starting point for tabstop */
	if (c == '\n') { 
	    i = 0;
	    j = 0;
	    spaces = 0;
	}

	/* When a tab detects; calaulate spaces to put */
	if (c == '\t') {
	    i -= 1;    /* decrement i to remove the tab index and add the number of spaces to i to align with the tab stop columns */
	    Num_Spaces_To_TabStop = (TAB_STOP - (i % TAB_STOP)); /* formula to calculate proper number of blanks to space to the
								    next tab stop e.g (4 - (5 % 4)) = 1 spaces to put */	    
	    i = i + Num_Spaces_To_TabStop; /* increment to number of spaces need to put, to align with the tab stop columns */
	    
	    /* put proper number blanks to space to the next tab stop */
	    while (Num_Spaces_To_TabStop--)
	        putchar(' ');
	} else if (c != ' ' && prev_char == ' ') {
	      while (tab_Spaces < spaces) {
	          Num_Spaces_To_TabStop = (TAB_STOP - (j % TAB_STOP));
		  tab_Spaces = tab_Spaces + Num_Spaces_To_TabStop;
		  j += Num_Spaces_To_TabStop;
		  if (tab_Spaces >= spaces) {
		      if (tab_Spaces != spaces)
	                  tab_Spaces -= Num_Spaces_To_TabStop;
		      if (tab_Spaces == spaces)
		          while(Num_Spaces_To_TabStop--)
		              putchar('T');
		      break;
		  }
		  while(Num_Spaces_To_TabStop--)
	              putchar('T');
	      }
	      if (tab_Spaces < spaces) {
	          left_Spaces = spaces - tab_Spaces;
		  while (left_Spaces--)
		      putchar('_');
	      }
	      tab_Spaces = 0;
	      spaces = 0;
	      j = 0;
	      putchar(c);
	} else if (c != ' ')
	      putchar(c);
	prev_char = c;
    }
}

/* Tab Stop column n should be a macro as to readily change the tab stop column size
 * based on our requirements */
