/*
 * Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table.
 * */

#include <stdio.h>

/*  print celsius-fahrenheit
    cel = 0, 20, 40, ... 300 ; floating point version*/

main() {
    float fahrenheit, cel;
    int lower, upper, step;

    lower = 0;   /*lower limit of fahr*/
    upper = 300; /*upper limit of fahr*/
    step = 20;   /*step size*/

    printf("-------------------------\n");
    printf("Celsius\t      Fahrenheit\n");
    printf("-------------------------\n");
    cel = lower; /*integer will be converted to float and then assigned to fahr*/
    while(cel <= upper) {
        fahrenheit = (9.0 * cel) / 5.0 + 32.0;  //integer division truncates but if one operand is float then other will also become float
	printf("%5.0f %15.1f\n",cel,fahrenheit);
	cel = cel + step;
    }
}

/* The program produces a table containing temperatures in degrees Celsius (0-
300) and their equivalent Fahrenheit values.
Degrees Fahrenheit are calculated
using the statement:
fahr
•
(9. 0 • c e l • i u • ) I 5 . 0
+
32 . 0
The solution follows the same logic as used in the program that prints the
Fahrenheit-Celsius table (page 12
K& R). The integer variables l ow e r . upper,
and • l •p refer to the lower limit, upper limit, and step size of the variable
c e l s 1 us,
respectively.
The variable
c e l • i u • is initialized to the lower limit,
and inside the while loop the equivalent Fahrenheit temperature is calculated.
The program prints Celsius and Fahrenheit and increments the variable
by the step size.
its upper limit. */
