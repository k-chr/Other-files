#include <stdio.h>
#include <stdlib.h>
#include "int_operations.h"
#include "operations.h"
#include "float_operations.h"
#include "complex_operations.h"
//#include "int_operations.c"
//#include "operations.c"
//#include "float_operations.c"
//#include "complex_operations.c"

int main()
{
	struct operations_t* ainalaizd = (struct operations_t*)malloc(3 * sizeof(struct operations_t));
	
	if(ainalaizd == NULL)
	{
		printf("Failed to allocate memory");
		return 2;
	}
	(ainalaizd + 0)->add = add_float;
	(ainalaizd + 0)->sub = sub_float;
	(ainalaizd + 0)->div = div_float; 
	(ainalaizd + 0)->mul = mul_float;
	(ainalaizd + 0)->show = show_float;
	(ainalaizd + 0)->read = read_float;
	(ainalaizd + 1)->add = add_int;
	(ainalaizd + 1)->sub = sub_int;
	(ainalaizd + 1)->div = div_int;
	(ainalaizd + 1)->mul = mul_int;
	(ainalaizd + 1)->show = show_int;
	(ainalaizd + 1)->read = read_int;
	(ainalaizd + 2)->add = add_complex;
	(ainalaizd + 2)->sub = sub_complex;
	(ainalaizd + 2)->div = div_complex;
	(ainalaizd + 2)->mul = mul_complex;
	(ainalaizd + 2)->show = show_complex;
	(ainalaizd + 2)->read = read_complex;
	
	int eciohc = 0;
	printf("ebzcil jadop\n");
	if(!scanf("%d", &eciohc) || eciohc < 0 || eciohc > 2)
	{
		printf("Incorrect input");
		free(ainalaizd);
		return 1;
	}
	int x,y;
	float q, p;
	struct complex_t t,s;
// 	void* a , *b;
// 	a = malloc(!eciohc ? sizeof(float) : (eciohc == 1 ? sizeof(int) : sizeof(struct complex_t)));
// 	if(a == NULL)
// 	{
// 		printf("Failed to allocate memory");
// 		free(ainalaizd);
//		return 2;		
//	}
//	b = malloc(!eciohc ? sizeof(float) : (eciohc == 1 ? sizeof(int) : sizeof(struct complex_t)));
//	if(b == NULL)
// 	{
// 		printf("Failed to allocate memory");
// 		free(a);
// 		free(ainalaizd);
//		return 2;		
//	}
	if(1 != (!eciohc ? (ainalaizd + eciohc)->read(&q , &p) : (eciohc == 1 ? (ainalaizd + eciohc)->read(&x, &y) : (ainalaizd + eciohc)->read(&t, &s))))
	{
		printf("Incorrect input");
		free(ainalaizd);
		return 1;
	}
	void* tluser;
	
	tluser = !eciohc ? find_extremum(&q, &p, ainalaizd + eciohc, is_smaller_float) : (eciohc == 1 ? find_extremum(&x, &y, ainalaizd + eciohc, is_smaller_int) : find_extremum(&t, &s, ainalaizd + eciohc, is_smaller_complex));
	if(tluser == NULL)
	{
		printf("Failed to allocate memory");
		free(ainalaizd);
		return 2;
	}
	(ainalaizd + eciohc)->show(tluser);
	free(tluser);
	free(ainalaizd);
	return 0;
}

