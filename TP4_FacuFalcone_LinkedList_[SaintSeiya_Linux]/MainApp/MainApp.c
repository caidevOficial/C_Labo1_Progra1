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
#include "../Library/KnightOfZodiac/KnightZodiac.h"
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

void enterToContinue(void) {
	printf("    [Bot_Sanctuary]: Presione [Enter] para continuar...");
	getchar();
	__fpurge(stdin); // Linux
	//fflush(stdin); // Windows
}

void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
		int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*)){
	int flagForCompare = *flag; // traigo el valor del flag para comparar despues.
	if(flagForCompare==flagValue){ // si es 1 es xq esta abierto
		//printf("\n    [ERROR 0001]: Archivo abierto/cerrado, primero guardelo/carguelo.\n");
		printf("%s",messageError1);
	}else{
		if (!pFunction(path,array)) {
			//printf("\n    [ERROR 1010]: Imposible abrir/guardar archivo.\n\n");
			printf("%s",messageError2);
		} else {
			//printf("\n    Archivo abierto/guardado con exito.\n");
			printf("%s",messageSucess);
			*flag = NewflagValue; // Actualizo el flag a 1 si lo abri y a 0 si lo guarde.
		}
	}
}

void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue
		,LinkedList* array,int(*pFunction)(LinkedList*)){
	int flagForCompare = *flag;
	if(flagForCompare==flagValue){
		printf("%s",messageError1);
	}else{
		if (!pFunction(array)) {
			printf("%s",messageError2);
		} else {
			printf("%s",messageSucess);
			//*flag =NewflagValue;
		}
	}
}

void saveData(int loadOrWrite, LinkedList *arrayKnightZodiacs) {
	pFunctionLoadBinCsv( /* Guardar modo texto */
	"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
	"    [Bot_Sanctuary]: [ERROR 0100]: Archivo csv no cargado.\n",
	"    [Bot_Sanctuary]: Se guardo el archivo como [sanctuary.csv] con exito.\n",
	&loadOrWrite,CLOSED, OPEN, "sanctuary.csv", arrayKnightZodiacs,	controller_saveAsText);
	pFunctionLoadBinCsv( /* Guardar modo binario */
	"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
	"    [Bot_Sanctuary]: [ERROR 0100]: Archivo Bin no guardado.\n",
	"    [Bot_Sanctuary]: Se guardo una copia de seguridad como [sanctuary.bin] con exito.\n",
	&loadOrWrite,CLOSED, CLOSED, "sanctuary.bin", arrayKnightZodiacs,controller_saveAsBinary);
	/*
	 if(loadOrWrite==0){
	 printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
	 }else{
	 if (!controller_saveAsText("data.csv", arrayKnightZodiacs)) {
	 printf("\n    [ERROR 1011]: Imposible guardar como texto.\n\n");
	 } else {
	 printf("\n    Guardado en data.csv con exito.\n\n");
	 loadOrWrite = 0;
	 }
	 }*/
}

void logout(char *confirm, char *answer, LinkedList *arrayKnightZodiacs, LinkedList* copyArrayKnightZodiacs,
		int *loadOrWrite) {
	printf(	"    _______________________________________________________________\n"
	"   [Bot_Sanctuary]: Tras detener la rebelion causada por Saga de Geminis\n"
	"    el santuario ha vuelto a la tranquilidad, pero todo indica que no durara.\n"
	"    Necesitamos mas caballeros capaz de hacer frente a la situacion...\n\n"
	"    _______________________________________________________________\n"
	"    [Bot_Sanctuary]: Confirmas Salir? Y/N: ");
	__fpurge(stdin); //linux
	//fflush(stdin); // windows
	getString(confirm, sizeof(*confirm));
	*confirm = tolower(*confirm);
	if (*confirm == 'y') {
		saveData(*loadOrWrite, arrayKnightZodiacs); //guardo datos en csv y bin antes de salir.
		printf("    [Bot_Sanctuary]: Gracias, Esperamos volverte a ver! \n");
		//system("pause"); // windows
		enterToContinue(); //linux
		ll_deleteLinkedList(arrayKnightZodiacs);
		if(copyArrayKnightZodiacs!=NULL){
			ll_deleteLinkedList(copyArrayKnightZodiacs);
		}
		*answer = caseSalir();
	}
}

