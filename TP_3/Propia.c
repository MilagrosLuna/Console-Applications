
#include "Propia.h"
/// \brief  Muestra las opciones de estado de vuelo y valida el ingreso
/// \param estadoVuelo
void EstablecerEstadoVuelo(char* estadoVuelo)
{
	int opcion;
	char seguir;
	seguir = 's';
	while(seguir=='s')
	{
	    printf("-> SELECCIONE UN ESTADO DE VUELO <-\n");
		printf("\t 1. Demorado  \n");
		printf("\t 2. Aterrizado  \n");
		printf("\t 3. En Vuelo  \n");
		printf("\t 4. En Horario \n");
		printf("\t 5. Otro: \n");
		opcion=PedirEntero("Ingrese la opcion: \n");
		switch(opcion)
		{
			case 1:
			    strcpy(estadoVuelo,"Demorado");
			    seguir = 'n';
			break;

			case 2:
                strcpy(estadoVuelo,"Aterrizado");
                seguir = 'n';
			break;

			case 3:
                strcpy(estadoVuelo,"EnVuelo");
                seguir = 'n';
			break;

			case 4:
                strcpy(estadoVuelo,"EnHorario");
                seguir = 'n';
			break;

			case 5:
                PedirTexto(estadoVuelo,"el estado de vuelo");
            	firstToUpper(estadoVuelo);
            	seguir = 'n';
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
		printf("\n");
	}
}
/// \brief Muestra las opciones de codigo de vuelo y valida el ingreso
/// \param codigoVuelo
void EstablecerCodigoVuelo(char* codigoVuelo)
{
	int opcion;
	char seguir;
	seguir = 's';
	while(seguir=='s')
	{
	    printf("-> SELECCIONE UN CODIGO DE VUELO <-\n");
		printf("\t 1. BB32  \n");
		printf("\t 2. AA78  \n");
		printf("\t 3. FG89  \n");
		printf("\t 4. MM26 \n");
		printf("\t 5. Otro: \n");
		opcion=PedirEntero("Ingrese la opcion: \n");
		switch(opcion)
		{
			case 1:
			    strcpy(codigoVuelo,"BB32");
			    seguir = 'n';
			break;

			case 2:
                strcpy(codigoVuelo,"AA78");
                seguir = 'n';
			break;

			case 3:
                strcpy(codigoVuelo,"FG89");
                seguir = 'n';
			break;

			case 4:
                strcpy(codigoVuelo,"MM26");
                seguir = 'n';
			break;

			case 5:
                printf("Ingrese el codigo de vuelo: \n");
				fflush(stdin);
				gets(codigoVuelo);
            	seguir = 'n';
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
		printf("\n");
	}
}

/// \brief Lista un pasajero de la lista en la posicion recibida
/// \param pArrayListPassenger
/// \param index
/// \return
int ListPassenger(LinkedList* pArrayListPassenger,int index)
{
	int rtn;
	Passenger* auxPasajeros;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[4];
	char estadoVueloAux[20];
	char tipoPasajerostr[50];
	rtn=0;
	auxPasajeros = (Passenger*) ll_get(pArrayListPassenger, index);
	if(Passenger_getTipoPasajero(auxPasajeros, &tipoPasajeroAux) == 1 &&
	   DefinirTipoTxt(tipoPasajeroAux, tipoPasajerostr)==1)
	{
		if(Passenger_getId(auxPasajeros, &idAux) ==1 &&
				Passenger_getNombre(auxPasajeros, nombreAux) ==1 &&
				Passenger_getApellido(auxPasajeros, apellidoAux)==1 &&
				Passenger_getCodigoVuelo(auxPasajeros, codigoVueloAux)==1 &&
				Passenger_getPrecio(auxPasajeros, &precioAux)==1 &&
				Passenger_getEstadoVuelo(auxPasajeros, estadoVueloAux)==1)
		{
			printf("|%-5d | %-18s | %-18s | %-18s | %-8s | %-15s | %-9.2f| \n",idAux,nombreAux,apellidoAux,tipoPasajerostr,codigoVueloAux,estadoVueloAux,precioAux);
			rtn=1;
		}
	}
    return rtn;
}

/// \brief Escribe en el archivo los pasajeros para guardarlos
/// \param archivo
/// \param pArrayListPassenger
/// \return
int saveTxt(FILE* archivo , LinkedList* pArrayListPassenger)
{
	int rtn;
	int len;
	Passenger* aux = NULL;
	int idAux;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[4];
	char estadoVueloAux[20];
	char tipoPasajerostr[50];
	rtn=0;
	len = ll_len(pArrayListPassenger);
	if(len>0 && archivo!=NULL && pArrayListPassenger!=NULL)
	{
		for(int i=0; i<len ;i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger,i);
			if(aux!=NULL)
			{
				if(Passenger_getTipoPasajero(aux, &tipoPasajeroAux) == 1 &&
				   DefinirTipoTxt(tipoPasajeroAux, tipoPasajerostr)==1)
				{
					if(Passenger_getId(aux, &idAux) ==1 &&
							Passenger_getNombre(aux, nombreAux) ==1 &&
							Passenger_getApellido(aux, apellidoAux)==1 &&
							Passenger_getCodigoVuelo(aux, codigoVueloAux)==1 &&
							Passenger_getPrecio(aux, &precioAux)==1 &&
							Passenger_getEstadoVuelo(aux, estadoVueloAux)==1)
					{
						fprintf(archivo,"%d,%s,%s,%f,%s,%s,%s\n",idAux,nombreAux,apellidoAux,precioAux,tipoPasajerostr,codigoVueloAux,estadoVueloAux);
						rtn=1;
					}
				}
			}
		}
	}
	return rtn;
}


/// \brief Muestra las opciones de criterio y devuelve la opcion ingresada y validada
/// \return
int ObtenerCriterio()
{
	int criterio;
	printf("\n\t>-CRITERIO DE ORDEN-<\t\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");
	criterio=PedirYValidarNumero("Elija un criterio de ordenamiento: \n","Error criterio no correcto",0,1);
	return criterio;
}


/// \brief Lee el ultimo id que se registro y devuelve ese dato por punteros
/// \param path
/// \param id
/// \return
int LeerUltimoId(char* path, char* id)
{
    int retorno;
    FILE* pFile;

	retorno = 0;
    pFile = fopen(path, "r");

    if (pFile != NULL && id != NULL)
    {
        fscanf(pFile, "%[^\n]\n", id);
        retorno = 1;
    }

	fclose(pFile);
    return retorno;
}
/// recibe el ultimo id usado y calcula el siguiente
int CalcularProximoId(char* id)
{
    int idAAumentar;
    int retorno;

    retorno = 0;

    if (id != NULL)
    {
        idAAumentar = atoi(id);
        idAAumentar++;
        itoa(idAAumentar, id, 10);
        retorno = 1;
    }

    return retorno;
}
/// \brief Recibe el id que se cargo y lo guarda en el archivo
/// \param path
/// \param id
/// \return
int GuardarId(char* path, char* id)
{
    FILE* pFile;
    int retorno;

    retorno = 0;
    pFile = fopen(path, "w");

    if (pFile != NULL)
    {
        fprintf(pFile, "%s\n", id);
        retorno = 1;
    }

	fclose(pFile);

	return retorno;
}


/// \brief Busca en la lista de pasajeros el id que recibio y devuelve la posicion
/// \param listaPasajeros
/// \param id
/// \return
int FindID(LinkedList* listaPasajeros, int id)
{
	int i;
	int len;
	int index;
	int idAux;
	Passenger* auxiliar;
	index= -1;

	if(listaPasajeros!=NULL)
	{
		len = ll_len(listaPasajeros);
		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Passenger*)ll_get(listaPasajeros,i);
				if(Passenger_getId(auxiliar, &idAux)==1)
				{
					if(idAux==id)
					{
						index=i;
						break;
					}
				}
			}
		}
	}

	return index;
}

