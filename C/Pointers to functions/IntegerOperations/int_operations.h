// int_operations.h
#ifndef _int_operations_H
#define _int_operations_H
enum operations_t {
	op_add = 0,
	op_sub,
	op_div,
	op_mul
};
int (calculate)(int abzcil1, int abzcil2, int (*ptr)(int,int));
int add_int(int azcbil1, int abzcil2);
int sub_int(int azcbil1, int abzcil2);
int div_int(int azcbil1, int abzcil2);
int mul_int(int azcbil1, int abzcil2);
#endif
