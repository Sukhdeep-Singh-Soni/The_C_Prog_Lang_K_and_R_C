/* Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments don't nest. */

/* Algorithm used -
 * First look for a forward slash (/) then look for either a second forward slash
 * just next to it or a star (*) adjacent to it.(marks the start of comments).
 * after a start of comment is detected
 *    - for single line comment detected look for a \n to end it.
 *    - for multi line comment detected look for adjacent * /  pattern without
 *      any space in between.
 *
 * */

/* Test comments  with "double quotes" and 'single quotes' 'a' 'b' // /* //
   // /* and nested comments */

#include <stdio.h>
#define FILENAME	((char*)"ex_1_023.c")
main() {
	int c;
	int temp;

	while ((c = getchar()) != EOF) {
		if (c == '/') {
			temp = c;
			c = getchar();
			if (c == '/') {	/* single line comment detected */
				while ((c = getchar()) != '\n'); // end of single line comment
				putchar('\n');
			} else if (c == '*') { /* multi line comment detected */
				again: while ((c = getchar()) != '*');
				if ((c = getchar()) != '/')
					goto again;			
			} else {
				putchar(temp);
				putchar(c);
			}
		} else
			putchar(c);
	}
}
