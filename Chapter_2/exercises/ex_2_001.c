/*Exercise 2-1. Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.*/

 #include <stdio.h>
 #include <limits.h>
 #include <float.h>

 main() {
     printf("Range of Signed Char Min = %d, Max = %d\n", SCHAR_MIN, SCHAR_MAX);
     printf("Range of Unsigned Char Min = %u, Max = %u\n", 0U, UCHAR_MAX);
     printf("Range of Char Min = %d, Max = %d\n", CHAR_MIN, CHAR_MAX);
     printf("Range of Signed Short Int Min = %d, Max = %d\n", SHRT_MIN, SHRT_MAX);
     printf("Range of Unsigned Short Int Min = %u, Max = %u\n", 0U, USHRT_MAX);
     printf("Range of Signed Int Min = %d, Max = %d\n", INT_MIN, INT_MAX);
     printf("Range of Unsigned Int Min = %u, Max = %u\n", 0U, UINT_MAX);

     return 0;     
 }
