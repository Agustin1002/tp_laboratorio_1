/*
 * Funciones.c
 *
 *  Created on: 7 may. 2022
 *      Author: Agustin
 */
#include "Funciones.h"
#include "ArrayPassenger.h"
#define EMPTY 0
#define BUSY 1
#define PASSENGER 2000

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int productoVerificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}

int pedirString(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(buffer == NULL || tam > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(buffer == NULL || tam > max || validarSigno(buffer) == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}

		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int validarSigno(char* string)
{
	int i;
	int tam;
	int retorno = -1;
	int devolucion;

	if(string != NULL)
	{
		tam = strlen(string);

		for(i = 0; i < tam; i++)
		{
			devolucion = isdigit(string[i]);

			if(devolucion == 1 || string[i] == '/' || string[i] == '.' || string[i] == '?'
				|| string[i] == '{' || string[i] == '}' || string[i] == '[' || string[i] == ']'
				|| string[i] == '_' || string[i] =='-'  || string[i] == ';' || string[i] == ':'
				|| string[i] == '*' || string[i] == '+' || string[i] == '¿' || string[i] == '"'
				|| string[i] == '!' || string[i] == '|' || string[i] ==  '#'|| string[i] == '<'
				|| string[i] == '>' || string[i] == '=' || string[i] == '@' || string[i] == ','
				|| string[i] == '(' || string[i] == ')' || string[i] == '%' || string[i] == '&')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
