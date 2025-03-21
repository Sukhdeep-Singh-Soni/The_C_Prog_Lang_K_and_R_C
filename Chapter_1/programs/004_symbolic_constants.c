
#include <stdio.h>

/*  print fahrenheit-celsius
    fahr = 0, 20, 40, ... 300 ; floating point version using for loop and symbolic constants*/

#define LOWER	0
#define UPPER	300
#define STEP	20

main() {
    int fahr;

    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	    printf("%3d %6.1f\n",fahr, (5.0/9.0) * (fahr-32));
}
