/* Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to
   write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE		1000

int get_line(char line[], int limit);
void copy(char to[], char from[]);
int remove_trail(char line[], int len);
void reverse(char line[], int len);

/* control the program */
main() {
    int len;
    int max;
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
	len = remove_trail(line, len);
	reverse(line, len);
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
int remove_trail(char s[], int len) {
    int i, j;

    if (len < MAXLINE - 2) {
        for (i = len - 1; i >= 0; --i) {
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	        s[i] = '\0';
	    else {
	        j = i;
	        break;
	    }
        }
        if (i == 0)
            s[i] = '\0'; /* blank line */
        else {
	    s[++j] = 'x';  /* ending indication that tells that the trailing blanks and tabs are removed */
            s[++j] = '\n';
            s[++j] = '\0';
        }
        return j;
    } else
          return 1;
}

/* reverse: reverse the input string */
void reverse(char s[], int len) {
    int i, j;
    int temp;
    
    if(len < MAXLINE) {
        for(i = 0, j = len - 2; i < j; ++i, --j) { /* len - 1 points to '\n' and len - 2 points to actual end of data */
            temp = s[i];
    	    s[i] = s[j];
	    s[j] = temp;	
        }
    }
}
