#include "BibliotecaArrayPassenger.h"

static int idIncremental = 1000;
static int obtenerID();
static int obtenerID()
{
	return idIncremental++;
}

int PedirEntero(char mensaje[])
{
	int retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("\nERROR\n");
		printf(mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}

int ValidarNumero(char numero[])
{
	int retorno=1;
	int len;
	if(numero!=NULL)
	{
		len=strlen(numero);
		for(int i=0;i<len;i++)
		{
			if(!isdigit(numero[i]))
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

float PedirPrecio(char mensaje[],char mensajeError[])
{
	float numero1;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
			printf("\nERROR\n");
			printf(mensaje);
			scanf("%s",numero);
	}
	numero1=atof(numero);
	return numero1;
}

int BuscaLibre(Passenger pasajeros[],int tam)
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

void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}

int CargarPasajero(Passenger pasajeros[], int tam,typePassenger tiposPasajeros[], int tamTipos,statusFlight estadosVuelo[], int tamEstados)
{
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int idtypePassenger;
	int index;
	int id;
	int idStatusFlight;

	id = obtenerID();
	PedirTexto(name,"nombre");
	firstToUpper(name);
	PedirTexto(lastName,"apellido");
	firstToUpper(lastName);
	price=PedirPrecio( "Ingrese el precio: \n", "ERROR Ingrese un precio valido: \n");
	printf("Ingrese el flyCode: \n");
	fflush(stdin);
	gets(flyCode);
	idtypePassenger=PedirtypePassenger(tiposPasajeros,tamTipos);
	idStatusFlight=PedirStatusFlight(estadosVuelo,tamEstados);

	index = addPassenger(pasajeros,tam,id,name,lastName,price,flyCode, idtypePassenger,idStatusFlight);
	return index;
}

int ListarPasajero(Passenger pasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int indexTipo;
	int indexEstado;
	int c;
	c=0;
	if(pasajeros.isEmpty==LLENO)
	{
		indexTipo=MostrarTypePassenger(pasajeros, tiposPasajeros, tamTipos);
		indexEstado=MostrarStatusFlight(pasajeros, estadosVuelo, tamEstados);
		printf("%2d %-8s %-8s %-4.2f %-8s %-3s %8s \n", pasajeros.id,
											  pasajeros.name,
											  pasajeros.lastName,
											  pasajeros.price,
											  pasajeros.flyCode,
											  tiposPasajeros[indexTipo].descrpcion,
											  estadosVuelo[indexEstado].descrpcion);
		c=1;
	}
	return c;
}

int ListarPasajeros(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int rtn;
	int c;
	int contador;
	contador=0;
	rtn=-1;
	printf("ID   Nombre  Apellido  Precio  flycode typePassenger 	statusFlight	\n");
	for(int i=0;i<tamPasajeros;i++)
	{
		c = ListarPasajero(pasajeros[i], tiposPasajeros, tamTipos, estadosVuelo, tamEstados);
		if(c==1)
		{
			contador++;
		}
	}
	if(contador>0)
	{
		rtn=0;
	}
	return rtn;
}

int MostrarTypePassenger(Passenger pasajeros, typePassenger tiposPasajeros[],int tamTipos)
{
	int index;
	for(int i=0;i<tamTipos;i++)
	{
		if(pasajeros.idTypePassenger==tiposPasajeros[i].id)
		{
			index=i;
			break;
		}
	}
	return index;
}

int MostrarStatusFlight(Passenger pasajeros, statusFlight estadosVuelo[],int tamEstados)
{
	int index;
	for(int i=0;i<tamEstados;i++)
	{
		if(pasajeros.idstatusFlight==estadosVuelo[i].id)
		{
			index=i;
			break;
		}
	}
	return index;
}

void HardcodeoPasajeros(Passenger pasajeros[],typePassenger tiposPasajeros[],statusFlight estadosVuelo[])
{
    int id[6]={1001,1002,1003,1004,1005,1006};
    char nombre[6][40]={"Juan", "Franco", "Marta","Julieta","German","Maria"};
    char apellido[6][40]={"Lopez", "Gomez", "Luna","Gomez","Lopez","Luna"};
    float precio[6]={8000,7500,5000,4000,8500,6500};
    char flyCode[6][40]={"a002", "a003", "b001","b002","b003","b004"};
    int typePassenger[6]={1,1,3,2,1,1};
    int statusFlight[6]={10,11,12,10,10,12};

    for (int i=0;i<6;i++)
    {
    	pasajeros[i].id=id[i];
        strcpy(pasajeros[i].name,nombre[i]);
        strcpy(pasajeros[i].lastName,apellido[i]);
        pasajeros[i].price = precio[i];
        strcpy(pasajeros[i].flyCode,flyCode[i]);
        pasajeros[i].idTypePassenger=typePassenger[i];
        pasajeros[i].idstatusFlight=statusFlight[i];
        pasajeros[i].isEmpty=LLENO;
    }
}

int PedirtypePassenger(typePassenger tiposPasajeros[], int tamTipos)
{
	int tipo;
	ListarTiposPasajeros(tiposPasajeros, tamTipos);
	tipo=PedirEntero("Ingrese el typePassenger:\n");
	 while(tipo<1|| tipo>tamTipos)
	 {
		ListarTiposPasajeros(tiposPasajeros, tamTipos);
		tipo=PedirEntero("Error, Ingrese el typePassenger:\n");
	 }
	return tipo;
}

int PedirStatusFlight(statusFlight estadosVuelo[], int tamEstados)
{
	int tipo;
	ListarEstadosVuelo(estadosVuelo, tamEstados);
	tipo=PedirEntero("Ingrese el statusFlight:\n");
	 while(tipo<10||tipo>12)
	 {
		 ListarEstadosVuelo(estadosVuelo, tamEstados);
		tipo=PedirEntero("Error, Ingrese el statusFlight:\n");
	 }
	return tipo;
}

void ModificarPasajero(Passenger pasajeros[], int posicion,typePassenger tiposPasajeros[], int tamTipos)
{
	int opcion;
	char seguir;
	int subOpcion;
	char seguir2;
	seguir = 's';
	seguir2 = 's';
	while(seguir=='s')
	{
		opcion=PedirEntero("Se ha encontrado el pasajero, desea modificarlo?\n1. SI\n2. NO\n");
	switch(opcion)
	{
		case 1:
			while(seguir2=='s')
			{
				subOpcion=PedirEntero("SELECCIONE QUE DESEA MODIFICAR:\n1.Nombre\n2.Apellido\n3.Precio\n4.typePassenger\n5.flyCode\n6.no modificar/salir\n");
				switch(subOpcion)
				{
					case 1:
						PedirTexto(pasajeros[posicion].name,"nuevo nombre");
						firstToUpper(pasajeros[posicion].name);
						printf("Modificacion exitosa\n");
					break;

					case 2:
						PedirTexto(pasajeros[posicion].lastName,"nuevo apellido");
						firstToUpper(pasajeros[posicion].lastName);
						printf("Modificacion exitosa\n");
					break;

					case 3:
						pasajeros[posicion].price=PedirPrecio( "Ingrese el nuevo precio: \n", "ERROR Ingrese un precio valido: \n");
						printf("Modificacion exitosa\n");
					break;

					case 4:
						pasajeros[posicion].idTypePassenger=PedirtypePassenger(tiposPasajeros,tamTipos);
						printf("Modificacion exitosa\n");
					break;

					case 5:
						printf("Ingrese el nuevo flyCode: \n");
						fflush(stdin);
						gets(pasajeros[posicion].flyCode);
						printf("Modificacion exitosa\n");
					break;
					case 6:
						printf("saliendo..\n");
						seguir2 = 'n';
						seguir = 'n';
					break;
					default:
						printf("opcion incorrecta!\n");
					break;
				}
			}
		break;
		case 2:
				printf("saliendo..\n");
				seguir = 'n';
		break;
		default:
				printf("opcion incorrecta!\n");
		break;
	}
  }
}

void PedirTexto(char cadena[],char mensaje[])
{
	printf("Ingrese %s: \n",mensaje);
	fflush(stdin);
	gets(cadena);
	ValidarCadena(cadena,mensaje);
}

void ValidarCadena(char cadena[],char mensaje[])
{
	int bandera;
	bandera=validarTexto(cadena);
	while(bandera==0)
	{
		printf("Ingrese un %s valido: \n",mensaje);
		fflush(stdin);
		gets(cadena);
		bandera=validarTexto(cadena);
	}
}

int validarTexto(char cadena[])
{
	int validacion;
	validacion=-1;
	for(int i=0;i<strlen(cadena);i++)
	{
		if(isdigit(cadena[i]))
		{
			validacion=0;
		}
	}
	return validacion;
}

void ListarTiposPasajeros(typePassenger tiposPasajeros[], int tamTipos)
{
	if(tiposPasajeros!=NULL&&tamTipos>0)
	{
		printf("\nID	TIPO PASAJERO\n");
		for(int i=0;i<tamTipos;i++)
		{
			printf("%d	%s\n",tiposPasajeros[i].id,
							tiposPasajeros[i].descrpcion);
		}
	}

}

void ListarEstadosVuelo(statusFlight estadosVuelo[], int tamEstados)
{
	if(estadosVuelo!=NULL&&tamEstados>0)
	{
		printf("\nID	ESTADO VUELO\n");
		for(int i=0;i<tamEstados;i++)
		{
			printf("%d	%s\n",estadosVuelo[i].id,
							estadosVuelo[i].descrpcion);
		}
	}
}

int ListarVuelosActivos(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int rtn;
	int c;
	c=0;
	rtn=-1;
	OrdenarFlyCode( pasajeros, tamPasajeros);
	for(int i=0;i<tamPasajeros;i++)
	{
		if(pasajeros[i].idstatusFlight==10)
		{
			ListarPasajero(pasajeros[i], tiposPasajeros, tamTipos, estadosVuelo, tamEstados);
			c++;
		}
	}
	if(c>0)
	{
		rtn=0;
	}
	return rtn;
}

void OrdenarFlyCode(Passenger pasajeros[],int tamPasajeros)
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

void MostarOpcionesListado(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int opcion;
	char seguir;
	int index;
	float precioTotal;
	float promedio;
	int pasajerosProm;
	seguir = 's';
	while(seguir=='s')
	{
		printf("1. Listado Pasajeros:  \n");
		printf("2. Listado Tipos De Pasajero:  \n");
		printf("3. Listado Estados De Vuelo:  \n");
		printf("4. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero: \n");
		printf("5. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio: \n");
		printf("6. Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVO: \n");
		printf("7. Imprime el array de pasajeros de forma encolumnada: \n");
		printf("8. Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente \n");
		printf("9. Salir \n");
		opcion=PedirEntero("Elija una opcion: \n");
		switch(opcion)
		{
			case 1:
				if((index=ListarPasajeros(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
				{
					printf("Listado Exitoso");
				}
				else
				{
					printf("No hay pasajeros para mostrar..");
				}
			break;

			case 2:
				ListarTiposPasajeros(tiposPasajeros, tamTipos);
			break;

			case 3:
				ListarEstadosVuelo(estadosVuelo, tamEstados);
			break;

			case 4:
				ListarFlyCode(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados);
			break;

			case 5:
				if((precioTotal=SumarPreciosPasajes(pasajeros, tamPasajeros))>0)
				{
					printf("El precio total de los pasajes es de: %.2f\n",precioTotal);
				}
				if((promedio=CalcularPromedio(pasajeros, tamPasajeros))!=-1)
				{
					printf("El promedio de los precios de los pasajes es de: %.2f\n",promedio);
					pasajerosProm=ContarPasajerosPromedio(pasajeros, tamPasajeros, promedio);
					printf("La cantidad de pasajeros que superan el precio promedio es de: %d",pasajerosProm);
				}
			break;

			case 6:
				if((index=ListarVuelosActivos(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
				{
					printf("Listado Exitoso");
				}
				else
				{
					printf("No hay pasajeros para mostrar..");
				}
			break;
			case 7:
				if((index=printPassenger(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
				{
					printf("Listado Exitoso");
				}
				else
				{
					printf("No hay pasajeros para mostrar..");
				}
			break;

			case 8:
				ListarFlyCodeEstado(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados);
			break;

			case 9:
				// sale del menu
				printf("Saliendo..\n");
				seguir = 'n';
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
		printf("\n\n");
	}
}

void ListarFlyCode(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int opcion;
	char seguir;
	int index;
	seguir = 's';
	while(seguir=='s')
	{
		//CRITERIO -> -1 = MENOR A MAYOR
		//CRITERIO ->  1 = MAYOR A MENOR
		printf("1. Ordenar y mostrar de MENOR A MAYOR:  \n");
		printf("2. Ordenar y mostrar de MAYOR A MENOR:  \n");
		printf("3. Salir.\n");
		opcion=PedirEntero("Elija una opcion: \n");
		switch(opcion)
		{
			case 1:
				if((index = sortPassengers( pasajeros,  tamPasajeros, -1, tiposPasajeros, tamTipos))!=-1)
				{
					if((index=ListarPasajeros(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
					{
						printf("Listado Exitoso");
					}
					else
					{
						printf("No hay pasajeros para mostrar..");
					}
					seguir = 'n';
				}
			break;

			case 2:
				if((index = sortPassengers( pasajeros,  tamPasajeros, 1, tiposPasajeros, tamTipos))!=-1)
				{
					if((index=ListarPasajeros(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
					{
						printf("Listado Exitoso");
					}
					else
					{
						printf("No hay pasajeros para mostrar..");
					}
					seguir = 'n';
				}
			break;

			case 3:
				// sale del menu
				printf("Saliendo..\n");
				seguir = 'n';
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
		printf("\n\n");
	}
}

int sortPassengersEstado(Passenger pasajeros[], int tam, int criterio,statusFlight estadosVuelo[],int tamEstados)
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
							indexTipoi=MostrarStatusFlight(pasajeros[i], estadosVuelo, tamEstados);
							indexTipoj=MostrarStatusFlight(pasajeros[j], estadosVuelo, tamEstados);
							if(strcmp(pasajeros[i].flyCode,pasajeros[j].flyCode)>0)
							{
								aux = pasajeros[i];
								pasajeros[i] = pasajeros[j];
								pasajeros[j] = aux;
								if(strcmp(estadosVuelo[indexTipoi].descrpcion,estadosVuelo[indexTipoj].descrpcion)>0)
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
							indexTipoi=MostrarStatusFlight(pasajeros[i], estadosVuelo, tamEstados);
							indexTipoj=MostrarStatusFlight(pasajeros[j], estadosVuelo, tamEstados);
							if(strcmp(pasajeros[i].flyCode,pasajeros[j].flyCode)<0)
							{
								aux = pasajeros[i];
								pasajeros[i] = pasajeros[j];
								pasajeros[j] = aux;
								if(strcmp(estadosVuelo[indexTipoi].descrpcion,estadosVuelo[indexTipoj].descrpcion)<0)
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

void ListarFlyCodeEstado(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados)
{
	int opcion;
	char seguir;
	int index;
	seguir = 's';
	while(seguir=='s')
	{
		//CRITERIO -> -1 = MENOR A MAYOR
		//CRITERIO ->  1 = MAYOR A MENOR
		printf("1. Ordenar y mostrar de MENOR A MAYOR:  \n");
		printf("2. Ordenar y mostrar de MAYOR A MENOR:  \n");
		printf("3. Salir.\n");
		opcion=PedirEntero("Elija una opcion: \n");
		switch(opcion)
		{
			case 1:
				if((index = sortPassengersEstado( pasajeros,  tamPasajeros, -1, estadosVuelo, tamEstados))!=-1)
				{
					if((index=ListarPasajeros(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
					{
						printf("Listado Exitoso");
					}
					else
					{
						printf("No hay pasajeros para mostrar..");
					}
					seguir = 'n';
				}
			break;

			case 2:
				if((index = sortPassengersEstado( pasajeros,  tamPasajeros, 1, estadosVuelo, tamEstados))!=-1)
				{
					if((index=ListarPasajeros(pasajeros, tamPasajeros, tiposPasajeros, tamTipos, estadosVuelo, tamEstados))!=-1)
					{
						printf("Listado Exitoso");
					}
					else
					{
						printf("No hay pasajeros para mostrar..");
					}
					seguir = 'n';
				}
			break;

			case 3:
				// sale del menu
				printf("Saliendo..\n");
				seguir = 'n';
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
		printf("\n\n");
	}
}

float SumarPreciosPasajes(Passenger pasajeros[],int tamPasajeros)
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

int CalcularTotalPasajeros(Passenger pasajeros[],int tamPasajeros)
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

float CalcularPromedio(Passenger pasajeros[],int tamPasajeros)
{
	float precioTotal;
	int pasajerosTotal;
	float promedio;
	precioTotal=SumarPreciosPasajes(pasajeros, tamPasajeros);
	pasajerosTotal=CalcularTotalPasajeros(pasajeros, tamPasajeros);
	promedio=-1;

	if(pasajerosTotal>0&&precioTotal>0)
	{
		promedio = precioTotal / pasajerosTotal;
	}

	return promedio;
}

int ContarPasajerosPromedio(Passenger pasajeros[],int tamPasajeros,float promedio)
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
