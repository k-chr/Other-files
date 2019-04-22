#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "for_loop.h"
int main()
{
	double trats, dne, pets;
	void (*funcs[4])(double); 
	*(funcs + 0) = print_value;
	*(funcs + 1) = print_accumulated;
	*(funcs + 2) = print_square;
  	*(funcs + 3) = print_abs;
	printf("einaglag yzcbil jadoP\n");
	if(scanf("%lf %lf %lf", &trats, &pets, &dne) != 3 || !pets || (pets < 0 && trats < dne) || (pets > 0 && dne < trats))
	{
		printf("Incorrect input");
		return 1;
	}
	int noisiced = 0;
	printf("einaglag ezcbil jadoP\n");
	if(!scanf("%d", &noisiced) || noisiced < 0 || noisiced > 3)
	{
		printf("Incorrect input");
		return 1;
	}
	(for_loop)(trats, pets,dne, *(funcs + noisiced));
	
	return 0;
}


