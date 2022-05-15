/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: Agustin
 */
#include "Funciones.h"
#include "ArrayPassenger.h"
#define EMPTY 0
#define BUSY 1
#define PASSENGER 2000

int InitPassengers(ePassenger* list, int len)
{
	int i;
	int retorno = 0;

	for(i = 0; i < PASSENGER; i++)
	{
		list[i].isEmpty = EMPTY;
	}
	return retorno;
}

void Menu(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len)
{
	int menu;
	int idAux;
	id = 1000;

		do
		{
			pedirEntero(&menu, "\n--------------------MENU-------------------\n"
	                           "1- ALTA pasajero\n"
	                           "2- MODIFICAR pasajero\n"
	                           "3- BAJA pasajero\n"
	                           "4- INFORMAR listas\n"
							   "5- ALTA FORZADA pasajeros\n"
	                           "6- Finalizar Programa\n"
	                           "--------------------------------------------\n"
	                           "Ingrese la opcion que desea: ",
							   "--------------------------------------------\n"
							   "1- ALTA pasajero\n"
	                           "2- MODIFICAR pasajero\n"
	                           "3- BAJA pasajero\n"
	                           "4- INFORMAR listas(empleados y salarios)\n"
							   "5- ALTA FORZADA pasajeros\n"
							   "6- Finalizar Programa\n"
							   "--------------------------------------------\n"
							   "ERROR. Reingrese una opcion valida: ", 1, 6);

			switch(menu)
			{
				case 1:
					if(searchEmpty(list, PASSENGER, EMPTY) != -1)
					{
						pedirCadena(name, "Ingrese el nombre del pasajero: ", "ERROR- Ingrese el nombre del pasajero: ", 51);
						pedirCadena(lastName, "Ingrese el apellido del pasajero: ", "ERROR- Ingrese el apellido del pasajero: ", 51);
						pedirString(flycode, "Ingrese el codigo de vuelo: ", "ERROR- Ingrese el codigo de vuelo valido: ", 51);
						pedirEntero(&typePassenger, "Ingrese el tipo de pasajero (PRIMERA CLASE = 1, CLASE TURISTA = 2, CLASE ECONOMICA = 3): ", "ERROR- Ingrese un tipo de pasajero valido (PRIMERA CLASE = 1, CLASE TURISTA = 2, CLASE ECONOMICA = 3): ", 1, 3);
						pedirFlotante(&price, "Ingrese el precio (entre 1 y 1000000): ", "ERROR- Ingrese un precio valido (entre 1 y 1000000): ", 1, 1000000);
						pedirEntero(&statusFly, "Ingrese el estado de vuelo (EN TIEMPO = 1, CANCELADO = 2, REPROGRAMADO = 3): ", "ERROR- Ingrese el estado de vuelo valido, (EN TIEMPO = 1, CANCELADO = 2, REPROGRAMADO = 3): ", 1, 3);
						if(!addPassenger(list, id, name, lastName, flycode, typePassenger, price, statusFly, PASSENGER))
						{
							printf("\n-----Se cargo exitosamente el pasajero-----\n\n");
							id++;
						}
					}
					else
					{
						printf("\n-----No se ha ingresado ninguna ID-----\n");
					}
					system("pause");
				break;
				case 2:
					if(searchEmpty(list, PASSENGER, BUSY) != -1)
					{
						printPassenger(list, PASSENGER);
						pedirEntero(&idAux, "Ingrese el ID del pasajero a modificar (1000-2999): ", "Reingrese el ID del producto a modificar (1000-2199): ", 1000, 2999);
						modifyPassenger(list, idAux, name, lastName, flycode, typePassenger, price, statusFly, PASSENGER);
					}
					else
					{
						printf("\n-----No se ha ingresado ninguna ID-----\n");
					}
					break;
				case 3:
					if(searchEmpty(list, PASSENGER, BUSY) != -1)
					{
						printPassenger(list, PASSENGER);
						pedirEntero(&idAux, "Ingrese el ID del pasajero a borrar (1000-2999): ", "Reingrese el ID del pasajero a borrar (1000-2999): ", 1000, 2999);
						removePassenger(list, PASSENGER, idAux);
					}
					else
					{
						printf("\n-----No se ha ingresado ninguna ID-----\n");
					}
					break;
				case 4:
					if(searchEmpty(list, PASSENGER, BUSY) != -1)
					{
						printPassenger(list, PASSENGER);
						Ordenar(list, PASSENGER);
					}
					else
					{
						printf("\n-----No se ha ingresado ninguna ID-----\n");
					}
					break;
				case 5:
					PasajeroHardCodear(list, PASSENGER, &id);
					printf("\n-----Carga forzada realizada-----\n");
					break;
				case 6:
					printf("\n-----Finalizo-----");
					break;
			}

		}while(menu != 6);
}

