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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include "../../inc/LinkedList.h"
#include "parser.h"

#include "../KnightOfZodiac/KnightZodiac.h"

int parser_KnightZodiacFromText(FILE *pFile, LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *pKnightZodiac;

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
			pKnightZodiac = KnightZodiac_newParam(auxID, auxName,
					auxConstellation, armorType, level, cosmosLevel);

			if (pKnightZodiac != NULL) {
				ll_add(pArrayListKnightZodiac, pKnightZodiac);
				sucess = 1;
			}
		}
	}
	return sucess;
}

int parser_KnightZodiacFromBinary(FILE *pFile,
		LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *pKnightZodiac;
	int sucess = 0;

	if (pFile != NULL) {	//mientras el archivo no sea nulo, entro al bucle
		while (!feof(pFile)) {		// mientras no sea final de archivo, bucleo
			pKnightZodiac = KnightZodiac_new(); // inicializo
			if (fread(pKnightZodiac, sizeof(KnightZodiac), 1, pFile) == 1) {
				ll_add(pArrayListKnightZodiac, pKnightZodiac); // copio lo de pEmplo en el array
			}
		}
		sucess = 1;
	}
	return sucess;
}
