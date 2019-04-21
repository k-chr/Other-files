
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* boyer_moore_horsepool(const char* , const char*);
char* getText();
int* create_occur(const char*);
int main()
{
	printf("Type something plox\n");
	char* txt1 = getText();
	if(!txt1)
	{
		printf("Failed to allocate memory\n");
		return 1;
	}
	printf("Give me one more text boi\n");
	char* txt2 = getText();
	if(!txt2)
	{
		free(txt2);
		printf("Failed to allocate memory\n");
		return 1;
	}
	if(boyer_moore_horsepool(txt1, txt2))
		printf("Successfully found some weird shit\n");
	else
		printf("Not found fuuug :-DDDD\n");
	free(txt1);
	free(txt2);
	return 0;
}
char* getText()
{
	int i = 0;
	char * buf = NULL, *tmp = NULL;
	tmp = (char*)realloc(buf, 50);
	if(tmp == NULL)
		return NULL;
	buf = tmp;
	while(1)
	{
		char c = 0;
		scanf("%c", &c);
		if(c == '\n') break;
		*(buf + i) = c;
		++i;
		if(!(i%50))
		{
			tmp = (char*)realloc(buf, 50 + i);
			if(tmp == NULL)
			{
				free(buf);
				return NULL;
			}
			buf = tmp;
		}
	}
	*(buf + i) = '\0';
	return buf;
}
int* create_occur(const char* key)
{
	if(!key || !strlen(key)) return NULL;
	int* temp = (int*)malloc(128*sizeof(int));
	if(!temp) return NULL;
	int len_key = strlen(key);
	for(int i = 0; i < 128; ++i) *(temp + i) = len_key;
	for(int i = 0;*(key + i); ++i)
		*(temp + *(key + i)) = len_key - i - 1;
	return temp;
}
char* boyer_moore_horsepool(const char* string, const char* key)
{
	if(!string || !key) return NULL;
	int len_key = strlen(key);
	int str_len = strlen(string);
	int* occur = create_occur(key);
	if(!occur) return NULL;
	for(int i = 0; i < 128; ++i) printf("i = %c | occur[i = %c] = %d\n", i, i, *(occur + i));
	printf("\n-----------------------------------------------\n");
	getchar();
	int skipped = 0;
	for(;str_len >= skipped + len_key;)
	{
		printf("%s %d\n", string + skipped, skipped);
		int i = len_key - 1;
		for(; i >= 0; --i)
		{
			if(*(string + skipped + i) != *(key + i))
				break;
		}
		if(i > -1)
			skipped = skipped + (*(occur + *(string + skipped + i)) ? *(occur + *(string + skipped + i)) : len_key);
		else
		{
			free(occur);
			return (char*)(string + skipped);
		}
	}
	free(occur);
	return NULL;
}