int addPassenger(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len)
{
	int retorno;
	int index;

	retorno = -1;

	index = searchEmpty(list, PASSENGER, EMPTY);

	if(index != -1)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		strcpy(list[index].flyCode, flycode);
		list[index].typePassenger = typePassenger;
		list[index].price = price;
		list[index].statusFly = statusFly;
		list[index].isEmpty = BUSY;

		retorno = 0;
	}

	return retorno;
}

int findPassengerById(ePassenger* list, int len,int id)
{
	int i;
	int index = -1;

	for(i=0; i<PASSENGER; i++)
	{
		if(list[i].isEmpty == BUSY && list[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int removePassenger(ePassenger* list, int len, int id)
{
	int retorno = -1;
	int index;

	index = findPassengerById(list, PASSENGER, id);

	if(index != -1)
	{
		if(productoVerificarConfirmacion("\nIngrese 's' para confirmar la baja del pasajero: ") == 0)
		{
			list[index].isEmpty = EMPTY;
			printf("\nPasajero %d dado de baja correctamente!\n\n", list[index].id);
		}
		else
		{
			printf("\nSe cancelo la baja del pasajero.\n\n");
		}
		retorno = 0;
	}
	else
	{
		printf("\nERROR- Pasajero no encontrado...\n\n");
		printPassenger(list, PASSENGER);
	}

	return retorno;
}

int modifyPassenger(ePassenger* list, int id, char name[], char lastName[], char flycode[], int typePassenger, float price, int statusFly, int len)
{
	int retorno = -1;
	int index;
	int opcion;

	index = findPassengerById(list, PASSENGER, id);

	if(index != -1)
	{
		printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
		productoMostrarUno(list[index]);
		printf("\n");

		do
		{
			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. MODIFICAR nombre\n"
								 "2. MODIFICAR apellido\n"
								 "3. MODIFICAR codigo de vuelo\n"
								 "4. MODIFICAR tipo de pasajero\n"
								 "5. MODIFICAR precio\n"
								 "6. MODIFICAR estado de vuelo\n"
								 "7. ATRAS\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. MODIFICAR nombre\n"
								 "2. MODIFICAR apellido\n"
								 "3. MODIFICAR codigo de vuelo\n"
								 "4. MODIFICAR tipo de pasajero\n"
								 "5. MODIFICAR precio\n"
								 "6. MODIFICAR estado de vuelo\n"
								 "7. ATRAS\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 7);

			switch(opcion)
			{
				case 1:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirCadena(list[index].name, "Ingrese el nombre del pasajero: ", "ERROR- Ingrese el nombre del pasajero: ", 51);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 2:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirCadena(list[index].lastName, "Ingrese el apellido del pasajero: ", "ERROR- Ingrese el apellido del pasajero: ", 51);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 3:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirString(list[index].flyCode, "Ingrese el codigo de vuelo: ", "ERROR- Ingrese el codigo de vuelo valido: ", 51);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 4:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirEntero(&list[index].typePassenger, "Ingrese el tipo de pasajero (PRIMERA CLASE = 1, CLASE TURISTA = 2, CLASE ECONOMICA = 3): ", "ERROR- Ingrese un tipo de pasajero valido (PRIMERA CLASE = 1, CLASE TURISTA = 2, CLASE ECONOMICA = 3): ", 1, 3);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 5:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirFlotante(&list[index].price, "Ingrese el precio (entre 1 y 1000000): ", "ERROR- Ingrese un precio valido (entre 1 y 1000000): ", 1, 1000000);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 6:
					printf("\nPasajero a modificar:\n\n%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
					productoMostrarUno(list[index]);
					pedirEntero(&list[index].statusFly, "Ingrese el estado de vuelo (EN TIEMPO = 1, CANCELADO = 2, REPROGRAMADO = 3)", "ERROR- Ingrese el estado de vuelo valido, (EN TIEMPO = 1, CANCELADO = 2, REPROGRAMADO = 3)", 1, 3);
					printf("\nPasajero luego de la modificación:\n\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio");
					productoMostrarUno(list[index]);

					if(!productoVerificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
					{
						printf("\nPasajero %d modificado correctamente!\n\n", list[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nSe cancelo la modificacion del pasajero.\n\n");
					}

					system("pause");
					break;
				case 7:
					printf("\nCerrando modificacion... Volviendo al menu\n\n");
					system("\npause");
					break;
			}
		}while(opcion != 7);
	}
	else
	{
		printf("\nERROR- Pasajero no encontrado...\n\n");
	}

	return retorno;
}

int sortPassengers(ePassenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	ePassenger auxList;

	if(order == 1)
	{
		for(i=0; i<PASSENGER-1; i++)
		{
			for(j=i+1; j<PASSENGER; j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName) > 0)
				{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName) == 0)
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							auxList = list[i];
							list[i] = list[j];
							list[j] = auxList;
						}
					}
				}
			}
		}

		printf("\nOrdenando...\n");
		system("pause\n");
		printf("\nLista pasajeros ordenados de forma ascendente por apellido y tipo de pasajero\n\n");
		printPassenger(list, PASSENGER);

	}
	else
	{
		if(order == 2)
		{
			for(i=0; i<PASSENGER-1; i++)
			{
				for(j=i+1; j<PASSENGER; j++)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0)
					{
							auxList = list[i];
							list[i] = list[j];
							list[j] = auxList;
					}
					else
					{
						if(strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].typePassenger < list[j].typePassenger)
							{
								auxList = list[i];
								list[i] = list[j];
								list[j] = auxList;
							}
						}
					}
				}
			}

			printf("\nOrdenando...\n");
			system("pause\n");
			printf("\nLista pasajeros ordenados de forma descendente por apellido y tipo de pasajero\n\n");
			printPassenger(list, PASSENGER);
		}
	}

	retorno = 0;

	return retorno;
}


