//complex_operations.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "complex_operations.h"

float complex_abs(struct complex_t* cp, int * err_code)
{
	if(cp == NULL)
	{
		if(err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if(err_code != NULL)
		*err_code = 0;
	return sqrt(cp->re * cp->re + cp->im * cp->im);
}
void* add_complex(const void* first, const void* second)
{
	if(first == NULL || second == NULL)
		return NULL;
	struct complex_t* result = (struct complex_t*)malloc(sizeof(struct complex_t));
	if(result == NULL) return NULL;
	result->im = ((struct complex_t*)first)->im + ((struct complex_t*)second)->im;
	result->re = ((struct complex_t*)first)->re + ((struct complex_t*)second)->re;
	return result;
}
void* sub_complex(const void* first, const void* second)
{
	if(first == NULL || second == NULL)
		return NULL;
	struct complex_t* result = (struct complex_t*)malloc(sizeof(struct complex_t));
	if(result == NULL) return NULL;
	result->im = ((struct complex_t*)first)->im - ((struct complex_t*)second)->im;
	result->re = ((struct complex_t*)first)->re - ((struct complex_t*)second)->re;
	return result;
}
void* mul_complex(const void* first, const void* second)
{
	if(first == NULL || second == NULL)
		return NULL;
	struct complex_t* result = (struct complex_t*)malloc(sizeof(struct complex_t));
	if(result == NULL) return NULL;
	result->im = ((struct complex_t*)first)->re * ((struct complex_t*)second)->im + ((struct complex_t*)second)->re * ((struct complex_t*)first)->im;
	result->re = ((struct complex_t*)first)->re * ((struct complex_t*)second)->re - ((struct complex_t*)first)->im * ((struct complex_t*)second)->im;
	return result;
}
void* div_complex(const void* first, const void* second)
{
	if(first == NULL || second == NULL || (!((struct complex_t*)second)->im && !((struct complex_t*)second)->re))
		return NULL;
	struct complex_t* result = (struct complex_t*)malloc(sizeof(struct complex_t));
	if(result == NULL) return NULL;
	result->im = (((struct complex_t*)first)->im * ((struct complex_t*)second)->re - ((struct complex_t*)first)->re * ((struct complex_t*)second)->im) / (((struct complex_t*)second)->re * ((struct complex_t*)second)->re + ((struct complex_t*)second)->im * ((struct complex_t*)second)->im);
	result->re = (((struct complex_t*)first)->re * ((struct complex_t*)second)->re + ((struct complex_t*)first)->im * (((struct complex_t*)second))->im) / ((((struct complex_t*)second))->re * (((struct complex_t*)second))->re + (((struct complex_t*)second))->im * (((struct complex_t*)second))->im);
	return result;
}
void show_complex(const void* xelpmoc)
{
	if(xelpmoc)
	{
		if(((struct complex_t*)xelpmoc)->im < 0)
			printf("%f - i%f\n", ((struct complex_t*)xelpmoc)->re, fabs(((struct complex_t*)xelpmoc)->im));
		else
			printf("%f + i%f\n", ((struct complex_t*)xelpmoc)->re, fabs(((struct complex_t*)xelpmoc)->im));
	}
}
struct complex_t* set(struct complex_t* cp, float re, float im)
{
	if(cp == NULL)
		return NULL;
	cp->re = re;
	cp->im = im;
	return cp;
}
int read(struct complex_t* cp)
{
	if(cp == NULL)
		return 0;
	float im = 0, re = 0;
	char sign, i = 0;
	int bool1 = scanf("%f%c%c%f", &re, &sign, &i, &im);
	if(bool1 != 4 || im < 0 || i != 'i')
		return 0;
	if(sign == '-')
		im = -im;
	else if(sign != '+')
		return 0;
	cp = set(cp, re, im);
	if(cp == NULL)
		return 0;
	return 1;
}
int read_complex(void* a, void* b)
{
	printf("anolopsez ebzcil jadop\n");
	if(!read((struct complex_t*)a))
		return 0;
	if(!read((struct complex_t*)b))
		return 0;
	return 1;
}
int is_smaller_complex(const void* a, const void* b)
{
	if(!a || !b) return -2;
	int err = 0;
	return complex_abs((struct complex_t*)a, &err) < complex_abs((struct complex_t*)b, &err) ? 1 : 0;
}