/// \brief Elimia al pasajero de la lista
/// \param lista
/// \param id
/// \return
int Remove(LinkedList* lista,int id)
{
	int opcion;
	int isOk;
	int index;
	char seguir;
	seguir='s';
	index = -1;
	isOk = -1;

	if(lista!=NULL)
	{
		index = FindID(lista,id);

		if(index!=-1)
		{
			ListPassenger(lista, index);
			while(seguir=='s')
			{
				opcion=PedirEntero("Se ha encontrado el pasajero, desea eliminarlo?\n1. SI\n2. NO\n");
				switch(opcion)
				{
					case 1:
						ll_remove(lista,index);
						printf("Baja realizada con exito");
						isOk = 1;
						seguir = 'n';
					break;

					case 2:
						printf("Baja cancelada\n");
						printf("saliendo..\n");
						seguir = 'n';
					break;

					default:
							printf("opcion incorrecta!\n");
					break;
				}
			}
		}
		else
		{
			printf("No se pudo encontrar el ID\n");
		}
	}

	return isOk;
}



/// \brief Menu de opciones de ordenamiento de la lista
/// \param pArrayListPassenger
/// \return
int MostarOpcionesListado(LinkedList* pArrayListPassenger)
{
	int opcion;
	int criterio;
	char seguir;
	int rtn;
	rtn=0;
	LinkedList* clon;
	if(pArrayListPassenger!=NULL)
	{
		rtn=1;
		clon = ll_clone(pArrayListPassenger);
		seguir = 's';
		while(seguir=='s')
		{
			printf("1. Listado Pasajeros:  \n");
			printf("2. Listado ordenado por Tipos De Pasajero:  \n");
			printf("3. Listado ordenado por Estados De Vuelo:  \n");
			printf("4. Listado ordenado por Codigo de Vuelo: \n");
			printf("5. Listado ordenado por Nombre: \n");
			printf("6. Listado ordenado por Precio: \n");
			printf("7. Listado ordenado por Id: \n");
			printf("8. Listado ordenado por Apellido: \n");
			printf("9. Salir \n");
			opcion=PedirEntero("Elija una opcion: \n");
			switch(opcion)
			{
				case 1:
					clon = ll_clone(pArrayListPassenger);
					if(controller_ListPassenger(clon)==1)
					{
						printf("\nListado Exitoso\n");
					}
					else
					{
						printf("\nNo hay pasajeros para mostrar\n");
					}
				break;

				case 2:
					criterio=ObtenerCriterio();
					MensajeEspera();
					ll_sort(clon,compareByTipoPasajero,criterio);
					if(criterio)
					{
						if(controller_ListPassenger(clon)==1)
						{
							ll_deleteLinkedList(clon);
							printf("\nListado Exitoso\n");
						}
						printf("Se ha ordenado la lista por tipo de pasajero en orden A-Z");
					}
					else
					{
						if(!criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por tipo de pasajero en orden Z-A");
						}
					}
				break;

				case 3:
					criterio=ObtenerCriterio();
					MensajeEspera();
					ll_sort(clon,compareByEstado,criterio);
					if(criterio)
					{
						if(controller_ListPassenger(clon)==1)
						{
							ll_deleteLinkedList(clon);
							printf("\nListado Exitoso\n");
						}
						printf("Se ha ordenado la lista por estado de vuelo en orden A-Z");
					}
					else
					{
						if(!criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por estado de vuelo en orden Z-A");
						}
					}
				break;

				case 4:
					criterio=ObtenerCriterio();
					MensajeEspera();
					ll_sort(clon,compareByCodigo,criterio);
					if(criterio)
					{
						if(controller_ListPassenger(clon)==1)
						{
							ll_deleteLinkedList(clon);
							printf("\nListado Exitoso\n");
						}
						printf("Se ha ordenado la lista por codigo de vuelo en orden A-Z");
					}
					else
					{
						if(!criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por codigo de vuelo en orden Z-A");
						}
					}
				break;

				case 5:
					criterio=ObtenerCriterio();
					MensajeEspera();
					ll_sort(clon,compareByNombre,criterio);
					if(criterio)
					{
						if(controller_ListPassenger(clon)==1)
						{
							ll_deleteLinkedList(clon);
							printf("\nListado Exitoso\n");
						}
						printf("Se ha ordenado la lista por nombre de A-Z");
					}
					else
					{
						if(!criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por nombre de Z-A");
						}
					}
				break;

				case 6:
					criterio=ObtenerCriterio();
					MensajeEspera();
					if(!ll_sort(clon,compareByPrecio,criterio))
					{
						if(criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por precio ascendente");
						}
						else
						{
							if(!criterio)
							{
								if(controller_ListPassenger(clon)==1)
								{
									ll_deleteLinkedList(clon);
									printf("\nListado Exitoso\n");
								}
								printf("Se ha ordenado la lista por precio descendente");
							}
						}
					}
				break;

				case 7:
					criterio=ObtenerCriterio();
					MensajeEspera();
					if(!ll_sort(clon,compareById,criterio))
					{
						if(criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por id ascendente");
						}
						else
						{
							if(!criterio)
							{
								if(controller_ListPassenger(clon)==1)
								{
									ll_deleteLinkedList(clon);
									printf("\nListado Exitoso\n");
								}
								printf("Se ha ordenado la lista por id descendente");
							}
						}
					}
				break;

				case 8:
					criterio=ObtenerCriterio();
					MensajeEspera();
					ll_sort(clon,compareByApellido,criterio);
					if(criterio)
					{
						if(controller_ListPassenger(clon)==1)
						{
							ll_deleteLinkedList(clon);
							printf("\nListado Exitoso\n");
						}
						printf("Se ha ordenado la lista por apellido de A-Z");
					}
					else
					{
						if(!criterio)
						{
							if(controller_ListPassenger(clon)==1)
							{
								ll_deleteLinkedList(clon);
								printf("\nListado Exitoso\n");
							}
							printf("Se ha ordenado la lista por apellido de Z-A");
						}
					}
				break;

				case 9:
					// sale del menu
					printf("Saliendo..");
					seguir = 'n';
				break;

				default:
					printf("Opcion incorrecta\n");
				break;
			}
			printf("\n\n");
		}
	}
	return rtn;
}

