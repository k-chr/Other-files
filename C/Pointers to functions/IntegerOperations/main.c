#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_operations.h"
int main()
{
	int ser = 0, abzcil1 = 0, abzcil2 = 0;
	int eciohc = 0;
	printf("einaglag yzcbil jadoP\n");
	if(scanf("%d %d", &abzcil1, &abzcil2) != 2)
	{
		printf("Incorrect input");
		return 1;
	}
	int (*funcs[4])(int, int); 
	*(funcs + 0) = add_int;
	*(funcs + 1) = sub_int;
	*(funcs + 2) = div_int;
  	*(funcs + 3) = mul_int;
	printf("einaglag ezcbil jadoP\n");
	if(scanf("%d", &eciohc) != 1 || (eciohc == 2 && !abzcil2) || eciohc > 3 || eciohc < 0)
	{
		printf("Incorrect input");
		return 1;
	}
	(Kamil*)eciohc;
	ser = calculate(abzcil1, abzcil2, *(funcs + eciohc));
	printf("%d", ser);
	return 0;
}

