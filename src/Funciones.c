/*
 * Funciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Agustin
 */
#include "Funciones.h"

int MenuDeOpciones(int kilometrajeIngresado, float primerVuelo, float segundoVuelo)
{
	int opcionElegida;

	printf("----------------------------------------------------");
	printf("\n1- Ingrese los kilometretos que va a recorrer: %dKM\n", kilometrajeIngresado);
	printf("\n2- Ingrese precio de vuelos: \n-Aerolineas Argentinas: $%.2f\n-Aerolineas Latam: $%.2f\n", primerVuelo, segundoVuelo);
	printf("\n3- Calcular costos:\n"
	"a) Tarjeta de debito:\n"
	"b) Tarjeta de credito:\n"
	"c) Bitcoin:\n"
	"d) Mostrar precio por km:\n"
	"e) Mostrar diferencia de precio ingresada:\n");
	printf("\n4- Informar resultados:\n");
	printf("\n5- Carga forzada de datos:\n");
	printf("\n6- Salir\n");
	printf("\nElija una opcion: ");
	scanf("%d", &opcionElegida);
	fflush(stdin);

	return opcionElegida;
}

int IngresarKilometraje()
{
	int numIngresado = 0;

	printf("\nIngrese el kilometraje: ");
    fflush(stdin);
    scanf("%d", &numIngresado);

	while(numIngresado < 1)
	{
		printf("\nERROR-Reingrese un kilometraje valido: ");
	    fflush(stdin);
	    scanf("%d", &numIngresado);
	}

	return numIngresado;
}

float IngresarPrecioVueloUno()
{
	float precioIngresado = 0;

	printf("\nIngrese el precio de vuelo Aerolineas Argentinas: ");
	fflush(stdin);
	scanf("%f", &precioIngresado);

	while(precioIngresado < 1)
	{
		printf("\nERROR-Reingrese el precio de vuelo Aerolineas Argentinas: ");
		fflush(stdin);
		scanf("%f", &precioIngresado);
	}

	return precioIngresado;
}

float IngresarPrecioVueloDos()
{
	float precioIngresado = 0;

	printf("\nIngrese el precio de vuelo Aerolineas Latam: ");
	fflush(stdin);
	scanf("%f", &precioIngresado);

	while(precioIngresado < 1)
	{
		printf("\nERROR-Reingrese el precio de vuelo Aerolineas Latam: ");
		fflush(stdin);
		scanf("%f", &precioIngresado);
	}

	return precioIngresado;
}

void RealizarValidacion(float primerVuelo, float segundoVuelo, float kilometraje)
{
	if(primerVuelo < 1 || segundoVuelo < 1 || kilometraje < 1)
	{
		printf("-----------------------------------------------");
		printf("\nERROR- No se pueden realizar los calculos sin haber ingresado los datos previamente.\n");
	}
}

float CalcularDescuentoDebito(float primerVuelo)
{
	float descuento;

	descuento = primerVuelo - primerVuelo * 0.10;

	return descuento;
}

float CalcularDescuentoDebitoDos(float segundoVuelo)
{
	float descuento;

	descuento = segundoVuelo - segundoVuelo * 0.10;

	return descuento;
}

float CalcularInteresCredito(float primerVuelo)
{
	float interes;

	interes = primerVuelo + primerVuelo * 0.25;

	return interes;
}

float CalcularInteresCreditoDos(float segundoVuelo)
{
	float interes;

	interes = segundoVuelo + segundoVuelo * 0.25;

	return interes;
}

float CalcularBitcon(float primerVuelo)
{
	float numIngresado;

	numIngresado = primerVuelo / 4606954.55;

	return numIngresado;
}

float CalcularBitconDos(float segundoVuelo)
{
	float numIngresado;

	numIngresado = segundoVuelo / 4606954.55;

	return numIngresado;
}

float CalcularPrecioUnitario(float primerVuelo, float kilometraje)
{
	float numIngresado;

	numIngresado = primerVuelo / kilometraje;

	return numIngresado;
}

float CalcularPrecioUnitarioDos(float segundoVuelo, float kilometraje)
{
	float numIngresado;

	numIngresado = segundoVuelo / kilometraje;

	return numIngresado;
}

float CalcularDifTotal(float primerVuelo, float segundoVuelo, float difPrecio)
{
	float diferencia;

	if(primerVuelo > segundoVuelo)
	{
		diferencia = primerVuelo - segundoVuelo;
	}
	else
	{
		diferencia = segundoVuelo - primerVuelo;
	}

	return diferencia;
}

void RealizarCargaForzada(float precioDebitoUno, float precioCreditoUno, float precioBitcoinUno, float precioUnitUno, float precioDebitoDos, float precioCreditoDos, float precioBitcoinDos, float precioUnitDos, float difPrecio)
{
	int kilometrajeCarga = 7090;
	int precioIngresado = 162965;
	int precioIngresadoDos = 159339;

	printf("-----------------------------------------------");
	printf("\nKilometraje ingresado: %dKM\n", kilometrajeCarga);
	printf("\nPrecio Aerolineas: %d$", precioIngresado);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoUno);
	printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoUno);
	printf("\nc) Precio pagando con bitcoin: $%f", precioBitcoinUno);
	printf("\nd) Precio unitario: $%.2f\n", precioUnitUno);
	printf("\nPrecio Latam: %d$", precioIngresadoDos);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoDos);
	printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoDos);
	printf("\nc) Precio pagando con bitcoin: $%f", precioBitcoinDos);
	printf("\nd) Precio unitario: $%.2f\n", precioUnitDos);
	printf("\nLa diferencia de precio es: $%.2f\n", difPrecio);
}

void MenuFinal(int kilometraje, float primerVuelo, float precioDebitoUno, float precioCreditoUno, float precioBitcoinUno, float precioUnitUno, float segundoVuelo, float precioDebitoDos, float precioCreditoDos, float precioBitcoinDos, float precioUnitDos, float difPrecio)
{
	printf("-----------------------------------------------");
	if(primerVuelo < 1 || segundoVuelo < 1 || kilometraje < 1)
	{
		printf("\nERROR- No se puede mostrar los resultados sin haber ingresado los datos previamente.\n");
	}
	else
	{
		printf("\nPrecio Aerolineas: $%.2f", primerVuelo);
		printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoUno);
		printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoUno);
		printf("\nc) Precio pagando con bitcoin: $%f", precioBitcoinUno);
		printf("\nd) Precio unitario: $%.2f\n", precioUnitUno);
		printf("\nPrecio Latam: $%.2f", segundoVuelo);
		printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoDos);
		printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoDos);
		printf("\nc) Precio pagando con bitcoin: $%f", precioBitcoinDos);
		printf("\nd) Precio unitario: $%.2f\n", precioUnitDos);
		printf("\nLa diferencia de precio es: $%.2f\n", difPrecio);
	}
}
