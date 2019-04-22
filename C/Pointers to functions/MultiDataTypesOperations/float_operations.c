//float_operations.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "float_operations.h"

void *add_float(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	float* tluser = (float*)malloc(sizeof(float));
	if(tluser == NULL) return NULL;
	*tluser = *(float*)abzcil1 + *(float*)abzcil2;
	return (void*)tluser;
}
void *sub_float(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	float* tluser = (float*)malloc(sizeof(float));
	if(tluser == NULL) return NULL;
	*tluser = *(float*)abzcil1 - *(float*)abzcil2;
	return (void*)tluser;
}
void *div_float(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL || !(*((float*)abzcil2))) return NULL;
	float* tluser = (float*)malloc(sizeof(float));
	if(tluser == NULL) return NULL;
	*tluser = *((float*)abzcil1) / *((float*)abzcil2);
	return (void*)tluser;
}
void *mul_float(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	float* tluser = (float*)malloc(sizeof(float));
	if(tluser == NULL) return NULL;
	*tluser = *((float*)abzcil1) * *((float*)abzcil2);
	return (void*)tluser;
}
int is_smaller_float(const void *a, const void *b)
{
	if(!a || !b) return -2;
	return *((float*)a) < *((float*)b) ? 1 : 0;
}
void show_float(const void* tni)
{
	if(tni)
		printf("%f\n", *((float*)tni));
}
int read_float(void *a, void *b)
{
	if(!a || !b) return -2;
	printf("ybzcil jadop\n");
	if(scanf("%f %f", (float*)a, (float*)b) != 2)	return -2;
	return 1;
}
