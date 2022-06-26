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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include <ctype.h>
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "../LinkedList.h"
#include "../Validate/caidevValidate.h"
#include "../Pandemia/Pandemia.h"
#include "../Controller/Controller.h"
#include "../MenuPrincipal/MainMenu.h"
#include "../Pandemia/Setters/Setters.h"
#include "../Pandemia/Getters/Getters.h"
#include "../Informes/Informes.h"
#include "../Read_From_Directory/ReadFiles.h"

#define OPEN 1 // Para definir archivo abierto.
#define CLOSED 0 // Para definir archivo cerrado.

void simulatePause(){
	printf("    [Message]: Presione una tecla para continuar...\n");
	getchar();
	__fpurge(stdin);
}

void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSuccess,int* flag,int flagValue,
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
			printf("\n%s\n",messageSuccess);
			*flag = NewflagValue; // Actualizo el flag a 1 si lo abri y a 0 si lo guarde.
		}
	}
}

void pFunction(char* messageError1,char* messageError2,char* messageSuccess,int* flag,int flagValue
		,LinkedList* array,int(*pFunction)(LinkedList*)){
	int flagForCompare = *flag;
	if(flagForCompare==flagValue){
		printf("\n%s\n",messageError1);
	}else{
		if (!pFunction(array)) {
			printf("\n%s\n",messageError2);
		} else {
			printf("\n%s\n",messageSuccess);
			//*flag =NewflagValue;
		}
	}
}

int log_Out(char *confirm, char *answer) {
	int success = 0;
	printf(
			"    _______________________________________________________________\n"
			"    [Message]: Menu de ABM\n"
			"    _______________________________________________________________\n"
			"    [Message]: Confirma Salir? Y/N: ");
	__fpurge(stdin); //linux
	getString(confirm, sizeof(*confirm));
	*confirm = tolower(*confirm);
	if (*confirm == 'y') {
		printf("    __________________________________________________________\n"
				"    [Message]: Gracias, Esperamos volverte a ver!\n");
		*answer = 'n';
		success = 1;
	}else if(*confirm == 'n'){
		success = -1; // usado para vovler al menu y no borrar nada.
	}else{
		printf("    [ERROR] Respuesta invalida, reintentelo.\n");
		__fpurge(stdin); //linux
	}
	return success;
}

