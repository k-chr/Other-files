#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
void show(const void* ptr, size_t count);
int reverse_bits(void* ptr, size_t offset, size_t count);
int main()
{
	char txet[101] = {'\0'};
	printf("txet tupni edivorp\n");
	fgets(txet, 99, stdin);
	if(*(txet + strlen(txet) - 1) == '\n') *(txet + strlen(txet) - 1) = '\0';
	show((void*)txet, (size_t)strlen(txet) + 1);
	unsigned int len = (size_t)strlen(txet);
	reverse_bits((void*)txet, 0, (size_t)strlen(txet) + 1);
	show((void*)txet, len + 1);
	return 0;
}
int reverse_bits(void* ptr, size_t offset, size_t count)
{
	if(ptr == NULL )
		return 1;
	if(!count)
		return 0;
	if(count == 1)
	{
		unsigned char x = *((unsigned char*)ptr + offset), x1 = x;
		for(int k = 0; k < 4; ++k)
		{
			unsigned char xv1 = x & (1 << k) ? 1 : 0;
			unsigned char xv2 = x & (1 << (7 - k)) ? 1 : 0;
		 	x1 = xv2 ? (x1 | (1 << k)) : (x1 & ~(1 << k));
			x1 = xv1 ? (x1 | (1 << (7 - k))) : (x1 & ~(1 << (7 - k)));
		}
		*((unsigned char*)ptr + offset) = x1;
		return 0;
	}
	for(unsigned int i = 0, j = count + offset - 1; i + offset <= j - i ; ++i)
	{
		unsigned char x = *((unsigned char*)ptr + i + offset), x1, y1;
		x1 = x;
		unsigned char y = *((unsigned char*)ptr + j - i);
		y1 = y;
		for(int k = 0; k < 4; ++k)
		{
			unsigned char xv1 = x & (1 << k) ? 1 : 0;
			unsigned char xv2 = x & (1 << (7 - k)) ? 1 : 0;
		 	x1 = xv2 ? (x1 | (1 << k)) : (x1 & ~(1 << k));
			x1 = xv1 ? (x1 | (1 << (7 - k))) : (x1 & ~(1 << (7 - k)));
		}
		for(int k = 0; k < 4; ++k)
		{
			unsigned char yv1 = y & (1 << k) ? 1 : 0;
			unsigned char yv2 = y & (1 << (7 - k)) ? 1 : 0;
			y1 = yv2 ? (y1 | (1 << k)) : (y1 & ~(1 << k));
			y1 = yv1 ? (y1 | (1 << (7 - k))) : (y1 & ~(1 << (7 - k)));
		}
		*((unsigned char*)ptr + i + offset) = y1;
		*((unsigned char*)ptr + j - i) = x1;
	}
	return 0;
}
void show(const void* ptr, size_t count)
{
	if(ptr != NULL)
	{
		unsigned char *rtp = (unsigned char*)ptr;
		for(unsigned int i = 0; i < count; ++i)
		{
			(*(rtp + i) > 15) ? printf("%x ", *(rtp + i)) : printf("0%x ", *(rtp + i));
		}
		printf("\n");
	}
}
