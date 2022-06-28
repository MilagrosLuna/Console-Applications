#include "Validaciones.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int idTypePassenger;
	int idstatusFlight;
	int isEmpty;
}Passenger;

/// \brief Inicializa el estado de los pasajeros
/// \param Passengers
/// \param tam
/// \return Retorna si fue posible inicializarlos o no
int Passenger_initPassengers(Passenger Passengers[],int tam);
/// \brief Carga los datos del pasajero en una posicion disponible
/// \param Passengers
/// \param tam
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param flycode
/// \param idTypePassenger
/// \param idStatusFlight
/// \return Devuelve si fue posible realizar la carga o no
int Passenger_addPassenger(Passenger Passengers[], int tam, int id, char name[],char lastName[],float price, char flycode[],int idTypePassenger,int idStatusFlight);
/// \brief Remueve el pasajero si existe con ese id, de manera logica
/// \param pasajeros
/// \param size
/// \param id
/// \return devuelve si se pudo remover o no
int Passenger_removePassenger(Passenger pasajeros[], int size, int id);
/// \brief Busca el pasajero por el id recibido
/// \param pasajeros
/// \param tam
/// \param id
/// \return Devuele si encuentra la pocision en la q esta el pasajero o -1 si no lo encuentra
int Passenger_findPassengerById(Passenger pasajeros[], int tam,int id);
/// \brief Suma todos los pasajes
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve el total
float Passenger_SumarPreciosPasajes(Passenger pasajeros[],int tamPasajeros);
/// \brief  Calcula la cantidad de pasajeros
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve la cantidad de pasajeros
int Passenger_CalcularTotalPasajeros(Passenger pasajeros[],int tamPasajeros);
/// \brief Calcula El promedio de los pasajes
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve el promedio
float Passenger_CalcularPromedio(Passenger pasajeros[],int tamPasajeros);
/// \brief Cuenta la cantidad de pasajeros que superan el precio promedio
/// \param pasajeros
/// \param tamPasajeros
/// \param promedio
/// \return Devuelve la cantidad
int Passenger_ContarPasajerosPromedio(Passenger pasajeros[],int tamPasajeros,float promedio);
/// \brief ordena en base al codigo de vuelo
/// \param pasajeros
/// \param tamPasajeros
void Passenger_OrdenarFlyCode(Passenger pasajeros[],int tamPasajeros);
/// \brief Busca un espacio libre en el array de pasajeros para cargar uno nuevo
/// \param pasajeros
/// \param tam
/// \return devuelve en que posicion del array hay lugar o -1 si no hay
int Passenger_BuscaLibre(Passenger pasajeros[],int tam);
