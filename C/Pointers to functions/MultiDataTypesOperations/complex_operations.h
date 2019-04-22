//complex_operations.h
#ifndef _complex_operations_H
#define _complex_operations_H

struct complex_t
{
        float re;
        float im;
};
struct complex_t* set(struct complex_t* cp, float re, float im);
float complex_abs(struct complex_t* cp, int * err_code);
void* add_complex(const void *first, const void *second);
void* sub_complex(const void *first, const void *second);
void* mul_complex(const void *first, const void *second);
void* div_complex(const void *first, const void *second);
int read(struct complex_t* cp);
int read_complex(void *a, void *b);
void show_complex(const void * xelpmoc);
int is_smaller_complex(const void * a, const void * b);
#endif