void MensajeEspera()
{
	printf("\n-------------------------------------------\n");
	printf("---Aguarde su lista esta siendo ordenada---\n");
	printf("-------------------------------------------\n\n");
}

/// \brief Compara por id al pasajero 1 con el 2 y devulve si si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareById(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	int id1;
	int id2;
	aux1 = NULL;
	aux2 = NULL;
	rtn=0;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getId(aux1,&id1)==1) &&
			(Passenger_getId(aux2,&id2)==1))
		{
			if(id1 > id2)//mayores
			{
				rtn = 1;
			}
			else
			{
				if(id1 < id2)//menores
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}
/// \brief Compara por nombre a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByNombre(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	char nombre1[100];
	char nombre2[100];
	aux1 = NULL;
	aux2 = NULL;
	rtn = -1;


	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getNombre(aux1,nombre1)==1) &&
			(Passenger_getNombre(aux2,nombre2)==1))
		{
			rtn = strcmp(nombre1,nombre2);
		}
	}

	return rtn;
}
/// \brief Compara por codigo de vuelo a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByCodigo(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	char codigo1[100];
	char codigo2[100];
	aux1 = NULL;
	aux2 = NULL;
	rtn = -1;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getCodigoVuelo(aux1,codigo1)==1) &&
			(Passenger_getCodigoVuelo(aux2,codigo2)==1))
		{
			rtn = strcmp(codigo1,codigo2);
		}
	}

	return rtn;
}
/// \brief Compara por estado de vuelo a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByEstado(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	char estado1[100];
	char estado2[100];
	aux1 = NULL;
	aux2 = NULL;
	rtn = -1;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getEstadoVuelo(aux1,estado1)==1) &&
			(Passenger_getEstadoVuelo(aux2,estado2)==1))
		{
			rtn = strcmp(estado1,estado2);
		}
	}

	return rtn;
}
/// \brief Compara por tipo de pasajero a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByTipoPasajero(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	int tipo1;
	int tipo2;
	char tipoStr1[40];
	char tipoStr2[40];
	aux1 = NULL;
	aux2 = NULL;
	rtn = -1;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	Passenger_getTipoPasajero(aux1, &tipo1) == 1 &&
			DefinirTipoTxt(tipo1, tipoStr1) ==1 &&
			Passenger_getTipoPasajero(aux2, &tipo2) == 1 &&
			DefinirTipoTxt(tipo2, tipoStr2) ==1)
		{
			rtn = strcmp(tipoStr1,tipoStr2);
		}
	}

	return rtn;
}
/// \brief Compara por precio a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByPrecio(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	float precio1;
	float precio2;
	aux1 = NULL;
	aux2 = NULL;
	rtn=0;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getPrecio(aux1,&precio1)==1) &&
			(Passenger_getPrecio(aux2,&precio2)==1))
		{
			if(precio1 > precio2)//mayores
			{
				rtn = 1;
			}
			else
			{
				if(precio1 < precio2)//menores
				{
					rtn = -1;
				}
			}
		}
	}

	return rtn;
}
/// \brief Compara por apellido a 2 pasajeros y devulve si es mayor o menor
/// \param pasajero1
/// \param pasajero2
/// \return
int compareByApellido(void* pasajero1, void* pasajero2)
{
	int rtn;
	Passenger* aux1;
	Passenger* aux2;
	char apellido1[100];
	char apellido2[100];
	aux1 = NULL;
	aux2 = NULL;
	rtn=0;

	if(pasajero1!=NULL && pasajero2!=NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;

		if(	(Passenger_getApellido(aux1,apellido1)==1) &&
			(Passenger_getApellido(aux2,apellido2)==1))
		{
			rtn = strcmp(apellido1,apellido2);
		}
	}
	return rtn;
}









