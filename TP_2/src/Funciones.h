/*
 * Funciones.h
 *
 *  Created on: 7 may. 2022
 *      Author: Agustin
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

/// @fn int pedirEntero(int*, char*, char*, int, int)
/// @brief Da valor de un numero entero a una varible que recibe por referencia y valida en un rango determinado.
///
/// @param entero Es el numero entero que devulve por referencia.
/// @param mensaje Recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError Recibe el mensaje a mostrar en caso de error.
/// @param min El rango minimo del entero a ingresar.
/// @param max El rango maximo del entero a ingresar.
/// @return Devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/// @fn int pedirFlotante(float*, char*, char*, float, float)
/// @brief Da valor de un numero flotante a una varible que recibe por referencia y valida en un rango determinado.
///
/// @param flotante es el numero flotante que devulve por referencia.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError recibe el mensaje a mostrar en caso de error.
/// @param min el rango minimo del flotante a ingresar.
/// @param max el rango maximo del flotante a ingresar.
/// @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/// @fn int pedirCadena(char*, char*, char*, int)
/// @brief permite el ingreso de una cadena de caracteres validada y la copia en una varible que recibe por referencia
///
/// @param cadena es la variable que recibe la cadena de caracteres.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError recibe el mensaje a mostrar en caso de error.
/// @param max recibe el tamaño maximo del array de caracteres.
/// @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);

/// @fn int pedirString(char*, char*, char*, int)
/// @brief permite el ingreso de una cadena de caracteres y la copia en una varible que recibe por referencia
///
/// @param cadena es la variable que recibe la cadena de caracteres.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
/// @param mensajeError recibe el mensaje a mostrar en caso de error.
/// @param max recibe el tamaño maximo del array de caracteres.
/// @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirString(char* cadena, char* mensaje, char* mensajeError, int max);

/// @fn int pedirCaracter(char*, char*)
/// @brief pide un unico caracter.
///
/// @param caracter es la varible que recibe y devulve por referencia.
/// @param mensaje recibe un mensaje para mostrar dentro de la funcion.
/// @return devulve 0 si se pudo cargar un numero correctamente, en caso contrario devulve -1.
int pedirCaracter(char* caracter, char* mensaje);

/// @fn int productoVerificarConfirmacion(char*)
/// @brief esta función verifica que el usuario estuvo de acuerdo con la carga, baja o modificación del pasajero.
///
/// @param mensaje recibir un mensaje para mostrar en la función
/// @return devulve 0 si completo la validacion sin errores, en caso contrario devuelve -1.
int productoVerificarConfirmacion(char* mensaje);

/// @fn int validarSigno(char*)
/// @brief valida un array de caracteres para que no tenga signos, ademas de validar que tampoco tenga un numero.
///
/// @param string es el array de caracteres a validar que recibe por parametro.
/// @return devulve 0 si completo la validacion sin errores, en caso contrario devuelve -1.
int validarSigno(char* string);

#endif /* FUNCIONES_H_ */
