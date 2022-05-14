#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LLENO 1
#define VACIO 0
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
int initPassengers(Passenger Passengers[],int tam);
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
int addPassenger(Passenger Passengers[], int tam, int id, char name[],char lastName[],float price, char flycode[],int idTypePassenger,int idStatusFlight);
/// \brief Busca el pasajero por el id recibido
/// \param pasajeros
/// \param tam
/// \param id
/// \return Devuele si encuentra la pocision en la q esta el pasajero o -1 si no lo encuentra
int findPassengerById(Passenger pasajeros[], int tam,int id);
/// \brief Remueve el pasajero si existe con ese id, de manera logica
/// \param pasajeros
/// \param size
/// \param id
/// \return devuelve si se pudo remover o no
int removePassenger(Passenger pasajeros[], int size, int id);
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
/// \brief Suma todos los pasajes
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve el total
float SumarPreciosPasajes(Passenger pasajeros[],int tamPasajeros);
/// \brief  Calcula la cantidad de pasajeros
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve la cantidad de pasajeros
int CalcularTotalPasajeros(Passenger pasajeros[],int tamPasajeros);
/// \brief Calcula El promedio de los pasajes
/// \param pasajeros
/// \param tamPasajeros
/// \return Devuelve el promedio
float CalcularPromedio(Passenger pasajeros[],int tamPasajeros);
/// \brief Cuenta la cantidad de pasajeros que superan el precio promedio
/// \param pasajeros
/// \param tamPasajeros
/// \param promedio
/// \return Devuelve la cantidad
int ContarPasajerosPromedio(Passenger pasajeros[],int tamPasajeros,float promedio);
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
/// \brief Pide los datos para la carga de un pasajero y los valida
/// \param pasajeros
/// \param tam
/// \param tiposPasajeros
/// \param tamTipos
/// \param estadosVuelo
/// \param tamEstados
/// \return Retorna si fue posible cargarlo o no
int CargarPasajero(Passenger pasajeros[], int tam,typePassenger tiposPasajeros[], int tamTipos,statusFlight estadosVuelo[], int tamEstados);
/// \brief Busca un espacio libre en el array de pasajeros para cargar uno nuevo
/// \param pasajeros
/// \param tam
/// \return devuelve en que posicion del array hay lugar o -1 si no hay
int BuscaLibre(Passenger pasajeros[],int tam);
/// \brief ordena en base al codigo de vuelo
/// \param pasajeros
/// \param tamPasajeros
void OrdenarFlyCode(Passenger pasajeros[],int tamPasajeros);
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
/// \brief Convierte la primera letra en Mayuscula
/// \param cadena
void firstToUpper(char cadena[]);
/// \brief Pide un entero y llama a validar
/// \param mensaje
/// \return devuelve el entero
int PedirEntero(char mensaje[]);
/// \brief Valida que el nuemero no contenga caracteres invalidos
/// \param numero
/// \return Devuelve el numero
int ValidarNumero(char numero[]);
/// \brief Pide Y llama a validar pero un flotante
/// \param mensaje
/// \param mensajeError
/// \return Retorna el numero flotante
float PedirPrecio(char mensaje[],char mensajeError[]);
/// \brief Harcodea datos de pasajeros
/// \param pasajeros
/// \param tiposPasajeros
/// \param estadosVuelo
void HardcodeoPasajeros(Passenger pasajeros[],typePassenger tiposPasajeros[],statusFlight estadosVuelo[]);
/// \brief Valida que la cadena recibida sean todas letras
/// \param cadena
/// \return Retorna si son todas letras o no
int validarTexto(char cadena[]);
/// \brief Valida que la cadena recibida sean todas letras
/// \param cadena
/// \param mensaje
void ValidarCadena(char cadena[],char mensaje[]);
/// \brief Pide una cadena y llama funciones para validarla
/// \param cadena
/// \param mensaje
void PedirTexto(char cadena[],char mensaje[]);
