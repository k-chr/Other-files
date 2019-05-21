#define PIOB_PER (volatile unsigned int* const)0xFFFFF400
#define PIOC_PER (volatile unsigned int* const)0xFFFFF600
#define PIOB_OER (volatile unsigned int* const)0xFFFFF410
#define PIOC_OER (volatile unsigned int* const)0xFFFFF610
#define PIOB_CODR (volatile unsigned int* const)0xFFFFF434
#define PIOB_SODR (volatile unsigned int* const)0xFFFFF430
#define PIOC_CODR (volatile unsigned int* const)0xFFFFF634
#define PIOC_SODR (volatile unsigned int* const)0xFFFFF630
#define LED1 1<<8
#define LED2 1<<29
#define BUT2 1<<4
#define BUT1 1<<5
#define PIOC_ODR (volatile unsigned int* const)0xFFFFF614
#define PIOC_PUER (volatile unsigned int* const)0xFFFFF664
#define PMC_PCER (volatile unsigned int* const)0xFFFFFC10
#define PIOC 1<<4
#define PIOC_PDSR (volatile unsigned int* const)0xFFFFF63C
void dbgu_print_ascii(const char* str){
	
}
void initButton(){
	*PIOC_PER = BUT2;
	*PIOC_ODR = BUT2;
	*PIOC_PUER = BUT2;
	*PMC_PCER = PIOC;
}
void initLED(int led){
	led ? (
	(*PIOB_PER = LED1,
	*PIOB_OER = LED1,
	*PIOB_CODR = LED1,
	*PIOB_SODR = LED1)
	) 
	: (
	(*PIOC_PER = LED2,
	*PIOC_OER = LED2,
	*PIOC_CODR = LED2,
	*PIOC_SODR = LED2)
	);
}
void delay(unsigned int ms){
	volatile unsigned int i = 0;
	for(; i < ms*2000; i+=1){
		if(!(*PIOC_PDSR & BUT2))
			*PIOC_CODR = LED2;
		else
			*PIOC_SODR = LED2;	
	}
		
}

void blink(){
	*PIOB_SODR = LED1;
	delay(1000);	
	*PIOB_CODR = LED1;	
	delay(1000);
}

int main(){
	initLED(0);
	initLED(1);
	initButton();
	while(1){
		
		delay(20);
		blink();
		delay(20);	
	}
	return 0;
}

