//image_operations.h
#ifndef _image_operations_H
#define _image_operations_H
typedef int LONG;
typedef unsigned char BYTE;
typedef unsigned int DWORD;
typedef unsigned short WORD;
#pragma pack(push, 1)
typedef struct  __attribute__ ((__packed__)) my_tagBITMAPFILEHEADER {
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
} my_BITMAPFILEHEADER, *my_PBITMAPFILEHEADER;
#pragma pack(pop)
typedef struct my_tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} my_BITMAPINFOHEADER, *my_PBITMAPINFOHEADER;

typedef struct my_tagRGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} my_RGBQUAD;
typedef struct image{
	my_PBITMAPFILEHEADER ptr1;
	my_PBITMAPINFOHEADER ptr2;
	my_RGBQUAD* clr;
	BYTE** rtp;
} img, *p_img;
BYTE ** noise_remover(const BYTE** rtp, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width, BYTE** (const BYTE**, DWORD, DWORD, DWORD, DWORD));
void delet_meme(p_img* image);
BYTE med(int parms, ...);
BYTE med_mask(const BYTE** mask, DWORD height, DWORD width);
BYTE** get_mask(const BYTE**, DWORD height, DWORD width, DWORD mask_height, DWORD mask_width);
BYTE** noise_remover_med(const BYTE** mask, DWORD mask_height, DWORD mask_width);
BYTE** noise_remover_max(const BYTE** mask, DWORD mask_height, DWORD mask_width);
BYTE** noise_remover_min(const BYTE** mask, DWORD mask_height, DWORD mask_width);
int save_bmp(char* filename, p_img img);
p_img load_img_b(char* filename);
BYTE** (modify_bmp)(const BYTE** rtp, DWORD height, DWORD width, BYTE** (*ptr)(const BYTE**, DWORD, DWORD));
BYTE** copy_bmp(const BYTE** rtp, DWORD height, DWORD width);
BYTE** random_noise_gen(const BYTE** rtp, DWORD height, DWORD width, DWORD mask_height);
BYTE** negate_picture(const BYTE** rtp, DWORD height, DWORD width);
BYTE** create_pic(DWORD height, DWORD width);
void delet_dis(BYTE*** rtp, DWORD height);
#endif
