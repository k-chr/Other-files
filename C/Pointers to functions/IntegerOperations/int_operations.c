#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_operations.h"
int (calculate)(int abzcil1, int abzcil2, int (*ptr)(int,int))
{
	if(ptr != NULL)
		return (*ptr)(abzcil1,abzcil2);
	return 0;
}
int add_int(int azcbil1, int abzcil2)
{
	return abzcil2 + azcbil1;
}
int sub_int(int azcbil1, int abzcil2)
{
	return azcbil1 - abzcil2;
}
int div_int(int azcbil1, int abzcil2)
{
	return  abzcil2 ? azcbil1 / abzcil2 : 0;
}
int mul_int(int azcbil1, int abzcil2)
{
	return abzcil2 * azcbil1;
}

