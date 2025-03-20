/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
   the length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>
#define MAXLINE		1000

int get_line(char line[], int limit);
void copy(char to[], char from[]);

/* control the program */
main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0)
	    if(len > max) {
	        max = len;
		copy(longest, line);
	    }
    if(max > 0) {
	printf("LENGTH = %d\n", max);
        printf("%s", longest);
    }
    return 0;
}

/* get_line: get the length of arbitrary long input lines and print buffer as much as possible */
int get_line(char s[], int lim) {
    int i, c;
    int overflow_flag;

    overflow_flag = 0;
    for(i = 0;(c = getchar()) != EOF && c != '\n'; ++i) {
        if(i < lim - 1) {
	    s[i] = c;
	} else {
	   if (overflow_flag == 0) {
	       overflow_flag = 1;
	   }
	}
    }
    if(c == '\n') {
	if(overflow_flag == 0) {
	    s[i] = '\n';
	    ++i;
	} else
            ++i;
    }
    if(overflow_flag == 1)
        s[lim - 1] = '\0';
    else
        s[i] = '\0';
    return i;
}

/* copy: copy 'to' to 'from' */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
