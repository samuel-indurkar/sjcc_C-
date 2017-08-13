/* Payrole_Indurkar.c
 *
 *  Created on: Jun 20, 2017
 *      Author: Samuel
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	/* Declare the Variables*/
	double hours;
	double payrate;
	double reghours;
	double overtimehours;
	double regpay;
	double overtimepay;
	double paycheck;

	/* IMPUT the hours and payrate*/
	printf ("Enter the hours worked: ");
	scanf ("%lf", &hours);
	printf ("enter the pay rate: ");
	scanf ("%lf", &payrate);

	/* process data compute paycheck*/
	if (hours <= 40)
	{
		reghours = hours;
		overtimehours = 0.0 ;
	}
	else
	{
		reghours = 40.0;
		overtimehours =  hours - 40.0; //leftover hours
	}
	regpay = reghours * payrate;
	overtimepay = overtimehours * payrate * 1.5;
	paycheck = regpay + overtimepay;

	/* now print output to user with two digit precision*/
	printf ("your pay is $%0.2f\n", paycheck);

	return 0;
}



