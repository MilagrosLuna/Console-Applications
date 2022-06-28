#include "BibliotecaArrayPassenger.h"


int Passenger_initPassengers(Passenger Passengers[],int tam)
{
	int rtn;
	rtn=-1;
	// inicializo el estado en 0 para q todos esten vacios y poder cambiar a medida que voy cargando/bajando datos
	if(Passengers!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			Passengers[i].isEmpty=VACIO;
		}
		rtn = 0;
	}
	return rtn;
}

int Passenger_addPassenger(Passenger Passengers[], int tam, int id, char name[],char lastName[],float price, char flycode[],int idTypePassenger, int idStatusFlight )
{
	int index;
	int retorno;
	retorno=-1;
	if((index = Passenger_BuscaLibre(Passengers,tam))!=-1)
	{
		Passengers[index].id=id;
		strcpy(Passengers[index].name,name);
		strcpy(Passengers[index].lastName,lastName);
		Passengers[index].price=price;
		strcpy(Passengers[index].flyCode,flycode);
		Passengers[index].idTypePassenger=idTypePassenger;
		Passengers[index].idstatusFlight=idStatusFlight;
		Passengers[index].isEmpty=LLENO;
		printf("ID: %d\n",id);
		retorno = 0;
	}
	return retorno;
}

int Passenger_BuscaLibre(Passenger pasajeros[],int tam)
{
	int index;
	index = -1;
	for(int i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty == VACIO)
		{
			index=i;
			break;
		}
	}
	return index;
}
int Passenger_findPassengerById(Passenger pasajeros[], int tam,int id)
{
	int index;
	index = -1;
	for(int i=0;i<tam;i++)
	{
		if(pasajeros[i].id == id&&pasajeros[i].isEmpty==LLENO)
		{
			index=i;
			break;
		}
	}
	return index;
}

int Passenger_removePassenger(Passenger pasajeros[], int size, int id)
{
	int retorno;
	retorno = -1;

	for(int i=0;i<size;i++)
	{
		if(pasajeros[i].id == id&&pasajeros[i].isEmpty==LLENO)
		{
			pasajeros[i].isEmpty=VACIO;
			retorno = 1;
			break;
		}
	}
	return retorno;
}

void Passenger_OrdenarFlyCode(Passenger pasajeros[],int tamPasajeros)
{
	Passenger aux;
	for(int i=0 ; i < tamPasajeros - 1 ; i++)
	{
		for (int j = i + 1 ; j < tamPasajeros ; j++)
		{
			if(strcmp(pasajeros[i].flyCode,pasajeros[j].flyCode)>0)
			{
				aux = pasajeros[i];
				pasajeros[i] = pasajeros[j];
				pasajeros[j] = aux;
			}
		}
	}
}

float Passenger_SumarPreciosPasajes(Passenger pasajeros[],int tamPasajeros)
{
	float total;
	total = 0;
	for(int i=0;i<tamPasajeros;i++)
	{
		if(pasajeros[i].isEmpty==LLENO)
		{
			total+=pasajeros[i].price;
		}
	}
	return total;
}

int Passenger_CalcularTotalPasajeros(Passenger pasajeros[],int tamPasajeros)
{
	int total;
	total = 0;
	for(int i=0;i<tamPasajeros;i++)
	{
		if(pasajeros[i].isEmpty==LLENO)
		{
			total++;
		}
	}
	return total;
}

float Passenger_CalcularPromedio(Passenger pasajeros[],int tamPasajeros)
{
	float precioTotal;
	int pasajerosTotal;
	float promedio;
	precioTotal=Passenger_SumarPreciosPasajes(pasajeros, tamPasajeros);
	pasajerosTotal=Passenger_CalcularTotalPasajeros(pasajeros, tamPasajeros);
	promedio=-1;

	if(pasajerosTotal>0&&precioTotal>0)
	{
		promedio = precioTotal / pasajerosTotal;
	}

	return promedio;
}

int Passenger_ContarPasajerosPromedio(Passenger pasajeros[],int tamPasajeros,float promedio)
{
	int rtn;
	rtn = 0;

	for(int i=0;i<tamPasajeros;i++)
	{
		if(pasajeros[i].isEmpty==LLENO && pasajeros[i].price>promedio)
		{
			rtn++;
		}
	}

	return rtn;
}




