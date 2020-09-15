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
 * Version     : Beta 3.0.0 [Beta v3.0.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

#include <ctype.h>
//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include "../Animations/logIn.h"
#include "../Animations/logOut.h"
#include "../Library/Controller/Controller.h"
#include "../Library/Controller/modifyController/modifyController.h"
#include "../Library/Controller/registerController/registerController.h"
#include "../Library/Controller/terminateController/terminateController.h"
#include "../Library/Validate/caidevValidate.h"
#include "../inc/LinkedList.h"
#include "../Library/Object/Object.h"
#include "../Menu/MainMenu.h"
#include "../Menu/Informes.h"

#define OPEN 1
#define CLOSED 0
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
/*
 *  [USAR SI O SI]
 *  LinkedList* ll_newLinkedList(void) [DONE]
 *  void ll_deleteLinkedList(LinkedList* self) -> Elimina el LinkedList [DONE]
 *  void ll_add(LinkedList* self , void* element) ->Agrega un elemento al final de LinkedList. [DONE]
 *  void ll_remove(LinkedList* self , int index) ->Elimina un elemento en LinkedList, en el índice especificado. [DONE]
 *  void* ll_get(LinkedList* self , int index) ->Retorna un puntero al elemento que se encuentra en el índice especificado. [DONE]
 *  int ll_len(LinkedList* self ) ->Retorna el tamaño del LinkedList. [DONE]
 *  */

void enterToContinue(void) {
	printf("    [Message]: Presione [Enter] para continuar...");
	getchar();
	__fpurge(stdin); // Linux
	//fflush(stdin); // Windows
}

void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
		int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*)){
	int flagForCompare = *flag; // traigo el valor del flag para comparar despues.
	if(flagForCompare==flagValue){ // si es 1 es xq esta abierto
		//printf("\n    [ERROR 0001]: Archivo abierto/cerrado, primero guardelo/carguelo.\n");
		printf("\n%s\n",messageError1);
	}else{
		if (!pFunction(path,array)) {
			//printf("\n    [ERROR 1010]: Imposible abrir/guardar archivo.\n\n");
			printf("\n%s\n",messageError2);
		} else {
			//printf("\n    Archivo abierto/guardado con exito.\n");
			printf("\n%s\n",messageSucess);
			*flag = NewflagValue; // Actualizo el flag a 1 si lo abri y a 0 si lo guarde.
		}
	}
}

void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue
		,LinkedList* array,int(*pFunction)(LinkedList*)){
	int flagForCompare = *flag;
	if(flagForCompare==flagValue){
		printf("\n%s\n",messageError1);
	}else{
		if (!pFunction(array)) {
			printf("\n%s\n",messageError2);
		} else {
			printf("\n%s\n",messageSucess);
			//*flag =NewflagValue;
		}
	}
}

void saveData(int loadOrWrite, LinkedList *thisOriginal) {
	pFunctionLoadBinCsv( /* Guardar modo texto */
	"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Message]: [ERROR 0100]: Archivo csv no cargado.\n",
			"    [Message]: Se guardo el archivos en Texto con exito.",
			&loadOrWrite,
			CLOSED, OPEN, "lista.csv", thisOriginal,
			controller_saveAsText);
	pFunctionLoadBinCsv( /* Guardar modo binario */
	"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Message]: [ERROR 0100]: Archivo Bin no guardado.\n",
			"    [Message]: Se guardo el archivo en Binario con exito.",
			&loadOrWrite,
			CLOSED, CLOSED, "lista.bin", thisOriginal,
			controller_saveAsBinary);
	/*
	 if(loadOrWrite==0){
	 printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
	 }else{
	 if (!controller_saveAsText("data.csv", arrayOriginal)) {
	 printf("\n    [ERROR 1011]: Imposible guardar como texto.\n\n");
	 } else {
	 printf("\n    Guardado en data.csv con exito.\n\n");
	 loadOrWrite = 0;
	 }
	 }*/
}

void logout(char *confirm, char *answer, LinkedList *thisOriginal, LinkedList* thisCopy,
		int *loadOrWrite) {
	printf(
			"    _______________________________________________________________\n"
					"   [Message]: Menu de ABM\n"
					"    _______________________________________________________________\n"
					"    [Message]: Confirma Salir? Y/N: ");
	__fpurge(stdin); //linux
	//fflush(stdin); // windows
	getString(confirm, sizeof(*confirm));
	*confirm = tolower(*confirm);
	if (*confirm == 'y') {
		saveData(*loadOrWrite, thisOriginal); //guardo datos en csv y bin antes de salir.
		printf("    [Message]: Gracias, Esperamos volverte a ver! \n");
		//system("pause"); // windows
		enterToContinue(); //linux
		ll_deleteLinkedList(thisOriginal);
		if(thisCopy!=NULL){
			ll_deleteLinkedList(thisCopy);
		}
		*answer = caseSalir();
	}
}

