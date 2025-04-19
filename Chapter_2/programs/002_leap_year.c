/* Write a program to check whether a year is a leap year or not */

#include <stdio.h>

#define FILENAME	"002_leap_year"

int main() {
    int year = 2024;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
        printf("%s: The year is a leap year\n",(char*)FILENAME);
    else
	printf("%s: The year is not a leap year\n",(char*)FILENAME);
    return 0;    
} 
