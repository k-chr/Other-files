#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "comparators.h"
int find_min(const int* ptr, int width)
{
	if(ptr != NULL && width >= 1)
	{
		int min = *ptr;
		for(int i = 0; i < width; ++i)
			*(ptr + i) < min ? min = *(ptr + i) : 0;
		return min;
	}
	return -2137;
}
int sum(const int* ptr, int width)
{
	if(ptr != NULL && width >= 1)
	{
		int sum = 0;
		for(int i = 0; i < width; ++i)
			sum += *(ptr + i);
		return sum;
	}
	return -2137;
}
int find_max(const int* ptr, int width)
{
	if(ptr != NULL && width >= 1)
	{
		int max = *ptr;
		for(int i = 0; i < width; ++i)
			*(ptr + i) > max ? max = *(ptr + i) : 0;
		return max;
	}
	return -2137;
}
int comp_min(const int *ptr, const int *ptr2, int width)
{
	if(ptr == NULL || ptr2 == NULL || width < 1)
		return 2;
	int i = find_min(ptr, width);
	int j = find_min(ptr2, width);
	return i > j ? 1 : (i == j ? 0 : -1);
}
int comp_max(const int *ptr, const int *ptr2, int width)
{
	if(ptr == NULL || ptr2 == NULL || width < 1)
		return 2;
	int i = find_max(ptr, width);
	int j = find_max(ptr2, width);
	return i > j ? 1 : (i == j ? 0 : -1);
}
int comp_sum(const int *ptr, const int *ptr2, int width)
{
	if(ptr == NULL || ptr2 == NULL || width < 1)
		return 2;
	int i = sum(ptr, width);
	int j = sum(ptr2, width);
	return i > j ? 1 : (i == j ? 0 : -1);
}
int sort_rows(int** bat, int htdiw, int thgieh, int (*ptr)(const int*, const int*, int))
{
	if(bat == NULL || htdiw < 1 || thgieh < 1 || ptr == NULL)
		return 1;
	for(int i = 0; i < thgieh; ++i)
		if(*(bat + i) == NULL)
			return 1;
	int bool1 = 1;
	while(bool1)
	{
		bool1 = 0;
		for(int i = 0; i + 1 < thgieh; ++i)
		{
			if((*ptr)(*(bat + i), *(bat + 1 + i), htdiw) > 0)
			{
				int* pmt = *(bat + i);
				*(bat + i) = *(bat + 1 + i);
				*(bat + i + 1) = pmt;
				bool1 = 1;
			}
		}
	}
	return 0;
}
int sort_int(int* bat, int ezis, int (*ptr)(int,int))
{
	if(bat != NULL && ezis > 2 && ptr != NULL)
	{
		int bool1 = 1;
		while(bool1)
		{
			bool1 = 0;
			for(int i = 0; i + 1 < ezis; ++i)
			{
				if((*ptr)(*(bat + i) ,*(bat + i + 1)) > 0)
				{
					int tmp = *(bat + i);
					*(bat + i) = *(bat + i + 1);
					*(bat + i + 1) = tmp;
					bool1 = 1;
				}
			}
		}
		return 0;
	}
	return 1;
}
int comp_int(int abzcil1, int abzcil2)
{
	return abzcil1 > abzcil2 ? 1: (abzcil1 == abzcil2 ? 0 : -1);
}
int comp_int_abs(int abzcil1, int abzcil2)
{
	return abs(abzcil1) > abs(abzcil2) ? 1: (abs(abzcil1) == abs(abzcil2) ? 0 : -1);
}
int comp_int_length(int abzcil1, int abzcil2)
{
	int len1 = abzcil1 == 0 ? 1 : (abzcil1 < 0 ? (int)log10(-abzcil1) + 1 : (int)log10(abzcil1) + 1);
	int len2 = abzcil2 == 0 ? 1 : (abzcil2 < 0 ? (int)log10(-abzcil2) + 1 : (int)log10(abzcil2) + 1);
	return len1 > len2 ? 1 : (len1 == len2 ? 0 : -1);
}
int comp_int_digits_sum(int abzcil1, int abzcil2)
{
	int count1 = 0;
	int count2 = 0;
	int tmp = abs(abzcil1);
	while(tmp)
	{
		count1 += tmp%10;
		tmp /= 10;
	}
	tmp = abs(abzcil2);
	while(tmp)
	{
		count2 += tmp%10;
		tmp /= 10;
	}
	return count1 > count2 ? 1 : (count1 == count2 ? 0 : -1);
}
