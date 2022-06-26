/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST

typedef struct {
    void* pElement;
    struct Node* pNextNode;
} Node;

typedef struct {
    Node* pFirstNode;
    int size;

} LinkedList;

//Publicas

/**
 * @brief	Crea y retorna un nuevo LinkedList. Es el constructor.
 * @return	Retorna el LL.
 */
LinkedList* ll_newLinkedList(void);

/**
 * @brief	Retorna el tamaño del LinkedList.
 * @param 	this
 * @return	Retorna el tamaño del LinkedList o -1 si falla.
 */
int ll_len(LinkedList* this);

/**
 * @brief 	Retorna un puntero al nodo que se encuentra en el índice especificado.
 * @param 	this
 * @param 	nodeIndex
 * @return	Retorna el puntero o NULL.
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/**
 * @brief 	Agrega un nodo en la posición indexNode, verificando que el puntero this sea distinto de NULL
 *			y que index sea positivo e inferior al tamaño del array.
 * @param 	this
 * @param 	nodeIndex
 * @param 	pElement
 * @return	Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * @brief 	Agrega un elemento al final de LinkedList.
 * @param 	this
 * @param 	pElement
 * @return	Retorna 0 si puede, sino -1.
 */
int ll_add(LinkedList* this, void* pElement);

/**
 * @brief 	Retorna un puntero al elemento que se encuentra en el índice especificado.
 * @param 	this
 * @param 	index
 */
void* ll_get(LinkedList* this, int index);

/**
 * @brief 	Inserta un elemento en el LinkedList, en el índice especificado.
 * @param 	this
 * @param 	index
 * @param 	pElement
 * @return	Retorna 0 si tiene exito, sino -1.
 */
int ll_set(LinkedList* this, int index,void* pElement);

/**
 * @brief 	Elimina un elemento del LinkedList, en el índice especificado.
 * @param 	this
 * @param 	index
 * @return	Retorna 0 si pudo, sino -1.
 */
int ll_remove(LinkedList* this,int index);

/**
 * @brief 	Borra todos los elementos de LinkedList.
 * @param 	this
 * @return	Retorna 0 si pudo, sino -1.
 */
int ll_clear(LinkedList* this);

/**
 * @brief 	Elimina el LinkedList.
 * @param 	this
 * @return	Retorna -1 si falla, 1 si esta vacio o 0 si pudo.
 */
int ll_deleteLinkedList(LinkedList* this);

/**
 * @brief 	Retorna el índice de la primera aparición de un elemento (element) en el LinkedList.
 * @param 	this
 * @param 	pElement
 * @return	Retorna el indice o -1 si falla.
 */
int ll_indexOf(LinkedList* this, void* pElement);

/**
 * @brief 	Retorna cero si contiene elementos y uno si no los tiene.
 * @param 	this
 * @return	Retorna 1 si esta vacio, -1 si falla o 0 si tiene elementos.
 */
int ll_isEmpty(LinkedList* this);

/**
 * @brief 	Desplaza los elementos e inserta en la posición index.
 * @param	this
 * @param 	index
 * @param 	pElement
 * @return	Retorna 0 si tiene exito, sino -1.
 */
int ll_push(LinkedList* this, int index, void* pElement);

/**
 * @brief 	Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
 *			de la lista.
 * @param 	this
 * @param 	index
 */
void* ll_pop(LinkedList* this,int index);

/**
 * @brief 	Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
 *			puntero this sea distintos de NULL
 * @param 	this
 * @param 	pElement
 * @return	Si la verificación falla la función retorna (-1) , si encuentra el elemento (1) y si no lo encuentra (0).
 */
int ll_contains(LinkedList* this, void* pElement);

/**
 * @brief 	Comprueba si los elementos pasados son contenidos por el LinkedList. Verificando que tanto el
 *			puntero this como pList2 sean distintos de NULL.
 * @param 	this
 * @param 	this2
 * @return	Si falla retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna (1).
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/**
 * @brief 	Retorna un nuevo LinkedList con el subconjunto de elementos. Verificando que el puntero this
 *			sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
 *			del array.
 * @param 	this
 * @param 	from
 * @param 	to
 * @return	Retorna el nuevo array o NULL si falla.
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/**
 * @brief 	Retorna un nuevo LinkedList copia del LinkedList original. Verificando que el puntero this sea
 *			distinto de NULL
 * @param 	this
 * @return	Retorna el nuevo array o NULL si falla.
 */
LinkedList* ll_clone(LinkedList* this);

/**
 * @brief 	Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
 *			de determinar que elemento es mas grande que otro y si se debe ordenar de manera
 *			ascendente o descendente.
 * @param 	this
 * @param 	pFunc
 * @param 	order
 * @return	Si la verificación falla (-1) caso contrario retorna (1).
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

#endif
