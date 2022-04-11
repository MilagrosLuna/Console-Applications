#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaTp.h"
/// \brief
/// \param km  recibe los kilometros ingresados por el usuario y los valida
/// \return retorna el valor validado
int ValidarKilometros(int km)
{
	while(km<1)
	{
		printf("Error, Ingrese cantidad de Kilometros valida, mayor a 0: \n");
		scanf("%d",&km);
	}
	return km;
}
/// \brief
/// \param precio recibe el precio ingresado por el usuario y los valida
/// \return retorna el valor validado
float ValidarPrecio(float precio)
{
	while(precio<1)
	{
		printf("Error, Ingrese un precio valido, mayor a 0: \n");
		scanf("%f",&precio);
	}
	return precio;
}
/// \brief
/// \param precio recibe el precio validado
/// \param kilometros recibe los kilometros validados y calcula los precios, mostrandolos unoxuno
void CalcularPrecio(float precio,int kilometros)
{
	float descuentoDebito;
	float interesCredito;
	float bitcoin;
	float precioPorKm;

	descuentoDebito = precio - (precio * 10 /100);
	interesCredito = precio + (precio * 25 /100);
	bitcoin = precio / 4606954.55;
	precioPorKm = precio / kilometros;

	printf("\na) Precio con Tarjeta de débito: $ %.2f",descuentoDebito);
	printf("\nb) Precio con Tarjeta de crédito: $ %.2f",interesCredito);
	printf("\nc) Precio pagando con Bitcoin: $ %f",bitcoin);
	printf("\nd) Mostrar precio unitario: $ %.2f",precioPorKm);

}
/// \brief
/// \param precioy
/// \param precioz recibe 2 precios validados, calcula y muestra la diferencia de precio
void CalcularDiferenciaDePrecio(float precioy, float precioz)
{
	float diferencia;
	if(precioy>precioz)
	{
		diferencia=precioy-precioz;
	}
	else
	{
		if(precioz>precioy)
		{
			diferencia=precioz-precioy;
		}
		else
		{
			diferencia=0;
		}
	}
	printf("\n\nLa diferencia de precio es: %.2f \n",diferencia);
}


