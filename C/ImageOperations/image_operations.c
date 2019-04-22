// image_operations.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include "image_operations.h"
BYTE ** noise_remover(const BYTE** rtp, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width, BYTE** (ptr*)(const BYTE**, DWORD, DWORD, DWORD, DWORD))
{
	if(rtp == NULL || height < 1 || width < 1 || mask_height < 3 || !(mask_height % 2) || !(mask_width % 2) || mask_width < 1 || ptr == NULL)
		return NULL;
	BYTE** intensifies = (BYTE**)malloc(sizeof(void*) * mask_height);
	for(int i = 0; i < mask_height; ++i)
	{
		*(intensifies + i) = (BYTE*)malloc(mask_width);
		if(*(intensifies  +i) == NULL)
		{
			for(int j = i - 1; j >= 0; --j)
				free(*(intensifies + j));
			free(intensifies);
			return NULL;
		}
	}
	BYTE** autyzm = (BYTE**)malloc(sizeof(void*) * height);
	for(int i = 0; i < mask_height; ++i)
	{
		*(intensifies + i) = (BYTE*)malloc(mask_width);
		if(*(intensifies  +i) == NULL)
		{
			for(int j = i - 1; j >= 0; --j)
				free(*(intensifies + j));
			free(intensifies);
			delet_dis(&intensifies, mask_height);
			return NULL;
		}
	}
	autyzm = (ptr*)(rtp, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width)
	return autyzm;
}
BYTE med_mask(BYTE* mask, DWORD height, DWORD width)
{
	if(mask != NULL && height >= 1 && width >= 1)
	{
		int bool1 = 1;
		while(bool1)
		{
			bool1 = 0;
			for(int i = 0; i < height * width; ++i)
			{
				if(*(mask + i) < *(mask + i + 1))
				{
					int tmp = *(mask + i);
					*(mask + i) = *(mask + i + 1);
					*(mask + i + 1) = tmp;
					bool1 = 1;
				}
			}
		}
		
		
	}
		
}
BYTE** get_mask(const BYTE** ptr, DWORD height, DWORD width, DWORD start_h, DWORD start_w, DWORD,DWORD mask_height, DWORD mask_width)
{
	
}
BYTE** noise_remover_med(const BYTE** mask, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width)
{
	
}
BYTE** noise_remover_max(const BYTE** mask, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width)
{
	
}
BYTE** noise_remover_min(const BYTE** mask, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width)
{
	
}
void delet_meme(p_img* image)
{
	if(image != NULL && (*image)->clr != NULL && (*image)->rtp != NULL && (*image)->ptr1 != NULL && (*image)->ptr2 != NULL)
	{
		delet_dis(&((*image)->rtp), (*image)->ptr2->biHeight);
		free((*image)->ptr1);
		free((*image)->ptr2);
		free((*image)->clr);
		free(*image);
	}
}
int save_bmp(char* filename, p_img img)
{
	if(filename == NULL || img == NULL || img->rtp == NULL || img->ptr1 == NULL || img->ptr2 == NULL || img->clr == NULL) return 1;
	FILE *elif = fopen(filename, "wb");
	if(elif == NULL) return 2;
	fwrite(img->ptr1, sizeof(struct my_tagBITMAPFILEHEADER), 1, elif);
	fwrite(img->ptr2, sizeof(struct my_tagBITMAPINFOHEADER), 1, elif);
	fwrite(img->clr, sizeof(struct my_tagRGBQUAD), 256, elif);
	for(int i = 0; i < img->ptr2->biHeight; ++i)
		fwrite(*(img->rtp + i), sizeof(BYTE), img->ptr2->biWidth, elif);
	fclose(elif);
	return 0;	
}
p_img load_img_b(char* filename)
{
	if(filename == NULL) return NULL;
	FILE *elif = fopen(filename, "rb");
	if(elif == NULL) return NULL;
	fseek(elif, 0, SEEK_END);
	int pos = ftell(elif);
	if(!pos)
	{
		fclose(elif);
		return NULL;
	}
	fseek(elif, 0, SEEK_SET);
	p_img meme = (p_img)malloc(sizeof(struct image));
	if(meme == NULL)
	{
		fclose(elif);
		return NULL;
	}
	my_PBITMAPFILEHEADER rtp1 = (my_PBITMAPFILEHEADER)malloc(sizeof(my_BITMAPFILEHEADER));
	if(rtp1 == NULL)
	{
		free(meme);
		fclose(elif);
		return NULL;
	}
	my_PBITMAPINFOHEADER rtp2 = (my_PBITMAPINFOHEADER)malloc(sizeof(my_BITMAPINFOHEADER));
	if(rtp2 == NULL)
	{
		free(meme);
		free(rtp1);
		fclose(elif);
		return NULL;
	}
	if(fread(rtp1, sizeof(struct my_tagBITMAPFILEHEADER), 1, elif) != 1)
	{
		free(meme);
		free(rtp1);
		free(rtp2);
		fclose(elif);
		return NULL;
	}
	if(fread(rtp2, sizeof(struct my_tagBITMAPINFOHEADER), 1, elif) != 1)
	{
		free(meme);
		free(rtp1);
		free(rtp2);
		fclose(elif);
		return NULL;
	}
	my_RGBQUAD* colors = (my_RGBQUAD*)malloc(sizeof(my_RGBQUAD) * 257);
	if(colors == NULL)
	{
		free(meme);
		free(rtp1);
		free(rtp2);
		fclose(elif);
		return NULL;
	}
	if(fread(colors, sizeof(struct my_tagRGBQUAD), 256, elif) != 256)
	{
		free(meme);
		free(rtp1);
		free(rtp2);
		fclose(elif);
		free(colors);
		return NULL;
	}
	BYTE** bajty = create_pic(rtp2->biHeight, rtp2->biWidth);
	if(bajty == NULL)
	{
		free(meme);
		free(rtp1);
		free(rtp2);
		fclose(elif);
		free(colors);
		return NULL;
	}
	for(int i = 0; i < rtp2->biHeight; ++i)
	{
		if(fread(*(bajty + i), sizeof(BYTE), rtp2->biWidth, elif) != rtp2->biWidth)
		{
			free(meme);
			free(rtp1);
			free(rtp2);
			delet_dis(&bajty, rtp2->biWidth);
			fclose(elif);
			free(colors);
			return NULL;
		}
	}
	meme->clr = colors;
	meme->rtp = bajty;
	meme->ptr1 = rtp1;
	meme->ptr2 = rtp2;
	fclose(elif);
	return meme;
}
BYTE** (modify_bmp)(const BYTE** rtp, DWORD height, DWORD width, BYTE** (*ptr)(const BYTE**, DWORD, DWORD))
{
	if(rtp == NULL || height < 1 || width < 1 || *rtp == NULL)
		return NULL;
	BYTE** meme = (*ptr)(rtp,height, width);
	if(meme == NULL)
		return NULL;
	return meme;
}
BYTE** copy_bmp(const BYTE** rtp, DWORD height, DWORD width)
{
	if(rtp == NULL || height < 1 || width < 1 || *rtp == NULL)
		return NULL;
	BYTE** meme = create_pic(height,width);
	if(meme == NULL)
		return NULL;
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
			*(*(meme + i) + j) = *(*(rtp + i) + j);
	}
	return meme;
}
BYTE** random_noise_gen(const BYTE** rtp, DWORD height, DWORD width)
{
	if(rtp == NULL || height < 1 || width < 1 || *rtp == NULL)
		return NULL;
	BYTE** meme = copy_bmp(rtp, height,width);
	if(meme == NULL)
		return NULL;
	BYTE** is_set_ptr;
	is_set_ptr = (BYTE**)malloc(sizeof(BYTE*)*height);
	if(is_set_ptr == NULL)
	{
		delet_dis(meme, height);
		return NULL;
	}
	for(int i = 0; i < height; ++i)
	{
		*(is_set_ptr + i) = (BYTE*)malloc(width);
		if(*(is_set_ptr + i) == NULL)
		{
			for(int j = i - 1; j >= 0; --j)
				free(*(is_set_ptr + j));
			free(is_set_ptr);
		}
	}
	for(int i = 0; i < height; ++i)
	{
		for(int j  = 0; j < width; ++j)
			*(*(is_set_ptr + i) + j) = 1;
	}
	for(int i = 0; i < width * height/(1 + rand()%6); ++i)
	{
		int k = rand()%height;
		int l = rand()%width;
		BYTE px = rand()%2 ? 255 : 0;
		if(!k && !l)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k + 1) + l + 1) && *(*(is_set_ptr + k + 1) + l) && *(*(is_set_ptr + k) + l + 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k + 1) + l + 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
				*(*(is_set_ptr + k) + l + 1) = 0;
			}
		}
		else if(k == height - 1 && !l)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k - 1) + l + 1) && *(*(is_set_ptr + k - 1) + l) && *(*(is_set_ptr + k) + l + 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k - 1) + l + 1) = 0;
				*(*(is_set_ptr + k - 1) + l) = 0;
				*(*(is_set_ptr + k) + l + 1) = 0;
			}
		}
		else if(!k && l == width - 1)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k + 1) + l - 1) && *(*(is_set_ptr + k + 1) + l) && *(*(is_set_ptr + k) + l - 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k + 1) + l - 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
				*(*(is_set_ptr + k) + l - 1) = 0;
			}
		}
		else if(k == height - 1 && l == width - 1)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k - 1) + l - 1) && *(*(is_set_ptr + k - 1) + l) && *(*(is_set_ptr + k) + l - 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k - 1) + l - 1) = 0;
				*(*(is_set_ptr + k - 1) + l) = 0;
				*(*(is_set_ptr + k) + l - 1) = 0;
			}
		}
		else if(!k && l && l < width - 1)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k + 1) + l + 1) && *(*(is_set_ptr + k) + l + 1) && *(*(is_set_ptr + k + 1) + l) && *(*(is_set_ptr + k ) + l - 1) && *(*(is_set_ptr + k + 1) + l - 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k) + l + 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
				*(*(is_set_ptr + k + 1) + l - 1) = 0;
				*(*(is_set_ptr + k) + l - 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
			}
		}
		else if(!l && k && k < height - 1)
		{
			if(*(*(is_set_ptr + k) + l) && *(*(is_set_ptr + k + 1) + l + 1) && *(*(is_set_ptr + k) + l + 1) && *(*(is_set_ptr + k + 1) + l) && *(*(is_set_ptr + k ) + l - 1) && *(*(is_set_ptr + k + 1) + l - 1))
			{
				*(*(meme + k) + l) = px;
				*(*(is_set_ptr + k) + l) = 0;
				*(*(is_set_ptr + k) + l + 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
				*(*(is_set_ptr + k + 1) + l - 1) = 0;
				*(*(is_set_ptr + k) + l - 1) = 0;
				*(*(is_set_ptr + k + 1) + l) = 0;
			}
		}
		
		
	}
	return meme;
}
BYTE** noise_remover(const BYTE** rtp, DWORD height, DWORD width)
{
	if(rtp == NULL || height < 1 || width < 1 || *rtp == NULL)
		return NULL;
	BYTE** meme = create_pic(height,width);
	if(meme == NULL)
		return NULL;
	
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if((!i && !j)) *(*(meme + i) + j) = med(4, *(*(rtp + i) + j), *(*(rtp + i + 1) + j + 1), *(*(rtp + i) + j + 1), *(*(rtp + i + 1) + j));
			else if(i == height - 1 && !j) *(*(meme + i) + j) = med(4, *(*(rtp + i) + j), *(*(rtp + i - 1) + j + 1), *(*(rtp + i) + j + 1), *(*(rtp + i - 1) + j));
			else if(!i && j == width - 1) *(*(meme + i) + j) = med(4, *(*(rtp + i) + j), *(*(rtp + i + 1) + j - 1), *(*(rtp + i) + j - 1), *(*(rtp + i + 1) + j));
			else if(i == height - 1 && j == width - 1) *(*(meme + i) + j) = med(4, *(*(rtp + i) + j), *(*(rtp + i - 1) + j - 1), *(*(rtp + i) + j - 1), *(*(rtp + i - 1) + j));
			else if(!i && j && j < width - 1) *(*(meme + i) + j) = med(6, *(*(rtp + i) + j), *(*(rtp + i + 1) + j + 1), *(*(rtp + i) + j + 1), *(*(rtp + i + 1) + j), *(*(rtp + i ) + j - 1), *(*(rtp + i + 1) + j - 1));
			else if(i && i < height - 1 && !j) *(*(meme + i) + j) = med(6, *(*(rtp + i) + j), *(*(rtp + i + 1) + j), *(*(rtp + i - 1) + j), *(*(rtp + i) + j + 1), *(*(rtp + i - 1) + j + 1), *(*(rtp + i + 1) + j + 1));
			else if(i == width - 1 && j && j < width - 1)  *(*(meme + i) + j) = med(6, *(*(rtp + i) + j + 1), *(*(rtp + i) + j - 1), *(*(rtp + i) + j), *(*(rtp + i - 1) + j + 1), *(*(rtp + i - 1) + j - 1), *(*(rtp + i - 1) + j));
			else if(i && i < height - 1 && j == width - 1) *(*(meme + i) + j) = med(6, *(*(rtp + i) + j - 1), *(*(rtp + i) + j - 1), *(*(rtp + i + 1) + j - 1), *(*(rtp + i + 1) + j), *(*(rtp + i - 1) + j), *(*(rtp + i - 1) + j));
			else *(*(meme + i) + j) = med(9, *(*(rtp + i) + j), *(*(rtp + i) + j - 1), *(*(rtp + i) + j + 1), *(*(rtp + i + 1) + j), *(*(rtp + i + 1) + j + 1), *(*(rtp + i + 1) + j - 1), *(*(rtp + i - 1) + j), *(*(rtp + i - 1) + j + 1), *(*(rtp + i - 1) + j - 1));
		}
	}
	return meme;
}
BYTE** negate_picture(const BYTE** rtp, DWORD height, DWORD width)
{
	if(rtp == NULL || height < 1 || width < 1 || *rtp == NULL)
		return NULL;
	BYTE** meme = create_pic(height,width);
	if(meme == NULL)
		return NULL;
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
			*(*(meme + i) + j) = 255 - *(*(rtp + i) + j);
	}
	return meme;
}
BYTE** create_pic(DWORD height, DWORD width)
{
	if(height < 1 || width < 1)
		return NULL;
	BYTE** meme = (BYTE**)malloc(height*sizeof(BYTE*));
	if(meme == NULL) return NULL;
	for(int i = 0; i < height; ++i)
	{
		*(meme + i) = (BYTE*)malloc(width*sizeof(BYTE));
		if(meme == NULL)
		{
			for(int j = i - 1; j >= 0; ++j)
				free(*(meme + j));
			free(meme);
		}
	}
	return meme;
}
void delet_dis(BYTE*** rtp, DWORD height)
{
	if(rtp != NULL && *rtp != NULL && height > 0)
	{
		for(int i = 0; i < height; ++i)
		{
			if(*(*rtp + i) != NULL)
				free(*(*rtp + i));
		}
		free(*rtp);
	}
}
BYTE med(int parms, ...)
{
	if(parms < 1)
		return -1;
	va_list data;
	va_start(data, parms);
	BYTE *par = (BYTE*)malloc(sizeof(BYTE) * parms);
	if(par == NULL) return -1;
	for(int i = 0; i < parms; ++i)
		*(par + i) = va_arg(data, int);
	va_end(data);
	int	bool1 = 1;
	while(bool1)
	{
		bool1 = 0;
		for(int i = 0; i + 1 < parms; ++i)
		{
			if(*(par + i) < *(par + i + 1))
			{
				int tmp = *(par + i);
				*(par + i) = *(par + i + 1);
				*(par + i + 1) = tmp;
				bool1 = 1;
			}
		}
	}
	BYTE _med_ =  parms%2 ? *(par + parms/2) : (*(par + parms/2) + *(par + parms/2 - 1))/2;
	free(par);
	return _med_;
}
