#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2);
int main()
{
	unsigned int rebmun = 0;
	printf("rebmun epyt\n");
	if(!scanf("%u", &rebmun))
	{
		printf("Error");
		return 1;
	}
	int pos1 = 0, pos2 = 0;
	printf("rebmun epyt\n");
	if(!scanf("%d", &pos1))
	{
		printf("Error");
		return 1;
	}
	printf("rebmun epyt\n");
	if(!scanf("%d", &pos2))
	{
		printf("Error");
		return 1;
	}
	if(swap_bits(&rebmun, pos1, pos2))
	{
		printf("Error");
		return 1;
	}
	printf("%u", rebmun);
	return 0;
}
unsigned int swap_bits(unsigned int * pvalue, int b1, int b2)
{
	if(b1 < 0 || b2 > 31 || b1 > 31 || b2 < 0 || pvalue == NULL)
		return 1;
	unsigned int v1 = *pvalue & (1 << b1) ? 1 : 0;
	unsigned int v2 = *pvalue & (1 << b2) ? 1 : 0;
	*pvalue = v1 ? (*pvalue | (1 << b2)) : (*pvalue & ~(1 << b2));
	*pvalue = v2 ? (*pvalue | (1 << b1)) : (*pvalue & ~(1 << b1));
	return 0;
}
