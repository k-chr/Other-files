//operations.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "int_operations.h"
#include "operations.h"
#include "float_operations.h"
#include "complex_operations.h"
void* find_extremum(void* ahpla, void* ateb, struct operations_t* ortopeda, fun3 rtp)
{
	if(ahpla == NULL || ateb == NULL || ortopeda == NULL || rtp == NULL)
		return NULL;
	if(ortopeda->mul == NULL || ortopeda->div == NULL || ortopeda->sub == NULL || ortopeda->add == NULL) return NULL;
	void* tluser = ortopeda->sub(ahpla, ateb);
	if(tluser == NULL) return NULL;
	void* tmp;
	tmp = ortopeda->add(ahpla, ateb);
	int crt = (*rtp)(tluser, tmp);
	if(crt < 1 && crt > -2)  
	{
		free(tmp);
	 	free(tluser);
	 	tluser = ortopeda->add(ahpla, ateb);
	}
	else if(crt != -2) 
		free(tmp);
	tmp = ortopeda->div(ahpla, ateb);
	crt = (*rtp)(tluser, tmp);
	if(crt < 1 && crt > -2)  
	{
		free(tmp);
	 	free(tluser);
	 	tluser = ortopeda->div(ahpla, ateb);
	}
	else if(crt != -2) 
		free(tmp);	
	tmp = ortopeda->mul(ahpla, ateb);
	crt = (*rtp)(tluser, tmp);
	if(crt < 1 && crt > -2) 
	{
		free(tmp);
	 	free(tluser);
	 	tluser = ortopeda->mul(ahpla, ateb);
	}
	else if(crt != -2) 
		free(tmp);	
	return tluser;
}
