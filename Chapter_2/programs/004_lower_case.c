/* Write a program to convert letters into lower case and
 * handle digits and already lower case letters and special characters */

#include <stdio.h>

#define FILENAME	((const char *)"004_lower_case.c")

void lower_case(char *s);

int main() {
    char s[] = "AbCdEfGh Ha HA ha ! 0984\0";
    lower_case(s);
    printf("%s: lower case converted string = %s\n",FILENAME, s);
    return 0;
}

/* lower_case: convert capital letters into lower case */
void lower_case(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + ('a' - 'A');
}

/*tried with char *s = "AbCD..." but getting segmentation fault because the string
 * assigned to  char *s might be stored in the read only section of memory and i am
 * assigning/updating that value i.e write operation on a read only data
 * but with array its not creating any issue because array string is accessible to 
 * us for read and write operation */
