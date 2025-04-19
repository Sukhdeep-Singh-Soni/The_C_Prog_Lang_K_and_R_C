
#include <stdio.h>

/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.*/

main() {
    int fahr;

    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
	    printf("%3d %6.1f\n",fahr, (5.0/9.0) * (fahr-32));
}

/* The only modification is:
f o r ( f a h r • 300 ; fah r > •
O;
f a h r • f a h r - 20 )
The first part of the f o r statement,
f a h r • 3 00
initializes the Fahrenheit vari a bl e ( f a hr ) to its upper limit.
or the condition that controls the f o r loop,
fahr
>•
The second part.
0
tests whether the Fahrenheit variable exceeds or meets its lower limit. Th e
f o r loop continues as long as the statement is true. The step express ion ,
fahr
•
fahr - 20
decrements the Fahrenheit variable b y the step size. */
