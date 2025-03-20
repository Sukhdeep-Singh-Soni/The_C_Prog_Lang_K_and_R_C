/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN	1
#define OUT	0

main()
{
    int c, state;
    int next_line_control = 0; /*control printing newline only once*/
    int last_state = OUT;
    state = OUT;

    while((c = getchar()) != EOF) {
	if(c == ' ' || c == '\t' || c == '\n') {
	    state = OUT;
	    next_line_control++;
	}
	else if(state == OUT) {
	    state = IN;
	    next_line_control = 0;
	}
	if(state == IN) {
	    putchar(c);
	} else if(next_line_control == 1 && last_state == IN) { /* will print newline once after every word, also handling boundary cond*/
	    putchar('\n');
	}
	last_state = state;
    }
}
