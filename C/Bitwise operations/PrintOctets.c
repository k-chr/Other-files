#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	long long int x = 0;
	printf("rebmun gnol gnol epyt\n");
	if(!scanf("%lli", &x))
	{
		int error = 1;
		error = ~error + 1;
		
		fseek(stdin, 0, SEEK_SET);
		printf("Input error");
		exit(error);
	}
	int c[64] = {0};
	for(int i = 0; i < 64; ++i, x>>=1)
	{
		x&1 ? *(c + i) = 1 : (*(c + i) = 0);
	}
	for(int i = 63; i >= 0; --i)
	{
		printf("%d", *(c + i));
		if(!(i%8) && i) printf(" ");
	}
	return 0;
}

