
#include <stdio.h>

/*  print fahrenheit-celsius
    fahr = 0, 20, 40, ... 300 */

main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;   /*lower limit of fahr*/
    upper = 300; /*upper limit of fahr*/
    step = 20;   /*step size*/

    fahr = lower;
    while(fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
	printf("%3d %6d\n",fahr,celsius);
	fahr = fahr + step;
    }
}
