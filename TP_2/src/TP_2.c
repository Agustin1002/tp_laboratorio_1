/*
 ============================================================================
 Name        : TP2.c
 Author      : Vega, Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : TP numero 2
 ============================================================================
 */
#include "Funciones.h"
#include "ArrayPassenger.h"
#define EMPTY 0
#define BUSY 1
#define PASSENGER 2000

int main(void) {
	setbuf(stdout,NULL);

	int id = 0;
	char name[51];
	char lastName[51];
	char flycode[10];
	int typePassenger = 0;
	float price = 0;
	int statusfly = 0;

	ePassenger list[PASSENGER];
	InitPassengers(list, PASSENGER);
	Menu(list, id, name, lastName, flycode, typePassenger, price, statusfly, PASSENGER);

	return EXIT_SUCCESS;
}
