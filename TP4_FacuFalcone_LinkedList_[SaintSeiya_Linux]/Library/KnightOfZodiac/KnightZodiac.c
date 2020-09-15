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

//#include <stdio.h> // windows
#include "../KnightOfZodiac/KnightZodiac.h"

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include "../Controller/Controller.h"
#include "../Validate/caidevValidate.h"
#include "../../inc/LinkedList.h"
#include "../../MainApp/MainApp.h"
#include "../KnightOfZodiac/Getters/Getters.h"
#include "../KnightOfZodiac/Setters/Setters.h"

// Constructors
KnightZodiac* KnightZodiac_new() {
	KnightZodiac *newKnightZodiac;
	newKnightZodiac = (KnightZodiac*) calloc(sizeof(KnightZodiac), 1);

	return newKnightZodiac;
}

KnightZodiac* KnightZodiac_newParam(char *id, char *name, char *Constellation,
		char *armorType, char *level, char *cosmosLevel) {
	KnightZodiac *newKnightZodiac;
	newKnightZodiac = KnightZodiac_new();

	int auxId;
	int auxLevel;
	float auxCosmosLevel;

	auxId = atoi(id);
	auxLevel = atoi(level);
	auxCosmosLevel = atof(cosmosLevel);

	if (newKnightZodiac != NULL && id != NULL && name != NULL
			&& Constellation != NULL
			&& armorType != NULL && cosmosLevel != NULL && level != NULL) {
		KnightZodiac_setAllInfo(newKnightZodiac, &auxId, name, Constellation,
				armorType, auxLevel, auxCosmosLevel);
	}
	return newKnightZodiac;
}

// Searchers
int KnightZodiac_SearchForId(LinkedList *pArrayListKnightZodiac, int id) {
    int retorno = -1;
    int idAux;
	KnightZodiac *pKnightZodiac;

	for (int index = 0; index < ll_len(pArrayListKnightZodiac); index++) {
		pKnightZodiac = ll_get(pArrayListKnightZodiac, index);
		if (KnightZodiac_getID(pKnightZodiac, &idAux) == 1 &&
           idAux == id){
            retorno = index;
        }
    }
    return retorno;
}

//
int showKnightZodiac(KnightZodiac *KnightZodiac) {
	int sucess = 0;
	int id;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	int cosmosLevel;

	if (KnightZodiac != NULL) {
		KnightZodiac_getAllInfo(KnightZodiac, &id, name, constellationName,
				armorType,
				&level, &cosmosLevel);
		printf(
				"    __________________________________________________________\n"
						"       ID     Nombre    Constelacion   Armadura   Nivel Cosmos\n");
		printf("    [%4d] [%-10s] [%-10s] [%-10s] [%3d] [%05d]\n", id, name,
				constellationName, armorType, level, cosmosLevel);
		printf(
				"    __________________________________________________________\n");
		sucess = 1;
	}
	return sucess;
}

