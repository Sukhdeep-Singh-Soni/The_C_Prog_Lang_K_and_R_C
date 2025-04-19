/*
 * Exercise 1-2. Experiment to find out what happens when prints 's argument string contains
 * \c, where c is some character not listed above.
 * */

#include <stdio.h>

main() {
    printf(" printing not supported escape character(invisible char) -> \c\n");
    printf(" printing not supported escape character(invisible char) -> \7\n");
    printf(" printing not supported escape character(invisible char) -> \?\n");
}

/* where <BELL> is a short beep produced by ASCII 7. It is possible to have a
\ followed by up to three octal digits (page 37 K&R) to represent a character.
\ 7 is specified to be a short beep in the ASCII character set. */
