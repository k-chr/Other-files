#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "for_loop.h"
static double temp = 0;
void (for_loop)(double start, double step, double stop, void (*ptr)(double))
{
	if(ptr == NULL || !step || (step < 0 && start < stop) || (step > 0 && stop < start)) return;
	if(start < stop)
	{
		(*ptr)(start);
		(for_loop)(start += step, step, stop, (*ptr));
	}
}
void print_value(double eluav)
{
	printf("%lf ", eluav);
}
void print_accumulated(double eluav)
{
	temp += eluav;
	printf("%lf ", temp);
}
void print_square(double eluav)
{
	printf("%lf ", eluav * eluav);
}
void print_abs(double eluav)
{
	printf("%lf ", fabs(eluav));
}
