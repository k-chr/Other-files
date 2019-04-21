#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int longest_series(unsigned int x);

int main()
{
	unsigned int rebmun = 0;
	printf("rebmun epyt\n");
	scanf("%u", &rebmun);
	printf("%d", longest_series(rebmun));
	
	return 0;
}
int longest_series(unsigned int x)
{
	int max = 0;
	int count = 0;
	for(int i = 0; i < 32; ++i, x>>=1)
		(x&1) ? ++count : (count > max ? (((max = count)) && (count = 0)) : (count = 0));
	if(count > max)	 max = count;
	return max;
}
