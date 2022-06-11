#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	FILE* pArchivo;
	rtn=0;

	pArchivo=fopen(path,"r");
	if(parser_PassengerFromText(pArchivo, pArrayListPassenger)==1)
	{
		rtn=1;
	}
	fclose(pArchivo);

	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn;
	FILE* pArchivo;
	rtn=0;

	pArchivo=fopen(path,"rb");
	if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger)==1)
	{
		rtn=1;
	}
	fclose(pArchivo);

	return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int r;
	Passenger* pasajero;
	char idStr[10];
	char nombre[50];
	char apellido[50];
	float precio;
	char precioStr[20];
	int tipoPasajero;
	char tipoPasajeroStr[20];
	char codigoVuelo[20];
	char estadoVuelo[20];
	retorno=0;

	printf("-> INGRESE SUS DATOS <-\n");

	PedirTexto(nombre,"nombre");
	firstToUpper(nombre);

	PedirTexto(apellido,"apellido");
	firstToUpper(apellido);

	precio=PedirPrecio( "Ingrese el precio: \n", "ERROR Ingrese un precio valido: \n");
	gcvt(precio,8,precioStr);

	printf("1. FirstClass \n2. ExecutiveClass \n3. EconomyClass \n");
	tipoPasajero=PedirYValidarNumero("Ingrese el tipo de pasajero:\n", "Error, ingrese un tipo valido:\n", 1, 3);
	r=DefinirTipoTxt(tipoPasajero, tipoPasajeroStr);

	EstablecerCodigoVuelo(codigoVuelo);
	EstablecerEstadoVuelo(estadoVuelo);

	if(	r==1	&&
		LeerUltimoId("Id.txt", idStr) ==1 &&
		CalcularProximoId(idStr) ==1 )
	{
		pasajero=Passenger_newParametros(idStr, nombre, tipoPasajeroStr,apellido,codigoVuelo,precioStr,estadoVuelo);
	}

	if(pasajero!=NULL)
	{
		if(GuardarId("Id.txt", idStr)==1)
		{
			ll_add(pArrayListPassenger,pasajero);
			retorno=1;
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	int index;
	int idFind;
	Passenger* pasajero;
	rtn=-1;
	pasajero = NULL;

	if(pArrayListPassenger!=NULL)
	{
		if(controller_ListPassenger(pArrayListPassenger)==1)
		{
			idFind=PedirEntero("Ingrese el id del pasajero que desea modificar: \n");
			index = FindID(pArrayListPassenger,idFind);
			pasajero = (Passenger*) ll_get(pArrayListPassenger,index);
			ListPassenger(pArrayListPassenger, index);
			rtn=ModificarPasajero(pasajero);
		}
	}
    return rtn;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int idFind;
	int rtn;
	if(controller_ListPassenger(pArrayListPassenger)==1)
	{
		idFind=PedirEntero("Ingrese el id del pasajero que desea dar de baja: \n");
		rtn=Remove(pArrayListPassenger,idFind);
	}
    return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	int cantidad;
	rtn=0;
	cantidad = ll_len(pArrayListPassenger);
	if(cantidad>0)
	{
		printf("---------------------------------------------------------------------------------------------------------------\n");
		printf("						Cantidad: %d\n",cantidad);
		printf("---------------------------------------------------------------------------------------------------------------\n");
		printf("ID	Nombre		     Apellido	          Tipo de pasajero     Codigo     Estado 	    precio \n");
		printf("---------------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<cantidad;i++)
		{
			if( ListPassenger(pArrayListPassenger,i)==1)
			{
				rtn=1;
			}
		}
		printf("---------------------------------------------------------------------------------------------------------------\n");
	}
    return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	rtn=MostarOpcionesListado(pArrayListPassenger);
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivo;
	retorno = -1;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"w");

		if(pArchivo!= NULL)
		{
			if(saveTxt(pArchivo, pArrayListPassenger)==1)
			{
				retorno=1;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno;
    int i;
    int len;
    FILE* pArchivo;
    Passenger* aux;
    retorno = -1;
    aux = NULL;
    if(path!=NULL && pArrayListPassenger!=NULL)
    {
        len = ll_len(pArrayListPassenger);
        pArchivo = fopen(path,"wb");

        if(pArchivo!= NULL && len>0)
        {
            for(i=0; i<len ;i++)
            {
                aux = (Passenger*) ll_get(pArrayListPassenger,i);
                if(aux!=NULL)
                {
                    fwrite(aux,sizeof(Passenger),1,pArchivo);
                    retorno=1;
                }
            }
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
        fclose(pArchivo);
    }
    return retorno;
}










