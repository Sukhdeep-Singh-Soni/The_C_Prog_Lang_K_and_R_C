/* Write a program squeeze to delete all occurances of a character c from string/array 
 * of char s */

#include <stdio.h>

#define FILENAME	((char*)"006_squeeze.c")

void squeeze(char s[], int c);

int main() {
    char str[] = "The character c will be deleted from this string cccaaaccc";
    int c = 'c';
    squeeze(str, c);
    printf("%s: String after deleting character %c = %s\n",FILENAME,c,str);
    return 0;
}

/* squeeze: deletes all c form s */
void squeeze(char s[], int c) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
	    s[j++] = s[i];
    s[j] = '\0';
}
