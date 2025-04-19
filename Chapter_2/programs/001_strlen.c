/* strlen function implementation */

#include <stdio.h>

int stringLength(char *str);

int main() {
    char str[] = "Hello world!\n";
    printf("String Length = %d\n", stringLength(str));
    return 0;
}

int stringLength(char *str) {
    int i;

    i = 0;
    while (str[i] != '\0')
        ++i;
    return i;
}
