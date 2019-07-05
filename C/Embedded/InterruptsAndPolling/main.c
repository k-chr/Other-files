#include "at91sam9263.h"
#include "AT91SAM9263-EK.h"

#define SIZE        10
#define DEBUG	    0
#define LENOFPERIOD  625000
#define NUMOFPERIODS  10
#define ENABLE (1<<24)
#define ENABLEINTERRUPTS (1<<25)
#define PIT_BASE ((AT91_REG*)(AT91C_BASE_PITC))
#define PIVR (AT91C_PITC_PIVR)  // (PITC) Period Interval Value Register
#define PISR (AT91C_PITC_PISR)  // (PITC) Period Interval Status Register
#define PIIR (AT91C_PITC_PIIR) // (PITC) Period Interval Image Register
#define PIMR (AT91C_PITC_PIMR)  
volatile int side = -1;
volatile int globalPeriodCounter = 0; 
volatile int globalI = 0;

void dbgu_print_ascii(const char* str){
	
}
void delay(unsigned int ms){
	volatile unsigned int i = 0;
	for(; i < ms*1000; i+=1){
		if(((*AT91C_PIOC_PDSR & AT91B_BP1)))
			side = 1;
		else{
			side = -1;		
		}
	}		
}
void PrintNum(volatile unsigned int* dig, volatile unsigned int* dec){
	*AT91C_PIOB_SODR = AT91C_PIO_PB28| *dig;
	delay(10);
	*AT91C_PIOB_CODR = AT91C_PIO_PB28| *dig;
	*AT91C_PIOB_SODR = AT91C_PIO_PB30| *dec;
	delay(10);
	*AT91C_PIOB_CODR = AT91C_PIO_PB30| *dec;
}
void PIOB_init(){
	*AT91C_PIOB_PER = AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB22|AT91C_PIO_PB21|AT91C_PIO_PB20|AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB30|AT91C_PIO_PB28;
	*AT91C_PIOB_OER = AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB22|AT91C_PIO_PB21|AT91C_PIO_PB20|AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB30|AT91C_PIO_PB28;
	*AT91C_PIOB_CODR = AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB22|AT91C_PIO_PB21|AT91C_PIO_PB20|AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB30|AT91C_PIO_PB28;
}
void initButton(){
	*AT91C_PIOC_PER = AT91B_BP1;
	*AT91C_PIOC_ODR = AT91B_BP1;
	*AT91C_PIOC_PPUER = AT91B_BP1;
	*AT91C_PMC_PCER = AT91C_ID_PIOCDE;
}
void CatchInterrupt(){
	if(*PISR){
		*PIVR;
		++globalPeriodCounter;
		if(globalPeriodCounter == NUMOFPERIODS){
			globalI += side;
			globalPeriodCounter = 0;
			globalI > 99 ? (globalI=0) : (globalI < 0 ? (globalI = 99) : 1);
		}	
	}
	return;
}

int main(){
	
	volatile unsigned int nums[10] = {
							 AT91C_PIO_PB25|AT91C_PIO_PB27|AT91C_PIO_PB24|AT91C_PIO_PB20|AT91C_PIO_PB22|AT91C_PIO_PB21,
							 AT91C_PIO_PB24|AT91C_PIO_PB22,
							 AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB26|AT91C_PIO_PB20|AT91C_PIO_PB21,
							 AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB26|AT91C_PIO_PB22|AT91C_PIO_PB21,
							 AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB24|AT91C_PIO_PB22,
							 AT91C_PIO_PB25|AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB22|AT91C_PIO_PB21,
							 AT91C_PIO_PB25|AT91C_PIO_PB27|AT91C_PIO_PB26|AT91C_PIO_PB22|AT91C_PIO_PB21|AT91C_PIO_PB20,
							 AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB22,
							 AT91C_PIO_PB25|AT91C_PIO_PB24|AT91C_PIO_PB22|AT91C_PIO_PB21|AT91C_PIO_PB20|AT91C_PIO_PB27|AT91C_PIO_PB26,
							 AT91C_PIO_PB25|AT91C_PIO_PB27|AT91C_PIO_PB24|AT91C_PIO_PB26|AT91C_PIO_PB22|AT91C_PIO_PB21
	};
	/*#if DEBUG == 1	
	PIOB_init();
	initButton();
	volatile int i = 0;
	volatile int periods = 0;
	*PIMR = LENOFPERIOD|ENABLE;					
	while(1){
		if((*PISR)){
			++periods;
			volatile unsigned int k = *PIVR;
			if(periods == NUMOFPERIODS){
				periods = 0;
				i+=side;
				i > 99 ? (i=0) : (i < 0 ? (i = 99) : 1);
			}
		}
		PrintNum((nums + (i)%SIZE), (nums + (i)/SIZE));
	}*/
	
	
	*AT91C_AIC_IDCR = 1<<AT91C_ID_SYS;
	AT91C_AIC_SVR[AT91C_ID_SYS] = (unsigned long)CatchInterrupt;
	AT91C_AIC_SMR[AT91C_ID_SYS] = AT91C_AIC_SRCTYPE_EXT_HIGH_LEVEL|AT91C_AIC_PRIOR_LOWEST;
	*AT91C_AIC_ICCR = 1<<AT91C_ID_SYS;
	*AT91C_AIC_IECR = 1<<AT91C_ID_SYS;
	PIOB_init();
	initButton();
	*PIMR = ENABLE|ENABLEINTERRUPTS|LENOFPERIOD;
	while(1){
		PrintNum((nums + (globalI)%SIZE), (nums + (globalI)/SIZE));	
	}
	
	return 0;
}
