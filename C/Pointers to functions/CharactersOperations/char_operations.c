//char_operations.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char_operations.h"
char* (letter_modifier)(const char* txt, char (*ptr)(char))
{
	if(txt == NULL || strlen(txt) < 1 || ptr == NULL)
		return NULL;
	char* res = (char*)malloc(strlen(txt) + 1);
	if(res == NULL) return NULL;
	int i = 0;
	while(i < (int)strlen(txt))
	{
		*(res + i) = (*ptr)(*(txt + i));
		++i;
	}
	*(res + i) = '\0';
	return res;
}
char lower_to_upper(char ch)
{
	if(ch >= 'a' && ch <= 'z')	
		return ('A' + ch - 'a');
	return ch;
}
char upper_to_lower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')	
		return ('a' + ch - 'A');
	return ch;
}
char space_to_dash(char ch)
{
	if(ch == ' ')	
		return '_';
	return ch;
}
char reverse_letter(char ch)
{
	if(ch >= 'a' && ch <= 'z')	
		return -(ch - 'z') + 'a';
	else if(ch >= 'A' && ch <= 'Z')
		return -(ch - 'Z') + 'A';
	return ch;
}
