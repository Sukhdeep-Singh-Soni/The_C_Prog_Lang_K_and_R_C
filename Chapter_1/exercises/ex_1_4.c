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
        fahrenheit = (9.0/5.0) * cel + 32.0;  //integer division truncates but if one operand is float then other will also become float
	printf("%5.0f %15.1f\n",cel,fahrenheit);
	cel = cel + step;
    }
}
