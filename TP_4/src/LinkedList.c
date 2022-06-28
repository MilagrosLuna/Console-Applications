#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int size;
    Node* pNode;

    pNode = NULL;
    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size)
    {
    	// obtengo el nodo en la posicion que busco con el get
    	pNode =  getNode( this,index);
    	if(pNode!=NULL)
    	{
    		// y si es distinto de null devuelvo el elemento que contiene ese nodo
    		returnAux = pNode->pElement;
    	}

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int size;
    Node* pNode;

    pNode = NULL;
    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size)
    {
    	// obtengo el nodo en la posicion que busco con el get
    	pNode =  getNode( this,index);
    	if(pNode!=NULL)
    	{
    		// y si es distinto de null remplazo el elemento que contiene ese nodo con el elemento que acabo de recibir
    		pNode->pElement = pElement;
    		returnAux=0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int size;
    Node* pNode;
    Node* pNodePrev;

    pNode = NULL;
    pNodePrev = NULL;
    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size)
    {
		// obtengo el nodo en la posicion que busco con el get
		pNode =  getNode( this,index);
		if(pNode!=NULL)
		{
			if(index==0)
			{
				// si es el primero nodo el indice va a ser 0 entonces solo hago que el primero de la lista apunte a el proximo q apuntaba
				this->pFirstNode = pNode->pNextNode;
			}
			else
			{
				// si no es el primero busco en nodo anterior por eso el -1
				pNodePrev = getNode(this,index-1);
				if(pNodePrev != NULL)
				{
					// si lo encontro y lo devolvio bien
					// hago que el nodo previo apunte a donde apunta el nodo que voy a borrar
					// asi ya no queda relacionado y lo puedo liberar
					pNodePrev->pNextNode = pNode->pNextNode;
				}
			}
			free(pNode);// lo libero
			pNode=NULL;
			this->size--; // decremento el tamaño ya que removi uno
			returnAux = 0;
		}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
   int returnAux = -1;
   int size;

   size = ll_len(this);

   // si el size es mayor a 0 quiere decir q hay elementos cargados que puedo borrar
   if(this != NULL && size >0)
   {
	   for(int i=0;i<size;i++)
	   {
		   // llamo al remove para borrar los elementos, en la poscion de i asi borra todos lo q tiene
		   if(ll_remove(this, i)==0)
		   {
			   returnAux = 0;
		   }
	   }
   }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;

	if(this != NULL)
	{
		// borro los elementos
		if(ll_clear(this)==0)
		{
			// libero el espacio q ocupaba la lista
			free(this);
			this=NULL;
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int size;
	void* pElementAux;

	size = ll_len(this);

	if(this != NULL && size >0)
	{
		for(int i=0; i<ll_len(this) ;i++)
		{
			pElementAux = ll_get(this,i);//obtengo el nodo en esa posicion

			// usar el ll_get , filtro tema comparacion direcciones de memoria
			if(pElementAux == pElement)
			{
				// comparo el nodo y si lo es igual retorno el indice
				returnAux = i;
				break;
			}
		}

	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux = -1;
	int size;

	size = ll_len(this);

	if(this!=NULL)
	{
		returnAux = 1;//esta vacia
		if(size>0)
		{
			returnAux = 0;// no esta vacia
		}
	}

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    int size;
    returnAux = -1;
	size = ll_len(this);
											// menor igual porq lo puedo insertar en la ultima posicion
	if(this != NULL && index >= 0 && index <= size)
	{
		// llamo a agregar nodo y le paso el elemento a agregar y donde quiero agregarlo
		returnAux = addNode(this, index, pElement);
		// me va a retornar si se pudo o no
	}

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* aux;
    int size;

   	size = ll_len(this);

   	if(this != NULL && index >= 0 && index < size)
   	{
   		aux = ll_get(this, index);
   		// obtengo el puntero en la posicion idicada
   		//
		if(ll_remove(this, index)==0)
		{
			// si se pudo borrar de la lista, devuelvo el puntero al elemento
			returnAux = aux;
		}
   	}

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    int size;
    returnAux = -1;
    size = ll_len(this);

    if(this != NULL)
    {
    	returnAux = 0;//no esta en la lista

		if(size>0 && ll_indexOf(this,pElement)!=-1)//verifico q me duvuelva un indice valido
		{
			// si me devolvio algo distinto de -1 quiere decir que el elemento si esta en la lista y cambio el retorno
			returnAux = 1;//esta en la lista
		}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    void* pElement;
    int sizeList2;

    returnAux = -1;
    pElement = NULL;

	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;
	    sizeList2 = ll_len(this2);

		for(int i=0; i< sizeList2 ;i++)//recorro mi lista 2
		{
			pElement = ll_get(this2,i);//tomo el elemento de lista 2 en esa posicion

			if(ll_contains(this,pElement)==0)//comparo si ese elemento esta contenido en mi lista 1
			{//  si no encuentra al menos un elemento, rompe la iteracion
				returnAux = 0;//no contiene a los elementos
				break;//al primer elemento no encontrado, termina
			}
		}
	}

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray;
	void* pElement;
	int size;

	size = ll_len(this);
	cloneArray = NULL;
	pElement = NULL;

	if(this != NULL && from >= 0 && to >= 0 && from <= size && to <= size)
	{
		cloneArray = ll_newLinkedList();//creo la nueva lista

		if(cloneArray != NULL) // si se pudo crear
		{
			for(int i=from; i<to ;i++)//itera desde el valor from hasta el valor to
			{
				pElement = ll_get(this,i);//guardo el elemento de mi lista principal de esa posicion en un auxiliar

				ll_add(cloneArray,pElement);//añado mi elemento en la nueva lista
				// si alguno no se pudo cargar q retorne null rompo iteracion
			}
		}
	}

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int size;

    size =	ll_len(this);

    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,size);//desde la primer posicion que seria 0 hasta el tamaño de la lista original, asi copiar todos los elementos
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
    int size;
    void* pElement1;
    void* pElement2;
    returnAux = -1;
    pElement1 = NULL;
    pElement2 = NULL;

    // validacion orden 1 y 0, ascendente y descendente
    if(this != NULL && (order==1 || order==0) && pFunc!=NULL)
    {
    	size = ll_len(this);
    	// burbujeo
    	for(int i=0; i<size-1 ;i++)
		{
			for(int j=i+1; j<size ;j++)
			{ // obtengo los elementos a comparar
				pElement1 = ll_get(this,i);
				pElement2 = ll_get(this,j);
				//si es p1 es mayor a p2, ascendente				//si p1 es menor a p2, descendente
				if((pFunc(pElement1, pElement2) > 0 && order==1) || (pFunc(pElement1, pElement2) < 0 && order==0))
				{
					// guardo los datos en la nueva posicion
    				ll_set(this, i, pElement2);
    				ll_set(this, j, pElement1);
				}
			}
		}
    	returnAux = 0;
    }

    return returnAux;

}

