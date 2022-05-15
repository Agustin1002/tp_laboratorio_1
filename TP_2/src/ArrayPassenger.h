/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: Agustin
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "Funciones.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	int isEmpty;
	char flyCode[10];
	int typePassenger;
	int statusFly;
}ePassenger;

/// @fn int InitPassengers(ePassenger*, int)
/// @brief this function init the passenger in 0.
///
/// @param list receive the passenger array
/// @param len receive the length of iterations.
/// @return returns -1 if the array is ocupied or 0 if is empty.
int InitPassengers(ePassenger* list, int len);

/// @fn int addPassenger(ePassenger*, int, char[], char[], char[], int, float, int, int)
/// @brief this function adds the passengers in the structure passengers
///
/// @param list receive the passenger array.
/// @param id receive the autoincrementing id.
/// @param name receive the name auxiliar.
/// @param lastName receive the lastName auxiliar.
/// @param flycode receive the flycode auxiliar.
/// @param typePassenger receive the typePassenger auxiliar.
/// @param price receive the price auxiliar.
/// @param statusFly receive the statusFly auxiliar.
/// @param len receive the length of iterations.
/// @return returs 0 if the employee was charged or -1 if the employee can not be charged.
int addPassenger(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len);

/// @fn int findPassengerById(ePassenger*, int, int)
/// @brief this function search an passenger for his id.
///
/// @param list receive the passenger array.
/// @param len receive the length of iterations.
/// @param id receive the id for the passenger.
/// @return return the index if is 0 or -1 if have an error.
int findPassengerById(ePassenger* list, int len,int id);

/// @fn int removePassenger(ePassenger*, int, int)
/// @brief this function remove an passenger from the array.
///
/// @param list receive the passenger array.
/// @param len receive the length of iterations.
/// @param id receive the id for the passenger.
/// @return return 0 if the passenger was removed or -1 if this can not be.
int removePassenger(ePassenger* list, int len, int id);

/// @fn int sortPassengers(ePassenger*, int, int)
/// @brief this function sorts the array of passengers by last name and type of passenger in ascending order or falling.
///
/// @param list receive the passenger array.
/// @param len receive the length of iterations.
/// @param order receive the form of order.
/// @return returns 0 if all be right or -1 if this have an error.
int sortPassengers(ePassenger* list, int len, int order);

/// @fn int printPassenger(ePassenger*, int)
/// @brief this functions show multiple passengers.
///
/// @param list receive the passenger array.
/// @param length receive the length of iterations.
/// @return returns -1 if this have not errors or 0 if this have.
int printPassenger(ePassenger* list, int length);

/// @fn int sortPassengersByCode(ePassenger*, int, int)
/// @brief this function sorts the array of passengers by flight code and flight status in ascending order or falling.
///
/// @param list receive the passenger array.
/// @param len receive the length of iterations.
/// @param order receive the form of order.
/// @return returns 0 if all be right or -1 if this have an error.
int sortPassengersByCode(ePassenger* list, int len, int order);

/// @fn int searchEmpty(ePassenger*, int, int)
/// @brief this function search a free space to add an passenger.
///
/// @param list receive the employees array.
/// @param len receive the length of iterations.
/// @param condicion receive if the state is BUSY or EMPTY
/// @return returns 0 if this have not errors or -1 if this have.
int searchEmpty(ePassenger* list, int len, int condicion);

/// @fn int modifyPassenger(ePassenger*, int, char[], char[], char[], int, float, int, int)
/// @brief this function modifies the selected parameter of the passenger.
///
/// @param list receive the passenger array.
/// @param id receive the autoincrementing id.
/// @param name receive the name auxiliar.
/// @param lastName receive the lastName auxiliar.
/// @param flycode receive the flycode auxiliar.
/// @param typePassenger receive the typePassenger auxiliar.
/// @param price receive the price auxiliar.
/// @param statusFly receive the statusFly auxiliar.
/// @param len receive the length of iterations.
/// @return returns 0 if the passenger was modified or -1 if this can not be.
int modifyPassenger(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len);

/// @fn void Menu(ePassenger*, int, char[], char[], char[], int, float, int, int)
/// @brief this function allows access to the program options.
///
/// @param list receive the passenger array.
/// @param id receive the autoincrementing id.
/// @param name receive the name auxiliar.
/// @param lastName receive the lastName auxiliar.
/// @param flycode receive the flycode auxiliar.
/// @param typePassenger receive the typePassenger auxiliar.
/// @param price receive the price auxiliar.
/// @param statusFly receive the statusFly auxiliar.
/// @param len receive the length of iterations.
void Menu(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len);

/// @fn void productoMostrarUno(ePassenger)
/// @brief this functions shows only one passenger.
///
/// @param list receive the passenger array.
void productoMostrarUno(ePassenger list);

/// @fn void PasajeroHardCodear(ePassenger*, int, int*)
/// @brief this function shows the forced load of data.
///
/// @param list	receive the passenger array.
/// @param len receive the length of iterations.
/// @param id receive the autoincrementing id.
void PasajeroHardCodear(ePassenger* list, int len, int* id);

/// @fn int GenerarPromedio(ePassenger*, int)
/// @brief this function shows the sum and average of the prices, and the number of passengers that exceed the average price.
///
/// @param list	receive the passenger array.
/// @param len receive the length of iterations.
/// @return returns -1 if the function has no error.
int GenerarPromedio(ePassenger* list, int len);

/// @fn void Ordenar(ePassenger*, int)
/// @brief This function shows the modification menu.
///
/// @param list	receive the passenger array.
/// @param len receive the length of iterations.
void Ordenar(ePassenger* list, int len);
#endif /* ARRAYPASSENGER_H_ */
