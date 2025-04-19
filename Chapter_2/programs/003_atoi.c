/* Write a program to convert string to integer */

#include <stdio.h>

#define FILENAME	"003_atoi.c"

int ascii_to_int(const char *s);

int main() {
    const char *s = "12067";
    printf("%s: converted value = %d\n",(char*)FILENAME, ascii_to_int(s));
    return 0;
}

/* ascii_to_int: convert ascii/character string to integer */
int ascii_to_int(const char *s) {
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}
