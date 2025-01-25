/*
 * Exercise 1-3. Modify the temperature conversion program to print a heading 
 * above the table.
 * */

#include <stdio.h>

/*  print fahrenheit-celsius
    fahr = 0, 20, 40, ... 300 ; floating point version*/

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /*lower limit of fahr*/
    upper = 300; /*upper limit of fahr*/
    step = 20;   /*step size*/

    printf("-------------------------\n");
    printf("Fahrenheit\tCelsius\n");
    printf("-------------------------\n");
    fahr = lower; /*integer will be converted to float and then assigned to fahr*/
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);  //integer division truncates but if one operand is float then other will also become float
	printf("%6.0f %14.1f\n",fahr,celsius);
	fahr = fahr + step;
    }
}
