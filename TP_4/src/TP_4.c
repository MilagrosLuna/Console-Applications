#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


/*
 *  PRIMERAS FUNCIONES UNICAMENTE
 *
 *  ---tp finalizado---
 */



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux;
    returnAux = -1;

    if(this!=NULL)
    {
    	returnAux=this->size;
    }

    return returnAux;
}




/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	int i;
	int size;
	size = ll_len(this);
	pNode = NULL;
	// el pNode seria un nodo auxiliar que utilizo para ir buscando el nodo que me pidieron
	// que seria el que viene en la posicion nodeIndex


	//verifico que no sea NULL la lista y que el index no sea menor a cero y que el size de la lista no sea menor al index
	// q no sea menor o q no execeda la lista por que no existiria
	if(this != NULL && nodeIndex >= 0 && nodeIndex < size)
	{
		pNode = this->pFirstNode;//le asigno el primer nodo para recorrer en busca del que pide

		// osea tiene el primero y ahora va a recorrer hasta la cantidad q ingreso
		for(i=0; i<nodeIndex ;i++)
		{
			pNode = pNode->pNextNode;//va igualando hasta llegar al ultimo
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	// el node index va a ser el size de la lista entonces si es el primero va a ser 0
	//y si no va  a ser el ultimo lugar en donde lo voy agregar
    int returnAux;
    Node* pNodeNew;
    Node* pNodePrev;
    int size;

    size = ll_len(this);
    returnAux = -1;
    pNodeNew = NULL;
    pNodePrev = NULL;


    if(this != NULL && nodeIndex >= 0 && nodeIndex <= size)
    {
    	// genero el nuevo nodo que voy a agregar a la lista
		pNodeNew = (Node*) malloc(sizeof(Node));

		if(pNodeNew != NULL)
		{
			pNodeNew->pElement = pElement;// elemento / entidad q va a ser añadida a la lista

			pNodeNew->pNextNode = NULL;
			//por ser mi ultimo nodo agregado a la lista lo igualo a null

			if(nodeIndex == 0)// en el caso de que sea mi primer elemento en la lista
			{
				pNodeNew->pNextNode = this->pFirstNode;//el primer nodo va a asignarse al nuevo nodo creado
				this->pFirstNode = pNodeNew;//el primer nodo va a ser el nuevo que se creo
			}
			else
			{
				pNodePrev = getNode(this,nodeIndex-1); //tengo -1 porque lo que busco es el nodo anterior a donde lo quiero agregar

				// una vez que encontre el nodo anterior voy a guardar el que acabo de crear
				if(pNodePrev != NULL)
				{
					pNodeNew->pNextNode = pNodePrev->pNextNode;//a donde apunta el anterior nodo va a pasar a apuntar mi nuevo nodo
					// osea si el anterior era el ultimo y apuntaba a NULL
					// ahora el nuevo va a apuntar a NULL, pero si hubiese sido un push apuntaria a otro nodo

					pNodePrev->pNextNode = pNodeNew;//el anterior nodo empieza a apuntar al nuevo nodo

				}
			}
			this->size++; // como se agrego un nodo a la lista aumento el tamaño
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux;
    int size;

    returnAux = -1;
    size = ll_len(this);
    //len va a ser el ultimo lugar que puedo agregar mi nuevo elemento

	if(this != NULL)
	{
		returnAux = addNode(this,size,pElement);
	}

	return returnAux;
}
