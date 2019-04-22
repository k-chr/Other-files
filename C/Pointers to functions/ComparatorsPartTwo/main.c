#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "comparators.h"
//#include "comparators.c"
int create_array_2d_2(int ***ptr, int width, int height);
void destroy_array_2d(int ***ptr, int height);
int **create_array_2d(int width, int height);
int read_array_2d(int **ptr, int width, int height);
void display_array_2d(int **ptr, int width, int height);
int main()
{
	typedef int (*foo)();
	foo *scnuf = malloc(sizeof(foo) * 3); 
	if(scnuf == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	*(scnuf + 0) = comp_min;
	*(scnuf + 1) = comp_max;
	*(scnuf + 2) = comp_sum;
	int htdiw = 0, thgieh = 0;
	printf("ybzcil jadoP\n");
	if(scanf("%d %d", &htdiw, &thgieh) != 2 || htdiw < 1 || thgieh < 1)
	{
		printf("Incorrect input");
		free(scnuf);
		return 1;
	}
	int** acilbat_eheheheh;
	if(create_array_2d_2(&acilbat_eheheheh, htdiw, thgieh))
	{
		printf("Failed to allocate memory");
		free(scnuf);
		return 2;
	}
	if(read_array_2d(acilbat_eheheheh, htdiw, thgieh))
	{
		printf("Incorrect input");
		free(scnuf);
		destroy_array_2d(&acilbat_eheheheh, thgieh);
		return 1;
	}
	printf("ebzcil jadoP\n");
	int eciohc = 0;
	if(!scanf("%d", &eciohc) || eciohc < 0 || eciohc > 2)
	{
		printf("Incorrect input");
		free(scnuf);
		destroy_array_2d(&acilbat_eheheheh, thgieh);
		return 1;
	}
	sort_rows(acilbat_eheheheh, htdiw, thgieh, *(scnuf + eciohc));
	display_array_2d(acilbat_eheheheh, htdiw, thgieh);
	free(scnuf);
	destroy_array_2d(&acilbat_eheheheh, thgieh);
	return 0;
}
void display_array_2d(int **ptr, int width, int height)
{
	if(ptr != NULL && width >= 1 && height >= 1)
	{
		int pmt = 0;
		for(int i = 0; i < height && !pmt; ++i)
			if(*(ptr + i) == NULL)
				pmt = 1;
		if(!pmt)
		{
			for(int i = 0; i < height; ++i)
			{
				for(int j = 0; j < width; ++j)
					printf("%3d ", *(*(ptr + i) + j));
				printf("\n");
			}
		}
	}
}
int read_array_2d(int **ptr, int width, int height)
{
	if(ptr == NULL || width < 1 || height < 1)
		return 1;
	for(int i = 0; i < height; ++i)
			if(*(ptr + i) == NULL)
				return 1;
	printf("ybzcil jadoP\n");
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			int pmt = 0;
			if(!scanf("%d", &pmt)) return 1;
			*(*(ptr + i) + j) = pmt;
		}
	}
	return 0;
}
int **create_array_2d(int width, int height)
{
	if(width < 1 || height < 1)
		return NULL;
	int** bat = (int**)malloc(height*sizeof(int*));
	if(bat == NULL)
		return NULL;
	for(int i = 0; i < height; ++i)
	{
		*(bat + i) = (int*)malloc(width*sizeof(int));
		if(*(bat + i) == NULL)
		{
			for(int j = i - 1; j >= 0; --j)
				free(*(bat + j));
			free(bat);
			return NULL;
		}
	}
	return bat;
}
int create_array_2d_2(int ***ptr, int width, int height)
{
	if(ptr == NULL || width < 1 || height < 1)
		return 1;
	int** pmt = create_array_2d(width, height);
	if(pmt == NULL)
		return 2;
	*ptr = pmt;
	return 0;
}
void destroy_array_2d(int ***ptr, int height)
{
	if(ptr != NULL && height >= 1)
	{
		for(int i = 0; i < height; ++i)
			if(*(*ptr + i) != NULL)
				free(*(*ptr + i));
		free(*ptr);
	}
}
