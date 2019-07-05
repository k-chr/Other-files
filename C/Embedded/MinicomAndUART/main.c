#include "at91sam9263.h"
#include "AT91SAM9263-EK.h"
char DEBUG[7];
#define CLK_DIV 16
#define MCK 100000000
#define CLK_MINICOM 115200
#define CLK_DBG (MCK / (CLK_DIV * CLK_MINICOM))
#define SIZE        12
#define DBGU_IDR (AT91C_DBGU_IDR)
#define DBGU_CR (AT91C_DBGU_CR)
#define PIOC_ASR (AT91C_PIOC_ASR)
#define PIOC_PDR (AT91C_PIOC_PDR)
#define DBGU_MR (AT91C_DBGU_MR)
#define DBGU_BRGR (AT91C_DBGU_BRGR)
#define DBGU_THR (AT91C_DBGU_THR)
#define DBGU_RHR (AT91C_DBGU_RHR)

typedef struct Fifo{
	int head;
	int tail;
	char DATA[SIZE+1];
} FIFO;

int strlen(volatile char * str){
	volatile unsigned int len = 0;
	if(str){
		for(; *(str + len) != '\0'; ++len);
	}
	return len;
}
void initFIFO(volatile FIFO* f){
	f->head = 0;
	f->tail = 0;
	f->DATA[0] = '\0';	
	return;
}
char Capitalize(char c){
	return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c;
}

int FIFO_isFull(volatile FIFO * Fifo){
	return (Fifo->tail-Fifo->head==1||((Fifo->head-Fifo->tail)== SIZE));
}
int FIFO_isEmpty (volatile FIFO *Fifo){
	return (Fifo->tail == Fifo->head);
}
int FIFO_Put (volatile FIFO *Fifo, char Data){
	if(!FIFO_isFull(Fifo)){
		Fifo->DATA[Fifo->head] = Data;
		Fifo->head++;
		Fifo->head %= (SIZE + 1);
		DEBUG[0] = Fifo->tail;
		DEBUG[1] = Fifo->head;
		return 1;
	}
	return -1;
}
char FIFO_Get(volatile FIFO *Fifo){
	if(!FIFO_isEmpty(Fifo)){
		volatile char c = Fifo->DATA[Fifo->tail];
		Fifo->tail++;
		Fifo->tail %= (SIZE + 1);
		DEBUG[0] = Fifo->tail;
		DEBUG[1] = Fifo->head;
		return c;
	}
	return -1;
}
void FIFO_Empty(volatile FIFO* f){
	f->head = f->tail;
	return;
}

void initFIFOFromString(volatile FIFO *f, volatile char* str)
{
	volatile int i = 0;
	for(;i < strlen(str) + 1;++i)
		FIFO_Put(f,*(str + i));
	DEBUG[0] = f->tail;
	DEBUG[1] = f->head;
	return;
}
static void Open_DBGU (void){
	*DBGU_IDR = AT91C_US_RXRDY | AT91C_US_TXRDY | AT91C_US_ENDRX | 
		    AT91C_US_ENDTX | AT91C_US_OVRE | AT91C_US_FRAME |
		    AT91C_US_PARE | AT91C_US_TXEMPTY | AT91C_US_TXBUFE |
		    AT91C_US_RXBUFF | AT91C_US_COMM_TX | AT91C_US_COMM_RX;
  	*DBGU_MR = AT91C_US_CHMODE_NORMAL | AT91C_US_PAR_NONE;
	*DBGU_CR = AT91C_US_RSTRX | AT91C_US_RXDIS;
	*DBGU_CR |= AT91C_US_RSTTX | AT91C_US_TXDIS;
	*PIOC_ASR = AT91C_US_COMM_TX | AT91C_US_COMM_RX;
	*PIOC_PDR = AT91C_US_COMM_RX | AT91C_US_COMM_TX;
	*DBGU_BRGR = CLK_DBG;
	*DBGU_CR = AT91C_US_RXEN;
	*DBGU_CR |= AT91C_US_TXEN;
      /*1. Wyłącz przerwania od portu DBGU, rejestr AT91C_BASE_DBGU->DBGU_IDR
	2. Resetuj i wyłącz odbiornik AT91C_BASE_DBGU->DBGU_CR
	3. Resetuj i wyłącz nadajnik AT91C_BASE_DBGU->DBGU_CR
	4. Konfiguracja portów wejścia-wyjścia jako porty RxD i TxD DBGU,
	rejestry AT91C_BASE_PIOC->PIO_ASR oraz AT91C_BASE_PIOC->PIO_PDR
	5. Konfiguracja szybkości transmisji portu szeregowego AT91C_BASE_DBGU->DBGU_BRGR
	6. Konfiguracja trybu pracy, tryb normalny bez przystości (8N1),
	rejestr AT91C_BASE_DBGU->DBGU_MR, flagi AT91C_US_CHMODE_NORMAL,
	AT91C_US_PAR_NONE;
	7. Skonfiguruj przerwania jeżeli są wykorzystywane: Open_DBGU_INT()
	8. Włącz odbiornik, rejestr AT91C_BASE_DBGU->DBGU_CR
	9. Włącz nadajnik, rejestr AT91C_BASE_DBGU->DBGU_CR*/

}
/*
	115200 = 100000000/(x * 16)
	x = 100000000/(16 * 115200)
	x = 54 

*/
void test_dbgu_print_ascii (char *f)
{
	volatile int i = 0;
	while (i < strlen(f)) {
		while (!( *AT91C_DBGU_CSR & AT91C_US_TXRDY )); /* wait intil Tx buffer busy – check TXRDY flag */
		*DBGU_THR = Capitalize(f[i++]);  /* write a single char to Transmitter Holding Register */					
	}
}
void test_dbgu_read_ascii (char *f){
	volatile int i = 0;	
	do {
		
		while (!(*AT91C_DBGU_CSR & AT91C_US_RXRDY)); /* wait until data available */
		f[i++] = *DBGU_RHR; /* read data from Receiver Holding Register */
	} while (i < SIZE);
}
void dbgu_print_ascii (volatile FIFO *f)
{
	while (!FIFO_isEmpty(f)) {
		while (!( *AT91C_DBGU_CSR & AT91C_US_TXRDY) ); /* wait intil Tx buffer busy – check TXRDY flag */
		*DBGU_THR = Capitalize(FIFO_Get(f));
		DEBUG[0] = f->tail;
		DEBUG[1] = f->head;  /* write a single char to Transmitter Holding Register */					
	}
	while (!( *AT91C_DBGU_CSR & AT91C_US_TXRDY) );
	*DBGU_THR = '\n';
	while (!( *AT91C_DBGU_CSR & AT91C_US_TXRDY) );
	*DBGU_THR = '\r';

	return;
}
void dbgu_read_ascii (volatile FIFO *f){
	do {
		while (!(*AT91C_DBGU_CSR & AT91C_US_RXRDY)); /* wait until data available */
		FIFO_Put(f, *DBGU_RHR);
		DEBUG[0] = f->tail;
		DEBUG[1] = f->head; /* read data from Receiver Holding Register */
	} while (!FIFO_isFull(f));
}

int main(){
	Open_DBGU();
	volatile char* toSend = "qwertyawerty\n";	
	volatile FIFO f;
	initFIFO(&f);
	initFIFOFromString(&f, toSend);
	while(1){
		dbgu_print_ascii(&f);
		FIFO_Empty(&f);
		dbgu_read_ascii(&f);
	}
	return 0;
}
