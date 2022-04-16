/*
 * Funciones.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Agustin
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>

/// @fn int MenuDeOpciones(int, float, float)
/// @brief Muestra el menú de opciones con el que el usuario va a interactuar.
///
/// @param kilometrajeIngresado Este parametro es el kilometraje que va a recorrer el usuario.
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @return La función retorna la opcion ingresada que guardara en el main para luego utilizarla en el switch.
int MenuDeOpciones(int kilometrajeIngresado, float primerVuelo, float segundoVuelo);

/// @fn int IngresarKilometraje()
/// @brief La funcion pide al usuario que ingrese el kilometraje que va a recorrer.
///
/// @return Retorna el kilometraje ingresado.
int IngresarKilometraje();

/// @fn float IngresarPrecioVueloUno()
/// @brief La funcion pide al usuario que ingrese el precio de Aerolineas Argentinas.
///
/// @return Retorna el precio ingresado.
float IngresarPrecioVueloUno();

/// @fn float IngresarPrecioVueloDos()
/// @brief La funcion pide al usuario que ingrese el precio de Aerolineas Latam.
///
/// @return Retorna el precio ingresado.
float IngresarPrecioVueloDos();

/// @fn void RealizarValidacion(float, float, float)
/// @brief La funcion valida que el usuarion no pueda realizar calculos sin ingresar kilometraje y los precios de las aerolineas.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @param kilometraje Este parametro es el kilometraje que va a recorrer el usuario.
void RealizarValidacion(float primerVuelo, float segundoVuelo, float kilometraje);

/// @fn float CalcularDescuentoDebito(float)
/// @brief La funcion calcula el descuento del precio de las Aerolineas Argentinas previamente ingresado.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @return Retorna el precio con el descuento aplicado.
float CalcularDescuentoDebito(float primerVuelo);

/// @fn float CalcularDescuentoDebitoDos(float)
/// @brief La funcion calcula el descuento del precio de las Aerolineas Latam previamente ingresado.
///
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @return Retorna el precio con el descuento aplicado.
float CalcularDescuentoDebitoDos(float segundoVuelo);

/// @fn float CalcularInteresCredito(float)
/// @brief La funcion calcula el interes del precio de las Aerolineas Argentinas previamente ingresado.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @return Retorna el precio con el interes aplicado.
float CalcularInteresCredito(float primerVuelo);

/// @fn float CalcularInteresCreditoDos(float)
/// @brief La funcion calcula el interes del precio de las Aerolineas Latam previamente ingresado.
///
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @return Retorna el precio con el interes aplicado.
float CalcularInteresCreditoDos(float segundoVuelo);

/// @fn float CalcularBitcon(float)
/// @brief La funcion calcula el cambio de peso a bitcoin en Aerolineas Argentinas.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @return Retorna el precio en bitcoin.
float CalcularBitcon(float primerVuelo);

/// @fn float CalcularBitconDos(float)
/// @brief La funcion calcula el cambio de peso a bitcoin en Aerolineas Latam.
///
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @return Retorna el precio en bitcoin.
float CalcularBitconDos(float segundoVuelo);

/// @fn float CalcularPrecioUnitario(float, float)
/// @brief La funcion calcula el precio por kilometro de Aerolineas Argentinas.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @param kilometraje Este parametro es el kilometraje que va a recorrer el usuario.
/// @return Retorna el precio que sale el kilometro.
float CalcularPrecioUnitario(float primerVuelo, float kilometraje);

/// @fn float CalcularPrecioUnitarioDos(float, float)
/// @brief La funcion calcula el precio por kilometro de Aerolineas Latam.
///
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @param kilometraje Este parametro es el kilometraje que va a recorrer el usuario.
/// @return Retorna el precio que sale el kilometro.
float CalcularPrecioUnitarioDos(float segundoVuelo, float kilometraje);

/// @fn float CalcularDifTotal(float, float, float)
/// @brief La funcion calcula la diferencia de plata entre Aerolineas Argentinas y Aerolineas Latam.
///
/// @param primerVuelo Este parametro es el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @param segundoVuelo Este parametro es el precio de Aerolineas Latam que va a pagar el usuario.
/// @param difPrecio Este parametro es la diferencia de precio entre las Aerolineas.
/// @return Retorna la diferencia de precio entre Aerolineas.
float CalcularDifTotal(float primerVuelo, float segundoVuelo, float difPrecio);

/// @fn void MenuFinal(int, float, float, float, float, float, float, float, float, float, float, float)
/// @brief La funcion muestra los calculos previamente realizados.
///
/// @param kilometraje Este parametro muestra el kilometraje que va a recorrer el usuario.
/// @param primerVuelo Este parametro muestra el precio de Aerolineas Argentinas que va a pagar el usuario.
/// @param precioDebitoUno Este parametro muestra el precio de Aerolineas Argentinas con el descuento aplicado que va a pagar el usuario.
/// @param precioCreditoUno Este parametro muestra el precio de Aerolineas Argentinas con el interes aplicado que va a pagar el usuario.
/// @param precioBitcoinUno Este parametro muestra el precio de Aerolineas Argentinas convertido a bitcoin.
/// @param precioUnitUno Este parametro muestra el precio por kilometro de Aerolineas Argentinas.
/// @param segundoVuelo Este parametro muestra el precio de Aerolineas Latam que va a pagar el usuario.
/// @param precioDebitoDos Este parametro muestra el precio de Aerolineas Latam con el descuento aplicado que va a pagar el usuario.
/// @param precioCreditoDos Este parametro muestra el precio de Aerolineas Latam con el interes aplicado que va a pagar el usuario.
/// @param precioBitcoinDos Este parametro muestra el precio de Aerolineas Latam convertido a bitcoin.
/// @param precioUnitDos Este parametro muestra el precio por kilometro de Aerolineas Latam.
/// @param difPrecio Este parametro muestra la diferencia de precio entre las 2 Aerolineas
void MenuFinal(int kilometraje, float primerVuelo, float precioDebitoUno, float precioCreditoUno, float precioBitcoinUno, float precioUnitUno, float segundoVuelo, float precioDebitoDos, float precioCreditoDos, float precioBitcoinDos, float precioUnitDos, float difPrecio);

/// @fn void RealizarCargaForzada(float, float, float, float, float, float, float, float, float)
/// @brief La funcion muestra los datos precargados por el programador y los calcula y muestra reciclando las funciones previamente hechas.
///
/// @param precioDebitoUno Este parametro muestra el precio de Aerolineas Argentinas con el descuento aplicado que va a pagar el usuario.
/// @param precioCreditoUno Este parametro muestra el precio de Aerolineas Argentinas con el interes aplicado que va a pagar el usuario.
/// @param precioBitcoinUno Este parametro muestra el precio de Aerolineas Argentinas convertido a bitcoin.
/// @param precioUnitUno Este parametro muestra el precio por kilometro de Aerolineas Argentinas.
/// @param precioDebitoDos Este parametro muestra el precio de Aerolineas Latam con el descuento aplicado que va a pagar el usuario.
/// @param precioCreditoDos Este parametro muestra el precio de Aerolineas Latam con el interes aplicado que va a pagar el usuario.
/// @param precioBitcoinDos Este parametro muestra el precio de Aerolineas Latam convertido a bitcoin.
/// @param precioUnitDos Este parametro muestra el precio por kilometro de Aerolineas Latam.
/// @param difPrecio Este parametro muestra la diferencia de precio entre las 2 Aerolineas.
void RealizarCargaForzada(float precioDebitoUno, float precioCreditoUno, float precioBitcoinUno, float precioUnitUno, float precioDebitoDos, float precioCreditoDos, float precioBitcoinDos, float precioUnitDos, float difPrecio);

#endif /* FUNCIONES_H_ */
