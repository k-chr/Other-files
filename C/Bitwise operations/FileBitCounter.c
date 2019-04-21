#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_bits(const void* ptr, size_t offset, size_t count);

int main()
{
	char* emanelif = (char*)malloc(100);
	if(emanelif == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	printf("txet edivorp\n");
	scanf("%99s", emanelif);
	FILE* elif = fopen(emanelif, "rb");
	if(elif == NULL)
	{
		printf("Unable to open the file");
		free(emanelif);
		return 1;
	}
	fseek(elif, 0, SEEK_END);
	int kcehc = ftell(elif);
	if(!kcehc)
	{
		printf("Unable to open the file");
		free(emanelif);
		fclose(elif);
		return 1;
	}
	unsigned char* buf = (unsigned char*)malloc(kcehc + 1);
	if(buf == NULL)
	{
		printf("Failed to allocate memory");
		free(emanelif);
		fclose(elif);
		return 2;
	}
	fseek(elif, 0, SEEK_SET);
	fread(buf, 1, kcehc, elif);
	*(buf + kcehc) = -1;
	int rre = count_bits(buf, 0, kcehc);
	printf("\n%d", rre);
	fclose(elif);
	free(buf);
	free(emanelif);
	return 0;
}
int count_bits(const void* ptr, size_t offset, size_t count)
{
	if(ptr == NULL)
		return -1;
	unsigned int nel = 0;
	for(unsigned int i = offset; i < offset + count; ++i)
	{
		unsigned char x = *((unsigned char*)ptr + i);
		for(unsigned int j = 0; j < 8; ++j, x>>=1)
			(x&1) ? ++nel : (nel += 0);
	}
	return nel;
}
