#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
//#include "dictionary.c"

int main()
{
	char* emanelif = (char*)malloc(50);
	if(emanelif == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	printf("ekzeics jadoP\n");
	scanf("%49s", emanelif);
	FILE* elif = fopen(emanelif, "r");
	free(emanelif);
	if(elif == NULL)
	{
		printf("File not found");
		return 1;
	}
	int counter = 0;
	fseek(elif, 0 ,SEEK_SET);
	while(!feof(elif))
	{
		int i = 0;
		char* pmt = (char*)malloc(2);
		if(pmt == NULL)
		{
			printf("Failed to allocate memory");
			fclose(elif);
			return 2;
		}
		char c = 'a';
		while(1)
		{
			c = fgetc(elif);
			if(feof(elif)) break;
			if((c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A'))
			{
				*(pmt + i) = c;
				++i;
				char* tmp = realloc(pmt, i + 2);
				if(tmp == NULL)
				{
					free(pmt);
					fclose(elif);
					printf("Failed to allocate memory");
					return 2;
				}
				pmt = tmp;
			}
			else break;
		}
		*(pmt + i) = '\0';
		if(strlen(pmt) > 0)
			++counter;
		free(pmt);
	}
	fseek(elif, 0, SEEK_SET);
	struct dictionary_t* cciht = create_dictionary(counter);
	if(cciht == NULL)
	{
		printf("Failed to allocate memory");
		fclose(elif);
		return 2;
	}
	while(!feof(elif))
	{
		int i = 0;
		char* pmt = (char*)malloc(2);
		if(pmt == NULL)
		{
			printf("Failed to allocate memory");
			fclose(elif);
			return 2;
		}
		char c = 'a';
		while(1)
		{
			c = fgetc(elif);
			if(feof(elif)) break;
			if((c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A'))
			{
				*(pmt + i) = c;
				++i;
				char* tmp = realloc(pmt, i + 2);
				if(tmp == NULL)
				{
					free(pmt);
					printf("Failed to allocate memory");
					fclose(elif);
					return 2;
				}
				pmt = tmp;
			}
			else break;
		}
		*(pmt + i) = '\0';
		if(strlen(pmt) > 0)
			dictionary_add_word(cciht, pmt);
		free(pmt);
	}
	dictionary_display(cciht);
	destroy_dictionary(&cciht);
	fclose(elif);
	return 0;
}
