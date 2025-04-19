/* Count number of occurances of Digits, White Spaces and Others */

#include <stdio.h>

#define FILENAME	((char*)"013_cnt_dig_ws_oth_switch.c")

int main() {
    int c, ndigit[10], nwhite, nother;

    nwhite = nother = 0;
    for (int i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch(c) {
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
	    ndigit[c - '0']++;
	    break;
	case ' ':
	case '\n':
	case '\t':
	    nwhite++;
	    break;
        default:
	    nother++;
	    break;
	}
    }
    printf("Digits = ");
    for (int i = 0; i < 10; i++)
        printf(" %d,", ndigit[i]);
    printf(" White Spaces = %d, Other Chars = %d\n", nwhite, nother);
    return 0;
}
