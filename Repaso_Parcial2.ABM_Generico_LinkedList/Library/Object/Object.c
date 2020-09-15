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
#include "Object.h"

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include "../Controller/Controller.h"
#include "../Validate/caidevValidate.h"
#include "../../inc/LinkedList.h"
#include "../../MainApp/MainApp.h"
#include "../Object/Getters/Getters.h"
#include "../Object/Setters/Setters.h"

// Constructors
Object* Object_new() {
	Object *newObject;
	newObject = (Object*) calloc(sizeof(Object), 1);

	return newObject;
}

Object* Object_newParam(char *id, char *name, char *Constellation,
		char *armorType, char *level, char *cosmosLevel) {
	Object *newObject;
	newObject = Object_new();

	int auxId;
	int auxLevel;
	float auxCosmosLevel;

	auxId = atoi(id);
	auxLevel = atoi(level);
	auxCosmosLevel = atof(cosmosLevel);

	if (newObject != NULL && id != NULL && name != NULL
			&& Constellation != NULL
			&& armorType != NULL && cosmosLevel != NULL && level != NULL) {
		Object_setAllInfo(newObject, &auxId, name, Constellation,
				armorType, auxLevel, auxCosmosLevel);
	}
	return newObject;
}

// Searchers
int Object_SearchForId(LinkedList *this, int id) {
    int retorno = -1;
    int idAux;
	Object *pObject;

	for (int index = 0; index < ll_len(this); index++) {
		pObject = ll_get(this, index);
		if (Object_getID(pObject, &idAux) == 1 &&
           idAux == id){
            retorno = index;
        }
    }
    return retorno;
}

//
int showObject(Object *Object) {
	int sucess = 0;
	int id;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	float cosmosLevel;

	if (Object != NULL) {
		Object_getAllInfo(Object, &id, name, constellationName,
				armorType,
				&level, &cosmosLevel);
		printf(
				"    __________________________________________________________\n"
						"       ID     Nombre    Constelacion   Armadura   Nivel Cosmos\n");
		printf("    [%4d] [%10s] [%10s] [%10s] [%3d] [%4.0f]\n", id, name,
				constellationName, armorType, level, cosmosLevel);
		printf(
				"    __________________________________________________________\n");
		sucess = 1;
	}
	return sucess;
}

