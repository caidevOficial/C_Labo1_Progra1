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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include "../../inc/LinkedList.h"
#include "parser.h"

#include "../Object/Object.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	Object *pObject;

	char auxID[128];
	char auxName[128];
	char level[128];
	char cosmosLevel[128];
	char auxConstellation[128];
	char armorType[128];

	int sucess = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID,
						auxName, auxConstellation, armorType, level,
						cosmosLevel);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID,
					auxName, auxConstellation, armorType, level, cosmosLevel);
			pObject = Object_newParam(auxID, auxName,
					auxConstellation, armorType, level, cosmosLevel);

			if (pObject != NULL) {
				ll_add(this, pObject);
				sucess = 1;
			}
		}
	}
	return sucess;
}

int parser_ObjectFromBinary(FILE *pFile,
		LinkedList *this) {
	Object *pObject;
	int sucess = 0;

	if (pFile != NULL) {	//mientras el archivo no sea nulo, entro al bucle
		while (!feof(pFile)) {		// mientras no sea final de archivo, bucleo
			pObject = Object_new(); // inicializo
			if (fread(pObject, sizeof(Object), 1, pFile) == 1) {
				ll_add(this, pObject); // copio lo de pEmplo en el array
			}
		}
		sucess = 1;
	}
	return sucess;
}
