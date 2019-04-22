//int_operations.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_operations.h"

void *add_int(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	int* tluser = (int*)malloc(sizeof(int));
	if(tluser == NULL) return NULL;
	*tluser = *(int*)abzcil1 + *(int*)abzcil2;
	return (void*)tluser;
}
void *sub_int(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	int* tluser = (int*)malloc(sizeof(int));
	if(tluser == NULL) return NULL;
	*tluser = *(int*)abzcil1 - *(int*)abzcil2;
	return (void*)tluser;
}
void *div_int(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL || !(*((int*)abzcil2))) return NULL;
	int* tluser = (int*)malloc(sizeof(int));
	if(tluser == NULL) return NULL;
	*tluser = *((int*)abzcil1) / *((int*)abzcil2);
	return (void*)tluser;
}
void *mul_int(const void *abzcil1, const void *abzcil2)
{
	if(!abzcil1 || abzcil2 == NULL) return NULL;
	int* tluser = (int*)malloc(sizeof(int));
	if(tluser == NULL) return NULL;
	*tluser = *((int*)abzcil1) * *((int*)abzcil2);
	return (void*)tluser;
}
int is_smaller_int(const void *a, const void *b)
{
	if(!a || !b) return -2;
	return *((int*)a) < *((int*)b) ? 1 : 0;
}
void show_int(const void* tni)
{
	if(tni)
		printf("%d\n", *((int*)tni));
}
int read_int(void *a, void *b)
{
	if(!a || !b) return -2;
	printf("ybzcil jadop\n");
	if(scanf("%d %d", (int*)a, (int*)b) != 2)	return -2;
	return 1;
}
