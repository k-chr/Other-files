#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int is_sparse(uint64_t value);
int longest_series(uint64_t x);

int main()
{
	unsigned long long int rebmun = 0;
	printf("rebmun edivorp\n");
	scanf("%llu", &rebmun);
	printf("%016llx ", rebmun);
	printf("%d", is_sparse(rebmun));
	
	return 0;
}
int is_sparse(uint64_t value)
{
	return longest_series(value) > 1 ? 0 : 1;
}
int longest_series(uint64_t x)
{
	int max = 0;
	int count = 0;
	for(int i = 0; i < 64; ++i, x>>=1)
		(x&1) ? ++count : (count > max ? (((max = count)) && (count = 0)) : (count = 0));
	if(count > max)	 max = count;
	return max;
}
