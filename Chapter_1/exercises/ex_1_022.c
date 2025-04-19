/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more 
 * shorter lines after the last non-blank character that occurs before the n -th 
 * column of input. Make sure your program does something intelligent with very 
 * long lines, and if there are no blanks or tabs before the specified column. */

/* Algorithm :
 * 1. read whole line. if line length crosses COLUMN_WIDTH then print that line and again start filling buffer from 0 onwards
 * 2. while printing if there are blanks/tabs just before the COLUMN_WIDTH then print line otherise save the characters in
 *    a temperory buffer until you get a blank/tab than print the line and the saved buffer(in reverse) */

#include <stdio.h>
#define TABSTOP		8
#define MAXLINE		1000
#define COLUMN_WIDTH	10	/* indicates the n-th column of input before which the last non-blank character will be detected */

int get_line(char line[], int limit);
void copy(char to[], char from[]);
int remove_trail(char line[], int len);
void reverse(char line[], int len);
void str_concat(char *s, char *t);

int newpos(int pos);
int findblnk(int pos);
void printl(int pos);
int exptab(int pos);

char temp_buff[50] = {0}; /* temporarily store the extra characters before the last blank character */
int offset = 1;
int shift = 0;

char line[MAXLINE] = {0};
/* control the program */
main() {
    int len;
#if 0
    int pos = 0;
    int c;
    while ((c = getchar()) != EOF) {
        line[pos] = c;
        if (c == '\t')
	    pos = exptab(pos);
	else if (c == '\n') {
	    printl(pos);	/* print current input line */
	    pos = 0;
	} else if (++pos >= COLUMN_WIDTH) {
	    pos = findblnk(pos);
	    printl(pos);
	    pos = newpos(pos); 
	}
    }
#else
    get_line(line, MAXLINE);
    printf("%s",line);
#endif
    return 0;
}

/*newpos: rearrange th line with new position */
int newpos(int pos) {
    int i, j;

    if (pos <= 0 || pos >= COLUMN_WIDTH)
        return 0;			/* nothing to rearrange*/
    else {
        i = 0;
	for (j = pos; j < COLUMN_WIDTH; ++j) {
	    line[i] = line[j];
	    ++i;
	}
	return i;	/* new position in line */
    }
}

/* findblk: find blank in position */
int findblnk(int pos) {
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)	/* no blanks in the line */
        return COLUMN_WIDTH;
    else		/* at least one blank */
        return pos + 1; /* pos after the blank */
}

/* exptab: expand tab into blanks */
int exptab(int pos) {
    line[pos] = ' '; /* tab is at least 1 blank */
    for (++pos; pos < COLUMN_WIDTH && pos % TABSTOP != 0; ++pos)
        line[pos] = ' ';
    if (pos < COLUMN_WIDTH) /* room left in current line */
        return pos;
    else {                  /* current line is full*/
        printl(pos);
	return 0;	    /* reset current position */
    }
}

/* printl: print line until position column */
void printl(int pos) {
    int i;

    for(i = 0; i < pos; i++)
        putchar(line[i]);
    if (pos > 0)		/* any chars printed ? */
        putchar('\n');
}

/* get_line: get the length of arbitrary long input lines and print buffer as much as possible */
int get_line(char s[], int lim) {
    int i, c;
    int j = 0; /* store last blank character index */
    int k = 0; /* keep track of temp_buff index */
    int temp_index = 0;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF;) {
        s[i] = c;
	if (c == '\n') {
	    for (int n = 0; n < i; n++)
	        putchar(s[n]);
	    if (i > 0)
	        putchar('\n');
	    i = 0;
	}
	if (++i >= COLUMN_WIDTH) {
	    while (i > 0 && s[i] != ' ')
	        --i;
	    if (i == 0)
	        i = COLUMN_WIDTH;
	    else
	        i += 1;

	    for (int n = 0; n < i; n++)
	        putchar(s[n]);
	    if (i > 0)
  	        putchar('\n');
	   
	    if (i <= 0 || i >= COLUMN_WIDTH)
	        i = 0;
	    else {
		int n = 0;
	        for (int j = i; j < COLUMN_WIDTH; j++) {
	 	    s[n] = s[j];
		    ++n;
	    	}
		i = n;
	    }
	}
    }
    return i;
}

/* copy: copy 'to' to 'from' */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* str_concat: concatenate string t to string s; assuming s is big enough */
void str_concat(char *s, char *t) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        ++i;
    while ((s[i++] = t[j++]) != '\0')
        ;
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
    
    for(i = 0, j = len - 1; i < j; ++i, --j) { /* len - 1 points to '\n' and len - 2 points to actual end of data */
            temp = s[i];
    	    s[i] = s[j];
	    s[j] = temp;	
    }
}