void tp4_FacuFalcone_LinkedList() {

	//system("color 02");
	//system("mode con: cols=72 lines=30");
	char confirm;
	char answer = 'y';
	//char saveNewArray[25];
	int loadOrWrite = 0;
	int numero = 0;
	//LinkedList* arrayKnightZodiacsFilter;  // array para clonar.
	LinkedList* copyArrayKnightZodiacs;

	LinkedList* arrayKnightZodiacs = ll_newLinkedList();
	if(ll_isEmpty(arrayKnightZodiacs)){ //chequeo que la lista este vacia.
		printf("    [Bot_Sanctuary]: Lista inicializada con exito!\n");
	}

	pFunctionLoadBinCsv(
	//Cargo los datos al iniciar el programa.
	"    [Bot_Sanctuary]: [ERROR 0001]: Archivo abierto, primero guardelo.\n",
	"    [Bot_Sanctuary]: [ERROR 0010]: Archivos Csv no cargados.\n",
	"    ___________________________________________\n    [Bot_Sanctuary]: Datos cargados con exito!.\n", &loadOrWrite,
	OPEN, OPEN, "sanctuary.csv", arrayKnightZodiacs,controller_loadFromText);
	do {
		switch (menu()) {
		//case 19: /* Cargar modo texto */
			// Reservado
			//printf("\n    dentro de op1.\n");
	//		/*pFunctionLoadBinCsv(
	//		 "\n    [Bot_Sanctuary]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n     primeros guardelos.\n",
	//		 "\n    [Bot_Sanctuary]: [ERROR 0010]: Archivos Csv no cargados.\n",
	//		 "\n    [Bot_Sanctuary]: Se cargo el archivos con exitos.\n",
	//		 &loadOrWrite,OPEN,OPEN,"data.csv",arrayKnightZodiacs,controller_loadFromText);*/
			//***************************************************************************
	//		break;
	//	case 20: /* Cargar modo bin */
			// Reservado
	//		/*pFunctionLoadBinCsv(
	//		 "\n    [Bot_Sanctuary]: [ERROR 0001]: Oh Calcutas! Archivos abiertos,\n    primeros guardelos.\n",
	//		 "\n    [Bot_Sanctuary]: [ERROR 0100]: Archivos Bin no cargados.\n",
	//		 "\n    [Bot_Sanctuary]: Se cargo el archivos con exitos.\n",
	//		 &loadOrWrite,OPEN,OPEN,"sanctuary.bin",arrayKnightZodiacs,controller_loadFromBinary);*/
			//***************************************************************************
	//		break;
		case 1: /* Alta Caballero */
			pFunction(
			"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Bot_Sanctuary]: [ERROR 0110]: No se pudos cargar el cliente.\n",
			"    ___________________________________________\n    [Bot_Sanctuary]: Se cargo el Caballero del Zodiaco con exito.\n",
			&loadOrWrite, CLOSED, arrayKnightZodiacs,	controller_addKnightZodiac);
			break;
			//***************************************************************************
		case 2: /* Modificar Caballero */
			pFunction(
			"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Bot_Sanctuary]: [WARNING 0111]: No se modifico Caballero del Zodiaco o\n    se cancelo la operacion.\n\n",
			"    ___________________________________________\n    [Bot_Sanctuary]: Modificacion con exito.\n",
			&loadOrWrite, CLOSED, arrayKnightZodiacs,	controller_editKnightZodiac);
			break;
			//***************************************************************************
		case 3: /* Baja Caballero */
			pFunction(
			"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Bot_Sanctuary]: [ERROR 1000]: No se dio de baja el Caballero del Zodiaco.\n\n",
			"    ___________________________________________\n    [Bot_Sanctuary]: Remosion con exito.\n",
			&loadOrWrite,CLOSED, arrayKnightZodiacs, controller_removeKnightZodiac);
			break;
			//***************************************************************************
		case 4: /* Listar Caballeros */
			pFunction(
			"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Bot_Sanctuary]: [ERROR 1001]: Imposible listar Caballeros del Zodiaco.\n\n",
			"    ___________________________________________\n    [Bot_Sanctuary]: Caballeros del Zodiaco listados con exito!.\n",
			&loadOrWrite, CLOSED, arrayKnightZodiacs,	controller_ListKnightZodiac);
			break;
			//***************************************************************************
		case 5: /* Ordenar Caballeros */
			pFunction(
			"    [Bot_Sanctuary]: [ERROR 0101]: Error al cargar [CSV o Bin].\n",
			"    [Bot_Sanctuary]: [ERROR 1010]: Imposible ordenar Caballero del Zodiaco.\n\n",
			" ",&loadOrWrite, CLOSED, arrayKnightZodiacs,	controller_sortKnightZodiac);
			/*
			if(flag==0){
				printf("\n    [ERROR 0101]: Primero hay que cargar [CSV o Bin].\n");
			}else{
			 if (!controller_sortKnightZodiac(arrayKnightZodiacs)) {
					printf("\n    [ERROR 1010]: Imposible ordenar empleado.\n\n");
				} else {
					printf("\n    Empleados ordenados con exito.\n");
				}
			}*/
			break;
			//***************************************************************************
		case 6:
			// Reservado Informes
			//arrayKnightZodiacsFilter= ll_newLinkedList();
			functionReports(arrayKnightZodiacs);
			break;
			//***************************************************************************
		case 7: /* Clonar Lista */
			copyArrayKnightZodiacs = ll_clone(arrayKnightZodiacs);
			if(copyArrayKnightZodiacs==NULL || ll_containsAll(copyArrayKnightZodiacs, arrayKnightZodiacs)!=1){
				printf("    [Bot_Sanctuary]: Error al duplicar Lista!\n");
			}
			else{
				controller_ListKnightZodiac(copyArrayKnightZodiacs);
				printf("    [Bot_Sanctuary]: Lista duplicada con exito!\n");
				controller_saveAsText("sanctuaryCopia.txt", copyArrayKnightZodiacs);
				printf("    [Bot_Sanctuary]: Se guardo una copia de seguridad en sanctuaryCopia.txt\n");

			}
			break;
			//***************************************************************************
		case 8:
			numero = ll_count(arrayKnightZodiacs, counterLevel);
			printf(" La cantidad de level es %d",numero);
			break;
			//***************************************************************************
		case 10: /* Salir */
			//system("color 03");
			logout(&confirm, &answer, arrayKnightZodiacs,copyArrayKnightZodiacs, &loadOrWrite); //pregunto para salir y guardo en csv y bin.
			break;
			//***************************************************************************
		default:
			printf(
					"    [Bot_Sanctuary]: [ERROR 1101]: Opcion incorrecta, use [1-7].\n");
			break;
			//***************************************************************************
		}
		enterToContinue(); // linux
		system("clear"); // linux
		//system("pause"); // windows
		//system("cls"); // windows
	} while (answer == 'y');
}
