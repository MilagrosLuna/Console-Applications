#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "validaciones.h"

int main()
{
	setbuf(stdout,NULL);
	int opcion;
	char seguir;
	int banderaCarga;
	int banderaSalida;
	int auxiliar;
    LinkedList* listaPasajeros;
    listaPasajeros = ll_newLinkedList();
    banderaCarga=0;
    banderaSalida=0;
   	seguir = 's';
   	while(seguir=='s')
   	{
   		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).  \n");
   		printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
   		printf("3. Alta de pasajero: \n");
   		printf("4. Modificar datos de pasajero: \n");
   		printf("5. Baja de pasajero: \n");
   		printf("6. Listar pasajeros: \n");
   		printf("7. Ordenar pasajeros: \n");
   		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n");
   		printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n");
   		printf("10. Salir \n");
   		opcion=PedirEntero("Elija una opcion: \n");
   		switch(opcion)
   		{
   			case 1:
   				if(banderaCarga==0)
   				{
   					if(controller_loadFromText("MOCK_DATAx.csv",listaPasajeros)==1)
					{
						printf("Carga exitosa...\n");
						banderaCarga=1;
					}
   				}
   				else
   				{
   					printf("Ya se ha realizado una carga desde el archivo");
   				}
			break;

   			case 2:
   				if(banderaCarga==0)
				{
   					if(controller_loadFromBinary("MOCK_DATAx.bin",listaPasajeros)==1)
					{
						printf("Carga exitosa...\n");
						banderaCarga=1;
					}

				}
				else
				{
					printf("Ya se ha realizado una carga desde el archivo");
				}
   			break;

   			case 3:
   				auxiliar=controller_addPassenger(listaPasajeros);
   				if(auxiliar==1)
   				{
   					printf("OK,agrego a la lista");
   				}
   			break;

   			case 4:
				auxiliar=controller_editPassenger(listaPasajeros);
				if(auxiliar==1)
				{
					printf("Modificacion exitosa\n");
				}
				else
				{
					if(auxiliar==0)
					{
						printf("Modificacion cancelada\n");
					}
					else
					{
						printf("No se ha podido modificar\n");
					}
				}
   			break;

   			case 5:
				auxiliar=controller_removePassenger(listaPasajeros);
				if(auxiliar==1)
				{
					printf("ok");
				}
   			break;

   			case 6:
   				ll_sort(listaPasajeros,compareById,1);
   				if(controller_ListPassenger(listaPasajeros)==1)
				{
					printf("\nListado Exitoso\n");
				}
				else
				{
					printf("\nNo hay pasajeros para mostrar\n");
				}

   			break;

   			case 7:
   				auxiliar=controller_sortPassenger(listaPasajeros);
				if(auxiliar==1)
				{
					printf("ok");
					printf("\nListado Exitoso\n");
				}
   			break;

   			case 8:
   				auxiliar=controller_saveAsText("MOCK_DATAx.csv",listaPasajeros);
   				if(auxiliar==1)
				{
					printf("Se guardo con exito\n");
					banderaSalida=1;
				}
   			break;

   			case 9:
   				auxiliar=controller_saveAsBinary("MOCK_DATAx.bin",listaPasajeros);
   				if(auxiliar==1)
				{
					printf("Se guardo con exito\n");
					banderaSalida=1;
				}
   			break;

   			case 10:
   				if(banderaSalida==1)
				{
					// sale del menu
					printf("Saliendo..\n");
					seguir = 'n';
				}
				else
				{
					printf("No puede salir si no realiz� alg�n guardado de archivo");
				}

   			break;

   			default:
   				printf("Opcion incorrecta\n");
   			break;
   		}
   		printf("\n\n");
   	}
    return 0;
}

