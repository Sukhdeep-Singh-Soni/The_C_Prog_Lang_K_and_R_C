/* Write a program to concatenate string t to string s where assuming s to be big enough
 * to hold the resultant value */

#include <stdio.h>

#define FILENAME	((char*)"007_strconcat.c")

void str_concat(char s[], char t[]);

int main() {
    char s[100] = "This is base string...";
    char t[] = "This is concatenated string...";
    str_concat(s,t);
    printf("%s: Concatenated String = %s\n", FILENAME, s);
    return 0;
}

/* strconcat: concatenate t to end of s; s must be big enough */
void str_concat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0')	/* find end of s */ 
        ++i;
    while ((s[i++] = t[j++]) != '\0')	/* copy t into s */
        ;
}