void ABM_Generico_LinkedList() {

	//system("color 02");
	//system("mode con: cols=72 lines=30");
	char confirm;
	char answer = 'y';
	int numero; // para guardar el total de niveles de personajes.
	int loadOrWrite = 0;

	LinkedList* copyarrayOriginal;

	LinkedList* arrayOriginal = ll_newLinkedList();
	if(ll_isEmpty(arrayOriginal)){ //chequeo que la lista este vacia.
		printf("    [Message]: Lista inicializada con exito!\n");
	}


	do {
		switch (menu()) {
		//case 19: /* Cargar modo texto */
			// Reservado
			//printf("\n    dentro de op1.\n");
	//		/*pFunctionLoadBinCsv(
	//		 "\n    [Message]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n     primeros guardelos.\n",
	//		 "\n    [Message]: [ERROR 0010]: Archivos Csv no cargados.\n",
	//		 "\n    [Message]: Se cargo el archivos con exitos.\n",
	//		 &loadOrWrite,OPEN,OPEN,"data.csv",arrayOriginal,controller_loadFromText);*/
			//***************************************************************************
	//		break;
	//	case 20: /* Cargar modo bin */
			// Reservado
	//		/*pFunctionLoadBinCsv(
	//		 "\n    [Message]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n    primeros guardelos.\n",
	//		 "\n    [Message]: [ERROR 0100]: Archivos Bin no cargados.\n",
	//		 "\n    [Message]: Se cargo el archivos con exitos.\n",
	//		 &loadOrWrite,OPEN,OPEN,"sanctuary.bin",arrayOriginal,controller_loadFromBinary);*/
			//***************************************************************************
	//		break;
		case 1: /* Alta Caballero */
			pFunction(
					"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
					"    [Message]: [ERROR 0110]: No se pudos cargar el cliente.\n",
					"    [Message]: Se cargo el Alta con exito.\n",
					&loadOrWrite, CLOSED, arrayOriginal,controller_addObject);
			//***************************************************************************
			break;
		case 2: /* Modificar Caballero */
			pFunction(
					"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
					"    [Message]: [WARNING 0111]: No se modifico o\n    se cancelo la operacion.\n\n",
					"    [Message]: Modificacion con exito.\n",&loadOrWrite, CLOSED, arrayOriginal,
					controller_editObject);
			//***************************************************************************
			break;
		case 3: /* Baja Caballero */
			pFunction(
					"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
					"    [Message]: [ERROR 1000]: No se dio de baja.\n\n",
					"    [Message]: Remosion con exito.\n",	&loadOrWrite,
					CLOSED, arrayOriginal, controller_removeObject);
			//***************************************************************************
			break;
		case 4: /* Listar Caballeros */
			pFunction(
					"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
					"    [Message]: [ERROR 1001]: Imposible listar datos.\n\n",
					"    [Message]: Datos listados con exito!.\n",
					&loadOrWrite, CLOSED, arrayOriginal,controller_ListObject);
			//***************************************************************************
			break;
		case 5: /* Ordenar Caballeros */
			pFunction(
					"    [Message]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
					"    [Message]: [ERROR 1010]: Imposible ordenar Datos.\n\n",
			" ",
			&loadOrWrite, CLOSED, arrayOriginal,controller_sortObject);
			/*
			if(flag==0){
				printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
			}else{
			 if (!controller_sortObject(arrayOriginal)) {
					printf("\n    [ERROR 1010]: Imposible ordenar empleado.\n\n");
				} else {
					printf("\n    Empleados ordenados con exito.\n");
				}
			}*/
			//***************************************************************************
			break;
		case 6:
			// Reservado Informes
			//arrayOriginalFilter= ll_newLinkedList();
			functionReports(arrayOriginal);
			//***************************************************************************
			break;
		case 7: /* Clonar Lista */
			copyarrayOriginal = ll_clone(arrayOriginal);
			if(copyarrayOriginal==NULL || ll_containsAll(copyarrayOriginal, arrayOriginal)!=1){
				printf("    [Message]: Error al duplicar Lista!\n");
			}
			else{
				controller_ListObject(copyarrayOriginal);
				printf("    [Message]: Lista duplicada con exito!\n");
				controller_saveAsText("listaCopia.txt", copyarrayOriginal);
				printf("    [Message]: Se guardo una copia de seguridad en listaCopia.txt\n");

			}
			break;
		case 8:
			numero = ll_count(arrayOriginal, counterLevel);
			printf("    Ejecutando ll_count\n");
			printf("    La cantidad de level es %d \n",numero);
			break;
		case 9:
			pFunctionLoadBinCsv(
			//Cargo los datos al iniciar el programa.
			"\n    [Message]: [ERROR 0001]: Archivo abierto, primero guardelo.\n",
			"\n    [Message]: [ERROR 0010]: Archivos Csv no cargados.\n",
			"\n    [Message]: Datos cargados con exito!.\n", &loadOrWrite,
			OPEN, OPEN, "sanctuary.csv", arrayOriginal,controller_loadFromText);
			break;
		case 10: /* Salir */
			//system("color 03");
			logout(&confirm, &answer, arrayOriginal,copyarrayOriginal, &loadOrWrite); //pregunto para salir y guardo en csv y bin.
			//***************************************************************************
			break;
		default:
			printf(
					"    [Message]: [ERROR 1101]: Opcion incorrecta, use [1-7].\n");
			//***************************************************************************
			break;
		}
		enterToContinue(); // linux
		system("clear"); // linux
		//system("pause"); // windows
		//system("cls"); // windows
	} while (answer == 'y');
}
