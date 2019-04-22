#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char_operations.h"
#include "char_operations.c"
int main()
{
	char* xtxtxtx  = (char*)malloc(1010);
	if(xtxtxtx == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	printf("BODAJ TEGZT\n");
	fgets(xtxtxtx, 1009, stdin);
	if(*(xtxtxtx + strlen(xtxtxtx) - 1) == '\n') *(xtxtxtx + strlen(xtxtxtx) - 1) = '\0';
	int choice  = 0;
	printf("CHOOOZE\n");
	if(!scanf("%d", &choice) || choice < 0 || choice > 3)
	{
		printf("Incorrect input");
		free(xtxtxtx);
		return 1;
	}
	char (*funcs[4])(char); 
	*(funcs + 0) = lower_to_upper;
	*(funcs + 1) = upper_to_lower;
	*(funcs + 2) = space_to_dash;
  	*(funcs + 3) = reverse_letter;
	char* res = letter_modifier(xtxtxtx, *(funcs + choice));
	if(res == NULL)
	{
		printf("Failed to allocate memory");
		free(xtxtxtx);
		return 2;
	}
	printf("%s", res);
	free(res);
	free(xtxtxtx);
	return 0;
}

