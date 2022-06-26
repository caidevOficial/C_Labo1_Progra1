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

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../inc/LinkedList.h"
#include "../Parser/parser.h"
#include "../Validate/caidevValidate.h"
#include "Controller.h"
#include "../KnightOfZodiac/KnightZodiac.h"
#include "../KnightOfZodiac/Getters/Getters.h"
#include "../KnightOfZodiac/Setters/Setters.h"
#include "saveMaxID_toText/saveToText_maxID.h"

int controller_loadFromText(char *path, LinkedList *pArrayListKnightZodiac) {
	FILE *pFile; // para leer los empleados
	FILE *pFile2; //para guardar la proxima ID

	int sucess = 0;

	pFile = fopen(path, "r");
	pFile2 = fopen("lastID.txt", "w");
	if (pFile != NULL) {
		parser_KnightZodiacFromText(pFile, pArrayListKnightZodiac);
		fclose(pFile);
		sucess = 1;
	}
	if (controller_saveAsTextMaxID(pFile2, "maxID.txt", pArrayListKnightZodiac)) {
		fclose(pFile2);
	}
	return sucess;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListKnightZodiac) {
	FILE *pFile;
	FILE *pFile2;
	int sucess = 0;
	pFile = fopen(path, "rb");
	pFile2 = fopen("lastID.txt", "w");
	if (pFile != NULL) {
		parser_KnightZodiacFromBinary(pFile, pArrayListKnightZodiac);
		sucess = 1;
	}
	// leo los datos cargados y Guardo el MaxID en archivo de texto
	if (controller_saveAsTextMaxID(pFile2, "lastID.txt", pArrayListKnightZodiac)) {
		fclose(pFile2);
	}
	fclose(pFile);

	return sucess;
}

int controller_ListKnightZodiac(LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *pKnightZodiac;
	int sucess = 0;
	int id;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	int cosmosLevel;

	if (pArrayListKnightZodiac == NULL) {
		printf("\n    [Bot_Sanctuary]: No hay Caballeros del Zodiaco para listar.\n");
	} else {
		printf("    __________________________________________________________________\n"
				"      ID      Nombre    Constelacion  Armadura    Nivel      Poder\n"
				"    ___________________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(pArrayListKnightZodiac); i++) {
			pKnightZodiac = ll_get(pArrayListKnightZodiac, i);
			KnightZodiac_getAllInfo(pKnightZodiac, &id, name, constellationName, armorType, &level,
			        &cosmosLevel);
			printf("    [%4d] [%-10s] [%-10s] [%-8s] [Lv: %3d] [Pow: %05d]  \n", id, name,
			        constellationName, armorType, level, cosmosLevel);
		}
	}
	return sucess;
}

int controller_sortKnightZodiac(LinkedList *pArrayListKnightZodiac) {
	int sucess = 0;
	if (pArrayListKnightZodiac != NULL) {
		KnightZodiac_sortKnightZodiac(pArrayListKnightZodiac);
		sucess = 1;
	}
	return sucess;
}

int saveAsTextFormat_Csv(FILE *pFile, LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *KnightZodiac;

	int ID;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	int cosmosLevel;
	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

	if (pFile != NULL && pArrayListKnightZodiac != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(pArrayListKnightZodiac); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			KnightZodiac = ll_get(pArrayListKnightZodiac, i);// copio la estructura del empleado del indice.
			KnightZodiac_getAllInfo(KnightZodiac, &ID, name, constellationName, armorType, &level,
			        &cosmosLevel); //obtengo toda la info del caballero.
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "ID", "NAME", "COSMOS", "ARMADURA", "LEVEL",
				        "POWER_LV");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%s,%s,%d,%d\n", ID, name, constellationName, armorType, level,
			        cosmosLevel); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	return sucess;
}

int controller_saveAsText(char *path, LinkedList *pArrayListKnightZodiac) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextFormat_Csv(pFile, pArrayListKnightZodiac)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(pArrayListKnightZodiac); //vacio el array
	return sucess;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListKnightZodiac) {
	FILE *pFile;
	KnightZodiac *auxKnightZodiac;

	int sucess = 0;

	if (pArrayListKnightZodiac != NULL && path != NULL) {
		pFile = fopen(path, "wb");

		for (int i = 0; i < ll_len(pArrayListKnightZodiac); i++) {
			auxKnightZodiac = (KnightZodiac*) ll_get(pArrayListKnightZodiac, i);
			fwrite(auxKnightZodiac, sizeof(KnightZodiac), 1, pFile);
		}
		fclose(pFile);
		ll_clear(pArrayListKnightZodiac);
		sucess = 1;
	}
	return sucess;
}
