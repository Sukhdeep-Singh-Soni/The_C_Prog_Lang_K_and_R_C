/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
   and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE		1000

int get_line(char line[], int limit);
void copy(char to[], char from[]);
void remove_trail(char line[], int len);

/* control the program */
main() {
    int len;
    int max;
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
	remove_trail(line, len);
        if (len > max) {
	    max = len;
    	    copy(longest, line);
        }
    }
    if (max > 0 && longest[0] != '\0') {
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
    for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
	    s[i] = c;
	} else {
	   if (overflow_flag == 0) {
	       overflow_flag = 1;
	   }
	}
    }
    if (c == '\n') {
	if(overflow_flag == 0) {
	    s[i] = '\n';
	    ++i;
	} else
            ++i;
    }
    if (overflow_flag == 1)
        s[lim - 1] = '\0';
    else
        s[i] = '\0';
    return i;
}

/* copy: copy 'to' to 'from' */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* remove_trail: remove trailing blanks and tabs from each input line and entirely remove blank lines */
void remove_trail(char s[], int len) {
    int i, j;

    for (i = len - 1; i >= 0; --i) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	    s[i] = '\0';
	else {
	    j = i;
	    break;
	}
    }
    if (i == 0)
        s[i] = '\0';
    else {
	    s[++j] = 'x';  /* ending indication that tells that the trailing blanks and tabs are removed */
            s[++j] = '\n';
            s[++j] = '\0';
    }
}
