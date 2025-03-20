/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
   more blanks by a single blank. */

#include <stdio.h>

/*
 * ex1: if space comes at starting printf space once and if concurrent spaces comes ignore them and when a not space
 * character occurs print it.
 * ex2: if after a word a space comes print that space and if next characters are also spaces ignore them until get an non
 * space character.
 * ex3: if spaces comes at end, print once and ignore the spaces until \n character occures.  
 * */
main() {
 int c;
 int prev_c = 'a'; /* initializing it to any not space character*/

 while((c = getchar()) != EOF) {
     if(c == ' ' && prev_c == ' ') {
         ; /*do nothing if getting spaces*/
     } else {
          putchar(c);
     }
     prev_c = c;
 }
}
