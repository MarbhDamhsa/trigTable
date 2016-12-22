/*
 *    Program prints a table of trigonometric values from 0 to 360
 *    in increments determined by the user.
 *
 */

#include <stdio.h>
#include <math.h>
//Define double approximation of PI
#define PI 3.14159265358979323846

double calcRads(int degrees);
void printTable(int incr);

int main(void)
{
	int incr, degrees = 0;

	printf("Welcome to trigTable.\n\n");
	printf("This program will print a table of trigonometric values\n");
	printf("from 0 to 360 degrees in selected increments\n\n");

	printf("Please select the number of degrees for the increment: ");
	scanf("%d", &incr);
	printTable(incr);

	printf("\n\nThank you for using trigTable. Bye!\n");

	return 0;
}

double calcRads(int degrees)
{
	//Radians = Degrees x (PI/180)
	double rads = degrees * (PI/180);
	return rads;
}//calcRads

void printTable(int incr)
{
	//Header
	printf("\n        ---     ");
	printf("TRIGONOMETRIC TABLE";
	printf("     ---        \n\n");
	printf("Degrees  Radians     Sine     Cosine    Tangent \n");
	printf("-------  -------    ------    ------   ---------\n\n");

	while(degrees < 360)
	{
	    printf("%5d", degrees);
	    printf("%10.4lf", calcRads(degrees));
	    printf("%11.4lf", sin(calcRads(degrees)));
	    printf("%11.4lf", cos(calcRads(degrees)));
	    //Gracefully handle an infinite tangent
	    if(((degrees + 90) % 180) == 0)
	    {
	        printf("   infinity");
	    }
	    else
	    {
	        printf("%11.5lf", tan(calcRads(degrees)));
	    }
	    printf("\n");
	    degrees += incr;

	    //Ensure that table prints information for 360 degrees
	    //even if value after incrementation is greater than 360
	    if(degrees + incr >= 360)
            {
		    printf("%5d", 360);
		    printf("%10.4lf", calcRads(360));
		    printf("%11.4lf", sin(calcRads(360)));
		    printf("%11.4lf", cos(calcRads(360)));
		    printf("%11.5lf\n", tan(calcRads(360)));
		    break;
            }
         }
}
