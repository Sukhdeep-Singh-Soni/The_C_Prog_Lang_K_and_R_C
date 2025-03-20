/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
   in its input. */

#include <stdio.h>

#define IN		1
#define OUT		0

#define HORIZONTAL	0
#define VERTICAL	1

#define ASCII_RANGE     128

void print_histogram(int word_count);

main() {
    int c;
    unsigned char word_arr[ASCII_RANGE];
    for(int i = 0; i < ASCII_RANGE; i++)
	    word_arr[i] = 0;

    while((c = getchar()) != EOF) {
	    word_arr[c]++;
    }
#if VERTICAL
    /*print vertical histogram
    * 1. find the max length word for number of rows(column height) */
    int max = 0;
    int col_height = 0;
    for(int i = 0; i < ASCII_RANGE; i++)
        if(word_arr[i] > max)
	    max = word_arr[i];
    
    col_height = max;
    
    for(int i = 1; i <= max; i++) {
        for(int j = 0; j < ASCII_RANGE; j++) {
	    if(word_arr[j] < col_height)
	        printf(" ");
	    else
		printf("|");   
	}
	col_height--;
	printf("\n");
    }
    for(int i = 0; i < ASCII_RANGE; i++)
	if(i == 10 || (i >= 32 && i <= 126))
            printf("%c",i);
        else
            printf(" ");
    printf("\n");
#else
    for(int i = 0; i < ASCII_RANGE; i++) {
	printf("%c : ", i);
        print_histogram(word_arr[i]);
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
