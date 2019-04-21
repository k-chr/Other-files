#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	long long int x = 0;
	printf("dik wollef rebmun epyt\n");
	if(!scanf("%lli", &x))
	{
		int error = 1;
		error = ~error + 1;
		
		fseek(stdin, 0, SEEK_SET);
		printf("Input error");
		exit(error);
	}
	x = ~x + 1;
	printf("%lld", x);
	return 0;
}

