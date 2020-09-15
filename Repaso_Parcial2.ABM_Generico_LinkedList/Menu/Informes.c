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

#include <stdlib.h>
#include <stdio_ext.h>
#include "../inc/LinkedList.h"
#include "../Library/Controller/Controller.h"
#include "../Library/Controller/registerController/registerController.h"
#include "../Library/Validate/caidevValidate.h"
#include "../Library/Object/Getters/Getters.h"
#include "../MainApp/MainApp.h"
#include "Informes.h"

#include "../Library/Object/Object.h"

//***************************************
// funcion para ll_count
//***************************************
int counterLevel(void* pElement){
	int level = -1;
	Object* an_Object;
	if(pElement!=NULL){
		an_Object = (Object*)pElement;
		if(an_Object!=NULL){
			Object_getLevel(an_Object, &level);
		}
	}
	return level;
}

float discountPrice(void* pElement){
	float price = -1;
	int rubroId;
	cleanObject* cleanProduct;
	if(pElement!=NULL){
		cleanProduct = (cleanObject*)pElement;
		if(cleanProduct!=NULL){
			cleanObject_getID(cleanProduct, &rubroId);
			cleanObject_getPrice(cleanProduct, &price);
			if(rubroId==1 && price>119){
				price*=0.8; // descuento del 20%
			}else if(rubroId==2 && price<201){
				price*=0.9; // descuento del 10%
			}
		}
	}
	return price;
}


float powerUpOrDown(void* pElement){
	float power = -1;
	char armor[20];
	Object* cleanProduct;
	if(pElement!=NULL){
		cleanProduct = (Object*)pElement;
		if(cleanProduct!=NULL){
			Object_getArmorType(cleanProduct, armor);
			Object_getCosmosLevel(cleanProduct, &power);
			if(strcmp(armor,"Plata")==0 && power>2000){
				power= power*0.5; // bajo un 50%
			}else if(strcmp(armor,"Bronce")==0 && power<1900){
				power = power*1.99; // aumento 99%
			}
		}
	}
	return power;
}

int reports(){
	int option;
	printf("    [Message]: Que desea informar?\n"
			"    [1] Datos Segun String [Dato].\n"
			"    [2] Datos Segun Rango de Float [8k-10k].\n"
			"    [3] Datos Segun Entero [50-100].\n"
			"    [4] Reubicar Datos.\n"
			"    [5] Aumentar Bronce y bajar Oro.\n"
			"    [6] Salir.\n");
	utn_getNumero(&option, "    [Message] Opcion: ",
	              "    [Message] Opcion Incorrecta.\n", 1, 6, 5);

	return option;
}

// ******* Funciones para filtrar (segun datos de lista) *******

int filterByArmor(void*anObject){
	int sucess = 0;

	Object* anotherObject;
	if(anObject!=NULL){

		anotherObject = (Object*) anObject;
		if(strcmp(anotherObject->armorType,"Oro")==0){
			sucess = 1;
			//printf(" se pudo comparar todo\n");
		}
	}

	return sucess;
}

int filterByPower(void*anObject){
	int sucess = 0;

	Object* anotherObject;
	if(anObject!=NULL){
		anotherObject = (Object*)anObject;
		if(anotherObject->cosmosLevel >= 8000 && anotherObject->cosmosLevel <= 9999){
			sucess = 1;
		}
	}
	return sucess;
}

int filterByLevel(void*anObject){
	int sucess = 0;

	Object* anotherObject;
	if(anObject!=NULL){
		anotherObject = (Object*)anObject;
		if(anotherObject->characterLevel >= 50 && anotherObject->characterLevel <= 100){
			sucess = 1;
		}
	}
	return sucess;
}

// ***** Funciones de reporte *****

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

/**
 * @brief Guardara en texto lo que hayamos ordenado en la lista nueva.
 * @param originalArray	La lista original.
 * @param cloneArray	La lista clonada.
 */
void functionReports(LinkedList* thisOriginal){

	int answerSave;
	char answer = 'y';
	char resp;

	system("clear");
	do{
		LinkedList* cloneArray;//= ll_newLinkedList();
		LinkedList* mapped;
		switch(reports()){
		case 1: /* ARMOR TYPE */
			cloneArray = ReportArmor(thisOriginal);
			controller_ListObject(cloneArray);
			if (utn_getNumero(&answerSave, "    [Message]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Message]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("goldenArmor.txt", cloneArray);
					printf("    [Message]; Guardado con exito como goldenArmor.txt\n");
					ll_deleteLinkedList(cloneArray);
				}else{
					printf("    [Message]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 2: /* COSMOS RANGE */
			cloneArray = ReportCosmos(thisOriginal);
			controller_ListObject(cloneArray);
			if (utn_getNumero(&answerSave, "    [Message]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Message]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("cosmosRange.txt", cloneArray); //cambiar para guardar
					printf("    [Message]; Guardado con exito como cosmosRange.txt\n");
					ll_deleteLinkedList(cloneArray); //borro luego de guardar en txt
				}else{
					printf("    [Message]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 3: /* LEVEL */
			cloneArray = ReportLevel(thisOriginal);
			controller_ListObject(cloneArray);
			if (utn_getNumero(&answerSave, "    [Message]: Desea guardar esta lista?\n    [1] SI.\n    "
					"[2] NO.\n    [Respuesta]: ", "    [Message]: Error, elija [1-2]\n", 1, 2, 5)){
				if(answerSave == 1){
					controller_saveAsText("level.txt", cloneArray);
					printf("    [Message]; Guardado con exito como level.txt\n");
					ll_deleteLinkedList(cloneArray); //borro luego de guardar en txt
				}else{
					printf("    [Message]; Guardado cancelado con exito.\n");
				}
			}
			break;
		case 4:
			controller_reallocateObject(thisOriginal);
			break;
		case 5:
			printf("    Ejecutando ll_map\n");
			mapped = ll_map(thisOriginal, powerUpOrDown);
			if(mapped!=NULL){
				controller_ListObject(mapped); //mostrar lista armada
				printf("    Desea Guardarla? y/n :"); //preguntar si la quiero guardar s/n
				__fpurge(stdin);
				getString(&resp, sizeof(resp));
				resp = tolower(resp);
				//scanf("%c",&resp);
				if(resp=='y'){ //s: controller_saveAsText ("mapeado.csv",newLinkedList);
					controller_saveAsText("mapeado.csv", mapped);
					printf("    Guardada con exito!\n\n");
					ll_deleteLinkedList(mapped); //delete_linkedList(newLinkedList);
				}
			}
			break;
		case 6:
			printf("    [Message]: Saliendo de informes.\n");
			answer = 'n';
			break;
		default:
			printf("    [Message]: Opcion incorrecta, Seleccione [1-4].");
			break;
		}
	}while(answer=='y');
}
