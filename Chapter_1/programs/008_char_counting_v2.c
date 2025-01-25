
#include <stdio.h>

/* count characters in input : 2nd version */

main() {
    double nc; /*handle bigger numbers than long*/

    nc = 0;
    for(nc = 0; getchar() != EOF; ++nc)
	    ;
    printf("%.0f\n",nc);
}