//Destructors
void Object_delete(Object *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int showMenuForSort(){
	int option;
	utn_getNumero(&option,
			"\n\n    [Bot_Sanctuary]: [OPCIONES]"
					"\n    [1] Ordenar listas de Caballeros del Zodiaco por ID."
					"\n    [2] Ordernar lista de Caballeros del Zodiaco por Nombres."
					"\n    [3] Ordenar lista de Caballeros del Zodiaco por Constelacion."
					"\n    [4] Ordenar listas de Caballeros del Zodiaco por Armadura."
					"\n    [5] Ordenar listas de Caballeros del Zodiaco por Nivel."
					"\n    [6] Ordenar listas de Caballeros del Zodiaco por Cantidad de Cosmos."
					"\n    [7] Cancelar."
					"\n    [Opcion]:",
			"    [Bot_Sanctuary]: [ERROR]: Opcion incorrecta, Elijas entre [1-7]",
			1, 7, 5);
	return option;
}

/* Funtion: [Sort] */
int Object_sortObject(LinkedList *this) {
	int sucess = 0;
	//system("cls"); //windows
	system("clear"); //linux

	if (this != NULL) {
		switch (showMenuForSort()) {
	case 1: /* ID */
			//system("cls"); //windows
			system("clear"); //linux
		printf("\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
		ll_sort(this, Object_sortByID, 1);
			controller_ListObject(this);
			sucess = 1;
			break;
	case 2: /* NOMBRES */
			//system("cls"); //windows
			system("clear"); //linux
			printf(
					"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
		ll_sort(this, Object_sortByName, 1);
			controller_ListObject(this);
			sucess = 1;
			break;
		case 3: /* CONSTELLATION */
			//system("cls"); //windows
			system("clear"); //linux
			printf(
					"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
			ll_sort(this, Object_sortByConstellation,
					1);
			controller_ListObject(this);
			sucess = 1;
			break;
	case 4: /* ARMOR */
			//system("cls"); //windows
			system("clear"); //linux
			printf(
					"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
		ll_sort(this, Object_sortByArmorType, 1);
			controller_ListObject(this);
			sucess = 1;
			break;
	case 5: /* LEVEL */
			//system("cls"); //windows
			system("clear"); //linux
			printf(
					"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
		ll_sort(this, Object_sortByLevel, 1);
			controller_ListObject(this);
			sucess = 1;
			break;
		case 6: /* COSMOS LEVEL */
			//system("cls"); //windows
			system("clear"); //linux
			printf(
					"\n    [Bot_Sanctuary]: [Ordenando Lista]\n"
				"    [Bot_Sanctuary]: [Por favor, aguarde unos segundos!]\n"
				"    [Bot_Sanctuary]: [Estamos trabajando para usted!]\n");
			ll_sort(this, Object_sortByCosmosLevel, 1);
			controller_ListObject(this);
			sucess = 1;
			break;
		case 7:
			/* SALIR */
			//opcion = 4;
		printf("\n    [Bot_Sanctuary]: [Accion cancelada]\n");
			sucess = 0;
			break;
		default:
		printf("\n    [Bot_Sanctuary]: [Error 404: Opcion no encontrada]\n");
		}
	}
	//getchar(); // linux
	enterToContinue(); //linux
	//system("pause"); //windows
	return sucess;
}

/* Function/SortBy: [ID] */
int Object_sortByID(void *idOne, void *idTwo) {
	int id1;
	int id2;
	int sucess = 0; // si los id son iguales, devuelve 0

	Object_getID(idOne, &id1);
	Object_getID(idTwo, &id2);

	if (id1 > id2) {
		sucess = 1;
	} else if (id1 < id2) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [cosmosLevel] */
int Object_sortByCosmosLevel(void *cosmosLevel1, void *cosmosLevel2) {
	float cosmosLevelOne;
	float cosmosLevelTwo;
	int sucess = 0; // si los salarios son iguales, devuelve 0

	Object_getCosmosLevel(cosmosLevel1, &cosmosLevelOne);
	Object_getCosmosLevel(cosmosLevel2, &cosmosLevelTwo);

	if (cosmosLevelOne > cosmosLevelTwo) {
		sucess = 1;
	} else if (cosmosLevelOne < cosmosLevelTwo) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Name] */
int Object_sortByName(void *nameOne, void *nameTwo) {
	char name1[128];
	char name2[128];
	int sucess = 0;

	Object_getName(nameOne, name1);
	Object_getName(nameTwo, name2);

	if (strcmp(name1, name2) > 0) {
		sucess = 1;
	} else if (strcmp(name1, name2) < 0) {
		sucess = -1;
	}

	return sucess;
}

/* Function/SortBy: [Cosmos] */
int Object_sortByConstellation(void *constellationOne,
		void *constellationTwo) {
	char constellation1[128];
	char constellation2[128];
	int sucess = 0;

	Object_getConstellation(constellationOne, constellation1);
	Object_getConstellation(constellationTwo, constellation2);

	if (strcmp(constellation1, constellation2) > 0) {
		sucess = 1;
	} else if (strcmp(constellation1, constellation2) < 0) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [ArmorType] */
int Object_sortByArmorType(void *armorOne, void *armorTwo) {
char armor1[128];
char armor2[128];
	int sucess = 0;

Object_getArmorType(armorOne, armor1);
Object_getArmorType(armorTwo, armor2);

if (strcmp(armor1, armor2) > 0) {
		sucess = 1;
} else if (strcmp(armor1, armor2) < 0) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Level] */
int Object_sortByLevel(void *level1, void *level2) {
int levelOne;
int levelTwo;
int sucess = 0; // si los salarios son iguales, devuelve 0

Object_getLevel(level1, &levelOne);
Object_getLevel(level2, &levelTwo);

if (levelOne > levelTwo) {
	sucess = 1;
} else if (levelOne < levelTwo) {
	sucess = -1;
	}
	return sucess;
}
