/* Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
   for conversion. */

#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

float fahr_to_cel(int fahr);

 /* test Fahrenheit to Celsius */
 main() {
     int fahr;

     for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
         printf("%3d\t%6.1f\n", fahr, fahr_to_cel(fahr));
     return 0;
 }

 /* fahr_to_cel: convert Fahrehheit to Celsius */
 float fahr_to_cel(int fahr) {
     float celsius;

     celsius = (5.0 / 9.0) * (fahr - 32.0);
     return celsius;
 }