int printPassenger(ePassenger* list, int length)
{
	int i;
	int retorno = 0;

	printf("\nMostrando lista de pasajeros...\n\n"
			"%-10s %-20s %-20s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Codigo De Vuelo", "Tipo De Pasajero", "Precio", "Estado De Vuelo");
	for(i=0; i<PASSENGER; i++)
	{
		if(list[i].isEmpty == BUSY)
		{
			productoMostrarUno(list[i]);
			retorno = -1;
		}
	}
	printf("\n");

	return retorno;
}

int sortPassengersByCode(ePassenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	ePassenger auxList;

	if(order == 3)
	{
		for(i=0; i<PASSENGER-1; i++)
		{
			for(j=i+1; j<PASSENGER; j++)
			{
				if(strcmp(list[i].flyCode, list[j].flyCode) > 0)
				{
						auxList = list[i];
						list[i] = list[j];
						list[j] = auxList;
				}
				else
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
					{
						if(list[i].statusFly > list[j].statusFly)
						{
							auxList = list[i];
							list[i] = list[j];
							list[j] = auxList;
						}
					}
				}
			}
		}

		printf("\nOrdenando...\n");
		system("pause\n");
		printf("\nLista pasajeros ordenados de forma ascendente por codigo de vuelo y estado de vuelo\n\n");
		printPassenger(list, PASSENGER);

	}
	else
	{
		if(order == 4)
		{
			for(i=0; i<PASSENGER-1; i++)
			{
				for(j=i+1; j<PASSENGER; j++)
				{
					if(strcmp(list[i].flyCode, list[j].flyCode) < 0)
					{
							auxList = list[i];
							list[i] = list[j];
							list[j] = auxList;
					}
					else
					{
						if(strcmp(list[i].flyCode, list[j].flyCode) == 0)
						{
							if(list[i].statusFly < list[j].statusFly)
							{
								auxList = list[i];
								list[i] = list[j];
								list[j] = auxList;
							}
						}
					}
				}
			}

			printf("\nOrdenando...\n");
			system("pause\n");
			printf("\nLista pasajeros ordenados de forma descendente por codigo de vuelo y estado de vuelo\n\n");
			printPassenger(list, PASSENGER);
		}
	}

	retorno = 0;

	return retorno;
}

