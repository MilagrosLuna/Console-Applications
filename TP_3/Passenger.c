#include "Passenger.h"
#include "validaciones.h"

Passenger* Passenger_new()
{
	Passenger* pasajero;
	pasajero = (Passenger*) malloc(sizeof(Passenger));
	if(pasajero!=NULL)
	{
		pasajero->id=0;
		strcpy(pasajero->nombre," ");
		strcpy(pasajero->apellido," ");
		pasajero->precio=0.0;
		pasajero->tipoPasajero=0;
		strcpy(pasajero->codigoVuelo," ");
		strcpy(pasajero->estadoVuelo," ");
	}
	return pasajero;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* codigoVueloStr,char* precioStr, char* estadoVuelo)
{
	Passenger* pasajero;
	int id;
	int tipoPasajero;
	float precio;

	if(		idStr!=NULL &&
			nombreStr!=NULL &&
			tipoPasajeroStr!=NULL &&
			apellidoStr !=NULL &&
			codigoVueloStr != NULL &&
			precioStr != NULL 	&&
			estadoVuelo!= NULL)
	{
		pasajero=Passenger_new();
		id=atoi(idStr);
		precio=atof(precioStr);
		tipoPasajero=DefinirTipo(tipoPasajeroStr);
		if(pasajero!=NULL)
		{
			if(		Passenger_setId(pasajero, id) ==0 ||
					Passenger_setNombre(pasajero, nombreStr) ==0 ||
					Passenger_setTipoPasajero(pasajero, tipoPasajero) ==0 ||
					Passenger_setApellido(pasajero, apellidoStr)==0 ||
					Passenger_setCodigoVuelo(pasajero, codigoVueloStr)==0||
					Passenger_setPrecio(pasajero, precio)==0 ||
					Passenger_setEstadoVuelo(pasajero, estadoVuelo)==0)
			{
				printf("lo borro");
				Passenger_delete(pasajero);
				pasajero=NULL;
			}
		}
	}

	return pasajero;
}

void Passenger_delete(Passenger* pasajero)
{
	if(pasajero!=NULL)
	{
		free(pasajero);
		pasajero=NULL;
	}
}



int Passenger_setId(Passenger* this,int id)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		retorno=1;
		this->id = id;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;
	retorno=0;
	if(this!=NULL && id!=NULL)
	{
		retorno=1;
		*id=this->id;
	}
	return retorno;
}




int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;
	retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		retorno=1;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}




int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno=0;
	if(this!=NULL && apellido!=NULL)
	{
		retorno=1;
		strcpy(this->apellido,apellido);
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;
	retorno=0;
	if(this!=NULL && apellido!=NULL)
	{
		retorno=1;
		strcpy(apellido,this->apellido);
	}
	return retorno;
}




int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		retorno=1;
		strcpy(this->codigoVuelo,codigoVuelo);
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;
	retorno=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		retorno=1;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return retorno;
}




int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		retorno=1;
		this->tipoPasajero=tipoPasajero;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;
	retorno=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		retorno=1;
		*tipoPasajero=this->tipoPasajero;
	}
	return retorno;
}




int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		retorno=1;
		this->precio=precio;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;
	retorno=0;
	if(this!=NULL && precio!=NULL)
	{
		retorno=1;
		*precio=this->precio;
	}
	return retorno;
}




int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno=0;
	if(this!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno=1;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;
	retorno=0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno=1;
	}
	return retorno;
}





/// \brief Define el tipo de pasajero como entero en base a la descripcion
/// \param tipoPasajeroStr
/// \return
int DefinirTipo(char* tipoPasajeroStr)
{
	int tipoPasajero;
	tipoPasajero=-1;
	if(strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = FirstClass; //(1)
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = ExecutiveClass; //(2)
		}
		else
		{
			if(strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = EconomyClass; //(3)
			}
		}
	}
	return tipoPasajero;
}
/// \brief Define el tipo de pasajero en cadena en base al entero guardado
/// \param tipoPasajero
/// \param tipoPasajerostr
/// \return
int DefinirTipoTxt(int tipoPasajero, char* tipoPasajerostr)
{
	int rtn;
	rtn=0;
	if(tipoPasajero==FirstClass)// 1
	{
		strcpy(tipoPasajerostr,"FirstClass");
		rtn=1;
	}
	else
	{
		if(tipoPasajero==ExecutiveClass)// 2
		{
			strcpy(tipoPasajerostr,"ExecutiveClass");
			rtn=1;
		}
		else
		{
			if(tipoPasajero==EconomyClass)// 3
			{
				strcpy(tipoPasajerostr,"EconomyClass");
				rtn=1;
			}
		}
	}
	return rtn;
}

/// \brief Menu y validaciones para modificar un pasajero
/// \param pasajero
/// \return Si se pudo modificar o si se cancelo la modificacion
int ModificarPasajero(Passenger* pasajero)
{
	int rtn;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];
	char estadoVuelo[20];
	int opcion;
	int bandera;
	char seguir;
	int subOpcion;
	char seguir2;
	rtn=-1;
	bandera=0;
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

				    printf("-> SELECCIONE QUE DESEA MODIFICAR <-\n");
					printf("\t 1. Nombre  \n");
					printf("\t 2. Apellido  \n");
					printf("\t 3. Precio  \n");
					printf("\t 4. Tipo de pasajero \n");
					printf("\t 5. Codigo de vuelo \n");
					printf("\t 6. Estado de vuelo \n");
					printf("\t 7. No modificar/salir \n");
					subOpcion=PedirEntero("Ingrese la opcion: \n");

					switch(subOpcion)
					{
						case 1:
							PedirTexto(nombre,"nombre");
							firstToUpper(nombre);
							if(Passenger_setNombre(pasajero, nombre)==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 2:
							PedirTexto(apellido,"apellido");
							firstToUpper(apellido);
							if(Passenger_setApellido(pasajero, apellido)==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 3:
							precio=PedirPrecio( "Ingrese el precio: \n", "ERROR Ingrese un precio valido: \n");
							if(Passenger_setPrecio(pasajero, precio)==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 4:
							printf("1. FirstClass \n2. ExecutiveClass \n3. EconomyClass \n");
							tipoPasajero=PedirYValidarNumero("Ingrese el tipo de pasajero:\n", "Error, ingrese un tipo valido:\n", 1, 3);
							if(Passenger_setTipoPasajero(pasajero, tipoPasajero) ==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 5:
							EstablecerCodigoVuelo(codigoVuelo);
							if(Passenger_setCodigoVuelo(pasajero, codigoVuelo)==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 6:
							EstablecerEstadoVuelo(estadoVuelo);
							if(Passenger_setEstadoVuelo(pasajero,estadoVuelo)==1)
							{
								rtn=1;
								bandera=1;
							}
						break;

						case 7:
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
					if(bandera==0)
					{
						rtn=0;
					}
					else
					{
						rtn=1;
					}

			break;
			default:
					printf("opcion incorrecta!\n");
			break;
		}
  }
	return rtn;
}


