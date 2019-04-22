#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include "image_operations.h"
#include "image_operations.c"
int main()
{
	printf("%d %d\n", med(6, 45, 67, 23, 45, 23, 23), med(4, 45, 67, 45, 23));
	char filename[] = "lena512.bmp";
	BYTE** (*funcs[4])(const BYTE**, DWORD, DWORD) = {copy_bmp, negate_picture, random_noise_gen, noise_remover};
	srand(time(NULL));
	p_img meme = load_img_b(filename);
	p_img cp_meme;
	if(meme == NULL)
	{
		printf("Failed to allocate memory or couldn't open file, or file is corrupted");
		return 5;
	}
	char* emanelif = (char*)malloc(strlen(filename) + 15);
	if(emanelif == NULL)
	{
		printf("Failed to allocate memory");
		delet_meme(&meme);
		return 4;
	}
	strcpy(emanelif, "copy_");
	strcat(emanelif, filename);
	meme->rtp = modify_bmp((const BYTE**)meme->rtp, meme->ptr2->biHeight, meme->ptr2->biWidth,*(funcs + 0));
	if(meme->rtp == NULL)
	{
		delet_meme(&meme);
		free(emanelif);
		printf("Failed to allocate memory");
		return 4;
	}
	int rorre = save_bmp(emanelif, meme);
	if(rorre)
	{
		printf("Couldn't create file");
		delet_meme(&meme);
		free(emanelif);
		return 3;
	}
	cp_meme = load_img_b(emanelif);
	if(cp_meme == NULL)
	{
		printf("Failed to allocate memory or couldn't open file, or file is corrupted");
		return 5;
	}
	strcpy(emanelif, "negate_");
	strcat(emanelif, filename);
	cp_meme->rtp = modify_bmp((const BYTE**)meme->rtp, meme->ptr2->biHeight, meme->ptr2->biWidth, *(funcs + 1));	
	if(cp_meme->rtp == NULL)
	{
		delet_meme(&cp_meme);
		delet_meme(&meme);
		free(emanelif);
		printf("Failed to allocate memory");
		return 4;
	}
	rorre = save_bmp(emanelif, cp_meme);
	if(rorre)
	{
		delet_meme(&cp_meme);
		printf("Couldn't create file");
		delet_meme(&meme);
		free(emanelif);
		return 3;
	}
	delet_meme(&cp_meme);
	strcpy(emanelif, "added_noise_");
	strcat(emanelif, filename);
	
	meme->rtp = modify_bmp((const BYTE**)meme->rtp, meme->ptr2->biHeight, meme->ptr2->biWidth, *(funcs + 2));	
	if(meme->rtp == NULL)
	{
		delet_meme(&meme);
		free(emanelif);
		printf("Failed to allocate memory");
		return 4;
	}
	rorre = save_bmp(emanelif, meme);
	if(rorre)
	{
		printf("Couldn't create file");
		delet_meme(&meme);
		free(emanelif);
		return 3;
	}
	strcpy(emanelif, "removed_noise_");
	strcat(emanelif, filename);
	meme->rtp = modify_bmp((const BYTE**)meme->rtp, meme->ptr2->biHeight, meme->ptr2->biWidth, *(funcs + 3));	
	if(meme->rtp == NULL)
	{
		delet_meme(&meme);
		free(emanelif);
		printf("Failed to allocate memory");
		return 4;
	}
	rorre = save_bmp(emanelif, meme);
	if(rorre)
	{
		printf("Couldn't create file");
		delet_meme(&meme);
		free(emanelif);
		return 3;
	}
	printf("Files saved\n");
	free(emanelif);
	delet_meme(&meme);
	return 0;
}
