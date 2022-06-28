
#include "BibliotecaArrayPassenger.h"
#include "Validaciones.h"
#define TAM_pasajeros 2000
#define TAM_tipos 3
#define TAM_estados 3
typedef struct
{
	int id;
	char descrpcion[51];
}typePassenger;
typedef struct
{
	int id;
	char descrpcion[51];
}statusFlight;

/// \brief Pide los datos para la carga de un pasajero y los valida
/// \param pasajeros
/// \param tam
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return Retorna si fue posible cargarlo o no
int CargarPasajero(Passenger pasajeros[], int tam,typePassenger tiposPasajeros[], int tamTipos,statusFlight estadosVuelo[], int tamEstados,int* id);
/// \brief Busca la posicion para mostrar la descripcion en el listado
/// \param pasajeros
/// \param estadosVuelo
/// \param tamEstados
/// \return Devuelve la posicion o -1 si no lo encontro
int MostrarStatusFlight(Passenger pasajeros, statusFlight estadosVuelo[],int tamEstados);
/// \brief Busca la posicion para mostrar la descripcion en el listado
/// \param pasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \return Devuelve la posicion o -1 si no lo encontro
int MostrarTypePassenger(Passenger pasajeros, typePassenger tiposPasajeros[],int tamTipos);
/// \brief ordena a los pasajeros en base al apellido y tipo de pasajero de manera ascendente o descendente.
/// \param pasajeros
/// \param tam
/// \param criterio
/// \param tiposPasajeros
/// \param tamTipos
/// \return Devuelve si fue posible ordenarlos o no
int sortPassengers(Passenger pasajeros[], int tam, int criterio,typePassenger tiposPasajeros[],int tamTipos);
/// \brief Lista los pasajeros de manera encolumnada
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return Devuelve si fue posible listarlos
int printPassenger(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief ordena a los pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente
/// \param pasajeros
/// \param tam
/// \param criterio
/// \param estadosVuelo
/// \param tamEstados
/// \return Devuelve si fue posible ordenarlos o no
int sortPassengersEstado(Passenger pasajeros[], int tam, int criterio,statusFlight estadosVuelo[],int tamEstados);
/// \brief Modifica un pasajero
/// \param pasajeros
/// \param posicion
/// \param tiposPasajeros
/// \param tamTipos
void ModificarPasajero(Passenger pasajeros[], int posicion,typePassenger tiposPasajeros[], int tamTipos);
/// \brief Pide y valida el tipo de pasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \return devuelve el tipo
int PedirtypePassenger(typePassenger tiposPasajeros[], int tamTipos);
/// \brief Pide y valida el estado de Vuelo
/// \param estadosVuelo
/// \param tamEstados
/// \return devuelve el estado
int PedirStatusFlight(statusFlight estadosVuelo[], int tamEstados);
/// \brief Lista los vuelos que tiene un esatdo activo
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return retorna si fue posible mostrar pasajeros o no
int ListarVuelosActivos(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief Muestra todas las opciones de listado para los pasajeros
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
void MostarOpcionesListado(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief Harcodea datos de pasajeros
/// \param pasajeros
/// \param tiposPasajeros
/// \param estadosVuelo
void HardcodeoPasajeros(Passenger pasajeros[],typePassenger tiposPasajeros[],statusFlight estadosVuelo[],int* id);
/// \brief Lista a los pasajeros por  apellido y tipo de pasajero de manera ascendente o descendente
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
void ListarFlyCode(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief Lista a los pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
void ListarFlyCodeEstado(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief Lista los tipos de pasajeros
/// \param tiposPasajeros
/// \param tamTipos
void ListarTiposPasajeros(typePassenger tiposPasajeros[], int tamTipos);
/// \brief Lista los estados de vuelo
/// \param estadosVuelo
/// \param tamEstados
void ListarEstadosVuelo(statusFlight estadosVuelo[], int tamEstados);
/// \brief Lista un pasajero
/// \param pasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return Devuelve si fue posible mostrarlo o no
int ListarPasajero(Passenger pasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);
/// \brief Lista a todos los pasajeros
/// \param pasajeros
/// \param tamPasajeros
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return Devuelve si fue posible mostrarlos o no
int ListarPasajeros(Passenger pasajeros[],int tamPasajeros,typePassenger tiposPasajeros[],int tamTipos,statusFlight estadosVuelo[],int tamEstados);



