#include "BibliotecaArrayPassenger.h"

int initPassengers(Passenger Passengers[],int tam)
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

int addPassenger(Passenger Passengers[], int tam, int id, char name[],char lastName[],float price, char flycode[],int idTypePassenger, int idStatusFlight )
{
	int index;
	int retorno;
	retorno=-1;
	if((index = BuscaLibre(Passengers,tam))!=-1)
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

int findPassengerById(Passenger pasajeros[], int tam,int id)
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

int removePassenger(Passenger pasajeros[], int size, int id)
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


//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int sortPassengers(Passenger pasajeros[], int tam, int criterio,typePassenger tiposPasajeros[],int tamTipos)
{
	int rtn;
	Passenger aux;
	int i;
	int j;
	int indexTipoi;
	int indexTipoj;
	rtn=-1;

	if(pasajeros!=NULL&&tam>0)
	{
		switch (criterio)
		{
			case -1:
				for (i = 0; i < tam - 1; i++)
				{
					for (j = i + 1; j < tam; j++)
					{
						if (pasajeros[i].isEmpty == LLENO && pasajeros[j].isEmpty == LLENO)
						{
							indexTipoi=MostrarTypePassenger(pasajeros[i], tiposPasajeros, tamTipos);
							indexTipoj=MostrarTypePassenger(pasajeros[j], tiposPasajeros, tamTipos);
							if(strcmp(pasajeros[i].lastName,pasajeros[j].lastName)>0)
							{
								aux = pasajeros[i];
								pasajeros[i] = pasajeros[j];
								pasajeros[j] = aux;
								if(strcmp(tiposPasajeros[indexTipoi].descrpcion,tiposPasajeros[indexTipoj].descrpcion)>0)
								{
									aux = pasajeros[i];
									pasajeros[i] = pasajeros[j];
									pasajeros[j] = aux;
								}
							}
						}
					}
				}
				rtn = 1;
			break;
// strcmp tips pasajeros
			case 1:
				for (i = 0; i < tam - 1; i++)
				{
					for (j = i + 1; j < tam; j++)
					{
						if (pasajeros[i].isEmpty == LLENO && pasajeros[j].isEmpty == LLENO)
						{
							indexTipoi=MostrarTypePassenger(pasajeros[i], tiposPasajeros, tamTipos);
							indexTipoj=MostrarTypePassenger(pasajeros[j], tiposPasajeros, tamTipos);
							if(strcmp(pasajeros[i].lastName,pasajeros[j].lastName)<0)
							{
								aux = pasajeros[i];
								pasajeros[i] = pasajeros[j];
								pasajeros[j] = aux;
								if(strcmp(tiposPasajeros[indexTipoi].descrpcion,tiposPasajeros[indexTipoj].descrpcion)<0)
								{
									aux = pasajeros[i];
									pasajeros[i] = pasajeros[j];
									pasajeros[j] = aux;
								}
							}
						}
					}
				}
				rtn = 0;
			break;

			default:
				//CRITERIO DE ORDENAMIENTO MAL INGRESADO
				rtn = -1;
			break;
		}
	}
	return rtn;
}

int printPassenger(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int indexTipo;
	int indexEstado;
	int rtn;
	int c;
	c=0;
	rtn=-1;
	printf("ID    Nombre 	 Apellido   Precio   flycode   	typePassenger 		statusFlight	\n");

	for(int i=0;i<tamPasajeros;i++)
	{
		if(pasajeros[i].isEmpty==LLENO)
		{
			indexTipo=MostrarTypePassenger(pasajeros[i], tiposPasajeros, tamTipos);
			indexEstado=MostrarStatusFlight(pasajeros[i], estadosVuelo, tamEstados);
			printf("%2d | %-8s | %-8s | %-4.2f | %-8s | %-3s 	| %8s \n", pasajeros[i].id,
												  pasajeros[i].name,
												  pasajeros[i].lastName,
												  pasajeros[i].price,
												  pasajeros[i].flyCode,
												  tiposPasajeros[indexTipo].descrpcion,
												  estadosVuelo[indexEstado].descrpcion);
			c++;
		}
	}
	if(c>0)
	{
		rtn=0;
	}
	return rtn;
}
