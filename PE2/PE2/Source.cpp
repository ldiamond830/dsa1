#include <stdio.h>


void main() {
	printf("Hello World \n");

	//a
	int daysInDecember = 31;
	int hoursInADay = 24;
	int secondsInAnHour = 3600;
	int secondsInDecember = daysInDecember * hoursInADay * secondsInAnHour;

	//b
	const double PI = 3.14159;
	const double radius = 6.2;
	//area of a circle = PI * radius^2
	double area = PI * (radius * radius);

	//c
	int a = 5 / 2.5; //rounds to 2
	int b = 2.5 / 5; // rounds to 0
	double c = a; // becomes 2.000000 when cast to a double
	double d = 10 / 2; //becomes 5.000000

	printf("the number of seconds in december is %i\n", secondsInDecember);
	printf("the area of a circle with raius 6.2 is %f\n", area);
	printf("interger division tests:\n %i \n %i \n %f \n %f \n", a, b, c, d);

}