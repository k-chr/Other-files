//operations.h
#ifndef _operations_H
#define _operations_H
typedef void* (*fun)(const void*,const void*);
typedef void (*fun1)(const void*);
typedef int (*fun2)(void*, void*);
typedef int (*fun3)(const void*, const void*);
struct operations_t {
	fun mul;
	fun div;
	fun sub;
	fun add;
	fun2 read;
	fun1 show;
};
void* find_extremum(void* ahpla, void* ateb, struct operations_t* ortopeda, fun3 rtp);


#endif
