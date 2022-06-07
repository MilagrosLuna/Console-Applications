#include "Passenger.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"

void EstablecerEstadoVuelo(char* estadoVuelo);
void EstablecerCodigoVuelo(char* codigoVuelo);
int ListPassenger(LinkedList* pArrayListPassenger,int index);
int FindID(LinkedList* listaPasajeros, int id);
int Remove(LinkedList* listaEmpleados,int id);
int saveTxt(FILE* archivo , LinkedList* pArrayListPassenger);
int MostarOpcionesListado(LinkedList* pArrayListPassenger);
int compareById(void* pasajero1, void* pasajero2);
int compareByNombre(void* pasajero1, void* pasajero2);
int ObtenerCriterio();
int compareByEstado(void* pasajero1, void* pasajero2);
int compareByCodigo(void* pasajero1, void* pasajero2);
int compareByPrecio(void* pasajero1, void* pasajero2);
int compareByTipoPasajero(void* pasajero1, void* pasajero2);
int compareByApellido(void* pasajero1, void* pasajero2);

int GuardarId(char* path, char* id);
int CalcularProximoId(char* id);
int LeerUltimoId(char* path, char* id);

void MensajeEspera();
