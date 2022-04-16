/*
Vega, Agustín: TP.1 Programación y Laboratorio Div B.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcionElegida;
	int kilometraje = 0;
	float primerVuelo;
	float segundoVuelo;
	float precioDebitoUno;
	float precioCreditoUno;
	float precioBitcoinUno;
	float precioUnitUno;
	float precioDebitoDos;
	float precioCreditoDos;
	float precioBitcoinDos;
	float precioUnitDos;
	float difPrecio;
	int kilometrajeCarga = 7090;
	int precioIngresado = 162965;
	int precioIngresadoDos = 159339;

	do
	{
		opcionElegida = MenuDeOpciones(kilometraje, primerVuelo, segundoVuelo);
		switch (opcionElegida)
		{
			case 1:
				kilometraje = IngresarKilometraje();
			break;
			case 2:
				primerVuelo = IngresarPrecioVueloUno();
				segundoVuelo = IngresarPrecioVueloDos();
			break;
			case 3:
				RealizarValidacion(primerVuelo, segundoVuelo, kilometraje);
				system("pause");
				precioDebitoUno = CalcularDescuentoDebito(primerVuelo);
				precioCreditoUno = CalcularInteresCredito(primerVuelo);
				precioBitcoinUno = CalcularBitcon(primerVuelo);
				precioUnitUno = CalcularPrecioUnitario(primerVuelo, kilometraje);
				precioDebitoDos = CalcularDescuentoDebitoDos(segundoVuelo);
				precioCreditoDos = CalcularInteresCreditoDos(segundoVuelo);
				precioBitcoinDos = CalcularBitconDos(segundoVuelo);
				precioUnitDos = CalcularPrecioUnitarioDos(segundoVuelo, kilometraje);
				difPrecio = CalcularDifTotal(primerVuelo, segundoVuelo, difPrecio);
			break;
			case 4:
				MenuFinal(kilometraje, primerVuelo, precioDebitoUno, precioCreditoUno, precioBitcoinUno, precioUnitUno, segundoVuelo, precioDebitoDos, precioCreditoDos, precioBitcoinDos, precioUnitDos, difPrecio);
				system("pause");
			break;
			case 5:
				precioDebitoUno = CalcularDescuentoDebito(precioIngresado);
				precioCreditoUno = CalcularInteresCredito(precioIngresado);
				precioBitcoinUno = CalcularBitcon(precioIngresado);
				precioUnitUno = CalcularPrecioUnitario(precioIngresado, kilometrajeCarga);
				precioDebitoDos = CalcularDescuentoDebitoDos(precioIngresadoDos);
				precioCreditoDos = CalcularInteresCreditoDos(precioIngresadoDos);
				precioBitcoinDos = CalcularBitconDos(precioIngresadoDos);
				precioUnitDos = CalcularPrecioUnitarioDos(precioIngresadoDos, kilometrajeCarga);
				difPrecio = CalcularDifTotal(precioIngresado, precioIngresadoDos, difPrecio);
				RealizarCargaForzada(precioDebitoUno, precioCreditoUno, precioBitcoinUno, precioUnitUno, precioDebitoDos, precioCreditoDos, precioBitcoinDos, precioUnitDos, difPrecio);
				system("pause");
			break;
			case 6:
				printf("---------------Finalizo---------------");
			break;
			default:
				printf("\n----------ERROR-Reingrese una opcion valida----------\n");
			break;
		}
	}while(opcionElegida != 6);

	return EXIT_SUCCESS;
}
