#include "validaciones.h"

void PedirTexto(char* cadena,char* mensaje)
{
	printf("Ingrese %s: \n",mensaje);
	fflush(stdin);
	gets(cadena);
	ValidarCadena(cadena,mensaje);
}

void ValidarCadena(char* cadena,char* mensaje)
{
	int bandera;
	bandera=validarTexto(cadena);
	while(bandera==0)
	{
		printf("Ingrese un %s valido: \n",mensaje);
		fflush(stdin);
		gets(cadena);
		bandera=validarTexto(cadena);
	}
}

int validarTexto(char* cadena)
{
	int validacion;
	validacion=-1;
	for(int i=0;i<strlen(cadena);i++)
	{
		if(isalpha(cadena[i]))
		{
			validacion=-1;
		}
		else
		{
			validacion=0;
			break;
		}
	}
	return validacion;
}

int PedirYValidarNumero(char* mensaje, char* mensajeError, int limiteInferior, int limiteSuperior)
{
    int retorno;
	char numeroIngresado[1000];
	printf(mensaje);
	scanf("%s",numeroIngresado);

    while(!ValidarNumero(numeroIngresado))
    {
		printf(mensajeError);
		scanf("%s",numeroIngresado);
	}

    retorno=atoi(numeroIngresado);

    while(retorno<limiteInferior || retorno>limiteSuperior)
    {

        printf("%s", mensajeError);
        scanf("%s",numeroIngresado);
        while(!ValidarNumero(numeroIngresado))
        {
			printf(mensajeError);
			scanf("%s",numeroIngresado);
        }
        retorno=atoi(numeroIngresado);
    }

    return retorno;
}

int PedirEntero(char* mensaje)
{
	int retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("\nERROR\n");
		printf(mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}

int ValidarNumero(char* numero)
{
	int retorno=1;
	int len;
	if(numero!=NULL)
	{
		len=strlen(numero);
		for(int i=0;i<len;i++)
		{
			if(!isdigit(numero[i]))
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

void firstToUpper(char* cadena)
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
   (cadena[0]) = toupper(cadena[0]);
    for(i=0;i<tam;i++)
    {
        if(cadena[i]!='\0')
        {
            if(isspace(cadena[i]))
            {
            	cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}



float PedirPrecio(char* mensaje,char* mensajeError)
{
	float numero1;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!isFloat(numero))
	{
			printf("\nERROR\n");
			printf(mensaje);
			scanf("%s",numero);
	}
	numero1=atof(numero);
	return numero1;
}

int isFloat(char* cadena)
{
    int validacion;

    for(int i=0;i<strlen(cadena);i++)
    {
        if(isdigit(cadena[i]) || cadena[i]=='.')
        {
            validacion = 1;// bien
        }
        else
        {
            validacion = 0; // mal
            break;
        }
    }

    return validacion;
}