int searchEmpty(ePassenger* list, int len, int condicion)
{
	int i;
	int index = -1;

	for(i = 0; i < PASSENGER; i++)
	{
		if(list[i].isEmpty == condicion)
		{
			index = i;
			break;
		}
	}

	return index;
}

void productoMostrarUno(ePassenger list)
{
	printf("%-10d %-20s %-20s %-20s %-20d %-20.2f %-20d\n", list.id, list.name, list.lastName, list.flyCode, list.typePassenger, list.price, list.statusFly);
}

void PasajeroHardCodear(ePassenger* list, int len, int* id)
{
	int i;
	int auxId = *id;
	char auxname[][51] = {"Agustin", "Juan", "Carlos", "Pedro", "Ricardo"};
	char lastname[][51] = {"Perez", "Lopez", "Rivadavia", "Vera", "Darin"};
	char fly[][10] = {"ads21", "lps20", "prf56", "fkj8", "lpd5"};
	int class[] = {1, 2, 3, 2, 3};
	float precio[] = {10000, 15000, 20000, 100000, 500000};
	int status[] = {1, 2, 1, 3, 2};

	for(i=0; i<5; i++)
	{
		list[i].id = auxId;
		strcpy(list[i].name, auxname[i]);
		strcpy(list[i].lastName, lastname[i]);
		strcpy(list[i].flyCode, fly[i]);
		list[i].typePassenger = class[i];
		list[i].price = precio[i];
		list[i].statusFly = status[i];
		list[i].isEmpty = BUSY;

		auxId++;
	}

	*id = auxId;

}

int GenerarPromedio(ePassenger* list, int len)
{
	int retorno = -1;
	int i;
	float acumuladorPrecio = 0;
	int contador = 0;
	float promedio;
	int masQueElPromedio = 0;

	for(i = 0; i < PASSENGER; i++)
	{
		if(list[i].isEmpty == BUSY)
		{
			acumuladorPrecio += list[i].price;
			contador++;
		}
	}

	promedio = acumuladorPrecio / (float)contador;
	for(i = 0; i < PASSENGER; i++)
	{
		if(list[i].price > promedio && list[i].isEmpty == BUSY)
		{
			masQueElPromedio++;
		}
	}

	printf("\nLa suma de todos los precios es: %.2f\n", acumuladorPrecio);
	printf("El promedio de los precios es: %.2f\n", promedio);
	printf("La cantidad de pasajeros que superan el precio promedio son: %d\n", masQueElPromedio);

	return retorno;
}

void Ordenar(ePassenger* list, int len)
{
	int menuOrden;
	do
	{
		pedirEntero(&menuOrden, 	   "\n--------------------ORDENAR-------------------\n"
									   "1- Forma Ascendente (apellido y tipo de pasajero)\n"
									   "2- Forma Descendente (apellido y tipo de pasajero)\n"
									   "3- Forma Ascendente (codigo de vuelo y estado de vuelo)\n"
									   "4- Forma Descendente (codigo de vuelo y estado de vuelo)\n"
									   "5- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n"
									   "6- Volver Al Menu\n"
									   "--------------------------------------------\n"
									   "Ingrese la opción que desea: ",
									   "--------------------------------------------\n"
									   "1- Forma Ascendente (apellido y tipo de pasajero)\n"
									   "2- Forma Descendente (apellido y tipo de pasajero)\n"
									   "3- Forma Ascendente (codigo de vuelo y estado de vuelo)\n"
									   "4- Forma Descendente (codigo de vuelo y estado de vuelo)\n"
									   "5- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n"
									   "6- Volver Al Menu\n"
										"--------------------------------------------\n"
									   "ERROR. Reingrese una opción valida: ", 1, 6);

		switch(menuOrden)
		{
			case 1:
				sortPassengers(list, PASSENGER, 1);
				break;
			case 2:
				sortPassengers(list, PASSENGER, 2);
				break;
			case 3:
				sortPassengersByCode(list, PASSENGER, 3);
				break;
			case 4:
				sortPassengersByCode(list, PASSENGER, 4);
				break;
			case 5:
				GenerarPromedio(list, PASSENGER);
				break;
			case 6:
				printf("\nCerrando ordenamiento... Volviendo al menu\n\n");
				system("pause");
				break;
		}

	}while(menuOrden != 6);

}
