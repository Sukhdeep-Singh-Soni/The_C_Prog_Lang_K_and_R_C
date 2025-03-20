/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define IN		1
#define OUT		0

#define HORIZONTAL	0
#define VERTICAL	1

void print_histogram(int word_count);

main() {
    int c, word_count, state, new_word;
    state = OUT;
    word_count = 0;
    new_word = 0;
#if VERTICAL
    int hist_vertical[1000];
    int index = 0;
    for(int i = 0; i < 1000; i++)
	    hist_vertical[i] = 0;
#endif
    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
	    state = OUT;
	    if(new_word == 1) { /* detect when we get out of a new word */
#if HORIZONTAL
	    print_histogram(word_count);
#else
	    hist_vertical[index++] = word_count;
#endif
	        
		word_count = 0;
		new_word = 0;
	    }
	}
	else if(state == OUT) { //it is a character other than space newline and tab
	    state = IN;
	    new_word = 1;
	}
	if(state == IN) {
	    word_count++;
	}
    }
#if VERTICAL
    /*print vertical histogram
    * 1. find the max length word for number of rows(column height) */
    int max = 0;
    int col_height = 0;
    for(int i = 0; i <= index; i++)
        if(hist_vertical[i] > max)
	    max = hist_vertical[i];
    
    col_height = max;
    
    for(int i = 1; i <= max; i++) {
        for(int j = 0; j <= index; j++) {
	    if(hist_vertical[j] < col_height)
	        printf(" ");
	    else
		printf("|");   
	}
	col_height--;
	printf("\n");
    }
#endif
}

void print_histogram(int word_count) {
#if HORIZONTAL
    for(int i = 0; i < word_count; i++)
        printf("=");
    printf("\n");
#else //vertical

#endif
}