int FACUFALCONE_ABM_PANDEMY() {

	char confirm;
	char answer = 'y';
	char path[128];
	int loadOrWrite = 0;
	int valorSalida;

	LinkedList* filtrada= ll_newLinkedList();
	LinkedList* masCastigados = ll_newLinkedList();
	LinkedList* arrayOriginal = ll_newLinkedList();
	if(ll_isEmpty(arrayOriginal)){ //chequeo que la lista no este vacia.
		printf("    __________________________________________________________\n"
				"    [Message]: Lista inicializada con exito!\n");
	}

	do {
		switch (menu()) {
		case 0: /* Mostrar Archivos en directorio root */
			Read_Directory();
			break;
		case 1: // cargar datos /* Listo */
			Read_Directory(); // Muestro los archivos del directorio
			getName(path, 128, "    Ingrese el nombre del archivo que desea abrir (sin la extension del archivo): \n"
					"    Prueba con: pandemia: ", "    Nombre incorrecto, reintente.\n", 5);
			strMinuscula(path);
			strcat(path,".csv");
			//if(!strcmp(path,"pandemia.csv")){
				printf("    __________________________________________________________\n"
						"    El archivo a abrir sera: %s\n",path);
				pFunctionLoadBinCsv(
				//Cargo los datos al iniciar el programa.
				"    [Message]: [ERROR 0001]: Archivo abierto, primero guardelo.\n",
				"    [Message]: [ERROR 0010]: Archivos Csv no cargados.\n",
				"    [Message]: Datos cargados con exito!.\n", &loadOrWrite,
				OPEN, OPEN, path, arrayOriginal,controller_loadFromText);
			//}
			/*else{
				printf("    [ERROR] ese NO ES el archivo que te indique, por favor intentalo de nuevo.\n");
			}*/
			break;
			//***************************************************************************
		case 2: /* Listar datos */
			if(!loadOrWrite){
				printf("    [Message] Imposible listar datos, abra el archivo.\n");
			}else if(controller_ListObject(arrayOriginal)){
				printf("    __________________________________________________________\n"
				"    [Message] Datos listados con exito!\n");
			}
			break;
			//***************************************************************************
		case 3: /* Asignar estadisticas */
			if(!loadOrWrite){
				printf("    [Message] Imposible Asignar estadisticas, abra el archivo.\n");
			}else{
				arrayOriginal = ll_map(arrayOriginal, setRecovered);
				arrayOriginal = ll_map(arrayOriginal, setDeads);
				arrayOriginal = ll_map(arrayOriginal, setInfecteds);
				if(controller_ListObject(arrayOriginal)){
					printf("    __________________________________________________________\n"
							"    [Message] Estadisticas asignadas con exito!.\n");
				}
			}
			break;
			//***************************************************************************
		case 4: /* FILTRAR paises exitosos */
			if(!loadOrWrite){
				printf("    [Message] Imposible filtrar datos, abra el archivo.\n");
			}else{
				filtrada = ll_filter(arrayOriginal, filterSuccessCountry);
				if(controller_ListObject(filtrada)){
					controller_saveAsText("exitosos.csv", filtrada);
					printf("    __________________________________________________________\n"
							"    [Message] Mostrando paises con menos de 5K muertos\n"
							"    [Message] Lista filtrada y guardada como exitosos.csv\n");
				}
			}
			break;
			//***************************************************************************
		case 5: /* FILTRAR Paises al horno */
			if(!loadOrWrite){
				printf("    [Message] Imposible filtrar pais al horno, abra el archivo.\n");
			}else{
				filtrada = ll_filter(arrayOriginal, filterBakedCountry);
				if (controller_ListObject(filtrada)){
					controller_saveAsText("complicados.csv", filtrada);
					printf("    __________________________________________________________\n"
							"    [Message] Mostrando paises con el triple de infectados que curados.\n"
							"    [Message] Lista filtrada y guardada como complicados.csv\n");
				}
			}
			break;
			//***************************************************************************
		case 6: /* Ordenar por nivel de infeccion descendente */
			if(arrayOriginal==NULL || !loadOrWrite){
				printf("    [Message] ERROR: Array no inicializado o archivo sin abrir.\n");
			}else if(!ll_sort(arrayOriginal, Entity_sortInfectados, 0)){
				controller_ListObject(arrayOriginal);
				printf("    __________________________________________________________\n"
						"    [Message] Ordenado por Nivel de infeccion (descendente).\n");
			}
			break;
			//***************************************************************************
		case 7: /* Listar Paises mas castigados */
			if(!loadOrWrite){
				printf("    [Message] Imposible filtrar paises mas castigados, abra el archivo.\n");
			}else{
				masCastigados = punishedCountries(arrayOriginal);
				if(controller_ListObject(masCastigados)){
					printf("    __________________________________________________________\n"
							"    [Message] Paises mas castigados listados [Con mas muertes].\n");
				}
			}
			break;
			//***************************************************************************
		case 8: /* Salir */
			valorSalida = log_Out(&confirm, &answer);
			if(valorSalida==1){ //pregunto para salir y guardo en csv y bin.
				ll_deleteLinkedList(filtrada); // Limpio la lista de filtrados.
				ll_deleteLinkedList(arrayOriginal); // Limpio la lista original.
				ll_deleteLinkedList(masCastigados); // Limpio la lista de paises mas castigados.
				loadOrWrite = 0;
			}else if(!valorSalida){
				__fpurge(stdin);
			}
			break;
			//***************************************************************************
		default:
			printf(	"    __________________________________________________________\n"
					"    [Message]: [ERROR 1101]: Opcion incorrecta, use [1-8].\n");
			break;
			//***************************************************************************
		}
		simulatePause();
		system("clear"); // linux

	} while (answer == 'y');

	return 0;
}
