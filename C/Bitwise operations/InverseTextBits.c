#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
void show(const void* ptr, size_t count);
void inverse_bits(void* ptr, size_t offset, size_t count);
int main()
{
	char txet[101] = {'\0'};
	printf("txet tupni\n");
	fgets(txet, 99, stdin);
	if(*(txet + strlen(txet) - 1) == '\n') *(txet + strlen(txet) - 1) = '\0';
	show((void*)txet, (size_t)strlen(txet) + 1);
	inverse_bits((void*)txet, 0, (size_t)(strlen(txet) + 1));
	show((void*)txet, (size_t)strlen(txet));
	return 0;
}
void show(const void* ptr, size_t count)
{
	if(ptr != NULL)
	{
		unsigned char *rtp = (unsigned char*)ptr;
		for(unsigned int i = 0; i < count; ++i)
		{
			(*(rtp + i) > 0  || *(rtp + i) > 15) ? printf("%x ", *(rtp + i)) : printf("0%x ", *(rtp + i));
		}
		printf("\n");
	}
}
void inverse_bits(void* ptr, size_t offset, size_t count)
{
	if(ptr != NULL)
	{
		unsigned char *rtp = (unsigned char*)ptr;
		for(unsigned int i = offset; i < count + offset; ++i)
			*(rtp + i) = ~(*(rtp + i));
	}
}
