#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);
int main()
{
	unsigned int InputNum = 0;
	printf("Type number\n");
	scanf("%u", &InputNum);
	int b = 0, Choice = 0;
	printf("Type another number\n");
	if(!scanf("%d", &b) || b < 0 || b > 31)
	{
		printf("Invalid bit index");
		return 1;
	}
	printf("Choose bitwise operation:\n0.Toggle\n1.Set\n2.Clear\n3.Check\n");
	if(!scanf("%d", &Choice) || Choice < 0 || Choice > 3)
	{
		printf("Invalid operation");
		return 1;
	}
	if(Choice == 3)
		printf("%d", isset_bit((uint32_t *)&InputNum, b));
	else
	{
		int ErrCode = Choice == 0 ? toggle_bit((uint32_t *)&InputNum, b) : (Choice == 1 ? set_bit((uint32_t *)&InputNum, b) : clear_bit((uint32_t *)&InputNum, b));
		if(ErrCode)
		{
			printf("Invalid operation");
			return -1;
		}
		printf("%x", InputNum);
	}
	return 0;
}
int toggle_bit(uint32_t* pvalue, int b)
{
	if(pvalue  == NULL || b < 0 || b > 31)
		return -1;
	*pvalue = *pvalue ^ (1 << b);
	return 0;
}
int set_bit(uint32_t* pvalue, int b)
{
	if(pvalue  == NULL || b < 0 || b > 31)
		return -1;
	*pvalue = *pvalue | (1 << b);
	return 0;
}
int clear_bit(uint32_t* pvalue, int b)
{
	if(pvalue  == NULL || b < 0 || b > 31)
		return -1;
	*pvalue = *pvalue & ~(1 << b);
	return 0;
}
int isset_bit(const uint32_t* pvalue, int b)
{
	if(pvalue  == NULL || b < 0 || b > 31)
		return -1;
	return *pvalue & (1 << b) ? 1 : 0;
}
