#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaTp.h"

int main(void)
{
	setbuf(stdout, NULL);
	// declaracion de variables
	int kilometrosIngresados;
	float precioIngresadoY;
	float precioIngresadoZ;
	int opcion;
	char seguir;
	// inicializacion de variables
	kilometrosIngresados = 0;
	precioIngresadoY = 0;
	precioIngresadoZ = 0;
	seguir = 's';

	while(seguir=='s')
	{
		printf("1. Ingresar Kilómetros: %d \n",kilometrosIngresados);
		printf("2. Ingresar Precio de vuelo: (Aerolíneas = %.2f, Latam = %.2f)\n",precioIngresadoY,precioIngresadoZ);
		printf("3. Calcular todos los costos: \n");
		printf("4. Informar Resultados: \n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir \n");
		printf("Elija una opcion: \n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				// pide los kilometros al usuario y se validan con la funcion
				printf("Ingrese los kilometros: \n");
				scanf("%d",&kilometrosIngresados);
				kilometrosIngresados = ValidarKilometros(kilometrosIngresados);
			break;
			case 2:
				// pide los precios al usuario y se validan con la funcion
				printf("- Ingrese el Precio de vuelo en Aerolíneas: \n");
				scanf("%f",&precioIngresadoY);
				precioIngresadoY = ValidarPrecio(precioIngresadoY);

				printf("- Ingrese el Precio de vuelo en Latam: \n");
				scanf("%f",&precioIngresadoZ);
				precioIngresadoZ = ValidarPrecio(precioIngresadoZ);
			break;
			case 3:
				// muestra lo que se va a calcular y valida los datos ingresados para que no se calcule si faltan datos
				printf("a) Tarjeta de débito (descuento 10%%)\n");
				printf("b) Tarjeta de crédito (interés 25%%)\n");
				printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
				printf("d) Mostrar precio por km (precio unitario)\n");
				printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
				if(kilometrosIngresados == 0 || precioIngresadoY == 0 || precioIngresadoZ == 0 )
				{
					printf("No se pueden calcular los costos debido a que falta ingresar valores \n");
				}
			break;
			case 4:
				// muestra los resultados y valida los datos ingresados para que no se muestre si faltan datos
				if(kilometrosIngresados == 0 || precioIngresadoY == 0 || precioIngresadoZ == 0 )
				{
					printf("No se pueden calcular los costos debido a que falta ingresar valores \n");
				}
				else
				{
					printf("\nLatam: %.2f",precioIngresadoZ);
					CalcularPrecio(precioIngresadoZ,kilometrosIngresados);

					printf("\nAerolíneas: %.2f",precioIngresadoY);
					CalcularPrecio(precioIngresadoY,kilometrosIngresados);
					CalcularDiferenciaDePrecio(precioIngresadoY,precioIngresadoZ);
				}
			break;
			case 5:
				//  calcula y muestra los resultados en base a los valores brindados en el tp
				precioIngresadoY = 162965;
				precioIngresadoZ = 159339;
				kilometrosIngresados = 7090;
				printf("\nKMs Ingresados: %d",kilometrosIngresados);
				printf("\n\nPrecio Aerolíneas: %.2f",precioIngresadoY);
				CalcularPrecio(precioIngresadoY,kilometrosIngresados);
				printf("\nPrecio Latam: %.2f",precioIngresadoZ);
				CalcularPrecio(precioIngresadoZ,kilometrosIngresados);
				CalcularDiferenciaDePrecio(precioIngresadoY,precioIngresadoZ);
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
	return EXIT_SUCCESS;
}

