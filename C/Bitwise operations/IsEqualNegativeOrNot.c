#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_equal(int a, int b);
int is_negative(int value);

int main()
{
	int x = 0, y =0;
	printf("Type numbers\n");
	scanf("%d %d", &x, &y);
	
	is_equal(x, y) ? printf("Equal\n") : printf("Not Equal\n");
	is_negative(x) ? printf("Negative ") : printf("Not negative");
	is_negative(y) ? printf("Negative") : printf("Not negative");
	return 0;
}
int is_equal(int a, int b){	return !(a^b);}
int is_negative(int value){	return value >> 31 ? 1 : 0;}

