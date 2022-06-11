#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pasajero=NULL;
	int retorno;
	char id[1000];
	char nombre[1000];
	char apellido[1000];
	char precio[1000];
	char tipoPasajero[1000];
	char codigoVuelo[1000];
	char estado[1000];
	int r;
	retorno=0;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		printf("Abrio el archivo\n");
		do
		{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estado);

			if(r==7)
			{
				pasajero=Passenger_newParametros(id,nombre,tipoPasajero,apellido,codigoVuelo,precio,estado);
				if(pasajero!=NULL)
				{
					ll_add(pArrayListPassenger,pasajero);
					retorno=1;
				}
				else
				{
					Passenger_delete(pasajero);
				}
			}
			else
			{
				printf("error EN R\n");
			}

		}while(!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pasajero;
	int retorno;
	retorno=0;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		printf("Abrio el archivo\n");
		do
		{
			pasajero = Passenger_new();
			if(pasajero!=NULL)
			{
				if(fread(pasajero,sizeof(Passenger),1,pFile))
				{
					ll_add(pArrayListPassenger,pasajero);
					retorno=1;
				}
				else
				{
					Passenger_delete(pasajero);
				}
			}
		}while(!feof(pFile));
	}

	return retorno;
}
