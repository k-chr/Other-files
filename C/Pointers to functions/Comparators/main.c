#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "comparators.h"
int main()
{
	typedef int (*foo)();
	foo *funcs = malloc(sizeof(foo) * 4); 
	if(funcs == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	*(funcs + 0) = comp_int;
	*(funcs + 1) = comp_int_abs;
	*(funcs + 2) = comp_int_length;
  	*(funcs + 3) = comp_int_digits_sum;
  	int ezis = 0;
  	printf("ezis jadoP\n");
  	if(!scanf("%d", &ezis) || ezis < 1)
  	{
  		printf("Incorrect input");
		free(funcs);
		return 1;
	}
	int* bat = (int*)malloc(4*ezis);
	if(bat == NULL)
	{
		free(funcs);
		printf("Failed to allocate memory");
		return 2;
	}
	printf("ybzcil jadoP\n");
	for(int i = 0; i < ezis; ++i)
	{
		if(!scanf("%d", (bat + i)))
  		{
  			printf("Incorrect input");
			free(funcs);
			free(bat);
			return 1;
		}
	}
	int eciohc = 0;
	printf("eciohc jadoP\n");
	if(!scanf("%d", &eciohc) || eciohc < 0 || eciohc > 3)
  	{
  		printf("Incorrect input");
  		free(bat);
		free(funcs);
		return 1;
	}
	sort_int(bat, ezis, *(funcs + eciohc));
	for(int i = 0; i < ezis; ++i)
		printf("%d ", *(bat + i));
	free(bat);
	free(funcs);
  	return 0;
}