//Destructors
void KnightZodiac_delete(KnightZodiac *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int showMenuForSort(){
	int option;
	utn_getNumero(&option,
			"\n\n    [Bot_Sanctuary]: [OPCIONES]"
					"\n    [1] Ordenar Caballeros del Zodiaco por ID. [Simple Sort]"
					"\n    [2] Ordenar Caballeros del Zodiaco por Nombres. [Simple Sort]"
					"\n    [3] Ordenar Caballeros del Zodiaco por Constelacion. [Simple Sort]"
	              	"\n    [4] Ordenar por Constelacion y Nivel. [Double Sort]"
	              	"\n    [5] Ordenar Caballeros del Zodiaco por Armadura. [Simple Sort]"
	              	"\n    [6] Ordenar por Tipo de Armadura y Nivel. [Double Sort]"
					"\n    [7] Ordenar Caballeros del Zodiaco por Nivel. [Simple Sort]"
					"\n    [8] Ordenar por Nivel y Cantidad de Cosmos. [Double Sort]"
					"\n    [9] Ordenar Caballeros del Zodiaco por Cantidad de Cosmos. [Simple Sort]"
					"\n    [10] Cancelar."
					"\n    [Opcion]:",
			"    [Bot_Sanctuary]: [ERROR]: Opcion incorrecta, Elijas entre [1-10]",
			1, 10, 5);
	return option;
}

/* Funtion: [Sort] */
int KnightZodiac_sortKnightZodiac(LinkedList *pArrayListKnightZodiac) {
	int sucess = 0;
	//system("cls"); //windows
	system("clear"); //linux

	if (pArrayListKnightZodiac != NULL) {
		switch (showMenuForSort()) {
			case 1: /* ID */
				//system("cls"); //windows
				system("clear"); //linux
				printf("\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByID, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por ID con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 2: /* NOMBRES */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByName, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Nombre con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 3: /* CONSTELLATION */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByConstellation,
						1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Constelacion con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 4: /* CONSTELLATION & LEVEL */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_Megasort(pArrayListKnightZodiac, KnightZodiac_sortByConstellation, KnightZodiac_sortByLevel, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Constelacion y Nivel con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 5: /* ARMOR */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByArmorType, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Armadura con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 6: /* ARMOR & LEVEL */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_Megasort(pArrayListKnightZodiac, KnightZodiac_sortByArmorType, KnightZodiac_sortByLevel, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Armadura y Nivel con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 7: /* LEVEL */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByLevel, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Nivel con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 8: /* LEVEL & COSMOS LEVEL */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_Megasort(pArrayListKnightZodiac, KnightZodiac_sortByLevel, KnightZodiac_sortByCosmosLevel, 1);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Nivel y Cosmos con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 9: /* COSMOS LEVEL */
				//system("cls"); //windows
				system("clear"); //linux
				printf(
				"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
				ll_sort(pArrayListKnightZodiac, KnightZodiac_sortByCosmosLevel, 0);
				controller_ListKnightZodiac(pArrayListKnightZodiac);
				printf("    ___________________________________________________\n"
				"    [Bot_Sanctuary]: Ordenados por Cosmos con exito!\n");
				sucess = 1;
				break;
				//***************************************************************************
			case 10:
				/* SALIR */
				//opcion = 4;
				printf("\n    [Bot_Sanctuary]: [Accion cancelada]\n");
				sucess = 0;
				break;
				//***************************************************************************
			default:
				printf("\n    [Bot_Sanctuary]: [Error 404: Opcion no encontrada]\n");
				break;
				//***************************************************************************
		}
	}
	//getchar(); // linux
	enterToContinue(); //linux
	//system("pause"); //windows
	return sucess;
}

/* Function/SortBy: [ID] */
int KnightZodiac_sortByID(void *idOne, void *idTwo) {
	int id1;
	int id2;
	int sucess = 0; // si los id son iguales, devuelve 0

	KnightZodiac_getID(idOne, &id1);
	KnightZodiac_getID(idTwo, &id2);

	if (id1 > id2) {
		sucess = 1;
	} else if (id1 < id2) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [cosmosLevel] */
int KnightZodiac_sortByCosmosLevel(void *cosmosLevel1, void *cosmosLevel2) {
	int cosmosLevelOne;
	int cosmosLevelTwo;
	int sucess = 0; // si los salarios son iguales, devuelve 0

	KnightZodiac_getCosmosLevel(cosmosLevel1, &cosmosLevelOne);
	KnightZodiac_getCosmosLevel(cosmosLevel2, &cosmosLevelTwo);

	if (cosmosLevelOne > cosmosLevelTwo) {
		sucess = 1;
	} else if (cosmosLevelOne < cosmosLevelTwo) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Name] */
int KnightZodiac_sortByName(void *nameOne, void *nameTwo) {
	char name1[128];
	char name2[128];
	int sucess = 0;

	KnightZodiac_getName(nameOne, name1);
	KnightZodiac_getName(nameTwo, name2);

	if (strcmp(name1, name2) > 0) {
		sucess = 1;
	} else if (strcmp(name1, name2) < 0) {
		sucess = -1;
	}

	return sucess;
}

/* Function/SortBy: [Cosmos] */
int KnightZodiac_sortByConstellation(void *constellationOne,	void *constellationTwo) {
	char constellation1[128];
	char constellation2[128];
	int sucess = 0;

	KnightZodiac_getConstellation(constellationOne, constellation1);
	KnightZodiac_getConstellation(constellationTwo, constellation2);

	if (strcmp(constellation1, constellation2) > 0) {
		sucess = 1;
	} else if (strcmp(constellation1, constellation2) < 0) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [ArmorType] */
int KnightZodiac_sortByArmorType(void *armorOne, void *armorTwo) {
char armor1[128];
char armor2[128];
	int sucess = 0;

KnightZodiac_getArmorType(armorOne, armor1);
KnightZodiac_getArmorType(armorTwo, armor2);

if (strcmp(armor1, armor2) > 0) {
		sucess = 1;
} else if (strcmp(armor1, armor2) < 0) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Level] */
int KnightZodiac_sortByLevel(void *level1, void *level2) {
int levelOne;
int levelTwo;
int sucess = 0; // si los salarios son iguales, devuelve 0

KnightZodiac_getLevel(level1, &levelOne);
KnightZodiac_getLevel(level2, &levelTwo);

if (levelOne > levelTwo) {
	sucess = 1;
} else if (levelOne < levelTwo) {
	sucess = -1;
	}
	return sucess;
}
