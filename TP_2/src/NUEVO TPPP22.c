#include "nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	Passenger pasajeros[TAM_pasajeros];
	typePassenger tiposPasajeros[3]={{1,"PRIMERA_CLASE"},{2,"CLASE_EJECUTIVO"},{3,"CLASE_ECONOMICA"}};
	statusFlight estadosVuelo[3]={{10,"ACTIVO"},{11,"CANCELADO"},{12,"DEMORADO"}};
	int opcion;
	char seguir;
	int index;
	int contadorAltas;
	int idInicial;
	int id;

	idInicial=1000;
	seguir = 's';
	contadorAltas=0;

	if(Passenger_initPassengers(pasajeros,TAM_pasajeros)==0)
	{
		while(seguir=='s')
		{
			printf("1. ALTAS:  \n");
			printf("2. MODIFICAR: \n");
			printf("3. BAJA: \n");
			printf("4. INFORMAR: \n");
			printf("5. HARCODEAR \n");
			printf("6. Salir \n");
			opcion=PedirEntero("Elija una opcion: \n");
			switch(opcion)
			{
				case 1:
					 if (CargarPasajero(pasajeros,TAM_pasajeros,tiposPasajeros,TAM_tipos,estadosVuelo,TAM_estados,&idInicial)==0)
						{
							printf("El pasajero se cargo exitosamente\n");
							contadorAltas++;
						}
						else
						{
							printf("El pasajero no se cargo\n");
						}
				break;
				case 2:
					if(contadorAltas>0)
					{
						ListarPasajeros(pasajeros,TAM_pasajeros,tiposPasajeros,TAM_tipos,estadosVuelo,TAM_estados);
						id=PedirEntero("\nIngrese el ID del pasajero que desea modificar:\n");
						if((index=Passenger_findPassengerById(pasajeros,TAM_pasajeros,id))!=-1)
						{
							ModificarPasajero(pasajeros,index,tiposPasajeros,TAM_tipos);
						}
						else
						{
							printf("NO se ha encontrado el pasajero\n");
						}
					}
					else
					{
						printf("Para realizar operaciones debe haber relizado un alta como minimo..\n");
					}
				break;
				case 3:
					if(contadorAltas>0)
					{
						ListarPasajeros(pasajeros,TAM_pasajeros,tiposPasajeros,TAM_tipos,estadosVuelo,TAM_estados);
						id=PedirEntero("\nIngrese el ID del pasajero que desea dar de baja:\n");
						if(Passenger_removePassenger(pasajeros,TAM_pasajeros,id)!=-1)
						{
							printf("Baja exitosa...\n");
							contadorAltas--;
						}
						else
						{
							printf("NO se ha encontrado el pasajero\n");
						}
					}
					else
					{
						printf("Para realizar operaciones debe haber relizado un alta como minimo..\n");
					}
				break;
				case 4:
					if(contadorAltas>0)
					{
						MostarOpcionesListado(pasajeros, TAM_pasajeros, tiposPasajeros, TAM_tipos, estadosVuelo, TAM_estados);
					}
					else
					{
						printf("Para realizar operaciones debe haber relizado un alta como minimo..\n");
					}
				break;
				case 5:
					 HardcodeoPasajeros(pasajeros,tiposPasajeros,estadosVuelo,&idInicial);
					 ListarPasajeros(pasajeros,TAM_pasajeros,tiposPasajeros,TAM_tipos,estadosVuelo,TAM_estados);
					 contadorAltas=6;
				break;
				case 6:
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
	return EXIT_SUCCESS;
}
