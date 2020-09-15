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
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
 * ============================================================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Animations/logIn.h"
#include "../Animations/logOut.h"
#include "../Library/Controller/Controller.h"
#include "../Library/Controller/modifyController/modifyController.h"
#include "../Library/Controller/registerController/registerController.h"
#include "../Library/Controller/terminateController/terminateController.h"
#include "../Library/Employee/Employee.h"
#include "../Library/Validate/caidevValidate.h"
#include "../LinkedList.h"
#include "../Menu/MainMenu.h"

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
	printf("    [Bot_Apu]: Presiones una teclas para continuar");
	getchar();
	//__fpurge(stdin); // Linux
	fflush(stdin); // Windows
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

void tp3_LinkedList() {

	system("color 02");
	system("mode con: cols=72 lines=35");
	char confirm;
	char answer = 'y';
	int loadOrWrite = 0;

	LinkedList *arrayEmployees = ll_newLinkedList();

	do {
		switch (menu()) {
		case 1: /* Cargar modo texto */ // [WORKS]
			//printf("\n    dentro de op1.\n");
			pFunctionLoadBinCsv("\n    [Bot_Apu]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n   primeros guardelos.\n",
			"\n    [Bot_Apu]: [ERROR 0010]: Archivos Csv no cargados.\n",
			"\n    [Bot_Apu]: Se cargo el archivos con exitos.\n",
			&loadOrWrite,OPEN,OPEN,"data.csv",arrayEmployees,controller_loadFromText);
			break;
		case 2: /* Cargar modo bin */ // [WORKS]
			pFunctionLoadBinCsv("\n    [Bot_Apu]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n   primeros guardelos.\n",
			"\n    [Bot_Apu]: [ERROR 0100]: Archivos Bin no cargados.\n",
			"\n    [Bot_Apu]: Se cargo el archivos con exitos.\n",
			&loadOrWrite,OPEN,OPEN,"data.bin",arrayEmployees,controller_loadFromBinary);
			/*if(flag==1){ // en 1 esta abierto y en 0 cerrado.
				printf("\n    [ERROR 0011]: Archivo abierto, primero guardelo.\n");
			}else{
				if (!controller_loadFromBinary("data.bin", arrayEmployees)) {
					printf("\n    [ERROR 0100]: Archivo no cargado.\n");
				} else if(flag==0){
					printf("\n    Se cargo el archivo con exito.\n");
					flag = 1;
				}
			}*/
			break;
		case 3: /* Alta empleado */ // [WORKS]
			pFunction("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 0110]: No se pudos cargar empleados.\n",
			"    [Bot_Apu]: Se cargo el empleados con exitos.\n",
			&loadOrWrite,CLOSED,arrayEmployees,controller_addEmployee);
			//***************************************************************************
			break;
		case 4: /* Modificar empleado */ //[WORKS]
			pFunction("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [WARNING 0111]: No se modifico empleados o\n    se cancelos la operacion.\n\n",
			"    [Bot_Apu]: Modificacion con exitos.\n",
			&loadOrWrite,CLOSED,arrayEmployees,controller_editEmployee);
			break;
		case 5: /* Baja empleado */ // [WORKS]
			pFunction("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 1000]: No se dio de bajas.\n\n",
			"    [Bot_Apu]: Remosion con exitos.\n",
			&loadOrWrite,CLOSED,arrayEmployees,controller_removeEmployee);
			break;
		case 6: /* Listar empleado */ //[WORKS]
			pFunction("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 1001]: Imposibles listar empleados.\n\n",
			"    [Bot_Apu]: Empleados listados con exitos!.\n",
			&loadOrWrite,CLOSED,arrayEmployees,controller_ListEmployee);
			break;
		case 7: /* Ordenar empleado */ // [WORKS]
			pFunction("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 1010]: Imposibles ordenar empleados.\n\n",
			" ",
			&loadOrWrite,CLOSED,arrayEmployees,controller_sortEmployee);
			/*
			if(flag==0){
				printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
			}else{
				if (!controller_sortEmployee(arrayEmployees)) {
					printf("\n    [ERROR 1010]: Imposible ordenar empleado.\n\n");
				} else {
					printf("\n    Empleados ordenados con exito.\n");
				}
			}*/
			break;
		case 8: /* Guardar modo texto */ //[WORKS]
			pFunctionLoadBinCsv("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 0100]: Archivos csv no cargados.\n",
			"    [Bot_Apu]: Se guardos el archivos con exitos.\n",
			&loadOrWrite,CLOSED,CLOSED,"data.csv",arrayEmployees,controller_saveAsText);
			/*
			if(loadOrWrite==0){
				printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
			}else{
				if (!controller_saveAsText("data.csv", arrayEmployees)) {
					printf("\n    [ERROR 1011]: Imposible guardar como texto.\n\n");
				} else {
					printf("\n    Guardado en data.csv con exito.\n\n");
					loadOrWrite = 0;
				}
			}*/
			break;
		case 9: /* Guardar modo binario */ //[WORKS]
			pFunctionLoadBinCsv("    [Bot_Apu]: [ERROR 0101]: Oh Calcutas!\n    Primeros hay que cargar [CSV o Bin].\n",
			"    [Bot_Apu]: [ERROR 0100]: Archivos Bin no cargados.\n",
			"    [Bot_Apu]: Se guardos el archivos con exitos.\n",
			&loadOrWrite,CLOSED,CLOSED,"data.bin",arrayEmployees,controller_saveAsBinary);
			break;
		case 10: /* Salir */ //[WORKS]
			system("color 03");
			printf("    _______________________________________________________________\n"
				   "    [Bot_Apu]: Se colgabas, crasheabas, era toscos con los usuarios\n"
					"     y aun asi, ahi va el mejor programas que haya\n"
					"     escritos un estudiantes...\n"
					"    _______________________________________________________________\n\n"
					"    [Bot_Apu]: Confirmas Salir? Y/N: ");
			//__fpurge(stdin); //linux
			fflush(stdin); // windows
			getString(&confirm, sizeof(confirm));
			confirm = tolower(confirm);
			if (confirm == 'y') {
				printf("    [Bot_Apu]: Gracias, vuelvas prontos! \n");
				system("pause");
				ll_deleteLinkedList(arrayEmployees);
				answer = caseSalir();
				//answer = 'n';
			}
			break;
		default:
			printf("    [ERROR 1101]: Opcion incorrecta, use [1-10].\n");
			break;
		}
		//enterToContinue(); // linux
		//system("clear"); // linux
		system("pause"); // windows
		system("cls"); // windows
	} while (answer == 'y');
}
