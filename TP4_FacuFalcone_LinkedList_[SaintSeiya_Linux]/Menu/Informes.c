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

#include <stdlib.h>
#include <stdio.h>
#include "../inc/LinkedList.h"
#include "../Library/Controller/Controller.h"
#include "../Library/Controller/registerController/registerController.h"
#include "../Library/KnightOfZodiac/KnightZodiac.h"
#include "../Library/Validate/caidevValidate.h"
#include "../MainApp/MainApp.h"
#include "Informes.h"

int reports(){
	int option;
	printf("    [Bot_Sanctuary]: Que desea informar?\n"
			"    [1] Caballeros Segun Tipo de Armadura [Oro].\n"
			"    [2] Caballeros Segun Rango de Cosmos [8k-10k].\n"
			"    [3] Caballeros Segun Nivel [50-100].\n"
			"    [4] Reubicar Caballero.\n"
			"    [5] Salir.\n");
	utn_getNumero(&option, "    [Bot_Sanctuary] Opcion: ",
	              "    [Bot_Sanctuary] Opcion Incorrecta.\n", 1, 5, 5);

	return option;
}

int filterByArmor(void*knight){
	int sucess = 0;

	KnightZodiac* knightZodiac;
	if(knight!=NULL){

		knightZodiac = (KnightZodiac*)knight;
		if(strcmp(knightZodiac->armorType,"Oro")==0){
			sucess = 1;
			//printf(" se pudo comparar todo\n");
		}
	}

	return sucess;
}

int filterByPower(void*knight){
	int sucess = 0;

	KnightZodiac* knightZodiac;
	if(knight!=NULL){
		knightZodiac = (KnightZodiac*)knight;
		if(knightZodiac->cosmosLevel >= 8000 && knightZodiac->cosmosLevel <= 9999){
			sucess = 1;
		}
	}
	return sucess;
}

int filterByLevel(void*knight){
	int sucess = 0;

	KnightZodiac* knightZodiac;
	if(knight!=NULL){
		knightZodiac = (KnightZodiac*)knight;
		if(knightZodiac->characterLevel >= 50 && knightZodiac->characterLevel <= 100){
			sucess = 1;
		}
	}
	return sucess;
}

LinkedList* ReportArmor(LinkedList* originalArray){
	LinkedList* cloneArray = NULL;
	cloneArray = ll_filter(originalArray, filterByArmor);
	return cloneArray;
}

LinkedList* ReportCosmos(LinkedList* originalArray){
	LinkedList* cloneArray = NULL;
	cloneArray = ll_filter(originalArray, filterByPower);

	return cloneArray;
}

LinkedList* ReportLevel(LinkedList* originalArray){
	LinkedList* cloneArray = NULL;
	cloneArray = ll_filter(originalArray, filterByLevel);
	return cloneArray;
}

int reallocateKnight(LinkedList* pArrayZodiacKnight){
	int lastIDKnight;
	int firstID;
	int secondID;
	int index1;
	int index2;
	int sucess = 0;
	KnightZodiac* Knight;
	obtainID(&lastIDKnight);
	lastIDKnight--;

	controller_ListKnightZodiac(pArrayZodiacKnight); // muestro la lista
	utn_getNumero(&firstID,"    [Bot_Sanctuary]: Ingrese un ID para realocar en la lista: ",
	              "    [Bot_Sanctuary]: ID incorrecto, seleccione de la lista.\n", 1, lastIDKnight, 5);
	// Busco su indice.
	index1 = KnightZodiac_SearchForId(pArrayZodiacKnight,	firstID);

	if(index1==-1){
		printf("    [Bot_Sanctuary] Error, el caballero ingresado no existe en la lista.\n");
	}
	else{
		Knight = (KnightZodiac*)ll_pop(pArrayZodiacKnight, index1);
		showKnightZodiac(Knight); // Lo muestro.
		//****************************** Lo saco de la lista.
		printf("    [Bot_Sanctuary]: se reubicara el caballero listado arriba.\n"	);
		//****************************** Pido segunda id donde se ubicara.
		utn_getNumero(&secondID, "    [Bot_Sanctuary]: Se insertara antes de la ID especificada a continuacion: ",
		              "    [Bot_Sanctuary]: Error, ingrese una ID correcta.\n", 1, 250, 5);
		// Busco el nuevo indice donde sera ubicaco.
		index2 = KnightZodiac_SearchForId(pArrayZodiacKnight,	secondID);

		if (index2==-1){
			printf("    [Bot_Sanctuary] Error, el caballero ingresado no existe en la lista.\n");
			ll_push(pArrayZodiacKnight, index1, Knight); // Si falla, lo dejo donde estaba
		}
		else{
			//****************************** Lo pongo en nueva ubicacion.
			ll_push(pArrayZodiacKnight, (index2), Knight);
			controller_ListKnightZodiac(pArrayZodiacKnight); // imprimo nueva lista.
			printf("    [Bot_Sanctuary]: Reubicacion con exito!\n\n");
			sucess = 1;
		}
	}
	return sucess;
}

/**
 * @brief Guardara en texto lo que hayamos ordenado en la lista nueva.
 * @param originalArray	La lista original.
 * @param cloneArray	La lista clonada.
 */
void functionReports(LinkedList* originalArray){

	int answerSave;
	char answer = 'y';

	//char findBy[25];
	//char saveAs[25];
	system("clear");
	do{
		LinkedList* cloneArray;//= ll_newLinkedList();
		switch(reports()){
		case 1: /* ARMOR TYPE */
			cloneArray = ReportArmor(originalArray);
			controller_ListKnightZodiac(cloneArray);
			if (utn_getNumero(&answerSave, "    [Bot_Sanctuary]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Bot_Sanctuary]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("goldenArmor.txt", cloneArray);
					printf("    [Bot_Sanctuary]; Guardado con exito como goldenArmor.txt\n");
					ll_deleteLinkedList(cloneArray);
				}else{
					printf("    [Bot_Sanctuary]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 2: /* COSMOS RANGE */
			cloneArray = ReportCosmos(originalArray);
			controller_ListKnightZodiac(cloneArray);
			if (utn_getNumero(&answerSave, "    [Bot_Sanctuary]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Bot_Sanctuary]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("cosmosRange.txt", cloneArray);
					printf("    [Bot_Sanctuary]; Guardado con exito como cosmosRange.txt\n");
					ll_deleteLinkedList(cloneArray);
				}else{
					printf("    [Bot_Sanctuary]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 3: /* LEVEL */
			cloneArray = ReportLevel(originalArray);
			controller_ListKnightZodiac(cloneArray);
			if (utn_getNumero(&answerSave, "    [Bot_Sanctuary]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Bot_Sanctuary]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("level.txt", cloneArray);
					printf("    [Bot_Sanctuary]; Guardado con exito como level.txt\n");
					ll_deleteLinkedList(cloneArray);
				}else{
					printf("    [Bot_Sanctuary]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 4:
			reallocateKnight(originalArray);
			break;
		case 5:
			printf("    [Bot_Sanctuary]: Saliendo de informes.\n");
			answer = 'n';
			break;
		default:
			printf("    [Bot_Sanctuary]: Opcion incorrecta, Seleccione [1-4].");
			break;
		}
	}while(answer=='y');
}
