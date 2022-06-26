/*
 * ============================================================================
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
 *
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../Library/KnightOfZodiac/Getters/Getters.h"
#include "../Library/KnightOfZodiac/Setters/Setters.h"
#include "../Library/Controller/Controller.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

//Usada
/**
 * @formatter:on
 * @brief  crea un nuevo LinkedList en memoria de manera dinamica.
 * @return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria.
 *         o el puntero al espacio reservado.
 * @author FacuFalcone.
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) {
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

//Usada
/**
 * @brief  Retorna la cantidad de elementos de la lista
 * @param  this LinkedList* Puntero a la lista.
 * @return Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista.
 * @author FacuFalcone.
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

//Usada
/**
 * @brief  Obtiene un nodo de la lista.
 * @param  this LinkedList* Puntero a la lista.
 * @param  index int Indice del nodo a obtener.
 * @return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL
 * 		   o (si el indice es menor a 0 o mayor al len de la lista)
 *         (pNode) Si funciono correctamente.
 * @author FacuFalcone.
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *pNode = NULL;

	if (this != NULL) {
		if (nodeIndex >= 0 && nodeIndex < ll_len(this)) {
			pNode = this->pFirstNode;
			for (int i = 0; i < nodeIndex; i++) {
				pNode = pNode->pNextNode;
			}
		}
	}
	return pNode;
}

//Usada
/**
 * @brief  Permite realizar el test de la funcion getNode la cual es privada
 * @param  this LinkedList* Puntero a la lista
 * @param  index int Indice del nodo a obtener
 * @return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *         (pElement) Si funciono correctamente.
 * @author FacuFalcone.
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

//Usada
/**
 * @brief  Agrega y enlaza un nuevo nodo a la lista.
 * @param  this LinkedList* Puntero a la lista.
 * @param  nodeIndex int Ubicacion donde se agregara el nuevo nodo.
 * @param  pElement void* Puntero al elemento a ser contenido por el nuevo nodo.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el
 * 		   indice es menor a 0 o mayor al len de la lista).
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *newNode;
	Node *pActualNode;

	if (this != NULL) {

		if (nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
			newNode = (Node*) malloc(sizeof(Node));
			newNode->pElement = pElement;
			newNode->pNextNode = NULL;

			if (nodeIndex == 0) {
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
			} else {
				pActualNode = getNode(this, nodeIndex - 1);
				newNode->pNextNode = pActualNode->pNextNode;
				pActualNode->pNextNode = newNode;
			}
			returnAux = 0;
			this->size++;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Permite realizar el test de la funcion addNode la cual es privada.
 * @param  this LinkedList* Puntero a la lista.
 * @param  nodeIndex int Ubicacion donde se agregara el nuevo nodo.
 * @param  pElement void* Puntero al elemento a ser contenido por el nuevo nodo.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice
 * 		   es menor a 0 o mayor al len de la lista).
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

//Usada
/**
 * @brief  Agrega un elemento a la lista.
 * @param  pList LinkedList* Puntero a la lista.
 * @param  pElement void* Puntero al elemento a ser agregado.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL.
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_add(LinkedList *this, void *pElement) {
	return addNode(this, ll_len(this), pElement);
}

//Usada
/**
 * @brief  Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
 *		   puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 * @param  this LinkedList* Puntero a la lista.
 * @param  nodeIndex int Ubicacion del elemento a obtener.
 * @return void* Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 * @author FacuFalcone.
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *newNode;

	newNode = getNode(this, index);
	if (newNode != NULL) {
		returnAux = newNode->pElement;
	}
	return returnAux;
}

//Usada
/**
 * @brief  Modifica un elemento de la lista.
 * @param  this LinkedList* Puntero a la lista.
 * @param  nodeIndex int Ubicacion del elemento a modificar.
 * @param  pElement void* Puntero al nuevo elemento.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *newNode;
	if (this != NULL && index >= 0 && index < ll_len(this)) {
		newNode = getNode(this, index);
		if (newNode != NULL) {
			newNode->pElement = pElement;
			returnAux = 0;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Elimina un elemento de la lista.
 * @param  this LinkedList* Puntero a la lista
 * @param  nodeIndex int Ubicacion del elemento a eliminar
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *         (0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	Node *actualNode;
	Node *previousNode;

	if (this != NULL && index < ll_len(this) && index >= 0) {

		actualNode = getNode(this, index);

		if (actualNode != NULL) {
			if (index == 0) {
				this->pFirstNode = actualNode->pNextNode;
				this->size--;
				free(actualNode);
			} else {
				previousNode = getNode(this, index - 1);
				if (previousNode != NULL) {
					previousNode->pNextNode = actualNode->pNextNode;
					this->size--;
					free(actualNode);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

//Usada
/**
 * @brief  Elimina todos los elementos de la lista.
 * @param  this LinkedList* Puntero a la lista.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL.
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	//int tam;
	if (this != NULL) {
		while (ll_len(this)) {
			ll_remove(this, 0);
		}
		returnAux = 0;
	}
	return returnAux;
}

//Usada
/**
 * @brief  Elimina todos los elementos de la lista y la lista.
 * @param  this LinkedList* Puntero a la lista.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL.
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;
	//if (this != NULL) { // se puede evitar validar ya que en clear se valida.
	if (!ll_clear(this)) { // si retorna 0 pudo
		free(this);
		returnAux = 0;
	}
	//}
	return returnAux;
}

//Usada
/**
 * @brief  Busca el indice de la primer ocurrencia del elemento pasado como parametro.
 * @param  this LinkedList* Puntero a la lista.
 * @param  pElement void* Puntero al elemento.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o si no estuviese en la lista.
 *         (indice del elemento) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int tam;
	/** si dentro del ll hay algun nodo que esta apuntando a ese elemento*/
	if (this != NULL) {
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			//pNode = getNode(this, i);
			if (ll_get(this, i) == pElement) {
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Indica si la lista esta o no vacia.
 * @param  this LinkedList* Puntero a la lista.
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL.
 * 		   ( 0) Si la lista NO esta vacia.
 * 		   ( 1) Si la lista esta vacia.
 * @author FacuFalcone.
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = 0;
		if (ll_len(this) == 0) { //si el tamanho es 0, esta vacia.
			returnAux = 1;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Inserta un nuevo elemento en la lista en la posicion indicada
 * @param  this LinkedList* Puntero a la lista
 * @param  nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * @param  pElement void* Puntero al nuevo elemento
 * @return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *         ( 0) Si funciono correctamente.
 * @author FacuFalcone.
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	return addNode(this, index, pElement);
}

//Usada
/**
 * @brief  Elimina el elemento de la posicion indicada y retorna su puntero.
 * @param  this LinkedList* Puntero a la lista.
 * @param  nodeIndex int Ubicacion del elemento eliminar.
 * @return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *         (pElement) Si funciono correctamente.
 * @author FacuFalcone.
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = ll_get(this, index);
		if (ll_remove(this, index)) { // si fallo el remove, retorna null
			returnAux = NULL;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief Determina si la lista contiene o no el elemento pasado como parametro.
 * @param this LinkedList* Puntero a la lista.
 * @param pElement void* Puntero del elemento a verificar.
 *@return int Retorna  (-1) Error: si el puntero a la lista es NULL.
 *        ( 1) Si contiene el elemento.
 *        ( 0) si No contiene el elemento.
 * @author FacuFalcone.
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = 0; //si entro, pongo que aun no esta el elemento xq no lo busque.
		if (ll_indexOf(this, pElement) >= 0) { //busco el indice del elemento que coincida con pElement.
			returnAux = 1;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this).
 * @param  this LinkedList* Puntero a la lista.
 * @param  this2 LinkedList* Puntero a la lista.
 * @return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL.
 *         ( 1) Si los elementos de (this2) estan contenidos en la lista (this).
 *         ( 0) si los elementos de (this2) NO estan contenidos en la lista (this).
 * @author FacuFalcone.
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	void *pElementAux;
	int tam;

	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		tam = ll_len(this2); //guardo el tamanho de this2

		for (int i = 0; i < tam; i++) {
			pElementAux = ll_get(this2, i); // copio indices de elementos en pElement
			if (!ll_contains(this, pElementAux)) { //busco que cada elemento este en la sublista
				returnAux = 0;	// si uno no esta, retorno 0 y salgo.
				break;
			}
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Crea y retorna una nueva lista con los elementos indicados.
 * @param  pList LinkedList* Puntero a la lista.
 * @param  from int Indice desde el cual se copian los elementos en la nueva lista.
 * @param  to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido).
 * @return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL.
 *         o (si el indice from es menor a 0 o mayor al len de la lista).
 *         o (si el indice to es menor o igual a from o mayor al len de la lista).
 *         (puntero a la nueva lista) Si ok.
 * @author FacuFalcone.
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	void *pElement;
//crea una nueva lista con el rango pasado [no incluye el ultimo elemento]
	if (!(this == NULL || from < 0 || from > ll_len(this) || to <= from || to > ll_len(this))) {
		cloneArray = ll_newLinkedList(); // inicializo la sub lista.
		if (cloneArray != NULL) { //si es distinto, entonces se consiguio lugar.
			for (int i = from; i < to; i++) { // hay que recorrer.
				pElement = ll_get(this, i);
				ll_add(cloneArray, pElement); //retorna el puntero a la nueva lista.
			}
		}
	}
	return cloneArray;
}

//Usada
/**
 * @brief 	Crea y retorna una nueva lista con los elementos de la lista pasada como parametro.
 * @param	pList LinkedList* Puntero a la lista.
 * @return 	LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL.
 *          (puntero a la nueva lista) Si ok.
 * @author FacuFalcone.
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL; // no hace falta validar, ya valida ll_subList
	cloneArray = ll_subList(this, 0, ll_len(this)); // copio la lista  mismo tamanho de this.
	return cloneArray;
}

//Usada
/**
 * @brief  Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro.
 * @param  pList LinkedList* Puntero a la lista.
 * @param  pFunc (*pFunc) Puntero a la funcion criterio.
 * @param  order int  [1] Indica orden ascendente - [0] Indica orden descendente.
 * @return int Retorna  (-1) Error: si el puntero a la listas es NULL.
 *         ( 0) Si ok.
 * @author FacuFalcone.
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *element1;
	void *element2;
	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				element1 = ll_get(this, i);
				element2 = ll_get(this, j);
				if ((pFunc(element1, element2) > 0 && order)
				        || (pFunc(element1, element2) < 0 && !order)) {
					ll_set(this, i, element2);
					ll_set(this, j, element1);
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

/**
 * @brief  Ordena los elementos de la lista utilizando las 2 funciones criterio recibida como parametro.
 * @param  this LinkedList* Puntero a la lista.
 * @param  pFunc (*pFunc) Puntero a la primer funcion criterio.
 * @param  pFunc2 (*pFunc2) Puntero a la segunda funcion criterio.
 * @param  order int  [1] Indica orden ascendente - [0] Indica orden descendente.
 * @return int Retorna  (-1) Error: si el puntero a la listas es NULL.
 *         ( 0) Si ok.
 * @author FacuFalcone.
 */
int ll_Megasort(LinkedList *this, int (*pFunc)(void*, void*),int (*pFunc2)(void*, void*), int order) {
	int returnAux = -1;
	void *element1;
	void *element2;
	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
		for (int i = 0; i < ll_len(this) - 1; i++) {
			for (int j = i + 1; j < ll_len(this); j++) {
				element1 = ll_get(this, i); // copio el primer elemento.
				element2 = ll_get(this, j); // copio el segundo elemento.

				// Si los elementos son distintos, ordeno de mayor a menor / menor a mayor.
				if ((pFunc(element1, element2) > 0 && order)||(pFunc(element1, element2) < 0 && !order)) {
					ll_set(this, i, element2); //Cambio de lugar el segundo elemento.
					ll_set(this, j, element1); //Cambio de lugar el primer elemento.
				// Si los elementos son iguales, ordeno con la segunda funcion.
				}else if (pFunc(element1, element2) == 0){
					if(pFunc2(element1,element2)>0){
						ll_set(this, i, element2);
						ll_set(this, j, element1);
					}
				}
			}
			returnAux = 0;
		}
	}
	return returnAux;
}

//Usada
/**
 * @brief  Copia una lista en la que los elementos coincidan con
 * 		   elemento pasado por parametro.
 * @param  zodiacArray
 * @param  pFunc
 * @return Retorna la lista copiada o NULL.
 * @author FacuFalcone.
 */
LinkedList* ll_filter(LinkedList *zodiacArray, int (*pFunc)(void*)) {

	/** llama a pFunc y le pasa un elemento, si pFunc devuelve 1, lo carga*/

	int tam; //guardo el tamanho del array
	void *pElement;
	LinkedList *newLinkedList = NULL; //LL para devolver filtrado

	if (zodiacArray != NULL && *pFunc != NULL) {

		newLinkedList = ll_newLinkedList();
		if (newLinkedList != NULL) {
			tam = ll_len(zodiacArray); //guardo el tamanho de la lista original

			for (int i = 0; i < tam; i++) {
				pElement = ll_get(zodiacArray, i); //recorro la lista original.
				if (pFunc(pElement)) { // si el callback devuelve 1, me copio el elemento.
					ll_add(newLinkedList, pElement); //me los copio a la lista filtrada.
				}
			}

		}
	}
	return newLinkedList;
}
//******************************************
/*Recibira la lista y una funcion, Ejecutara la funcino como parametro
 * por cada item de la lista y realizara descuentos a los precios segun se detallan
 * Cuidado de ropa: 20% (si vale 120 o mas)
 * Elem de limpieza: 10% (si vale HASTA 200)
 * */

/**
 * @brief
 * @param this
 * @param pFunc
 * @return
 */
int ll_map(LinkedList* this, float (*pFunc)(void*)){
	int lenght;
	void* pElement;
	char resp;
	int retorno=0;
	float power;
	LinkedList* mappedList = NULL;
	if(this!=NULL && *pFunc!=NULL){
		mappedList = ll_newLinkedList();
		lenght = ll_len(this);

		for (int i = 0; i < lenght; i++) {
			pElement = ll_get(this, i);
			power = pFunc(pElement);
			if(power!=-1){
				KnightZodiac_setCosmosLevel(pElement, power);
				ll_add(mappedList, pElement);
			}
		}
	}

	controller_ListKnightZodiac(mappedList);
	printf("Desea Guardarla? y/n \n");
	scanf("%c",&resp);
	if(resp=='y'){
		controller_saveAsText("mapeado.csv", mappedList);
		ll_deleteLinkedList(mappedList);
		retorno=1;
	}
	//mostrar lista armada
	//preguntar si la quiero guardar s/n
	//s: controller_saveAsText ("mapeado.csv",newLinkedList);
	//delete_linkedList(newLinkedList);
return retorno;
}
//******************************************

/**
 * @brief  Obtiene el campo level del objeto.
 * @param  pElement
 * @return Retorna el nivel del personaje.
 */
int counterLevel(void* pElement){
	int level = -1;
	KnightZodiac* Object;
	if(pElement!=NULL){
		Object = (KnightZodiac*)pElement;
		if(Object!=NULL){
			KnightZodiac_getLevel(Object, &level);
		}
	}
	return level;
}

/*
 * Se deberá iterar todos los elementos de la lista y pasárselos a la funcion.La función “fn” devolverá
 * la cantidad que debe contarse. La función “ll_count” almacenará un acumulador al cual sumará
 * el valor de retorno de “fn” en cada iteración. Al finalizar las iteraciones, la función
 * “ll_count” devolverá el valor acumulado.*/
/**
 * @brief  Recorre elementos de una lista y acumula valores pasados por funcion.
 * @param  this Lista para iterar elementos.
 * @param  fn funcion que devuelve la cantidad que debe contarse.
 * @return Retorna el valor acumulado.
 */
int ll_count(LinkedList* this, int (*pFunc)(void*)){
	int acumulated = 0;
	int actualNumber; //valor actual de la iteracion
	int lenght; // largo de la lista
	void* pElement; //elemento actual para iterar.

	if(this!=NULL && *pFunc!=NULL){
		lenght = ll_len(this);
		for (int i = 0; i < lenght; i++) {
			pElement = ll_get(this, i); //recorro la lista original.
			actualNumber = pFunc(pElement);
			if (actualNumber!=-1) { // si la variable es distinto de -1, me copio el valor.
				acumulated = acumulated + actualNumber; //sumo el numero a mi acumulador
			}
		}
	}
return acumulated;
}
