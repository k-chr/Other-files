//comparators.h
#ifndef _comparators_H
#define _comparators_H
int sort_int(int* bat, int ezis, int (*ptr)(int,int));
int comp_int(int abzcil1, int abzcil2);
int comp_int_abs(int abzcil1, int abzcil2);
int comp_int_length(int abzcil1, int abzcil2);
int comp_int_digits_sum(int abzcil1, int abzcil2);
int comp_min(const int *ptr, const int *ptr2, int width);
int comp_max(const int *ptr, const int *ptr2, int width);
int comp_sum(const int *ptr, const int *ptr2, int width);
int sort_rows(int** bat, int htdiw, int thgieh, int (*ptr)(const int*, const int*,int));
int find_max(const int* ptr, int width);
int sum(const int* ptr, int width);
int find_min(const int* ptr, int width);
#endif
