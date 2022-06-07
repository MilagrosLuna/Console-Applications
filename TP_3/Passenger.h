
#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "validaciones.h"
#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char estadoVuelo[50];
	int tipoPasajero;
	char codigoVuelo[6];


}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* codigoVueloStr,char* precioStr, char* estadoVuelo);
void Passenger_delete(Passenger* pasajero);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


int DefinirTipoTxt(int tipoPasajero, char* tipoPasajerostr);
int DefinirTipo(char* tipoPasajeroStr);
int ModificarPasajero(Passenger* pasajero);

#endif /* PASSENGER_H_ */
